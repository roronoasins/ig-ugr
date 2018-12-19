/*
* Practicas de IG
* Domingo Martin Perandres© 2014-2018
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
  Vertices.resize(Coordinates.size()/3);

  for (unsigned int i=0;i<Vertices.size();i++){
    Vertices[i].x=Coordinates[i*3];
    Vertices[i].y=Coordinates[i*3+1];
    Vertices[i].z=Coordinates[i*3+2];
  }

  Triangles.resize(Positions.size()/3);

  for (unsigned int i=0;i<Triangles.size();i++){
    Triangles[i]._0=Positions[i*3];
    Triangles[i]._1=Positions[i*3+1];
    Triangles[i]._2=Positions[i*3+2];
  }
}
