#include <Wire.h>

#define EEPROM_I2C_ADDRESS_0 0x50
#define EEPROM_I2C_ADDRESS_1 0x51

int EEPROM_I2C_ADDRESS = NULL;
int i=1;
void setup()
{
  Wire.begin();
  Serial.begin(9600);
}

// Function to write to EEPROOM
void writeAT24(byte dataAddress, byte dataVal)
{
  Wire.beginTransmission(EEPROM_I2C_ADDRESS);

  Wire.write(dataAddress);
  Wire.write(dataVal);
  Wire.endTransmission();

  delay(5);
}

// Function to read from EEPROM
byte readAT24(byte dataAddress)
{
  byte readData = NULL;
  Wire.beginTransmission(EEPROM_I2C_ADDRESS);
  Wire.write(dataAddress);
  Wire.endTransmission();

  delay(5);
  Wire.requestFrom(EEPROM_I2C_ADDRESS, 1);
  //delay(1);

  if(Wire.available())
  {
    readData =  Wire.read();
  }

  return readData;
}

void loop()
{
	if(i==0)
	{
    EEPROM_I2C_ADDRESS = 0x50;
    writeAT24(0, 33);//void writeAT24(byte dataAddress, byte dataVal)
  }
  else
  {
    EEPROM_I2C_ADDRESS = 0x51;
    writeAT24(1, 34);
  }
	delay(1000);
	Serial.println("Data from EEPROM");
	Serial.println("-----------------");
  if(i==0)
  {
    EEPROM_I2C_ADDRESS = 0x50;
    Serial.println((int)readAT24(i));//byte readAT24(byte dataAddress)
  }
  else
  {
    EEPROM_I2C_ADDRESS = 0x51;
    Serial.println((int)readAT24(1));
  }
  delay(1000);
}