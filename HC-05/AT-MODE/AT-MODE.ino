/*
 * AT MODE per la configurazione del HC-05
 * 
 * RICORDARE
 * - Impostare "Entrmabi NL & CR"
 * - Velocità Seriale (38400 baud)
 * - (Ardunino) RX to TX (HC-05)
 * - (Ardunino) TX to RX (HC-05)
 */

void setup() {
  Serial.begin(38400);
  Serial1.begin(38400);
}
void loop() {
  if(Serial1.available()){
    Serial1.write(Serial1.read());
  }
  if (Serial.available()) {
    Serial1.print(Serial.read());
  }
}
