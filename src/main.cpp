#include <iostream>
#include "vec3.h"
#include "color.h"
#include "ray.h"

color ray_color(const ray& r) {
    vec3 unit_direction = unit_vector(r.direction());
    auto a = 0.5*(unit_direction.y()+1.0);
    return (1.0-a)*color(1.0,1.0,1.0) + a*color(0.5, 0.7, 1.0);
}   

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

    //calculating the vectors across the horizontal and down the  vertical viewport edges
    auto viewport_u = vec3(viewport_width, 0, 0);
    auto viewport_v = vec3(0, -viewport_height, 0);

    //calculating the horizontal and vertical delta vectors from pixel to pixel i.e how much you move from left to right and up to down.
    auto pixel_delta_u = viewport_u / image_width;
    auto pixel_delta_v = viewport_v / image_height;

    //calculation of location of upper left pixel of the viewport
    auto viewport_upper_left = camera_center - vec3(0, 0, focal_length) -(viewport_u/2) - viewport_v/2;
    auto pixel00_loc = viewport_upper_left + 0.5*(pixel_delta_u + pixel_delta_v);               //with only viewport_upper_left, the ray shoots from top left corner of the pixel
                                                                                                //so to shoot from center of the pixe., pixel delta offset is used                                                                            
                    
    //render image
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for(int j=0; j<image_width; j++) {
        std::clog << "\rScanlines remaining: " << (image_height-j) << ' ' << std::flush;
        for (int i=0; i<image_height; i++) {
            auto pixel_center = pixel00_loc + (i*pixel_delta_u) + (j*pixel_delta_v);
            auto ray_direction = pixel_center - camera_center;
            ray r(camera_center, ray_direction);

            color pixel_color = ray_color(r);
            write_color(std::cout, pixel_color);
        }
    }

    std::clog << "\rDone.                      \n";
}

