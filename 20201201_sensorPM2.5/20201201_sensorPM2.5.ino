int data, i=0, sum;
int pmdata[7];

void setup() {
  Serial.begin(2400);
}

void loop() {
  while (Serial.available() > 0)
  {
    data = Serial.read();
    if (data == 170)
    {
      i = 0;
      pmdata[i] = data;
    }
    else
    {
      i++;
      pmdata[i] = data;
    }
    if (i == 6)
    {
      sum = pmdata[1] + pmdata[2] + pmdata[3] + pmdata[4];
      if (pmdata[5] == sum && pmdata[6]==255)
      {
        for (int z = 0; z < 7; z++)
        {
          Serial.print(pmdata[z]);
          Serial.print("|");
        }
        Serial.print("V=");
        float vo = (pmdata[1] * 256.0 + pmdata[2] / 1024.0 * 5.00);
        Serial.print(vo, 3);
        Serial.print("v|");
        float Pm = vo * 700;
        Serial.print("PM2.5 ");
        Serial.print(Pm, 2);
        Serial.print("ug/m3 ");
        Serial.println();
      }
      else
      {
        i = 0;
        Serial.flush();
        data = '/0';
        for (int x; x < 7; x++)
        {
          pmdata[x] = 0;
        }
      }
      i=0;
    }
  }
}
