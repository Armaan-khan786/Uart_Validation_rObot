// Receiver ESP32 - UART2
HardwareSerial MySerial(2); // UART2

int messageCount = 0;
bool started = true; // start receiving automatically

void setup() {
  Serial.begin(115200);                       // PC monitor
  MySerial.begin(115200, SERIAL_8N1, 16, 17); // UART2: RX2=16, TX2=17
  delay(2000);
  Serial.println("RECEIVER READY");
}

void loop() {
  if (started && MySerial.available()) {
    String msg = MySerial.readStringUntil('\n');
    msg.trim();

    if (msg.length() > 0) {
      messageCount++;
      Serial.print("RECEIVED: ");
      Serial.println(msg);

      if (msg == "DONE") {
        Serial.print("TOTAL MESSAGES RECEIVED: ");
        Serial.println(messageCount - 1); // exclude DONE
        Serial.println("WAITING AGAIN...");
        started = false; // stop after first batch
      }
    }
  }
}