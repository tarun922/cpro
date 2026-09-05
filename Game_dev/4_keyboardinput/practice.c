#include <stdio.h>
#include <SDL3/SDL.h>

int main(){

    if (!SDL_Init(SDL_INIT_VIDEO)){
        printf("aree aree not worning  : %s"  ,SDL_GetError() );
        return 1;
    }
    SDL_Window *window = SDL_CreateWindow("new win " , 800 , 600 , 0);
    if (window ==NULL){
        printf("error while creating window : %s" , SDL_GetError());
        return 1;
    }
    SDL_Renderer *renderer = SDL_CreateRenderer(window , NULL);
    if (renderer ==NULL){
        printf("error while rendering: %s" , SDL_GetError());
        return 1;
    }

    int run = 1;
    SDL_Event event;
    SDL_FRect player = {100,100 , 50,50};
    float speed = 0.3f;
    while(run==1){
        while(SDL_PollEvent(&event)){
            if (event.type == SDL_EVENT_QUIT){
                run=0;
            }
        }

        const bool *keys = SDL_GetKeyboardState(NULL);

        if (keys[SDL_SCANCODE_D]) player.x +=speed ;
        else if (keys[SDL_SCANCODE_A]) player.x -=speed ;
        else if (keys[SDL_SCANCODE_W]) player.y -=speed ;
        else if (keys[SDL_SCANCODE_S]) player.y +=speed ;

        SDL_SetRenderDrawColor(renderer , 30,30,30,255);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer , 200,30,30,255);
        SDL_RenderFillRect(renderer, &player);
        SDL_RenderPresent(renderer);


























    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0 ;
}
