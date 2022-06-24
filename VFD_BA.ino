#include <GU7000_Interface.h>
#include <GU7000_Parallel.h>
#include <GU7000_Serial_Async.h>
#include <GU7000_Serial_Sync.h>
#include <GU7000_Serial_SPI.h>
#include <Noritake_VFD_GU7000.h>
#include "c.h"

// ****************************************************
// ****************************************************
// Uncomment one of the communication interfaces below.
//

//GU7000_Serial_Async interface(38400,3, 5, 7); // BAUD RATE,SIN,BUSY,RESET
GU7000_Serial_Sync interface(6, 7, 8, 9); // SIN,BUSY,SCK,RESET
//GU7000_Serial_SPI interface(3, 5, 6, 7, 8); // SIN,BUSY,SCK,RESET,CS
//GU7000_Parallel interface('R', 8,9,10,11, 0,1,2,3,4,5,6,7); // Module Pin#3=RESET; BUSY,RESET,WR,RD,D0-D7
//GU7000_Parallel interface('B', 8,9,10,11, 0,1,2,3,4,5,6,7); // Module Pin#3=BUSY; BUSY,RESET,WR,RD,D0-D7
//GU7000_Parallel interface('N', 8,9,10,11, 0,1,2,3,4,5,6,7); // Module Pin#3=nothing; BUSY,RESET,WR,RD,D0-D7
//
// ****************************************************
// ****************************************************

Noritake_VFD_GU7000 vfd;

// 140x16 image "logo16"
// This image data was provided by the Noritake Bitmap Image Tool for GU-7000
// const static uint8_t PROGMEM image[] = {
// data}




unsigned long b=65;
int a=65;//ascii A
int img_num=0;

void setup() {
  
  delay(500);           // wait for device to power up
  vfd.begin(112, 16);       // 140x16 module
  // Enter the 4-digit model class number
  // E.g. 7040 for GU140X16G-7040A
  vfd.interface(interface); // select which interface to use
  vfd.isModelClass(7003);
  //vfd.isGeneration('B');    // Uncomment this for B generation
  vfd.GU7000_reset();       // reset module
  vfd.GU7000_init();        // initialize module
  vfd.GU7000_invertOn();
  vfd.GU7000_setScreenBrightness(1);
}

void loop() {

  //print("%s", getName(img_num));

  
  
  
  
  
  ///*
  // Display image
  for (int i=0; i<680; i++){
    
    vfd.GU7000_drawImage_p(24, 16, image[i]);
    
    vfd.GU7000_carriageReturn();
    delay(13);
  }
  
    
  //*/
  //vfd.GU7000_drawImage_p(24, 16, image[0]);
  //img_num++;
}
