#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "RenderingEngine.hpp"

class VulkanRenderer : public RenderingEngine
{
private:

public:
    VulkanRenderer();
    ~VulkanRenderer() override;
    bool Init() override;
    void Render() override;
    void Cleanup() override;
};

#endif // end renderer hpp