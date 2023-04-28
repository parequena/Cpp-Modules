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
    explicit constexpr Point2D(T x, T y)
        : x_{ x }
        , y_{ y }
    {}

    [[nodiscard]] inline constexpr T x() const noexcept { return x_; }
    [[nodiscard]] inline constexpr T y() const noexcept { return y_; }

private:
    T x_{};
    T y_{};
};

}