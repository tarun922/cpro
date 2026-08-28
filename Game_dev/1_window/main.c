/*
 * Chapter 1: Window & Init
 * -------------------------
 * Goal: open an empty SDL3 window and close it cleanly.
 *
 * New concepts:
 *   - SDL_Init()        : starts up SDL's internal systems (video, etc.)
 *   - SDL_CreateWindow(): creates an actual OS window
 *   - SDL_Delay()       : pauses the program (in milliseconds)
 *   - SDL_DestroyWindow(), SDL_Quit(): cleanup, always do this before exiting
 *
 * Note for C beginners: SDL_Window* is a POINTER to a window object that
 * SDL manages internally. We don't need to know what's inside it — we
 * just pass this pointer to other SDL functions that need to know
 * "which window" to act on.
 */

#include <SDL3/SDL.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    /* SDL_Init returns true on success, false on failure.
     *      Always check return values for functions that can fail. */
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        printf("SDL_Init failed: %s\n", SDL_GetError());
        return 1; /* non-zero return means "something went wrong" */
    }

    /* Create a window: title, width, height, flags (0 = default behavior) */
    SDL_Window *window = SDL_CreateWindow("Chapter 1 - Window", 800, 600, 0);

    if (window == NULL) {
        printf("CreateWindow failed: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    printf("Window created! It will close in 3 seconds.\n");

    /* Keep the window open for 3 seconds so you can actually see it.
     *      (We don't have a proper event loop yet — that's Chapter 2.) */
    SDL_Delay(3000);

    /* Always clean up in reverse order of creation. */
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
