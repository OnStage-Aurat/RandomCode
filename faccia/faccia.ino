#include <Servo.h>

void pos();
void pos1();
void forser(Servo* mover, int arrivo);

#define OX1 occhioX1
#define OY1 occhioY1

#define OX2 occhioX2
#define OY2 occhioY2

Servo occhioX1;
Servo occhioY1;

Servo occhioX2;
Servo occhioY2;

void setup()
{
  Serial.begin(38400);
  Serial.println("Codice Caricato Giorno 15/06 Versione Finita 4 Servo Occhio");
  pinMode(LED_BUILTIN, OUTPUT);
  occhioX1.attach(9); // Quello sotto
  occhioY1.attach(10); // Quello dietro
  occhioX2.attach(11); // Quello sotto
  occhioY2.attach(12); // Quello dietro
  pos1();
  delay(3000);
  pos();
}

void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    char inputchar[input.length() + 1];
    input.toCharArray(inputchar, sizeof(inputchar));
    int values[4], i = 0;
    char *value = strtok(inputchar, ";");
    while (value != NULL && i < 4) {
      values[i] = atoi(value);
      value = strtok(NULL, ";");
      i++;
    }
    if ( i == 4) {
      Serial.println(values[0]); Serial.println(values[1]); Serial.println(values[2]); Serial.println(values[3]);
      if ( values[0] < 160 && values[0] > 20)     forser(&OX1, values[0]);
      if ( values[1] <= 160 && values[1] >= 20)   forser(&OY1, values[1]);
      if ( values[2] <= 160 && values[2] >= 20)   forser(&OX2, values[2]);
      if ( values[3] <= 160 && values[3] >= 20)   forser(&OY2, values[3]);
    }
  }
}
void forser(Servo* mover, int arrivo) {
  int posAttuale = mover->read();
  if (arrivo == posAttuale) {
    return;
  }
  else if (arrivo < posAttuale) {
    for (int pos = posAttuale; pos > arrivo; pos -= 3) {
      mover->write(pos);
      delay(10);
    }
  }
  else {
    for (int pos = posAttuale; pos < arrivo; pos += 3) {
      mover->write(pos);
      delay(10);
    }
  }
  mover->write(arrivo);
}
void pos() {
  OX1.write(90);
  OY1.write(90);
  OX2.write(90);
  OY2.write(90);
}
void pos1() {
  OX1.write(0);
  OY1.write(0);
  OX2.write(0);
  OY2.write(0);
}
