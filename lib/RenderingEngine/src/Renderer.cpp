#include "Renderer.hpp"
#include "Logger.hpp"

VulkanRenderer::VulkanRenderer()
{

}

VulkanRenderer::~VulkanRenderer()
{
    LOG("\tDestroying Vulkan Renderer");
    Cleanup();
}

bool VulkanRenderer::Init()  
{
    return true;
}

void VulkanRenderer::Render() 
{
    LOG("VULKANRENDERER");
}

void VulkanRenderer::Cleanup() 
{

}