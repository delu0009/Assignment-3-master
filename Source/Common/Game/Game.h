#ifndef GAME_H
#define GAME_H

#include <vector>
#include "../Screen Manager/Screen.h"

class GameObject;
class Level;
class UIFont;

class Game : public Screen
{
public:
  Game();
  ~Game();

  //Game lifecycle methods
  void update(double delta);
  void paint();
  void reset();

  //Screen name, must be implemented, it's a pure
  //virtual method in the Screen class
  const char* getName();
  
  Level* getLevel();

private:
  //Mouse Events
  void mouseLeftClickUpEvent(float positionX, float positionY);
  void keyUpEvent(int keyCode);

  //Level pointer
  Level* m_Level;

  //temp font pointer
  UIFont* m_Font;
};

#endif