
#include <Wire.h>

#define address_read 0x30
#define address_write 0x30

void setup()
{
  Wire.begin();
  Serial.begin(9600);
  Wire.beginTransmission(address_read);
  Serial.println(Wire.endTransmission());
  ReadAll();

  Wire.beginTransmission(address_write);
  Wire.write(8);
  Wire.write(0x1D);
  Wire.endTransmission();

  ReadAll();
  Wire.beginTransmission(address_write);
  Wire.write(0x09);
  Wire.write(0x01);
  Wire.endTransmission();
  ReadAll();

  Serial.println("Start");
}

void ReadAll() {
  Wire.beginTransmission(address_write);
  Wire.write(0x00);
  Serial.print(Wire.endTransmission());
  Serial.print("\t");
  delay(300);
  Wire.requestFrom(address_read, 14);
  for (int i = 0; i < 15; i++) {
    Serial.print(Wire.read());
    Serial.print("\t");
  }
  Serial.print(Wire.read());
  Serial.println("\t");
}

void Read() {
  Wire.beginTransmission(address_write);
  Wire.write(0x01);
  Serial.print(Wire.endTransmission());
  Serial.print("\t");
  delay(300);

  Serial.print(" Data\t");
  Wire.requestFrom(address_read, 6);
  Serial.print(Wire.read() << 8 | Wire.read());
  Serial.print("\t");
  Serial.print(Wire.read() << 8 | Wire.read());
  Serial.print("\t");
  Serial.print(Wire.read() << 8 | Wire.read());
  Serial.println("\t");
  delay(200);
}

void loop()
{
  Wire.beginTransmission(address_write);
  Wire.write(0x0A);
  Wire.write(0x01);
  Wire.endTransmission();
  delay(600);
  Read();
}
