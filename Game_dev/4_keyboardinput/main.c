#include <stdio.h>
#include <SDL3/SDL.h>


int main(){

    if(!SDL_Init(SDL_INIT_VIDEO)){

        printf("lo bhaiya hogya kaand ");
        return 1;
    }
    SDL_Window *window = SDL_CreateWindow("lets seee " , 700 , 600 , 0 );
    if (window == NULL ){
        printf("got an error while creating a window ");
        return 1;
    }
    SDL_Renderer *renderer = SDL_CreateRenderer(window  , NULL);

    if (renderer == NULL){
        printf("error while rendering ");
        return 1;
    }
    // initilising game loops
    int run=1;
    // catching all the events that going to happens
    SDL_Event event;
    SDL_FRect player = { 150, 200, 60, 60 }; // defining our player block
    float speed = 0.3f; // player speed --> in next lec we will make it more better
    while (run ==1 ){
        while(SDL_PollEvent(&event)){
            if (event.type == SDL_EVENT_QUIT){
                run = 0;
            }
        }
        // getting the keboard key states
        // thiss will help us to know what keys are getting pressed
        const bool *keys = SDL_GetKeyboardState(NULL);
        // checking for all keys right left up down , and changes the positiong according to it
        if (keys[SDL_SCANCODE_RIGHT]) player.x += speed;
        if (keys[SDL_SCANCODE_LEFT])  player.x -= speed;
        if (keys[SDL_SCANCODE_UP])    player.y -= speed;
        if (keys[SDL_SCANCODE_DOWN])  player.y += speed;
        // again checking for all keys a d w s and changes the positiong according to it
        if (keys[SDL_SCANCODE_D]) player.x += speed;
        if (keys[SDL_SCANCODE_A])  player.x -= speed;
        if (keys[SDL_SCANCODE_W])    player.y -= speed;
        if (keys[SDL_SCANCODE_S])  player.y += speed;
        /// colouring our screen first
        SDL_SetRenderDrawColor(renderer, 30, 30, 40, 255);
        SDL_RenderClear(renderer);
        // displaying our player
        SDL_SetRenderDrawColor(renderer, 100, 200, 100, 255);
        SDL_RenderFillRect(renderer, &player);

        SDL_RenderPresent(renderer);
    }
    // destruction
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
