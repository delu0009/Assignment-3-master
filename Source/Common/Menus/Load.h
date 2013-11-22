//Student:			James DeLuca
//Creation date:	November 21, 2013
//Course number:	GAM1514
//Professor:		Danny Lingman
//Purpose:			Load class

#ifndef LOAD_MENU_H
#define LOAD_MENU_H

#include "Menu.h"
#include "../Game/Level.h"
#include "../Level Editor/LevelEditor.h"

//This is the Load class, inherits from Menu
//and returns the load screen name, it also
//has a private function which takes a button parameter
//and completes an action to the respective button
class Load : public Menu
{
public:
    Load();
    ~Load();
    
    const char* getName();

private:
	Level* m_Level;
    void buttonAction(UIButton* button);
};

#endif
