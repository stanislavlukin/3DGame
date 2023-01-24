#include <iostream>
#include <chrono>

int main() {
    double dt = 0;
    while (true) {
        // Measure elapsed time
        auto start = std::chrono::high_resolution_clock::now();
        // Handle input
        handleInput();
        // Update game state
        update(dt);
        // Render current frame
        render();
        // Measure elapsed time
        auto end = std::chrono::high_resolution_clock::now();
        dt = std::chrono::duration<double, std::milli>(end - start).count();
    }
    return 0;
}


#include <SDL2/SDL.h>

void handleInput() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {
                    case SDLK_LEFT:
                        // Handle left arrow key press
                        break;
                    case SDLK_RIGHT:
                        // Handle right arrow key press
                        break;
                    // ...
                }
                break;
            case SDL_MOUSEBUTTONDOWN:
                // Handle mouse button press
                break;
            // ...
        }
    }
}


#include <bullet/btBulletDynamicsCommon.h>

btDiscreteDynamicsWorld* dynamicsWorld;

void initPhysics() {
    // Create
