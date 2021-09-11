#pragma once

#include <SDL2/SDL.h>
#include "Logging.h"

struct AudioData
{
    Uint8* pos;
    Uint32 len;
};

struct Sound
{
    SDL_AudioDeviceID audio_device;
    SDL_AudioSpec wav_spec;
    Uint8* wav_start;
    Uint32 wav_length;
    AudioData audio;

    Sound(const char* path);

    void play();
    void pause();

    ~Sound();
};
