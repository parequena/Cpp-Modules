export module Math:Vect2D;

using T = int;
export struct Vect2D
{
    explicit constexpr Vect2D() noexcept = default;
    explicit constexpr Vect2D(T x, T y) noexcept
        : x_{ x }
        , y_{ y }
    {}

    [[nodiscard]] inline constexpr T x() const noexcept { return x_; }
    [[nodiscard]] inline constexpr T y() const noexcept { return y_; }
    
private:
    T x_{};
    T y_{};
};