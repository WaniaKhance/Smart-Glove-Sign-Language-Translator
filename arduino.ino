#include "Wire.h" // This library allows you to communicate with I2C devices.
const int flexPin0 = A5;
const int flexPin1 = A3;
const int flexPin2 = A2;
const int flexPin3 = A1;
const int flexPin4 = A0;
int value0;
int value1;
int value2;
int value3; 
int value4; 
const int MPU_ADDR = 0x68; // I2C address of the MPU-6050. If AD0 pin is set to HIGH, the I2C address will be 0x69.
int16_t accelerometer_x, accelerometer_y, accelerometer_z; // variables for accelerometer raw data
int16_t gyro_x, gyro_y, gyro_z; // variables for gyro raw data
int16_t temperature; // variables for temperature data
char tmp_str[7]; // temporary variable used in convert function
char* convert_int16_to_str(int16_t i) { // converts int16 to string. Moreover, resulting strings will have the same length in the debug monitor.
  sprintf(tmp_str, "%6d", i);
  return tmp_str;
}
void setup() {
  Serial.begin(9600);
  Wire.begin();
  Wire.beginTransmission(MPU_ADDR); // Begins a transmission to the I2C slave (GY-521 board)
  Wire.write(0x6B); // PWR_MGMT_1 register
  Wire.write(0); // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);
  Serial.println("THUMB,INDEX,MIDDLE,RING,LITTLE,G1,G2,G3");
}
void loop() {
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x3B); // starting with register 0x3B (ACCEL_XOUT_H) [MPU-6000 and MPU-6050 Register Map and Descriptions Revision 4.2, p.40]
  Wire.endTransmission(false); // the parameter indicates that the Arduino will send a restart. As a result, the connection is kept active.
  Wire.requestFrom(MPU_ADDR, 7*2, true); // request a total of 6*2=12 registers
  
  // "Wire.read()<<8 | Wire.read();" means two registers are read and stored in the same variable
  //accelerometer_x = Wire.read()<<8 | Wire.read(); // reading registers: 0x3B (ACCEL_XOUT_H) and 0x3C (ACCEL_XOUT_L)
  //accelerometer_y = Wire.read()<<8 | Wire.read(); // reading registers: 0x3D (ACCEL_YOUT_H) and 0x3E (ACCEL_YOUT_L)
  //accelerometer_z = Wire.read()<<8 | Wire.read(); // reading registers: 0x3F (ACCEL_ZOUT_H) and 0x40 (ACCEL_ZOUT_L)
  gyro_x = Wire.read()<<8 | Wire.read(); // reading registers: 0x43 (GYRO_XOUT_H) and 0x44 (GYRO_XOUT_L)
  gyro_y = Wire.read()<<8 | Wire.read(); // reading registers: 0x45 (GYRO_YOUT_H) and 0x46 (GYRO_YOUT_L)
  gyro_z = Wire.read()<<8 | Wire.read(); // reading registers: 0x47 (GYRO_ZOUT_H) and 0x48 (GYRO_ZOUT_L)
  //Print out data
  value0 = analogRead(flexPin0);  
  value1 = analogRead(flexPin1);
  value2 = analogRead(flexPin2);
  value3 = analogRead(flexPin3);    
  value4 = analogRead(flexPin4);   
  Serial.print(value0);
  Serial.print(","); 
  Serial.print(value1);
  Serial.print(","); 
  Serial.print(value2);
  Serial.print(","); 
  Serial.print(value3);
  Serial.print(",");   
  Serial.print(value4);
  Serial.print(",");
  //  value = map(value, 700, 900, 0, 255);
//  Serial.print(" aX = "); Serial.print(convert_int16_to_str(accelerometer_x));
  //Serial.print(" | aY = "); Serial.print(convert_int16_to_str(accelerometer_y));
  //Serial.print(" | aZ = "); Serial.print(convert_int16_to_str(accelerometer_z));
  // the following equation was taken from the documentation [MPU-6000/MPU-6050 Register Map and Description, p.30]
  Serial.print(convert_int16_to_str(gyro_x));
  Serial.print(",");
  Serial.print(convert_int16_to_str(gyro_y));
  Serial.print(",");
  Serial.print(convert_int16_to_str(gyro_z));
  Serial.println();

  delay(400);
}
 