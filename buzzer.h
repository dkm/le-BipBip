#ifndef BUZZER_H_INCLUDED
#define BUZZER_H_INCLUDED

#include <stdbool.h>
#include <stdint.h>

void play( const char *song);
extern const char * stringSink;
extern const char * stringLift;
void BuzzerResetSound();
void BuzzerStart();
void BuzzerSetFrequency(unsigned int freq);    // set pitch freq
void BuzzerSetCyclical(unsigned int cyclical); // set period in ms
//void BuzzerSetCadence();
void BuzzerPlay(unsigned int freq, unsigned int ms);
void BuzzerStartSound();
void BuzzerStopSound();
void BuzzerSetBlocking(unsigned int freq, unsigned int ms);
void BuzzerSetNow(unsigned int freq, unsigned int ms);
void BuzzerSetQueue(unsigned int freq, unsigned int ms);
void BuzzerTask();
void BuzzerStop();
void BuzzerDemoSound();
void BuzzerSetVolume(char button);

void BuzzerDemoSoundTacTacOn();
void BuzzerDemoSoundTacTacOff();


void CheckBuzzerStart(void);
void CheckBuzzer(bool mode);

#endif //BUZZER_H_INCLUDED
