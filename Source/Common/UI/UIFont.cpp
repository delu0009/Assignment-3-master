//
//  UIFont.cpp
//  GAM-1514 OSX Game
//
//  Created by Bradley Flood on 2013-11-08.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#include "UIFont.h"
#include "../OpenGL/OpenGL.h"
#include "../Libraries/jsoncpp/json.h"
#include "../Utils/Utils.h"
#include <fstream>
#include <algorithm>
#include <ctype.h>
#include <math.h>


UIFont::UIFont(const char* fontName, float spaceAmount) :
    m_Font(NULL),
    m_Text(""),
    m_Width(0.0f),
    m_Height(0.0f),
    m_SpaceAmount(spaceAmount)
{
	m_Font = new OpenGLTexture(fontName);

	parseFontData(fontName);
	// PUT CODE HERE
}

UIFont::~UIFont()
{
    //delete the font texture object
	if(m_Font != NULL)
	{
		delete m_Font;
		m_Font = NULL;
	}

	//cycle through and delete all the fontframe objects in the m_FontData map

    // (this was a bit complex, so rather than make you type it...
    for(std::map<std::string, UIFontFrame*>::iterator it = m_FontData.begin(); it != m_FontData.end(); ++it)
    {
        if(it->second != NULL)
        {
            delete it->second;
            it->second = NULL;
        }
    }
    
    m_FontData.clear();
}

void UIFont::draw(float x, float y)
{
	for(int i = 0; i < m_Text.length(); i++)
	{
		//get the character
		std::string character = m_Text.substr(i, 1);

		//is the character a space?
		if(character == " ")
		{
			x += m_SpaceAmount;
			continue;
		}

		//get the font frame
		UIFontFrame* fontFrame = getFontFrame(character);
		if(fontFrame != NULL)
		{
			//set the font texture's source frame, based on the font's frame
		
			m_Font->setSourceFrame(fontFrame->x, fontFrame->y, fontFrame->width, fontFrame->height);
			
			//draw the font texture
			OpenGLRenderer::getInstance()->drawTexture(m_Font, x, y + (m_Height - fontFrame->height));

			//increment the x value
			x += fontFrame->width;
		}
	}
}

void UIFont::setText(const char* text)
{
	m_Text.assign(text);
	//Calculate the text's size based on the font data
	calculateSize();

}

const char* UIFont::getText()
{
    return m_Text.c_str();
}

float UIFont::getWidth()
{
    return m_Width;
}

float UIFont::getHeight()
{
    return m_Height;
}

void UIFont::parseFontData(const char* fontName)
{
    std::string jsonPath = ResourceUtils::getPathForResource(fontName, "json");
	std::ifstream inputStream;
	inputStream.open(jsonPath.c_str());

	//check to see if input stream is open
	if(inputStream.is_open() == true)
	{
		Json::Value root;
		Json::Reader reader;
		if(reader.parse(inputStream, root) == true)
		{
			Json::Value frames = root["frames"];
			for(int i = 0; i< frames.size(); i++)
			{
				//get the character and the frame data
				std::string character = frames[i]["filename"].asString();
				Json::Value frame = frames[i]["frame"];

				//create a new UIFontFrame object
				UIFontFrame* fontFrame = new UIFontFrame();
				fontFrame->x = frame["x"].asUInt();
				fontFrame->y = frame["y"].asUInt();
				fontFrame->width = frame["w"].asUInt();
				fontFrame->height = frame["h"].asUInt();

				//set the font data
				m_FontData[character] = fontFrame;
			}
		}
	}
	//close the input stream
	inputStream.close();

}

void UIFont::calculateSize()
{
	// JUST KEEP TYPING...
	m_Width = 0.0f;
	m_Height = 0.0f;

	//safety check the legnth of the text, make sure there is something to process
	if(m_Text.length() > 0)
	{
		for(int i = 0; i < m_Text.length(); i++)
		{
			//get character
			std::string character = m_Text.substr(i, 1);

			//is character a space?
			if(character == " ")
			{
				m_Width += m_SpaceAmount;
				continue;
			}

			//get the font frame
			UIFontFrame* fontFrame = getFontFrame(character);
			if(fontFrame != NULL)
			{
				m_Width += fontFrame->width;
				m_Height = fmaxf(m_Height, fontFrame->height);
			}
		}

}
}
UIFont::UIFontFrame* UIFont::getFontFrame(std::string character)
{
	// LAST BIT OF CODE...
	UIFontFrame* fontFrame = m_FontData[character];

	//if the font frame is NULL, try changing to upper case
	if(fontFrame == NULL && islower(character.at(0)) > 0)
	{
		transform(character.begin(), character.end(), character.begin(), ::toupper);
		fontFrame = m_FontData[character];
	}

	//If the font frame is still NULL, try changing to lower case
	if(fontFrame == NULL && isupper(character.at(0)) > 0)
	{
		transform(character.begin(), character.end(), character.begin(), ::tolower);
		fontFrame = m_FontData[character];

	}

	//there is still a change that fontFrame is NULL, so always 
	//safety check the treturn value of this function
	return fontFrame;
}

