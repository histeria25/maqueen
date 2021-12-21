#include <Maqueen.h>
Maqueen bot;

//NewPing.h and Adafruit_Microbit.h are inlcuded the library header
//but still need to be invoked here.
Adafruit_Microbit microbit;

//on the makeblock line map
//Black Line returns a Zero (0)
//White returns a one (1)

int speed = 10; //this is a percentage from 1 to 100

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

 bot.setSpeed(speed);
  if (bot.readPatrolLeft() == 0 && bot.readPatrolRight() == 0) {
    bot.forward(); 
  }
  if (bot.readPatrolLeft() == 1 && bot.readPatrolRight() == 0) {
    bot.right();
  }
  if (bot.readPatrolRight() == 1 && bot.readPatrolLeft() == 0) {
    bot.left();
  }
  if (bot.readPatrolRight() == 1 && bot.readPatrolLeft() == 1) {
    bot.spinLeft();
  }
}
