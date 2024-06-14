#ifndef RAY_H
#define RAY_H


//defining a ray in 3D as P(t) = A + tB where A is origin of ray B is direction and t is the "Magnitude"
#include "vec3.h"

class ray {
  public:
    ray() {}

    ray(const point3& origin, const vec3& direction) : orig(origin), dir(direction) {}

    const point3& origin() const  { return orig; }
    const vec3& direction() const { return dir; }

    //fn at() provides P(t).
    point3 at(double t) const {
        return orig + t*dir;
    }

  private:
    point3 orig;
    vec3 dir;
};

#endif