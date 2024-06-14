#include <iostream>
#include "color.h"
#include "vec3.h"

int main()
{
    //sets image size hence width and hight
    int imageW = 256;
    int imageH = 256;


    
    //start of the ppm format where P3 represents "ASCII PPM" format and 255 reps the max color size.
    std::cout << "P3\n" << imageW << ' ' << imageH << "\n255\n";


    for(int i{0}; i < imageH; ++i)
    {
        std::clog << "\rScanLines remaining: " << (imageH - i) << ' ' << std::flush;
        for(int j{0}; j < imageW; ++j)
        { 
            auto pixel_color = color(double(j)/(imageW-1), double(i)/(imageH-1), 0);


        }
    }


    std::clog << "\rDone.                      \n";


    
}