//Student:			James DeLuca
//Creation date:	November 21, 2013
//Course number:	GAM1514
//Professor:		Danny Lingman
//Purpose:			TreeTile class

#include "TreeTile.h"
#include "../../OpenGL/OpenGL.h"
#include "../../Constants/Constants.h"


TreeTile::TreeTile(const char* textureName) : Tile(TileTypeTree, textureName, true)
{

}

TreeTile::~TreeTile()
{

}

const char* TreeTile::getType()
{
    return TILE_TREE_TYPE;
}
