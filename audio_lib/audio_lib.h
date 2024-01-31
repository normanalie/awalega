#ifndef AUDIOLIBH
#define AUDIOLIBH

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <stdio.h>
#include <string.h>

#include "soundfile_struct.h"

#define ERROR -1
#define REP_INF -1
#define REP_ONCE 0
#define AUDIO_INCREMENT 8
#define HALF_MAX_VOLUME MIX_MAX_VOLUME / 2
#define DEFAULT_VOLUME HALF_MAX_VOLUME - AUDIO_INCREMENT
#define NUM_CHANNELS 7
#define MUSIC_STRUCT Audio.musicSection
#define SOUND_STRUCT Audio.soundSection
#define PMUSIC_STRUCT Audio->musicSection
#define PSOUND_STRUCT Audio->soundSection
#define MENU_MUSIC MUSIC_STRUCT.menuMusic
#define ABOUT_MUSIC MUSIC_STRUCT.aboutMusic
#define INGAME_MUSIC MUSIC_STRUCT.inGameMusic
#define LEADERBOARD_MUSIC MUSIC_STRUCT.leaderboardMusic

int openAudio();                                                // open the SDL_mixer audio track
int openSoundChannels(int num_channels);                        // allocate channels to enable sounds adding to the game
Mix_Chunk *loadSound(const char path[]);                        // get the sounds from the files
Mix_Music *loadMusic(const char path[]);                        // get the music from the files
void loadAllMusics(audio *Audio);                               // initialize all the musics based on the structure soundfile_struct.h
void loadAllSounds(audio *Audio);                               // initialize all the sounds based on the structure soundfile_struct.h
int playAudio(Mix_Music *music, int loop);                      // start the music when called
int playSound(int num_channel, Mix_Chunk *chunk, int num_reps); // launch a sound when called
void pauseAudio();                                              // stop the music and resume if already paused
void rewindAudio();                                             // restart the music from the beginning
void playAudioAgain(Mix_Music *music, int loop);                // restart the music from the beginning after stopping it for 4 seconds
void soundVolumeUpdate(int num_channel, int volume);            // update the sound section volume based on the level of the music sound
void actualAudioVolume(int volume);                             // re-actualise the volume
void audioVolumeUpdate(int *volume, int value);                 // increase the volume(pause the music if volume = 0)
void audioVolumeMuteUnmute(int *volume, int value);             // turn off the volume (recursive)
void freeMusic(Mix_Music *music);                               // desallocate the music in argument
void freeSound(Mix_Chunk *chunk);                               // desallocate the sound in argument
void freeAllMusics(audio *Audio);                               // desallocate all musics
void freeAllSounds(audio *Audio);                               // desallocate all sounds
void closeAudio();                                              // close the SDL_mixer audio track

// NEW VERSION
typedef enum SOUND_EFFECTS
{
    MOUSECLICK,
    VICTORY,
    DEFEAT,
    LOADING,
    BEANDEPOSIT,
    BUZZWRONGACTION,
    TYPING
} SOUND_EFFECTS;

void initAudio();
void soundPlayEffect(SOUND_EFFECTS name);

#endif
