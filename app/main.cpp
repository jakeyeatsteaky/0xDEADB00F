#ifdef __linux__
#include <SDL2/SDL.h>
#else
#include <SDL.h>
#endif 

#include "Logger.hpp"
#include "App.hpp"

#if 0

Global TODO:
   [x] Finish constructinng the app class (windowing, eventmanager)
    [x] construct renderer object for vulkan stuffs
    [x] How do I make the "RenderingEngine" standalone library?
    [x] vkguide.dev start - Chapter 0 Code walkthrough.  
    [ ] vkguide.dev start - Chapter 1 Vulkan Initialization Code.  

   !! START HERE !!  
    [ ] Working on SDL renderer for game.  Need to configure SDL renderer object 
            Figure out a good way to pass the App::m_windowObj to the 
            SDLRenderer object for SDL_CreateRenderer(...)
    [ ] finish building sdl renderer
    
#endif



int main(int /*argc*/, char** /*argv[]*/) {

    App app;

    try {
        app.Run();
    } catch (const std::runtime_error& e)  {
        ERR("Runtime error has occured", e.what());
        return -1;
    } catch (const std::exception& e) {
        ERR("Exception has occured", e.what());
        return -2;
    }

    return 0;
}
