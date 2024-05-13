#ifndef RENDERING_ENGINE_HPP
#define RENDERING_ENGINE_HPP

typedef enum{
    Vulkan,
    OpenGL
} Renderer_Type;

class RenderingEngine
{
private:
    bool Init_Vulkan();
    bool Init_OpenGL(); 
    void Cleanup();

    Renderer_Type m_type;
public:
    RenderingEngine(Renderer_Type type);
    ~RenderingEngine();

    bool Init();
    void Render();
};

#endif // end rendering engine

class Renderer
{
private:

public:

    Renderer();
    ~Renderer();


};