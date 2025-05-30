#include<iostream>

int main() {
    //image
    int image_width = 256;
    int image_height = 256;

    //render
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for(int j=0; j<image_height; j++){
        std::clog << "\rScanLines remaining: " << (image_height - j) << ' ' << std::flush;
        for(int i=0; i<image_width; i++){
            auto r = double(j) / (image_width-1);
            auto g = 0;
            auto b = double(i) / (image_height-1);

            int ir = int(255.999 * r);
            int ig = int(255.999 * g);
            int ib = int(255.999 * b);

            std::cout<< ir << ' ' << ig << ' ' << ib << '\n';
        }
    }
}