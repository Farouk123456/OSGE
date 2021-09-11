#include "Sound.h"

void Audiocallback(void* userdata, Uint8* stream, int streamlength)
{
    AudioData* audio = (AudioData*)userdata;

    if (audio->len == 0)
    {
        return;
    }
    Uint32 length = (Uint32)streamlength;
    length = (length > audio -> len ? audio -> len : length);
    
    SDL_memcpy(stream, audio->pos, length);

    audio -> pos += length;
    audio -> len -= length;
}

Sound::Sound(const char* path)
{
    SDL_Init(SDL_INIT_AUDIO);

    if (SDL_LoadWAV(path, &wav_spec, &wav_start, &wav_length) == NULL)
    {
        error("SDL: FILE NOT LOADED SUCCESSFULLY");
    }
    
    audio.pos = wav_start;
    audio.len = wav_length;

    wav_spec.callback = Audiocallback;
    wav_spec.userdata = &audio;

    audio_device = SDL_OpenAudioDevice(NULL, 0, &wav_spec, NULL, SDL_AUDIO_ALLOW_ANY_CHANGE);

    if(!audio_device)
    {
        error(SDL_GetError());
    }

}

void Sound::play()
{
    SDL_PauseAudioDevice(audio_device, 0);
}

void Sound::pause()
{
    SDL_PauseAudioDevice(audio_device, 1);
}

Sound::~Sound()
{
    SDL_CloseAudioDevice(audio_device);
    SDL_FreeWAV(wav_start);
    SDL_Quit();
}
