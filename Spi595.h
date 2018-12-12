#pragma once

class SPIClass;

#include "I595.h"

class Spi595 : public I595
{
    SPIClass& spi;
    const uint8_t latchPin;
    const uint8_t outputEnablePin;
    const uint8_t resetPin;

    static const uint32_t spiSpeed = 8000000ul;
    static const uint32_t tResetUs = 1;
    static const uint32_t tLatchUs = 1;

public:
    Spi595(SPIClass& spi, uint8_t latchPin, uint8_t outputEnablePin, uint8_t resetPin);

    void begin();

    void Reset();
    void ShiftOut(uint8_t* values, uint8_t count);
    void Latch();
    void EnableOutputs();
    void DisableOutputs();
};
