#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

int16_t ax, ay, az;
int16_t gx, gy, gz;

float AccX, AccY, AccZ;
float GyroX, GyroY, GyroZ;

float AccXangle, AccYangle;
float GyroXangle, GyroYangle, GyroZangle;
float TotalXangle, TotalYangle;

float alpha = 0.96; 

void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu.initialize();
  mpu.CalibrateGyro(1);
}
uint32_t timer = millis();
void loop() {
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  AccX = (float)ax / 16384.0;
  AccY = (float)ay / 16384.0;
  AccZ = (float)az / 16384.0;

  GyroX = (float)gx / 131.0;
  GyroY = (float)gy / 131.0;
  GyroZ = (float)gz / 131.0;

  AccXangle = atan(AccY / sqrt(AccX * AccX + AccZ * AccZ)) * 57.2957795;
  AccYangle = atan(-1 * AccX / sqrt(AccY * AccY + AccZ * AccZ)) * 57.2957795;

  GyroXangle += GyroX * (float)(millis() - timer) / 1000;
  GyroYangle += GyroY * (float)(millis() - timer) / 1000;
  GyroZangle += GyroZ * (float)(millis() - timer) / 1000;

  TotalXangle = alpha * GyroXangle + (1 - alpha) * AccXangle;
  TotalYangle = alpha * GyroYangle + (1 - alpha) * AccYangle;

  Serial.print("X-Angle: ");
  Serial.println(TotalXangle + 180);
  timer = millis();
  delay(100);
}
