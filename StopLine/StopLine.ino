#include <Maqueen.h>
Maqueen bot;
Adafruit_Microbit microbit;
void setup() {
  bot.begin();
  microbit.matrix.begin();
}
void loop() {
  while (bot.readA()) { //wait for BTNA to be pushed
    microbit.matrix.print("A");
  }
  microbit.matrix.clear();
  delay(500);
  microbit.matrix.show(smile_bmp);
  bot.setSpeed(20);
  while(bot.readPatrolLeft()==0){
    bot.forward();
  }
  bot.stop();
}
