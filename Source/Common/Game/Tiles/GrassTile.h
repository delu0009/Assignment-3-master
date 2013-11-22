//Student:			James DeLuca
//Creation date:	November 21, 2013
//Course number:	GAM1514
//Professor:		Danny Lingman
//Purpose:			MountainTile class

#ifndef GRASS_TILE_H
#define GRASS_TILE_H

#include "Tile.h"


//This is the GrassTile class, inherits from Tile
//and implements the grass tile type getter
class GrassTile : public Tile
{
public:
	GrassTile(const char* textureName = RES_TILE_GRASS);
	virtual ~GrassTile();
  
    //Return the type of the tile
    const char* getType();
};

#endif
