
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL_image.h>

class Window{
public:
    Window();
    void createWindow();
    
private:
    SDL_Window* SDL_window;
    SDL_Surface* SDL_surface;
    SDL_Texture* SDL_texture;
    SDL_Renderer* SDL_renderer;
    
    int w_widht;
    int w_height;
};
