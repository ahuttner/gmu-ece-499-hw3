/* Homework 3 Part 2
 
Makes one xl-320 servo move from 45 deg to 90 deg with a period
of 2 seconds and a second xl-320 servo move from 0 deg to 180 deg
with a period of 1 second.
 
 */
 /* Serial device defines for dxl bus */
#define DXL_BUS_SERIAL1 1  //Dynamixel on Serial1(USART1)  <-OpenCM9.04
#define DXL_BUS_SERIAL2 2  //Dynamixel on Serial2(USART2)  <-LN101,BT210
#define DXL_BUS_SERIAL3 3  //Dynamixel on Serial3(USART3)  <-OpenCM 485EXP
/* Dynamixel ID defines */
#define J_ID_1 1
#define J_ID_2 2
 
Dynamixel Dxl(DXL_BUS_SERIAL1); 
 
void setup() {
  // Initialize the dynamixel bus:
  // Dynamixel 2.0 Baudrate -> 0: 9600, 1: 57600, 2: 115200, 3: 1Mbps  
  Dxl.begin(3);  
  Dxl.jointMode(J_ID_1); //jointMode() is to use position mode  
  Dxl.jointMode(J_ID_2); //jointMode() is to use position mode
}
 
void loop() {
  /*Turn dynamixel ID 2 to position 160 (45 deg)*/
  Dxl.goalPosition(J_ID_2, 160); 
  /*Turn dynamixel ID 1 to position 0 (0 deg)*/
  Dxl.goalPosition(J_ID_1, 0); 
  // Wait for 0.5 second (500 milliseconds)
  delay(500);              
  /*Turn dynamixel ID 1 to position 640 (180 deg)*/
  Dxl.goalPosition(J_ID_1, 640);
  // Wait for 0.5 second (500 milliseconds)
  delay(500);      
  /*Turn dynamixel ID 2 to position 320 (90 deg)*/
  Dxl.goalPosition(J_ID_2, 320); 
  /*Turn dynamixel ID 1 to position 0 (0 deg)*/
  Dxl.goalPosition(J_ID_1, 0); 
  // Wait for 0.5 second (500 milliseconds)
  delay(500);      
  /*Turn dynamixel ID 1 to position 640 (180 deg)*/
  Dxl.goalPosition(J_ID_1, 640);
  // Wait for 0.5 second (500 milliseconds)
  delay(500);      
}
