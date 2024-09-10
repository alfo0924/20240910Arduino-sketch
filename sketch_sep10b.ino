void setup() {
  // put your setup code here, to run once:
 pinMode(LED_BUILTIN,OUTPUT);
 Serial.begin(9600); 
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(LED_BUILTIN,HIGH);
delay(2000);
digitalWrite(LED_BUILTIN,LOW);
delay(5000);
Serial.println("hello from NodeMCU-32s");
Serial.print("Hello world from NodeMCU-32s controll pad ");
Serial.println("initialing Multiplication table");

for (int i=1;i<=9;i++)
{
  for(int i2=1;i2<=9;i2++)
  {
    String val = String(i) + "*" + String(i2) + "=" + (i*i2) + "\t";
    Serial.print(val);
  }
  Serial.println();
}

}
