//Student:			James DeLuca
//Creation date:	November 21, 2013
//Course number:	GAM1514
//Professor:		Danny Lingman
//Purpose:			MountainTile class

#include "GrassTile.h"
#include "../../OpenGL/OpenGL.h"
#include "../../Constants/Constants.h"


GrassTile::GrassTile(const char* textureName) : Tile(TileTypeGrass, textureName, true)
{

}

GrassTile::~GrassTile()
{

}

const char* GrassTile::getType()
{
    return TILE_GRASS_TYPE;
}
