#include "buzzer.h"
void setupBuzzer()
{
    pinMode(BUZZER_PIN, OUTPUT);
}
void buzzer_accept()
{
    tone(BUZZER_PIN, 440, 100);
}

void buzzer_error()
{
    tone(BUZZER_PIN, 880, 100);
}