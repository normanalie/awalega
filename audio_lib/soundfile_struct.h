#ifndef SOUNDFILESTRUCTH
#define SOUNDFILESTRUCTH

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <stdio.h>
#include <stdlib.h> 

typedef struct
{
    Mix_Music* music;
    int ID;
}music_comp;

typedef struct
{
    music_comp music1;
    music_comp music2;
    music_comp menuMusic;
    music_comp inGameMusic;
    music_comp leaderboardMusic;
    music_comp aboutMusic;
}music;


typedef struct //sound components
{
    Mix_Chunk* sound;
    int numChannel;
}sound_comp;


typedef struct 
{
    sound_comp mouseClick;
    sound_comp victory;
    sound_comp defeat;
    sound_comp loading;
    sound_comp beanDeposit;
    sound_comp buzzWrongAction;
    sound_comp typing;
}sound;

typedef struct 
{
    music musicSection;
    sound soundSection;
}audio;
//audio Audio;




 #endif 