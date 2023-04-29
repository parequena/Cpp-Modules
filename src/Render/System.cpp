module;

#include <vector>
#include <cstdint>

export module Render.System;

export import Render.Component;

namespace tinyEngine
{
export 
{
struct RenderSystem
{
    constexpr explicit RenderSystem() = default;

    RenderComponent& addComponent(std::uint32_t height, std::uint32_t width)
    {
        return components_.emplace_back(height, width);
    }

private:
    std::vector<RenderComponent> components_{};
};
}
} // namespace tinyEngine