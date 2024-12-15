int sensorValue[5];
byte dataSensor = 0b00000;

void sensorInit() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
}

void setMuxChannel(int channel) {
  digitalWrite(S0, bitRead(channel, 0));
  digitalWrite(S1, bitRead(channel, 1));
  digitalWrite(S2, bitRead(channel, 2));
  digitalWrite(S3, bitRead(channel, 3));
}

void readSensor() {
  Serial.print("|");
  for (int i = 6; i < 11; i++) {
    setMuxChannel(i);
    sensorValue[i - 6] = analogRead(SignalPin);
    Serial.print(String(sensorValue[i - 6]));
    Serial.print("|");
    if (sensorValue[i - 6] < 2000) {
      dataSensor |= (0b10000 >> i - 6);
    }
  }
  Serial.println("");
  Serial.println(dataSensor, BIN);
}