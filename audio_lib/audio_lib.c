#include "audio_lib.h"

int openAudio()
{
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 8192) != 0) // problem with the output of the sound (jittering and cuts) -> change in the parameters ?
    {
        printf("Erreur lors de l'initialisation de la SDL_Mixer.\n");
        return ERROR;
    }
    return 0;
}

int openSoundChannels(int num_channels)
{
    if (Mix_AllocateChannels(num_channels) != num_channels)
    {
        printf("Erreur lors de l'allocation des canaux requis.\n");
        return ERROR;
    }
    return 0;
}

Mix_Chunk *loadSound(const char path[])
{
    Mix_Chunk *chunk_temp = NULL;
    chunk_temp = Mix_LoadWAV(path);
    if (chunk_temp == NULL)
    {
        printf("Erreur lors de l'importation du son.\n");
        return NULL;
    }
    return chunk_temp;
}

Mix_Music *loadMusic(const char path[])
{
    Mix_Music *music_temp = NULL;
    music_temp = Mix_LoadMUS(path);
    if (music_temp == NULL)
    {
        printf("Erreur lors de l'importation de la musique.\n");
        return NULL;
    }
    return music_temp;
}

void loadAllMusics(audio *Audio)
{

    PMUSIC_STRUCT.menuMusic.music = NULL;
    PMUSIC_STRUCT.menuMusic.ID = 0;
    PMUSIC_STRUCT.menuMusic.music = loadMusic("./audio_lib/audio/menuMusic.mp3");
    PMUSIC_STRUCT.inGameMusic.music = NULL;
    PMUSIC_STRUCT.inGameMusic.ID = 1;
    PMUSIC_STRUCT.inGameMusic.music = loadMusic("./audio_lib/audio/inGameMusic.mp3");
    PMUSIC_STRUCT.leaderboardMusic.music = NULL;
    PMUSIC_STRUCT.leaderboardMusic.ID = 2;
    PMUSIC_STRUCT.leaderboardMusic.music = loadMusic("./audio_lib/audio/leaderboardMusic.mp3");
    PMUSIC_STRUCT.aboutMusic.music = NULL;
    PMUSIC_STRUCT.aboutMusic.ID = 3;
    PMUSIC_STRUCT.aboutMusic.music = loadMusic("./audio_lib/audio/aboutMusic.mp3");
}

void loadAllSounds(audio *Audio)
{
    PSOUND_STRUCT.mouseClick.sound = NULL;
    PSOUND_STRUCT.mouseClick.numChannel = 0;
    PSOUND_STRUCT.mouseClick.sound = loadSound("./audio_lib/audio/mouseClick.wav");
    PSOUND_STRUCT.victory.sound = NULL;
    PSOUND_STRUCT.victory.numChannel = 1;
    PSOUND_STRUCT.victory.sound = loadSound("./audio_lib/audio/successTrumpets.wav");
    PSOUND_STRUCT.defeat.sound = NULL;
    PSOUND_STRUCT.defeat.numChannel = 2;
    PSOUND_STRUCT.defeat.sound = loadSound("./audio_lib/audio/loss.wav");
    PSOUND_STRUCT.loading.sound = NULL;
    PSOUND_STRUCT.loading.numChannel = 3;
    PSOUND_STRUCT.loading.sound = loadSound("./audio_lib/audio/collect.wav");
    PSOUND_STRUCT.beanDeposit.sound = NULL;
    PSOUND_STRUCT.beanDeposit.numChannel = 4;
    PSOUND_STRUCT.beanDeposit.sound = loadSound("./audio_lib/audio/dice.wav");
    PSOUND_STRUCT.buzzWrongAction.sound = NULL;
    PSOUND_STRUCT.buzzWrongAction.numChannel = 5;
    PSOUND_STRUCT.buzzWrongAction.sound = loadSound("./audio_lib/audio/buzzWrongCase.wav");
    PSOUND_STRUCT.typing.sound = NULL;
    PSOUND_STRUCT.typing.numChannel = 6;
    PSOUND_STRUCT.typing.sound = loadSound("./audio_lib/audio/keyboardSound.wav");
}

int playAudio(Mix_Music *music, int loop)
{
    if (Mix_PlayMusic(music, loop) != 0)
    {
        printf("Erreur lors du lancement de la musique. \n");
        return ERROR;
    }
    return 0;
}

int playSound(int num_channel, Mix_Chunk *chunk, int num_reps)
{
    if (Mix_PlayChannel(num_channel, chunk, num_reps) != num_channel)
    {
        printf("Impossible d'effectuer le lancement du son.\n");
        return ERROR;
    }
    return 0;
}

void pauseAudio()
{
    if (Mix_PausedMusic() == 1)
    {
        // printf("Music resumed. \n");
        Mix_ResumeMusic();
    }
    else
    {
        // printf("Music paused.\n");
        Mix_PauseMusic();
    }
}

void rewindAudio()
{
    // printf("Audio restarted.\n");
    Mix_RewindMusic();
}

void playAudioAgain(Mix_Music *music, int loop)
{
    Mix_HaltMusic();
    // printf("Music stopped. Will replay in 4 seconds.\n");
    SDL_Delay(4000);
    playAudio(music, loop);
}

void playSoundAgain(Mix_Chunk *chunk, int num_channel, int num_reps)
{
    Mix_HaltChannel(num_channel);
    SDL_Delay(2000);
    playSound(num_channel, chunk, num_reps);
}

void soundVolumeUpdate(int num_channel, int volume)
{

    int val = volume * (0.75);
    Mix_Volume(num_channel, val);
    if (num_channel > 0)
    {
        // printf("Sound volume on channel %d has been updated to %d.\n", num_channel, val);
        soundVolumeUpdate(num_channel - 1, volume);
    }
    else
    {
        return;
    }
}

void actualAudioVolume(int volume)
{
    Mix_VolumeMusic(volume);
    // printf("Volume has been actualised.\n");
}

void audioVolumeUpdate(int *volume, int value)
{
    if (*volume == 0 && value == -AUDIO_INCREMENT)
    {
        if (Mix_PausedMusic() == 0)
            pauseAudio();
        return;
        // printf("Volume cannot be decreased.\n");
    }
    else if (*volume == HALF_MAX_VOLUME && value == AUDIO_INCREMENT)
    {
        return;
        // printf("Volume cannot be increased.\n");
    }
    else
    {
        if (*volume == 0)
        {
            pauseAudio();
        }
        *volume += value;
        // printf("Volume has been updated to %d.\n", *volume);
        actualAudioVolume(*volume);
        soundVolumeUpdate(NUM_CHANNELS, *volume);
    }
}

void audioVolumeMuteUnmute(int *volume, int value)
{
    if ((*volume == 0 && value == -AUDIO_INCREMENT) || (*volume == HALF_MAX_VOLUME && value == AUDIO_INCREMENT))
    {
        audioVolumeUpdate(volume, value);
        return;
    }
    else
    {
        SDL_Delay(300);
        audioVolumeUpdate(volume, value);
        audioVolumeMuteUnmute(volume, value);
    }
    // printf("Audio track has been muted.\n");
}

void freeMusic(Mix_Music *music)
{
    Mix_FreeMusic(music);
}

void freeSound(Mix_Chunk *chunk)
{
    Mix_FreeChunk(chunk);
}

void freeAllMusics(audio *Audio)
{
    freeMusic(Audio->musicSection.menuMusic.music);
    freeMusic(Audio->musicSection.inGameMusic.music);
    freeMusic(Audio->musicSection.leaderboardMusic.music);
    freeMusic(Audio->musicSection.aboutMusic.music);
}

void freeAllSounds(audio *Audio)
{
    freeSound(Audio->soundSection.mouseClick.sound);
    freeSound(Audio->soundSection.victory.sound);
    freeSound(Audio->soundSection.defeat.sound);
    freeSound(Audio->soundSection.loading.sound);
    freeSound(Audio->soundSection.beanDeposit.sound);
    freeSound(Audio->soundSection.buzzWrongAction.sound);
}

void closeAudio()
{
    Mix_CloseAudio();
}