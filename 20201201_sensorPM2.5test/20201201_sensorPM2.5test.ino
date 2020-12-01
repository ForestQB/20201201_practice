int data, i=0, sum;
int pmdata[7];

void setup() {
  // put your setup code here, to run once:
Serial.begin(2400);
}

void loop() {
  // put your main code here, to run repeatedly:
while (Serial.available() > 0)
  {
    data = Serial.read();
    Serial.println(data, HEX);
  }
}
