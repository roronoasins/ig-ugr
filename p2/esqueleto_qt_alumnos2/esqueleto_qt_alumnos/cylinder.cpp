#include "cylinder.h"

_cylinder::_cylinder()
{

}

void _cylinder::create(unsigned int Divisions) {
    vector<_vertex2f> Curve;
    Curve.push_back(_vertex2f(0.0, -0.5));
    Curve.push_back(_vertex2f(0.5, -0.5));
    Curve.push_back(_vertex2f(0.5, 0.5));;
    Curve.push_back(_vertex2f(0.0, 0.5));
    _object3d_sweep_basic::create(Curve,Divisions);
}
