#include "Spi595.h"

#include <SPI.h>


Spi595::Spi595(SPIClass& spi, uint8_t latchPin, uint8_t outputEnablePin, uint8_t resetPin) :
    spi(spi),
    latchPin(latchPin),
    outputEnablePin(outputEnablePin),
    resetPin(resetPin)
{
}

void Spi595::begin()
{
    pinMode(latchPin, OUTPUT);
    digitalWrite(latchPin, HIGH);

    pinMode(resetPin, OUTPUT);
    digitalWrite(resetPin, HIGH);

    pinMode(outputEnablePin, OUTPUT);
    digitalWrite(outputEnablePin, HIGH);
}

void Spi595::Reset()
{
    digitalWrite(resetPin, LOW);
    delayMicroseconds(tResetUs);
    digitalWrite(resetPin, HIGH);
}

void Spi595::ShiftOut(uint8_t* values, uint8_t count)
{
    spi.beginTransaction(SPISettings(spiSpeed, MSBFIRST, SPI_MODE0));
    spi.transfer(values, count);
    spi.endTransaction();
}

void Spi595::Latch()
{
    digitalWrite(latchPin, LOW);
    delayMicroseconds(tLatchUs);
    digitalWrite(latchPin, HIGH);
}

void Spi595::EnableOutputs()
{
    digitalWrite(outputEnablePin, LOW);
}

void Spi595::DisableOutputs()
{
    digitalWrite(outputEnablePin, HIGH);
}
