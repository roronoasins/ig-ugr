/*
* Prácticas de IG
* Copyright Domingo Martín Perandrés 2014-218
* dmartin@ugr.es
*
* GPL 3
*/

#include "object_ply.h"

/**
*
*@param
*@returns
*/


void _object_ply::create(vector<float> &Coordinates,vector<unsigned int> &Positions)
{
    for(unsigned int i=0; i < Coordinates.size()/3; i++){
        Vertices.resize(Coordinates.size()/3);
        Vertices[i] = _vertex3f(Coordinates[3*i], Coordinates[3*i+1], Coordinates[3*i+2]);
    }
    for(unsigned int i=0; i < Positions.size()/3; i++){
        Triangles.resize(Positions.size()/3);
        Triangles[i] = _vertex3ui(Positions[3*i], Positions[3*i+1], Positions[3*i+2]);
    }
}
