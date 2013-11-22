//Student:			James DeLuca
//Creation date:	November 21, 2013
//Course number:	GAM1514
//Professor:		Danny Lingman
//Purpose:			PyramidTile class

#include "PyramidTile.h"
#include "../../OpenGL/OpenGL.h"
#include "../../Constants/Constants.h"


PyramidTile::PyramidTile(const char* textureName) : Tile(TileTypePyramid, textureName, true)
{

}

PyramidTile::~PyramidTile()
{

}

const char* PyramidTile::getType()
{
    return TILE_PYRAMID_TYPE;
}
