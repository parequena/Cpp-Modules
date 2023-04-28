export module Math:Vect3D;

import Math:Vect2D;

using T = int;
export struct Vect3D
{
    explicit constexpr Vect3D() noexcept = default;
    explicit constexpr Vect3D(T x, T y, T z) noexcept
        : xy_{ x , y }
        , z_{ z }
    {}

    [[nodiscard]] inline constexpr T x() const noexcept { return xy_.x(); }
    [[nodiscard]] inline constexpr T y() const noexcept { return xy_.y(); }
    [[nodiscard]] inline constexpr T z() const noexcept { return z_; }
    
private:
    Vect2D xy_{};
    T z_{};
};