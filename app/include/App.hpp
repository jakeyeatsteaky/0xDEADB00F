#ifndef APP_HPP
#define APP_HPP

#include <memory>
#include "Windowing.hpp"
#include "EventManager.hpp"
#include "RenderingEngine.hpp"
#include "GameObject.hpp"

constexpr RendererType DEFAULT_RENDERER_TYPE = RendererType::eSDLRenderer;

class SDLInit
{
public:
    SDLInit();
    ~SDLInit();

    int initCode;
};

class App
{
private:
    bool m_initialized;
    bool m_isRunning;
    RendererType m_rendererType;
    std::unique_ptr<SDLInit> m_sdl;
    std::unique_ptr<Window> m_windowObj;
    std::unique_ptr<EventManager> m_events;
    std::unique_ptr<RenderingEngine> m_renderer;
    std::vector<std::unique_ptr<GameObject>> m_gameObjects;


    void Setup();
    bool AppShouldQuit();
    void InitStartState();
    void SyncRenderData();

    void Input();
    void Update();
    void Render();

public:
    App();
    ~App() noexcept;

    void Run();
};

#endif // APP_HPP
