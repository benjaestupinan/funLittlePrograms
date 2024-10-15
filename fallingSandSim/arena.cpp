#include <iostream>
#include <SDL2/SDL.h>
#include <vector>

// compilar con g++ arena.cpp -o arena -lSDL2 && ./arena


int main(int argc, char* argv[]) {
    // Inicializar SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "Error al inicializar SDL: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Crear una ventana
    SDL_Window* window = SDL_CreateWindow("Ventana SDL",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          640, 480,
                                          SDL_WINDOW_SHOWN);

    if (!window) {
        std::cerr << "Error al crear la ventana: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }
    
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer)
    {
        std::cerr << "Error al crear el renderer: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    bool running = true;
    SDL_Event event;
    int tamaño = 150;

    std::vector<std::vector<int>> matriz(tamaño, std::vector<int>(tamaño));

    int width, height;
    SDL_GetWindowSize(window, &width, &height);
    
    bool click = false;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
            if (event.type == SDL_KEYDOWN)
            {
                if (event.key.keysym.sym == SDLK_ESCAPE)
                {
                    running = false;
                }
                
            }
            if (event.type == SDL_MOUSEBUTTONUP)
            {
                click = false;
            }
            if (event.type == SDL_MOUSEBUTTONDOWN)
            {
                click = true;
            }
            
        }        

        int mouseX, mouseY;
        Uint32 buttons = SDL_GetMouseState(&mouseX, &mouseY);


        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        // drawGrid(tamaño, renderer, window);

        int j = floor(tamaño * mouseX / width);
        int i = floor(tamaño * mouseY / height);
    
        if (click)
        {
            matriz[i][j] = 1;
        }
        
        
        for (int i = 0; i < tamaño; i++)
        {
            
            for (int j = 0; j < tamaño; j++)
            {
                if (matriz[i][j] == 0)
                {
                    SDL_Rect square = {width * j/ tamaño, height * i / tamaño, width / tamaño, height / tamaño};
                    // SDL_RenderDrawRect(renderer, &square);
                }

                else if (matriz[i][j] == 1)
                {
                    SDL_Rect square = {width * j/ tamaño, height * i / tamaño, width / tamaño, height / tamaño};
                    SDL_SetRenderDrawColor(renderer, floor(i*255/tamaño), floor(j*255/tamaño), floor(i*j*255/tamaño / tamaño), 255);
                    SDL_RenderFillRect(renderer, &square);
                    if (i +1 < tamaño && matriz[i+1][j] == 0)
                    {
                        matriz[i][j] = 0;
                        matriz[i+1][j] = 1;
                    }
                    else if (i+ 1 < tamaño && matriz[i+1][j+1] == 0)
                    {
                        matriz[i][j] = 0;
                        matriz[i+1][j+1] = 1;
                    }
                    else if (i+1 < tamaño && matriz[i+1][j-1] == 0)
                    {
                        matriz[i][j] = 0;
                        matriz[i+1][j-1] = 1;
                    }
                    
                    
                }
            }
        }

        // Actualizar la pantalla
        SDL_RenderPresent(renderer);
    }
    
    

    // Destruir la ventana y limpiar SDL
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}