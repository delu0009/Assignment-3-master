//
//  LevelEditor.cpp
//  GAM-1514 OSX Game
//
//  Created by Bradley Flood on 2013-10-25.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#include "LevelEditor.h"
#include "../Constants/Constants.h"
#include "../Game/Level.h"
#include "../Screen Manager/ScreenManager.h"
#include "../UI/UIButton.h"
#include "../UI/UIToggle.h"


LevelEditor::LevelEditor() :
    m_TilesMenu(NULL),
	m_TilesMenu2(NULL),
    m_Level(NULL),
    m_IsMouseDown(false),
    m_SelectedTileIndex(-1)
{
    //Create the Tiles menu items
    m_TilesMenu = new UISideMenu(this, SideMenuRight);
    m_TilesMenu->addButton(new UIToggle("MenuTileGround"));//added the rest of the menu tile buttons
	m_TilesMenu->addButton(new UIToggle("MenuTileMountain"));
	m_TilesMenu->addButton(new UIToggle("MenuTileGrass"));
	m_TilesMenu->addButton(new UIToggle("MenuTileTree"));
	m_TilesMenu->addButton(new UIToggle("MenuTilePyramid"));
	m_TilesMenu->addButton(new UIToggle("MenuTileWater"));
    
	m_TilesMenu2 = new UISideMenu(this, SideMenuLeft);//changed and refactored code to have a second menu on the Left side
    m_TilesMenu2->addButton(new UIButton("MenuSave"));//added buttons to said menu
	m_TilesMenu2->addButton(new UIButton("MenuLoad"));
	m_TilesMenu2->addButton(new UIButton("MenuExit"));
	m_TilesMenu2->addButton(new UIButton("MenuClear"));


    //Create the level object
    m_Level = new Level(true);
    
    //Reset everything
    reset();
}

LevelEditor::~LevelEditor()
{
    if(m_Level != NULL)
    {
        delete m_Level;
        m_Level = NULL;
    }
    
    if(m_TilesMenu != NULL)
    {
        delete m_TilesMenu;
        m_TilesMenu = NULL;
    }

	if(m_TilesMenu2 != NULL)//deleting newely created menu
    {
        delete m_TilesMenu2;
        m_TilesMenu2 = NULL;
    }
}

const char* LevelEditor::getName()
{
    return LEVEL_EDITOR_SCREEN_NAME;
}

void LevelEditor::update(double delta)
{
    if(m_Level != NULL)
    {
        m_Level->update(delta);
    }

    if(m_TilesMenu != NULL)
    {
        m_TilesMenu->update(delta);
    }
	if(m_TilesMenu2 != NULL)//updating newely created menu
    {
        m_TilesMenu2->update(delta);
    }
}

void LevelEditor::paint()
{
    if(m_Level != NULL)
    {
        m_Level->paint();
    }

    if(m_TilesMenu != NULL)
    {
        m_TilesMenu->paint();
    }
	if(m_TilesMenu2 != NULL)//painting newely created menu
    {
        m_TilesMenu2->paint();
    }
}

void LevelEditor::reset()
{
    if(m_Level != NULL)
    {
        m_Level->reset();
    }
}

void LevelEditor::mouseMovementEvent(float deltaX, float deltaY, float positionX, float positionY)
{    
    if(m_TilesMenu != NULL)
    {
        m_TilesMenu->mouseMovementEvent(deltaX, deltaY, positionX, positionY);
    }

	if(m_TilesMenu2 != NULL)//mouse movement event for newely created menu
    {
        m_TilesMenu2->mouseMovementEvent(deltaX, deltaY, positionX, positionY);
    }
    
    if(m_Level != NULL)
    {        
        if(m_SelectedTileIndex != -1 && m_IsMouseDown == true)
        {
            m_Level->setTileTypeAtPosition((TileType)m_SelectedTileIndex, positionX, positionY);
        }
    }
}

void LevelEditor::mouseLeftClickDownEvent(float positionX, float positionY)
{
    //Set the mouse down flag
    m_IsMouseDown = true;
}

void LevelEditor::mouseLeftClickUpEvent(float positionX, float positionY)
{
    //Set the mouse up flag
    m_IsMouseDown = false;
    
    //Safety check the level pointer, then set the new tile type in the index
    if(m_Level != NULL)
    {
        if(m_SelectedTileIndex != -1 && m_TilesMenu->isShowing() == false)
        {
            m_Level->setTileTypeAtPosition((TileType)m_SelectedTileIndex, positionX, positionY);
        }
    }
 
    //Notify the tiles menu of the mouse event
    if(m_TilesMenu != NULL)
    {
        m_TilesMenu->mouseLeftClickUpEvent(positionX, positionY);
    }

	if(m_TilesMenu2 != NULL)//mouse event is true for the left menu if it is not NULL
    {
        m_TilesMenu2->mouseLeftClickUpEvent(positionX, positionY);
    }
}
 
void LevelEditor::keyUpEvent(int keyCode)
{
    if(keyCode == KEYCODE_TAB)//show both menu's on tab press
    {
        if(m_TilesMenu != NULL)
        {
            m_TilesMenu->isShowing() == true ? m_TilesMenu->hide() : m_TilesMenu->show();
        }

		if(m_TilesMenu2 != NULL)
        {
            m_TilesMenu2->isShowing() == true ? m_TilesMenu2->hide() : m_TilesMenu2->show();
        }
    }

    else
    {
        if(m_Level != NULL)
        {
            m_Level->keyUpEvent(keyCode);
        }
    }
}

void LevelEditor::sideMenuButtonAction(UISideMenu* sideMenu, UIButton* button, int buttonIndex)
{

	switch(buttonIndex)//switch between buttons based on their number in the button index
	{
	case 3:
		for(int i = 0; i < m_Level->getNumberOfTiles(); i++)
		{
			m_Level->setTileTypeAtIndex((TileType)TileTypeGround, i);
		}
		break;
		
	case 0:
		ScreenManager::getInstance()->switchScreen(SAVE_MENU_SCREEN_NAME);
		break;

	case 1:
		ScreenManager::getInstance()->switchScreen(LOAD_MENU_SCREEN_NAME);
		break;
	   
	case 2:
		exit(1);
		break;
	}
}

void LevelEditor::sideMenuToggleAction(UISideMenu* sideMenu, UIToggle* toggle, int toggleIndex)
{
    if(sideMenu == m_TilesMenu)
    {
        //Un-toggled the previously selected toggle
        UIToggle* previousToggle = (UIToggle*)m_TilesMenu->getButtonForIndex(m_SelectedTileIndex);
        if(previousToggle != NULL)
        {
            previousToggle->setIsToggled(false);
        }
    
        //Set the selected tile index
        m_SelectedTileIndex = toggle->isToggled() == true ? toggleIndex : -1;
        
        //Hide the options and tiles menus
        m_TilesMenu->hide();
		m_TilesMenu2->hide();
    }
}
  
