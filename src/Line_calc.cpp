module Line:calculations;

import Point2D;

[[nodiscard]] Point2D<int> calculate_distance(Point2D<int> const& lhs, Point2D<int> const& rhs) noexcept
{
    return lhs - rhs;
}