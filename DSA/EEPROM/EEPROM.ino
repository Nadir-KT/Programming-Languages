#include <EEPROM.h>
//int address = 0; // start reading from the first byte (address 0) of the EEPROM
unsigned int address[4] = {0,1,2,3}; /** the current address in the EEPROM (i.e. which byte we're going to write to next) **/
unsigned long int read_value[4] = {0};
unsigned long int read_data[4] = {0}; // 4-Bytes value
unsigned char write_value[4] = {0};
float writeData=99999999.00000000000000000000000000;
unsigned long int write_data = writeData;
double readData;

void setup() { Serial.begin(9600); while (!Serial) { ; } } // initialize serial and wait for serial port to connect. Needed for native USB port only

void loop() {

  //value = EEPROM.read(address); // read a byte from the current address of the EEPROM
  read_value[0] = EEPROM.read(address[0]); // read a byte from the current address of the EEPROM
  read_value[1] = EEPROM.read(address[1]); // read a byte from the current address of the EEPROM
  read_value[2] = EEPROM.read(address[2]); // read a byte from the current address of the EEPROM
  read_value[3] = EEPROM.read(address[3]); // read a byte from the current address of the EEPROM
  read_data[0] = (read_value[3]*256*256*256)+(read_value[2]*256*256)+(read_value[1]*256)+read_value[0]; // Need to combine the bytes for retrieving the original value.
  read_data[1] = (read_value[3]<<24)+(read_value[2]<<16)+(read_value[1]<<8)+read_value[0];
  read_data[2] = read_value[0]+((read_value[1]+((read_value[2]+(read_value[3]*256))*256))*256);
  read_data[3] = read_value[0]+((read_value[1]+((read_value[2]+(read_value[3]<<8))<<8))<<8);

  readData=read_data[0];

  Serial.print("byte=");
  Serial.print(address[0]);
  Serial.print("/value=");
  Serial.print(read_value[0]);
  //Serial.print("\t");
  Serial.print(" byte=");
  Serial.print(address[1]);
  Serial.print("/value=");
  Serial.print(read_value[1]);
  //Serial.print("\t");
  Serial.print(" byte=");
  Serial.print(address[2]);
  Serial.print("/value=");
  Serial.print(read_value[2]);
  //Serial.print("\t");
  Serial.print(" byte=");
  Serial.print(address[3]);
  Serial.print("/value=");
  Serial.print(read_value[3]);
  Serial.print("\t");
  Serial.print("read_data=");
  Serial.print(read_data[0]);
  Serial.print("\t");
  Serial.print("read_data=");
  Serial.print(read_data[1]);
  Serial.print("\t");
  Serial.print("read_data=");
  Serial.print(read_data[2]);
  Serial.print("\t");
  Serial.print("read_data=");
  Serial.print(read_data[3]);
  Serial.print("\t");
  Serial.print("float=");
  Serial.print(readData);
  Serial.println();

  //unsigned long int write_data = 4294967295; // Need to split to bytes because input range from 0 to 4294967295 and each byte of the EEPROM can only hold a value from 0 to 255.
  if (writeData>readData)
  //for (write_data=4294967295; write_data<=4294967295; write_data++)
  {
//  write_value[0]=write_data%256;
//  write_value[1]=(write_data/256)%256;
//  write_value[2]=((write_data/256)/256)%256;
//  write_value[3]=((write_data/256)/256)/256;

  write_value[0] = write_data;
  write_value[1] = write_data >> 8;
  write_value[2] = write_data >> 16;
  write_value[3] = write_data >> 24;

//  write_value[0] = write_data;
//  write_value[1] = write_data >> 8;
//  write_value[2] = (write_data >> 8) >> 8;
//  write_value[3] = ((write_data >> 8) >> 8) >> 8;
  
  //EEPROM.write(address, value); // Write the value to the appropriate byte of the EEPROM. these values will remain there when the board is turned off.
  EEPROM.write(address[0], write_value[0]); // Write the value to the appropriate byte of the EEPROM. these values will remain there when the board is turned off.
  EEPROM.write(address[1], write_value[1]); // Write the value to the appropriate byte of the EEPROM. these values will remain there when the board is turned off.
  EEPROM.write(address[2], write_value[2]); // Write the value to the appropriate byte of the EEPROM. these values will remain there when the board is turned off.
  EEPROM.write(address[3], write_value[3]); // Write the value to the appropriate byte of the EEPROM. these values will remain there when the board is turned off.

  //address = address + 1; // Advance to the next address
  //if (address == 3) {address = 0;} // when at the end restart at the beginning.
  //label1:
  //if (write_data == 4294967295) // Stop value at 4294967295
  //goto label1;
  }
 }
