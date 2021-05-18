#include <Arduino.h>
#include "Wire.h"

#ifndef MMC5883_h
#define MMC5883_h

#define MMC_ADDRESS 0x30 // I2C address of MMC5883MC

#define COMPASS_CONFIG_REGISTER 0x08
#define COMPASS_THRESHOLD_REGISTER 0x0B
#define COMPASS_STATUS_REGISTER 0x07
#define COMPASS_DATA_REGISTER 0x00
#define Product_ID 0x2F

class MMC5883MA
{
public:
    MMC5883MA(TwoWire &w);

    void begin();
    void calibrate();
    String readData();
    void update();
    float getX();
    float getY();
    float getZ();
    float getAngel();

    byte ID = 0;
    int reg = 0;
    long xMax = 0;
    long xMin = 0;
    long yMax = 0;
    long yMin = 0;
    long zMax = 0;
    long zMin = 0;

    unsigned short xLSB;
    unsigned short xMSB;
    unsigned short yLSB;
    unsigned short yMSB;
    unsigned short zLSB;
    unsigned short zMSB;

    float x;
    float y;
    float z;
    float angle;

    long sx;
    long sy;
    long sz;

private:
    TwoWire *wire;
    uint8_t i2c_address;
};
#endif