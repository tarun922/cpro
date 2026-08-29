// looping the game window

#include <SDL3/SDL.h>
#include <stdio.h>

int main(){

    //initilising
    if(!SDL_Init(SDL_INIT_VIDEO)){
        printf("failed to start ");
        return 1;
    }

    //creating a game window
    SDL_Window *window = SDL_CreateWindow("haha", 400,500,0);

    // checking for window
    if (window==NULL){
        printf("error creating window ");
        return 1;
    }
    // creating renderer
    SDL_Renderer *renderer = SDL_CreateRenderer(window, NULL);
    if (renderer==NULL){
        printf("error while rendering ");
        return 1;
    }
    // now doing game loop
    // creating a run varible that decides the game running
    int run =1;
    // creating a event varible that monitors events like mouse click btn click

    SDL_Event event;
    while (run == 1){
        // <--- 1. saare pending events check karo --->
        while (SDL_PollEvent(&event)){
            if (event.type == SDL_EVENT_QUIT){
                run = 0;   // X button dabaya, toh loop band karo
            }
        }

        // here doing drawing rendering works
        SDL_SetRenderDrawColor(renderer, 30, 30, 40, 255);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);

    }
    // after loop exitss  then we destroy the windowss
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
