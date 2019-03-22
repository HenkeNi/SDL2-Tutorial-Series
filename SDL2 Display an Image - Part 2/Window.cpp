//
//  Window.cpp
//  SDLTest
//
//  Created by Hürol Inci on 22.03.19.
//  Copyright © 2019 Hürol Inci. All rights reserved.
//

#include "Window.hpp"
#include <SDL2/SDL.h>
#include <SDL_image.h>

Window::Window(){
    
    SDL_window = nullptr;
    SDL_surface = nullptr;
    SDL_renderer = nullptr;
    SDL_texture = nullptr;
    
    w_height = 500;
    w_widht = 500;
}

void Window::createWindow(){
    
    SDL_INIT_EVERYTHING;
    SDL_surface = IMG_Load("/Users/hurolinci/Desktop/dimage.png");
    SDL_window = SDL_CreateWindow("Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w_widht, w_height, SDL_WINDOW_SHOWN);
    SDL_renderer = SDL_CreateRenderer(SDL_window, -1, 0);
    SDL_texture = SDL_CreateTextureFromSurface(SDL_renderer, SDL_surface);
    
    SDL_Event event;
    bool quit = false;
    
    while(!quit){
        SDL_RenderCopy(SDL_renderer, SDL_texture, NULL, NULL);
        SDL_RenderPresent(SDL_renderer);
        
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_KEYDOWN){
                quit = true;
            }
        }
    }
    SDL_DestroyTexture(SDL_texture);
    SDL_FreeSurface(SDL_surface);
    SDL_DestroyRenderer(SDL_renderer);
    SDL_DestroyWindow(SDL_window);
    SDL_Quit();
    
    
}
