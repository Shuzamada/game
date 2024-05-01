 #include <SPI.h>
#include <Adafruit_GFX.h>
#include <Max72xxPanel.h>

#include <My2x2Mat.hpp>
#include <Field.hpp>

Max72xxPanel matrix = getMatrix();
Field f;

bool but_flag = false;
bool but = false;

void setup()
{
  Serial.begin(9600);
  matrix.setIntensity(1);
  clear();
  f.draw(4, 4, 1);
  f.draw(5, 4, 1);
  f.draw(6, 4, 1);
  f.draw(6, 5, 1);
  drawField(f);
  pinMode(A5, INPUT_PULLUP);
}

void checkBut()
{
   but = !digitalRead(A5);

   if (but == 1 && but_flag == 0)
   {
    but_flag = 1;
    f.draw(4, 4, 1);
   }
   if (but == 0 && but_flag == 1)
   {
    but_flag = 0;
   }
}

unsigned long last = millis();
void loop()
{
  checkBut();
  if (millis() - last > 100)
  {
    last = millis();
    f.fall(180.0);
    drawField(f);
  }
  drawField(f);
}
