//Student:			James DeLuca
//Creation date:	November 21, 2013
//Course number:	GAM1514
//Professor:		Danny Lingman
//Purpose:			Load class

#include "Load.h"
#include "../UI/UIButton.h"
#include "../Game/Game.h"
#include "../Screen Manager/ScreenManager.h"


Load::Load() : Menu(NULL, NULL)
{
    addButton(new UIButton("ButtonSave1"));
    addButton(new UIButton("ButtonSave2"));
    addButton(new UIButton("ButtonSave3"));
	addButton(new UIButton("ButtonSave4"));
    addButton(new UIButton("ButtonSave5"));
    addButton(new UIButton("ButtonSave6"));
}

Load::~Load()
{

}

const char* Load::getName()
{
    return LOAD_MENU_SCREEN_NAME;
}

void Load::buttonAction(UIButton* button)
{
	
    int index = getIndexForButton(button);//index that stores the buttons the function takes as a parameter

    if(index == 0)
    {
		LevelEditor* editorPtr = (LevelEditor*)ScreenManager::getInstance()->getScreenForName(LEVEL_EDITOR_SCREEN_NAME);//pointer that points to level editor screen
		
		editorPtr->m_Level->load("level1.json");//using pointer to point to the current level load to it level1.json

		ScreenManager::getInstance()->switchScreen(LEVEL_EDITOR_SCREEN_NAME);//return back to the level editor screen
    }

    else if(index == 1)
    {
      	LevelEditor* editorPtr = (LevelEditor*)ScreenManager::getInstance()->getScreenForName(LEVEL_EDITOR_SCREEN_NAME);
		
		editorPtr->m_Level->load("level2.json");

		ScreenManager::getInstance()->switchScreen(LEVEL_EDITOR_SCREEN_NAME);
    }

    else if (index == 2)
    {
        LevelEditor* editorPtr = (LevelEditor*)ScreenManager::getInstance()->getScreenForName(LEVEL_EDITOR_SCREEN_NAME);
		
		editorPtr->m_Level->load("level3.json");

		ScreenManager::getInstance()->switchScreen(LEVEL_EDITOR_SCREEN_NAME);
    }

	else if (index == 3)
    {
        LevelEditor* editorPtr = (LevelEditor*)ScreenManager::getInstance()->getScreenForName(LEVEL_EDITOR_SCREEN_NAME);
		
		editorPtr->m_Level->load("level4.json");

		ScreenManager::getInstance()->switchScreen(LEVEL_EDITOR_SCREEN_NAME);
    }

	else if (index == 4)
    {
        LevelEditor* editorPtr = (LevelEditor*)ScreenManager::getInstance()->getScreenForName(LEVEL_EDITOR_SCREEN_NAME);
		
		editorPtr->m_Level->load("level5.json");

		ScreenManager::getInstance()->switchScreen(LEVEL_EDITOR_SCREEN_NAME);
    }

	else if (index == 5)
    {
        LevelEditor* editorPtr = (LevelEditor*)ScreenManager::getInstance()->getScreenForName(LEVEL_EDITOR_SCREEN_NAME);
		
		editorPtr->m_Level->load("level6.json");

		ScreenManager::getInstance()->switchScreen(LEVEL_EDITOR_SCREEN_NAME);
    }
}
