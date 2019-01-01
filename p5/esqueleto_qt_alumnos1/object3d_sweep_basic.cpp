/*
* Prácticas de IG
* Copyright Domingo Martín Perandrés 2014-218
* dmartin@ugr.es
*
* GPL 3
*/

#include "object3d_sweep_basic.h"

/**
*
*@param
*@returns
*/

void _object3d_sweep_basic::create(vector<_vertex2f> &Curve, unsigned int Num_horizontal_divisions1)
{
  _vertex3f Vertex;
  vector<_vertex3f> Generator_vertices;

  // comprobaciones
  if (Curve.size()<2){
    cout << "Error: the curve has only 1 point" << endl;
    exit(-1);
  }

  Num_vertical_divisions=Curve.size()-1;

  if (Num_horizontal_divisions1<3) Num_horizontal_divisions=3;
  else Num_horizontal_divisions=Num_horizontal_divisions1;

  // se inicializan los vectores
  Vertices.clear();
  Triangles.clear();

  Vertices.resize((Num_vertical_divisions+1)*Num_horizontal_divisions);
  Triangles.resize(Num_vertical_divisions*Num_horizontal_divisions*2);

  // ahora se generan el resto de los meridianos
  unsigned int Counter=0;
  for (unsigned int Col=0;Col<Num_horizontal_divisions;Col++){
    for (unsigned int Row=0;Row<=Num_vertical_divisions;Row++){
      Vertex.x=Curve[Row].x*cos((2*M_PI*(float)Col)/(float) Num_horizontal_divisions);
      Vertex.y=Curve[Row].y;
      Vertex.z=-Curve[Row].x*sin((2*M_PI*(float)Col)/(float) Num_horizontal_divisions);
      Vertices[Counter++]=Vertex;
      }
    }

  // ahora los triangulos
  // P(Row,Col+1),P(Row,Col),P(Row+1,Col) y P(Row+1,Col),P(Row+1,Col+1),P(Row,Col+1)
  _vertex3ui Triangle;

  Counter=0;
  for (unsigned int Row=0;Row<Num_vertical_divisions;Row++){
    for (unsigned int Col=0;Col<Num_horizontal_divisions;Col++){
      // par
      Triangle._0=linear_position(Row,Col);
      Triangle._1=linear_position(Row,Col+1);
      Triangle._2=linear_position(Row+1,Col);
      Triangles[Counter++]=Triangle;
      // impar
      Triangle._0=linear_position(Row,Col+1);
      Triangle._1=linear_position(Row+1,Col+1);
      Triangle._2=linear_position(Row+1,Col);
      Triangles[Counter++]=Triangle;
    }
  }
}
