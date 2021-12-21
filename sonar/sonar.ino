#include <Maqueen.h>
Maqueen bot;

//NewPing.h and Adafruit_Microbit.h are inlcuded the library header
//but still need to be invoked here.
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
Adafruit_Microbit microbit;

void setup() {
  Serial.begin(9600);
  bot.begin();
  microbit.matrix.begin();
  while (bot.readA()) { //wait for BTNA to be pushed
    microbit.matrix.print("A");
  }
  microbit.matrix.clear();
  microbit.matrix.show(smile_bmp);

}

void loop() {
  int us = sonar.ping_in();
  microbit.matrix.print(us);
  Serial.println(us);
  if(us>5) {
    bot.setSpeed(20);
    bot.forward();
  } else {
    bot.stop();
  }
}
