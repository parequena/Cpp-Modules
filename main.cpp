#include <iostream>

import Line;

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

    return EXIT_SUCCESS;
}