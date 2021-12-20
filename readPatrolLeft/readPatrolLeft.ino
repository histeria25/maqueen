#include <Maqueen.h>
Maqueen bot;
Adafruit_Microbit microbit;
void setup() {
  bot.begin();
  microbit.matrix.begin();
}
void loop() {
  microbit.matrix.print(bot.readA());
}
