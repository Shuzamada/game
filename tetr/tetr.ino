#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Max72xxPanel.h>

#include <My2x2Mat.hpp>
#include <Field.hpp>

Max72xxPanel matrix = getMatrix();
Field f;

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
}

void move()
{
   int d = Serial.parseInt();
}

unsigned long last = millis();
void loop()
{
  if (Serial.available())
  {
    int x = Serial.parseInt();
    int y = Serial.parseInt();
    Serial.println(x);
    Serial.println(y);
    f.draw(x, y, 1);
  }
  if (millis() - last > 500)
  {
    last = millis();
    drawField(f);
    f.fall();
  }
  drawField(f);
}
