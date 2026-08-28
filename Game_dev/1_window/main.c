#include <SDL3/SDL.h>
#include <stdio.h>

int main(){
    //intilising the game window
    //SDL_Init(SDL_INIT_VIDEO) --> THIS HELPS TO initialise THE SDL WINDOW

    if (!SDL_Init(SDL_INIT_VIDEO)){     // <--- must to do always
        printf("failed to initialise: %s\n", SDL_GetError());
        return 1;
    }

    // now definiling our window size and titile
    // using SDL_Window *window = SDL_CreateWindow("TITLE " , X,Y,Z);

    SDL_Window *window = SDL_CreateWindow("muhehe", 400, 300, 0);
    if (window == NULL){
        printf("window error: %s\n", SDL_GetError());
        return 1;
    }

    // THIS IS TO RENDER OUR WINDOW
    // USING SDL_Renderer *renderer = SDL_CreateRenderer(WINDOW , {NAME OF BACKEND RENDERER TO USE LIKE VULKAN OPENGL ETCETC BUT U CAN USE NULL } )
    // NULL IS FOR IDK JS USE THE BEST BACKEND RENDERER

    SDL_Renderer *renderer = SDL_CreateRenderer(window, NULL);
    if (renderer == NULL){
        printf("renderer error: %s\n", SDL_GetError());
        return 1;
    }

    // ye 2 lines actually screen pe kuch draw karti hain

    SDL_SetRenderDrawColor(renderer, 100, 100, 40, 255); // <--- THIS FILLS COLLOR ON WINDOW IT TAKES (WHERE TO DRAW , RED , BLUE ,GREEN , ALPHA -- OPACITY )
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);   // <-- iske bina window blank/invisible rehti hai Wayland pe
                                    // IT DISPLAYS THE WINDOW

    SDL_Delay(3000);// WINDOW WILL OPEN FOR 3 SEC THEN CLOSES

    SDL_DestroyRenderer(renderer); // DESTROYING RENDERER
    SDL_DestroyWindow(window);// DESTROYING WINDOW
    SDL_Quit();
    return 0;
}
