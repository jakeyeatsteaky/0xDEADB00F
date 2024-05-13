#include "RenderingEngine.hpp"
#include "Logger.hpp"

RenderingEngine::RenderingEngine(Renderer_Type type) :
    m_type(type)
{
    Init();
}

RenderingEngine::~RenderingEngine()
{
    Cleanup();
    LOG("\tDestroying Rendering Engine");
}

bool RenderingEngine::Init()
{
    bool ret = false;
    switch(m_type)
    {
        case Vulkan:
            ret = Init_Vulkan();
            break;
        case OpenGL:
            ret = Init_OpenGL();
            break;
        default:
            break;
    }
    return ret;
}

bool RenderingEngine::Init_Vulkan()
{
    return true;
}

bool RenderingEngine::Init_OpenGL()
{
    return false;
}

void RenderingEngine::Cleanup()
{

}

void RenderingEngine::Render()
{

}