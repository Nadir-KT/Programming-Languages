  write_value=4294967295;

  write_data[0]=write_value%256;
  write_data[1]=(write_value/256)%256;
  write_data[2]=((write_value/256)/256)%256;
  write_data[3]=((write_value/256)/256)/256;

  write_data[0] = write_value;
  write_data[1] = write_value >> 8;
  write_data[2] = write_value >> 16;
  write_data[3] = write_value >> 24;

  write_data[0] = write_value;
  write_data[1] = write_value >> 8;
  write_data[2] = (write_value >> 8) >> 8;
  write_data[3] = ((write_value >> 8) >> 8) >> 8;

  EEPROM.write(address[0], write_data[0]);
  EEPROM.write(address[1], write_data[1]);
  EEPROM.write(address[2], write_data[2]);
  EEPROM.write(address[3], write_data[3]);

  read_data[0] = EEPROM.read(address[0]);
  read_data[1] = EEPROM.read(address[1]);
  read_data[2] = EEPROM.read(address[2]);
  read_data[3] = EEPROM.read(address[3]);
----------------------------------------------------------------------------------------------------
  value3=read_data[3]*256*256*256; //= 4278190080
  value2=read_data[2]*256*256; //= 16711680
  value1=read_data[1]*256; //= 65280
  read_value=value3+value2+value1+read_data[0]; //= 4278190080+16711680+65280+255 = 4294967295

  loop()
  {
  read_value=read_data[3]*256*256*256; // = 4278190080
  read_value=read_value+(read_data[2]*256*256); // = 16711680+4278190080 = 4294901760
  read_value=read_value+(read_data[1]*256); //  = 65280+4294901760 = 4294967040
  read_value=read_value+read_data[0]; // = 255+4294967040 = 4294967295
  }

  read_value = (read_data[3]*256*256*256)+(read_data[2]*256*256)+(read_data[1]*256)+read_data[0];
----------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------
  value3=read_data[3]*256; // = 65280
  value2=read_data[2]*256; // = 16776960
  value1=read_data[1]*256; // = 4294967040
  read_value=read_data[0]+value1+value2+value3; // = 4294967295

  read_value = read_data[0]+((read_data[1]+((read_data[2]+(read_data[3]*256))*256))*256);
--------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------
  value3=read_data[3]<<8 = 65280
  value2=(read_data[2]+value3)<<8 = 16776960
  value1=(read_data[1]+value2)<<8 = 4294967040
  read_value=read_data[0]+value1 = 4294967295

  read_value = read_data[0]+((read_data[1]+((read_data[2]+(read_data[3]<<8))<<8))<<8);
-----------------------------------------------------------------------------------------
---------------------------------------------------------------------------------------
  value3=read_data[3]<<24; // = 4278190080
  value2=read_data[2]<<16; // = 16711680+4278190080 = 4294901760
  value1=read_data[1]<<8; // = 65280+4294901760 = 4294967040 
  read_value=value3+value2+value1+read_data[0]; // = 255+4294967040 = 4294967295

  read_value = (read_data[3]<<24)+(read_data[2]<<16)+(read_data[1]<<8)+read_data[0];
---------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------------------------
  read_value[0] = (read_data[3]*256*256*256)+(read_data[2]*256*256)+(read_data[1]*256)+read_data[0];
  read_value[2] = read_data[0]+((read_data[1]+((read_data[2]+(read_data[3]*256))*256))*256);
  read_value[3] = read_data[0]+((read_data[1]+((read_data[2]+(read_data[3]<<8))<<8))<<8);
  read_value[1] = (read_data[3]<<24)+(read_data[2]<<16)+(read_data[1]<<8)+read_data[0];
------------------------------------------------------------------------------------------