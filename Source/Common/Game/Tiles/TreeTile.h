//Student:			James DeLuca
//Creation date:	November 21, 2013
//Course number:	GAM1514
//Professor:		Danny Lingman
//Purpose:			TreeTile class

#ifndef TREE_TILE_H
#define TREE_TILE_H

#include "Tile.h"

//This is the TreeTile class, inherits from Tile
//and implements the tree tile type getter
class TreeTile : public Tile
{
public:
	TreeTile(const char* textureName = RES_TILE_TREE);
	virtual ~TreeTile();
  
    //Return the type of the tile
    const char* getType();
};

#endif
