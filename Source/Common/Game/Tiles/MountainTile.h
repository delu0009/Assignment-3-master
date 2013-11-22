//Student:			James DeLuca
//Creation date:	November 21, 2013
//Course number:	GAM1514
//Professor:		Danny Lingman
//Purpose:			MountainTile class

#ifndef MOUNTAIN_TILE_H
#define MOUNTAIN_TILE_H

#include "Tile.h"

//This is the MountainTile class, inherits from Tile
//and implements the mountain tile type getter
class MountainTile : public Tile
{
public:
	MountainTile(const char* textureName = RES_TILE_MOUNTAIN);
	virtual ~MountainTile();
  
    //Return the type of the tile
    const char* getType();
};

#endif
