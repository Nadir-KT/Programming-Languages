
void setup() 
{
  Serial.begin(9600);
}

void loop() {
  unsigned int k = 0;
  signed int  c = k - 273.15;
  unsigned int a = c;
  unsigned int b = 65536 - a;
  Serial.println(b);
}
