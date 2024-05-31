#ifdef __linux__
#include <SDL2/SDL.h>
#else
#include <SDL.h>
#endif 

#include "Logger.hpp"
#include "App.hpp"

#if 0

Global TODO:
    [ ] Clean up how the dependencies are managed -- i dont think I need to include the source. ==
    [x] Finish constructinng the app class (windowing, eventmanager)
    [x] construct renderer object for vulkan stuffs
    [x] How do I make the "RenderingEngine" standalone library?
    [x] vkguide.dev start - Chapter 0 Code walkthrough.  

   !! START HERE !!  
    [ ] vkguide.dev start - Chapter 1 Vulkan Initialization Code.  
    
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
