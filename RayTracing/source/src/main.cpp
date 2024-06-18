#include <iostream>
#include "color.h"
#include "vec3.h"
#include "ray.h"


bool hit_sphere(const point3& centre, double radius, const ray& r)
{
    vec3 oc = centre - r.origin();
    auto a = dot(r.direction(),r.direction());
    auto b = -2.0*(dot(r.direction(), oc));
    auto c = dot(oc,oc) - (radius * radius); 
    auto discriminant  = b * b - 4 * a * c;

    return(discriminant >= 0);
}




color ray_color(const ray& r)
{
    if(hit_sphere(point3(0,0,-1), 0.5,r))
    return color(1,0,0);
    
    
    vec3 unit_direction = unit_vector(r.direction());
    auto a = 0.5*(unit_direction.y() + 1.0);
    return (1.0-a)*color(1.0, 1.0, 1.0) + a*color(0.5, 0.7, 1.0);
}

int main()
{
    
    auto aspect_ratio = 16.0/9.0;
    int imageW = 400;

    //aspect ratio = imageW/imagwH, making sure imageH >= 1.
    int imageH = int(imageW/aspect_ratio);
    imageH = (imageH < 1) ? 1 : imageH;

    //camera pos
    auto focal = 1.0;
    auto viewportH = 2.0;
    auto viewportW = viewportH * (double(imageW)/imageH);
    auto camera_center = point3(0,0,0);

    //Vector across horizontal and down the viewport edges.
    auto viewport_u = vec3(viewportW,0,0);
    auto viewport_v = vec3(0,-viewportH,0);

    //calc delta vector, these vector give the change bw each pixel both horizontaly and vertically.
    auto pixel_delta_u = viewport_u/imageW;
    auto pixel_delta_v = viewport_v/imageH;

    //upper left pixel
    auto viewport_upper_left = camera_center - vec3(0,0,focal) - viewport_u/2 - viewport_v/2;
    auto pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);

    
    
    
    
    
    
    //start of the ppm format where P3 represents "ASCII PPM" format and 255 reps the max color size.
    std::cout << "P3\n" << imageW << " " << imageH << "\n255\n";

    for (int j = 0; j < imageH; j++) {
        std::clog << "\rScanlines remaining: " << (imageH - j) << ' ' << std::flush;
        for (int i = 0; i < imageW; i++) {
            auto pixel_center = pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v);
            auto ray_direction = pixel_center - camera_center;
            ray r(camera_center, ray_direction);

            color pixel_color = ray_color(r);
            write_color(std::cout, pixel_color);
        }
    }

    std::clog << "\rDone.                 \n";
}