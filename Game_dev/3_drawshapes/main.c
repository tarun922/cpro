#include <stdio.h>
#include  <SDL3/SDL.h>

int main(){

    if (!SDL_Init(SDL_INIT_VIDEO)){
        printf("error initilising ! ");
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow("drawing shapes ", 600 , 500 , 0 );

    if (window == NULL){
        printf("nhi chala kya kar lega ");
        return 1;

    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window , NULL);
    if (window == NULL){
        printf("nhi chala kya kar lega ");
        return 1;

    }
    // defining a rectangle - x, y, width, height
    SDL_FRect player ={150 ,100 , 50 ,50 };
    SDL_FRect box = { 50, 50, 80, 80 };
    int run =1;
    SDL_Event event;
    while (run ==1){
        while (SDL_PollEvent(&event)){
            if (event.type == SDL_EVENT_QUIT){
                run = 0;   // press x to exit
            }
        }
        SDL_SetRenderDrawColor(renderer , 40,40,40,255);
        SDL_RenderClear(renderer);

        // u have to doo here all ur code to display on window
        // step 2: drawing a filled rectangle  (player placeholder)
        SDL_SetRenderDrawColor(renderer, 100, 200, 100, 255);
        SDL_RenderFillRect(renderer, &player);

        // step 3: outline-only rectangle draw
        SDL_SetRenderDrawColor(renderer, 200, 100, 100, 255);
        SDL_RenderRect(renderer, &box);

        // step 4: simple line
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        // line giving (renderer , x1 ,y1 , x2 ,y2)
        SDL_RenderLine(renderer, 0, 250, 400, 20);



        SDL_RenderPresent(renderer);


    }
    // after loop exitss  then we destroy the windowss
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
