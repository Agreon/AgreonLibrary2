/* 
 * File:   main.cpp
 * Author: daniel
 *
 * Created on February 2, 2015, 3:13 PM
 */

#include <iostream>
#include <memory>
#include "AL.h"
#include "Input.h"
#include "Sound.h"

int main(int argc, char** argv)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Event event;
    bool running = true;
    
    std::auto_ptr<AL::Graphics> g(new AL::Graphics);
    std::auto_ptr<AL::Input> input(new AL::Input);
    std::auto_ptr<AL::Sound> sound(new AL::Sound);
    
    g->init(800,600,"Agreon Library 2",NULL);
        
    if(!g->loadTexture("data/agreon_logo.png","agreon_logo"))
    {
        running = false;
    }
    
    AL::Graphics *g2 = new AL::Graphics();
        
    if(!sound->loadSound("data/wolf_howl.wav","wolf_howl"));
    
    sound->playSound("wolf_howl");
    sound->setVolume(10);
    
    while(running)
    {
        input->handleInput();
        
        if(input->appClosed()) running = false;
        
        if(input->isKeyReleased(SDLK_ESCAPE))
        {
            running = false;
        }
        
        if(input->isKeyReleased(SDLK_LEFT)) running = false;
                 
        glClear(GL_COLOR_BUFFER_BIT);
                        
        g->drawTexture("agreon_logo",0,0);      
        
        g->swapWindow();
    }
    
    SDL_Quit();
    return 0;
}
