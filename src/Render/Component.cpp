module;

#include <vector>
#include <cstdint>
#include <cassert>

export module Render.Component;


namespace tinyEngine
{
export 
{
struct RenderComponent
{
    constexpr explicit RenderComponent(std::uint32_t const height, std::uint32_t const width)
        : height_{ height }
        , width_{ width }
        , totalSize_ { height_ * width_ }

    {
        sprite_.resize(totalSize_);
    }

    constexpr std::uint8_t& operator[](std::size_t const index) noexcept { assert(index < totalSize_); return sprite_[index]; }
    constexpr std::uint8_t const& operator[](std::size_t const index) const noexcept { assert(index < totalSize_); return sprite_[index]; }

    constexpr std::size_t size() const noexcept { return sprite_.size(); }

private:
    std::uint32_t height_{};
    std::uint32_t width_{};
    std::uint32_t totalSize_{};
    std::vector<std::uint8_t> sprite_{};
};
}
} // namespace tinyEngine