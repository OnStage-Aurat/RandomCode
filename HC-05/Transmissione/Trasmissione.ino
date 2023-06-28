/*
 * RICORDARE
 * - Impostare "Entrmabi NL & CR"
 * - Velocità Seriale (38400 baud)
 * - (Ardunino) RX to TX (HC-05)
 * - (Ardunino) TX to RX (HC-05)
 */

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  Serial.println("Codice 28.06 Ricordare le seguenti cose:\n- Impostare \"Entrmabi NL & CR\"\n- Velocità Seriale (38400 baud)\n- (Ardunino) RX to TX (HC-05)\n- (Ardunino) TX to RX (HC-05)");
}
void loop() {
  if(Serial1.available()){
    Serial.print((char)Serial1.read());
  }
  if (Serial.available()) {
    Serial1.print((char)Serial.read());
  }
}
