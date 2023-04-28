export module Line;
import Point2D;
import :calculations;

export
{
using Point2Di = Point2D<int>;

struct Line
{
    explicit constexpr Line(Point2Di const& init, Point2Di const& end) noexcept
        : init_ { init }
        , end_ { end }
    {}

    [[nodiscard]] Point2Di distance() const noexcept
    {
        return calculate_distance(init_, end_);
    }

private:
    Point2Di init_{};
    Point2Di end_{};
};
}