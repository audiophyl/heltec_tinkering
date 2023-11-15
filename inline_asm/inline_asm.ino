void setup() {
  Serial.begin(115200);
}

void loop() {
  Serial.println("Attempting inline assembly...");

  asm volatile (
    "NOP \n\t"
  );

  delay(5000);
}
