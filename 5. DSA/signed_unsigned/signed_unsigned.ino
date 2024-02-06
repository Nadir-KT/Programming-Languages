
void setup() 
{
  Serial.begin(9600);
}

void loop() {
  signed int x = -1; // -1= 0xffff
  unsigned int a = x;
  Serial.print("value of     x = ");
  Serial.println(x);
  Serial.print("unsigned int x = ");
  Serial.println(a);
  Serial.println();
  unsigned int y = 65535; // 65535= 0xffff
  signed int  b = y;
  Serial.print("value of   y = ");
  Serial.println(y);
  Serial.print("signed int y = ");
  Serial.println(b);
  Serial.println();
  unsigned long int z = 0xffffffff; //4294967295 = 0xffffffff;
  unsigned int c = z;
  Serial.print("value of     z = ");
  Serial.println(z);
  Serial.print("unsigned int z = ");
  Serial.println(c);
  Serial.println();
}
