//Student:			James DeLuca
//Creation date:	November 21, 2013
//Course number:	GAM1514
//Professor:		Danny Lingman
//Purpose:			WaterTile class

#include "WaterTile.h"
#include "../../OpenGL/OpenGL.h"
#include "../../Constants/Constants.h"


WaterTile::WaterTile(const char* textureName) : Tile(TileTypeWater, textureName, true)
{

}

WaterTile::~WaterTile()
{

}

const char* WaterTile::getType()
{
    return TILE_WATER_TYPE;
}
