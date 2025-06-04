#include <iostream>
#include "vec3.h"
#include "color.h"


int main() {
    //image
    auto aspect_ratio = 16.0 /9.0;
    int image_width = 400;

    //calculating image height and ensuring that it's at least 1
    int image_height = int(image_width / aspect_ratio);
    image_height = (image_height < 1) ? 1 : image_height;       //is (image_height < 1) if it is then substitute image_height = 1 otherwise substitute as it is
    
    //camera
    auto focal_length = 1.0;
    auto viewport_height = 2.0;
    auto viewport_width = viewport_height * aspect_ratio;
    auto camera_center = point3(0, 0, 0);

    //render image
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for(int j=0; j<image_width; j++) {
        std::clog << "\rSccanlines remaining: " << (image_height-j) << ' ' << std::flush;
        for (int i=0; i<image_height; i++) {
            auto pixel_color = color(double(i)/(image_width-1), double(j)/(image_height-1), 0);
            write_color(std::cout, pixel_color);
        }
    }

    std::clog << "\rDone.                      \n";
}

