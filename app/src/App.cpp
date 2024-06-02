
#ifdef __linux__
#include "SDL2/SDL.h"
#else
#include <SDL.h>
#endif
#include "App.hpp"
#include "AppUtil.hpp"
#include "Logger.hpp"
#include "Utility.hpp"
#include "Renderer.hpp"
#include "GameObject.hpp"


SDLInit::SDLInit()
{
    initCode = SDL_Init(SDL_INIT_VIDEO);
}

SDLInit::~SDLInit()
{
    LOG("\tDestroying the SDL Instance");
    SDL_Quit();
}

App::App() :
    m_initialized(false),
    m_isRunning(false),
    m_windowObj(nullptr),
    m_events(nullptr),
    m_rendererType(DEFAULT_RENDERER_TYPE)
{
    Setup();
}

App::~App() noexcept
{
    LOG("Destroying the App:");
}

void App::Setup()
{
    m_sdl = std::make_unique<SDLInit>();
    if(0 != m_sdl->initCode) {
        ERR("Could Not initialize SDL", SDL_GetError());
        return;
    }

    m_windowObj = std::make_unique<Window>();
    bool initParam1 = m_windowObj->Init();

    m_events = std::make_unique<EventManager>();
    bool initParam2 = m_events->Init();

    if(RendererType::eSDLRenderer == m_rendererType)
        m_renderer = std::make_unique<SDLRenderer>(DEFAULT_WINDOW_WIDTH, 
                                                    DEFAULT_WINDOW_HEIGHT,
                                                    m_windowObj->GetWindow());
    else
        m_renderer = std::make_unique<VulkanRenderer>(DEFAULT_WINDOW_WIDTH, 
                                                        DEFAULT_WINDOW_HEIGHT); 
    
    bool initParam3 = m_renderer->Init();

    m_initialized = initParam1 && initParam2 && initParam3;
}

bool App::AppShouldQuit()
{
    return m_events->quitEvent();
}

void App::Input()
{
    m_events->Poll();
}

void App::Update()
{
    int timeToWait = MS_PER_FRAME - (SDL_GetTicks() - timePrevFrame);
    if (timeToWait > 0)
        SDL_Delay(timeToWait);

    float  deltaTime = (SDL_GetTicks() - timePrevFrame) / 1000.0f;
    if (deltaTime > 0.05)
        deltaTime = 0.05f;
    timePrevFrame = SDL_GetTicks();

    for (size_t i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects.at(i)->SetDT(deltaTime);
        m_gameObjects.at(i)->Update();
    }

    SyncRenderData();
}

void App::SyncRenderData()
{
    for (size_t i = 0; i < m_gameObjects.size(); i++)
    {
        RenderData data = m_gameObjects.at(i).get()->GetRenderData();
        m_renderer->UpdateRenderObject(i, data);
    }
}

void App::Render()
{
    m_renderer->Render();
}

void App::InitStartState()
{
    // Initialize game objects here.  
    m_gameObjects.push_back(GameObject::CreateObject(m_rendererType));

    for (size_t i = 0; i < m_gameObjects.size(); i++) {
        GameObject* object = m_gameObjects.at(i).get();
        if (!object->Init())
            ERR("Could not create game object at index: " + i);

        RenderData data = object->GetRenderData();
        m_renderer->AddRenderObject(data);
    }
    
}

void App::Run()
{
    if(!m_initialized) {
        LOG("Failed to initialize the application");
        throw std::runtime_error("RUN failed");
    }

    InitStartState();

    LOG("App Start: We are underway!");
    while(!AppShouldQuit()) {

        Input();
        Update();
        Render();

        util::TimeDelay_ms(100);
    }
}
