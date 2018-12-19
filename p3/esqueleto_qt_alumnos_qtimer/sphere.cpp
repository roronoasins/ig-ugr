#include "sphere.h"

_sphere::_sphere()
{

}

void _sphere::create(unsigned int Divisions, float radio) {
    vector<_vertex2f> Curve;
    this->radio = radio;
    float angulo;
    for(int i=0; i <= Divisions; i++){
        angulo = i*(180/Divisions);
        angulo += 270;  //Obtenemos el equivalente en la parte inferior
        Curve.push_back(_vertex2f(radio*cos(angulo*M_PI/180),radio*sin(angulo*M_PI/180)));
    }

    _object3d_sweep_basic::create(Curve,Divisions);


}

