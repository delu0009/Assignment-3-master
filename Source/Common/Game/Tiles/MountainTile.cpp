//Student:			James DeLuca
//Creation date:	November 21, 2013
//Course number:	GAM1514
//Professor:		Danny Lingman
//Purpose:			MountainTile class

#include "MountainTile.h"
#include "../../OpenGL/OpenGL.h"
#include "../../Constants/Constants.h"


MountainTile::MountainTile(const char* textureName) : Tile(TileTypeMountain, textureName, true)
{

}

MountainTile::~MountainTile()
{

}

const char* MountainTile::getType()
{
    return TILE_MOUNTAIN_TYPE;
}
