//Student:			James DeLuca
//Creation date:	November 21, 2013
//Course number:	GAM1514
//Professor:		Danny Lingman
//Purpose:			Save class


#include "Save.h"
#include "../UI/UIButton.h"
#include "../Game/Game.h"
#include "../Screen Manager/ScreenManager.h"


Save::Save() : Menu(NULL, NULL)
{
    addButton(new UIButton("ButtonSave1"));//creation of 6 save buttons
    addButton(new UIButton("ButtonSave2"));
    addButton(new UIButton("ButtonSave3"));
	addButton(new UIButton("ButtonSave4"));
    addButton(new UIButton("ButtonSave5"));
    addButton(new UIButton("ButtonSave6"));
}

Save::~Save()
{

}

const char* Save::getName()
{
    return SAVE_MENU_SCREEN_NAME;
}

void Save::buttonAction(UIButton* button)
{
	
    int index = getIndexForButton(button);//index that stores the buttons the function takes as a parameter

    if(index == 0)
    {
		LevelEditor* editorPtr = (LevelEditor*)ScreenManager::getInstance()->getScreenForName(LEVEL_EDITOR_SCREEN_NAME);//pointer that points to level editor screen
		
		editorPtr->m_Level->save("level1.json");//using pointer to point to the current level save to it level1.json

		ScreenManager::getInstance()->switchScreen(LEVEL_EDITOR_SCREEN_NAME);//return back to the level editor screen
    }

    else if(index == 1)
    {
      	LevelEditor* editorPtr = (LevelEditor*)ScreenManager::getInstance()->getScreenForName(LEVEL_EDITOR_SCREEN_NAME);
		
		editorPtr->m_Level->save("level2.json");

		ScreenManager::getInstance()->switchScreen(LEVEL_EDITOR_SCREEN_NAME);
    }

    else if (index == 2)
    {
        LevelEditor* editorPtr = (LevelEditor*)ScreenManager::getInstance()->getScreenForName(LEVEL_EDITOR_SCREEN_NAME);
		
		editorPtr->m_Level->save("level3.json");

		ScreenManager::getInstance()->switchScreen(LEVEL_EDITOR_SCREEN_NAME);
    }

	else if (index == 3)
    {
        LevelEditor* editorPtr = (LevelEditor*)ScreenManager::getInstance()->getScreenForName(LEVEL_EDITOR_SCREEN_NAME);
		
		editorPtr->m_Level->save("level4.json");

		ScreenManager::getInstance()->switchScreen(LEVEL_EDITOR_SCREEN_NAME);
    }

	else if (index == 4)
    {
        LevelEditor* editorPtr = (LevelEditor*)ScreenManager::getInstance()->getScreenForName(LEVEL_EDITOR_SCREEN_NAME);
		
		editorPtr->m_Level->save("level5.json");

		ScreenManager::getInstance()->switchScreen(LEVEL_EDITOR_SCREEN_NAME);
    }

	else if (index == 5)
    {
        LevelEditor* editorPtr = (LevelEditor*)ScreenManager::getInstance()->getScreenForName(LEVEL_EDITOR_SCREEN_NAME);
		
		editorPtr->m_Level->save("level6.json");

		ScreenManager::getInstance()->switchScreen(LEVEL_EDITOR_SCREEN_NAME);
    }
}
