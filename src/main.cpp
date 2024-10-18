#include <encoderRead.h>

EncoderRead Encoder(27, 22, 26);  // GPIO pinA,pinB,Button

void setup() {
  Serial.begin(115200);
  Encoder.begin();
}

void loop() {
  static int lastCounter = 0;
  int counter = Encoder.getCounter(); 

  if(counter != lastCounter){
    Serial.println(counter);
    lastCounter = counter;
  }

  if(Encoder.encBtn()) {
    Serial.println("Button Pressed!");
  }
}
