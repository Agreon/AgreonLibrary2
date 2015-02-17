/* 
 * File:   main.cpp
 * Author: daniel
 *
 * Created on February 2, 2015, 3:13 PM
 */

#include <iostream>
#include <memory>
#include "AL.h"
#include "Animation.h"

int main(int argc, char** argv)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Event event;
    bool running = true;
    
    AL::Graphics *graphics = new AL::Graphics();
    AL::AnimationManager *animManager = new AL::AnimationManager(graphics);
    AL::Input *input = new AL::Input();
    AL::Sound *sound = new AL::Sound();
        
    graphics->init(800,600,"Agreon Library 2",NULL);
        
    if(!graphics->loadTexture("data/agreon_logo.png","agreon_logo")
    || !graphics->loadTexture("data/player_right_anim.png","player_anim")
    || !graphics->loadFont("data/roboto.ttf","roboto"))
    {
        running = false;
    }
    graphics->setFont("roboto", 50, AL::color(1,1,1,0.2));
    
    animManager->createAnimation("player_anim","player_anim",-1,10,0,200,200,64,64);
    //animManager->
    
    if(!sound->loadSound("data/wolf_howl.wav","wolf_howl"))
    {
        running = false;
    }
    
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
                 
        animManager->updateAll();
        
        glClear(GL_COLOR_BUFFER_BIT);
        graphics->setColor(AL::color(1,1,1,1));

        graphics->drawTexture("agreon_logo",0,0);      
        graphics->drawText("Agreon Library 2.0",200,500);
        graphics->setColor(AL::color(0.5,1,1,1));
        animManager->showAll();
        
        graphics->swapWindow();
    }
    
    SDL_Quit();
    return 0;
}
