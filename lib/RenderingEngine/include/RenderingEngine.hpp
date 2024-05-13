#ifndef RENDERING_ENGINE_HPP
#define RENDERING_ENGINE_HPP

class RenderingEngine
{
private:

public:
    virtual ~RenderingEngine(){}

    virtual bool Init() = 0;
    virtual void Render() = 0;
    virtual void Cleanup() = 0;
};

#endif // end rendering engine
