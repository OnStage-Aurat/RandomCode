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
  Serial1.println("Enter AT commands:");
  Serial1.begin(38400);
}
void loop() {
  if (Serial1.available()) {
    char c = Serial1.read();
    Serial.print(c);
  }
  if (Serial.available()) {
    char c = Serial.read();
    Serial1.print(c);
  }
}
