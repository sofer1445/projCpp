#include <SDL.h>
#include <cstdio>

// A function to move the rectangle using the arrow keys.
void moveRectUseArows(SDL_Renderer *renderer, SDL_Rect *rect) {
    // Check for events.
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        // Handle events.
        switch (e.type) {
            case SDL_KEYDOWN:
                // Move the rectangle in the direction of the pressed key.
                switch (e.key.keysym.sym) {
                    case SDLK_DOWN:
                        if (rect->y < 450){
                            rect->y += 10;
                        }

                        break;
                    case SDLK_UP:
                        if (rect->y > 0)
                            rect->y -= 10;
                        break;
                    case SDLK_LEFT:
                        if (rect->x > 0)
                            rect->x -= 10;
                        break;
                    case SDLK_RIGHT:
                        if (rect->x < 611)
                            rect->x += 10;
                        break;
                }
                break;
            case SDL_QUIT:
                // Quit the game.
                SDL_Quit();
                return;
            default:
                // Do nothing.
                break;
        }
    }
}

SDL_Rect drawShape(SDL_Renderer *renderer) {
    SDL_Rect rect = {220, 20, 25, 25};
    enum tetrisShape {
        I, J, L, O, S, T, Z
    };
    tetrisShape randomShape = static_cast<tetrisShape>(rand() % 7);
    switch (randomShape) {
        case I:
            // Draw the I.
            for (int i = 0; i < 4; ++i) {
                SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
                SDL_RenderFillRect(renderer, &rect);
                rect.x += 25;
            }
            break;
        case J:
            // Draw the J.
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
            SDL_RenderFillRect(renderer, &rect);
            rect.x += 25;
            SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
            SDL_RenderFillRect(renderer, &rect);
            rect.x += 25;
            rect.y += 25;
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
            SDL_RenderFillRect(renderer, &rect);
            break;
        case L:
            // Draw the L.
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
            SDL_RenderFillRect(renderer, &rect);
            rect.x += 25;
            SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
            SDL_RenderFillRect(renderer, &rect);
            rect.x += 25;
            rect.y -= 25;
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
            SDL_RenderFillRect(renderer, &rect);
            break;
        case O:
            // Draw the square.
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
            SDL_RenderFillRect(renderer, &rect);
            rect.x += 25;
            rect.y += 25;
            SDL_RenderFillRect(renderer, &rect);
            break;
        case S:
            // Draw the S.
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
            SDL_RenderFillRect(renderer, &rect);
            rect.x += 25;
            rect.y -= 25;
            SDL_RenderFillRect(renderer, &rect);
            rect.y += 25;
            SDL_RenderFillRect(renderer, &rect);
            break;
        case T:
            // Draw the +.
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
            SDL_RenderFillRect(renderer, &rect);
            rect.x += 25;
            SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
            SDL_RenderFillRect(renderer, &rect);
            rect.x -= 25;
            rect.y += 25;
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
            SDL_RenderFillRect(renderer, &rect);
            break;
        case Z:
            // Draw the Z.
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
            SDL_RenderFillRect(renderer, &rect);
            rect.x += 25;
            SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
            SDL_RenderFillRect(renderer, &rect);
            rect.x -= 25;
            rect.y -= 25;
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
            SDL_RenderFillRect(renderer, &rect);
            break;
    }

    return rect;
}

int main(int argc, char **argv) {
    // Initialize SDL.
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // Create a window.
    SDL_Window *window = SDL_CreateWindow("Hello SDL World", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480,
                                          SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // Create a renderer for the window.
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
    if (renderer == nullptr) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // Create a rectangle.
    SDL_Rect rect = {220, 20, 25, 25};

    // Start the main loop.
    while (true) {
        // Clear the screen.
        SDL_SetRenderDrawColor(renderer, 20, 0, 10, 255);
        SDL_RenderClear(renderer);
//        rect = drawShape(renderer);
        // Move the rectangle using the arrow keys.
        moveRectUseArows(renderer, &rect);
        if(rect.y == 450){
            rect = drawShape(renderer);
        }

        // Draw the rectangle.
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(renderer, &rect);

        // Present the screen.
        SDL_RenderPresent(renderer);

    }

    // Cleanup.
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}



