//Student:			James DeLuca
//Creation date:	November 21, 2013
//Course number:	GAM1514
//Professor:		Danny Lingman
//Purpose:			PyramidTile class

#ifndef PYRAMID_TILE_H
#define PYRAMID_TILE_H

#include "Tile.h"

//This is the PyramidTile class, inherits from Tile
//and implements the pyramid tile type getter
class PyramidTile : public Tile
{
public:
	PyramidTile(const char* textureName = RES_TILE_PYRAMID);
	virtual ~PyramidTile();
  
    //Return the type of the tile
    const char* getType();
};

#endif
