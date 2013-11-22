//Student:			James DeLuca
//Creation date:	November 21, 2013
//Course number:	GAM1514
//Professor:		Danny Lingman
//Purpose:			WaterTile class

#ifndef WATER_TILE_H
#define WATER_TILE_H

#include "Tile.h"

//This is the WaterTile class, inherits from Tile
//and implements the water tile type getter
class WaterTile : public Tile
{
public:
	WaterTile(const char* textureName = RES_TILE_WATER);
	virtual ~WaterTile();
  
    //Return the type of the tile
    const char* getType();
};

#endif
