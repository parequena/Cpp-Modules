#include <iostream>

import Line;
import Math;
import Render.System;

int main()
{
    std::cout << "Hola, Mundo!\n";

    Point2Di point{ 1, 2 };
    std::cout << "point.x() = " << point.x() << '\n';
    std::cout << "point.y() = " << point.y() << '\n';

    Line line{ point, Point2Di{ 1 , 1 } };
    auto const& dist = line.distance();
    std::cout << "dist.x() = " << dist.x() << '\n';
    std::cout << "dist.y() = " << dist.y() << '\n';

    Vect2D vect2d { 2 , 3 };
    std::cout << "vect2d.x() = " << vect2d.x() << '\n';

    Vect3D vect3d { 7 , 3, 7 };
    std::cout << "vect3d.x() = " << vect3d.x() << '\n';


    tinyEngine::RenderSystem renderSystem{};
    tinyEngine::RenderComponent& render = renderSystem.addComponent(1, 1);
    std::cout << "render.size(): " << render.size() << '\n';
    std::cout << "render[0]: " << int(render[0]) << '\n';
    render[0] = 155;
    std::cout << "render[0]: " << int(render[0]) << '\n';

    return EXIT_SUCCESS;
}