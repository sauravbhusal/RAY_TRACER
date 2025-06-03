#ifndef COLOR_H
#define COLOR_H

#include <iostream>
#include "vec3.h"

using color = vec3 ;         //creating color as alias of vec3

void write_color(std::ostream& out, const color& pixel_color) {
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();

    //translating the range from [0,1] to [0,255]
    int rbyte = int(255.999*r);
    int gbyte = int(255.999*g);
    int bbyte = int(255.999*b);

    //writing out the pixel color components
    out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}

#endif
