#ifndef WINDOWING_HPP
#define WINDOWING_HPP

#ifdef __linux__
#include "SDL2/SDL.h"
#else
#include <SDL.h>
#endif

#include "SDL_vulkan.h"
#include <memory>

constexpr int DEFAULT_WINDOW_WIDTH = 1600;
constexpr int DEFAULT_WINDOW_HEIGHT = 900;

class Window
{
private:
    std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> m_window;

public:
    Window();
    ~Window() noexcept;
    bool Init();
    SDL_Window& GetWindow();

};
#endif //end windowing hpp