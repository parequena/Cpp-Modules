module;

// Includes.
#include <concepts>

export module Point2D;

export
{
template <typename T>
concept arithmetic = std::integral<T> or std::floating_point<T>;

template <arithmetic T>
struct Point2D
{
    explicit constexpr Point2D() noexcept = default;
    explicit constexpr Point2D(T x, T y) noexcept
        : x_{ x }
        , y_{ y }
    {}

    [[nodiscard]] inline constexpr T x() const noexcept { return x_; }
    [[nodiscard]] inline constexpr T y() const noexcept { return y_; }

    inline constexpr        Point2D& operator-=(Point2D const& rhs) { x_ -= rhs.x_; y_ -= rhs.y_; return *this; }
    inline constexpr friend Point2D  operator- (Point2D lhs, Point2D const& rhs) { lhs -= rhs; return lhs; }
    
private:
    T x_{};
    T y_{};
};

}