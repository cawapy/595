#pragma once

#include <inttypes.h>

class I595
{
public:
    virtual void Reset() = 0;
    virtual void ShiftOut(uint8_t* values, uint8_t count) = 0;
    virtual void Latch() = 0;
    virtual void EnableOutputs() = 0;
    virtual void DisableOutputs() = 0;
};
