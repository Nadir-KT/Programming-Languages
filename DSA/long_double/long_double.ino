void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long int read_odo= 999999967; // max = 4294967295 , 
  Serial.print("read_odo =");
  Serial.println(read_odo);
  float ODO_float;
  if ((read_odo > ODO_float) && (read_odo <= 999999967)) // max = 999999967 = 999999936 for 6 digits
  {
  ODO_float = read_odo; // max = 999999936.00
  }
  else{}
  Serial.print("ODO_float =");
  Serial.println(ODO_float);
  unsigned long int odo = ODO_float/1000; //  // max = 100000
  Serial.print("odo =");
  Serial.println(odo);
  unsigned long int write_odo = ODO_float; // max = 100000000
  Serial.print("write_odo =");
  Serial.println(write_odo);
}
