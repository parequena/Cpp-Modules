#include <iostream>

import Line;

int main()
{
    std::cout << "Hola, Mundo!\n";

    Point2Di point{ 1, 2 };
    std::cout << "point.x() = " << point.x() << '\n';
    std::cout << "point.y() = " << point.y() << '\n';

    return EXIT_SUCCESS;
}