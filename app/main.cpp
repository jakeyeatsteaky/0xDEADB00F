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
    [ ] Need to pass updates to renderData when position is updated to the renderer.  
            probably neeeds to be a method in the App class.  Basically getting game objects
            synced up with object render data in the rendering lib.
    [ ] Create SDL Text for FPS counter
    [ ] Create pixel art character for texture?

    
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
