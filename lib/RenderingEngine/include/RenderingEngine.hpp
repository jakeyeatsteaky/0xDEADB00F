#ifndef RENDERING_ENGINE_HPP
#define RENDERING_ENGINE_HPP

#include <glm/glm.hpp>

typedef enum
{
    eVulkanRenderer,
    eSDLRenderer
}RendererType;

typedef struct
{
    size_t idx;
    glm::vec2 positionData;
    glm::vec4 colorData;

}RenderData;

class RenderingEngine
{
private:
    
public:
    virtual ~RenderingEngine(){}

    virtual bool Init() = 0;
    virtual void Render() = 0;
    virtual void AddRenderObject(RenderData object) = 0;
    virtual void UpdateRenderObject(size_t idx, RenderData newData) = 0;
};

#endif // end rendering engine
