// delta time & fps capping
#include <SDL3/SDL.h>
#include <stdio.h>

int main(){
    if (!SDL_Init(SDL_INIT_VIDEO)){
        printf("failed to start: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow("delta time", 800, 600, 0);
    if (window == NULL){
        printf("error creating window: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, NULL);
    if (renderer == NULL){
        printf("error while rendering: %s\n", SDL_GetError());
        return 1;
    }

    int run = 1;
    SDL_Event event;

    SDL_FRect player = { 100, 100, 50, 50 };
    float speed = 200.0f;   // ab ye "pixels per SECOND" hai, per frame nahi

    const int FPS = 60;
    const int frameDelay = 1000 / FPS;   // ~16ms per frame target

    Uint64 lastTime = SDL_GetTicks();    // pichle frame ka time

    while (run == 1){
        Uint64 frameStart = SDL_GetTicks();   // is frame ka start time

        // --- delta time nikaalo ---
        Uint64 currentTime = SDL_GetTicks();
        float deltaTime = (currentTime - lastTime) / 1000.0f;  // ms se seconds
        lastTime = currentTime;

        while (SDL_PollEvent(&event)){
            if (event.type == SDL_EVENT_QUIT){
                run = 0;
            }
        }

        const bool *keys = SDL_GetKeyboardState(NULL);
        // ab speed ko deltaTime se multiply kar rahe hain
        if (keys[SDL_SCANCODE_D]) player.x += speed * deltaTime;
        if (keys[SDL_SCANCODE_A]) player.x -= speed * deltaTime;
        if (keys[SDL_SCANCODE_W]) player.y -= speed * deltaTime;
        if (keys[SDL_SCANCODE_S]) player.y += speed * deltaTime;

        SDL_SetRenderDrawColor(renderer, 30, 30, 30, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 200, 30, 30, 255);
        SDL_RenderFillRect(renderer, &player);

        SDL_RenderPresent(renderer);

        // --- fps cap: agar frame jaldi complete ho gaya, thoda so jao ---
        Uint64 frameTime = SDL_GetTicks() - frameStart;
        if (frameTime < frameDelay){
            SDL_Delay(frameDelay - frameTime);
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
