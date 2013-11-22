//Student:			James DeLuca
//Creation date:	November 21, 2013
//Course number:	GAM1514
//Professor:		Danny Lingman
//Purpose:			Save class

#ifndef SAVE_MENU_H
#define SAVE_MENU_H

#include "Menu.h"
#include "../Game/Level.h"
#include "../Level Editor/LevelEditor.h"

//This is the Save class, inherits from Menu
//and returns the save screen name, it also
//has a private function which takes a button parameter
//and completes an action to the respective button
class Save : public Menu
{
public:
    Save();
    ~Save();
    
    const char* getName();

private:
	Level* m_Level;
    void buttonAction(UIButton* button);
};

#endif
