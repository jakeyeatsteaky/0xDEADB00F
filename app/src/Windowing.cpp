#include "Windowing.hpp"
#include "Logger.hpp"



Window::Window() :
    m_window(nullptr, SDL_DestroyWindow)
{
    LOG_("Creating a window object");
}

Window::~Window() noexcept
{
    // Destroy SDL Window
    LOG("\tDestroying the SDL Window instance");
    SDL_DestroyWindow(m_window.get());
}

bool Window::Init()
{
    bool ret = false;
    SDL_Window* window = SDL_CreateWindow("0xDEADBEEF",
                                SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED,
                                DEFAULT_WINDOW_WIDTH,
                                DEFAULT_WINDOW_HEIGHT,
                                SDL_WINDOW_SHOWN | SDL_WINDOW_VULKAN | SDL_WINDOW_RESIZABLE);
    if(nullptr == window) { 
        ERR("Failed to create SDL window", SDL_GetError());
        return ret;
    }
    // Since the struct SDL_Window is a C struct, (cannot be "constructed"), use .reset();
    m_window.reset(window);

    ret = true;
    return ret;
}

SDL_Window& Window::GetWindow()
{
    if (!m_window) {
        throw std::runtime_error("SDL_Window is not initialized");
    }

    return *m_window;
}