#include <Digitizer.h>

//include user-defined files
#include "GMDPSoftware.h"

int luposx = DISPLAY_RESOLUTION_X/10;
int luposy = DISPLAY_RESOLUTION_Y/2;
int posxpitch = 10;
int posypitch = 10;

int posxarr[7];
int posyarr[3];

//prototype declaration
int getluposx(void);
int getluposy(void);
int getpitchx(void);
int getpitchy(void);
void setpos(void);
void testmode(void);
void initialize(void);

void setup() {
    Serial.begin(9600);
    pinMode(PIN_SAFETY,INPUT_PULLUP);
    
    Digitizer.setDisplayResolution(0, 0, DISPLAY_RESOLUTION_X, DISPLAY_RESOLUTION_Y);
    Digitizer.setLogicalResolution(0, 0, LOGICAL_RESOLUTION_X, LOGICAL_RESOLUTION_Y);
    
    pinMode(LU_POS_X,INPUT);
    pinMode(LU_POS_Y,INPUT);
    pinMode(POS_X_PITCH,INPUT);
    pinMode(POS_Y_PITCH,INPUT);
    pinMode(POWER_LED,OUTPUT);
//    digitalWrite(POWER_LED,HIGH);
}
 
void loop() {
  if(digitalRead(7)== LOW){
    initialize();
    testmode();
  } 
}

void initialize(void){
#if DEBUG >= 1 && DEBSERIAL == 1
    Serial.println("------------------------------------");
    Serial.println("GMDProject "+String(SOFTWARE_VERSION));
    Serial.println("------------------------------------");
#endif
    luposx = getluposx();
    luposy = getluposy();
    posxpitch = getpitchx();
    posypitch = getpitchy();
}

void testmode(void){
#if DEBUG >= 1 && DEBSERIAL == 1
    Serial.println("DEBUG >= 1 && DEBSERIAL == 1");
#endif
    setpos();
    for(int j = 0; j < 3; j++){
      for(int i = 0; i < 7; i++){
       Digitizer.move(posxarr[i],posyarr[j]);
//       Digitizer.click();
#if DEBUG >= 1 && DEBSERIAL == 1
  Serial.print(String(posxarr[i])+","+String(posyarr[j])+"  ");
#endif
       delay(500); 
      }
#if DEBUG >= 1 && DEBSERIAL == 1
  Serial.println(" ");
#endif
    }
}

int getluposx(void){
  int adval, rtval;
  adval = analogRead(LU_POS_X);
  rtval = (adval/1023)*DISPLAY_RESOLUTION_X;
#if DEBUG >= 1
  
#endif
#if DEBUG == 2
  Serial.println("LU_POS_X: "+String(rtval));
  rtval = DISPLAY_RESOLUTION_X/10;
#endif
  return rtval;
}

int getluposy(void){
  int adval, rtval;
  adval = analogRead(LU_POS_Y);
  rtval = (adval/1023)*DISPLAY_RESOLUTION_Y;
#if DEBUG >= 1 && DEBSERIAL == 1
  
#endif
#if DEBUG == 2
  Serial.println("LU_POS_Y: "+String(rtval));
  rtval = DISPLAY_RESOLUTION_Y/2;
#endif
  return rtval;
}

int getpitchx(void){
  int adval, rtval;
  adval = analogRead(POS_X_PITCH);
  rtval = (adval/1023)*DISPLAY_RESOLUTION_X/10;
#if DEBUG >= 1 && DEBSERIAL == 1
  
#endif
#if DEBUG == 2
  Serial.println("POS_X_PITCH: "+String(rtval));
  rtval = 100;
#endif
  return rtval;
}

int getpitchy(void){
  int adval, rtval;
  adval = analogRead(POS_Y_PITCH);
  rtval = (adval/1023)*DISPLAY_RESOLUTION_Y/10;
#if DEBUG >= 1 && DEBSERIAL == 1
  
#endif
#if DEBUG == 2 && DEBSERIAL == 1
  Serial.println("POS_Y_PITCH: "+String(rtval));
  rtval = 100;
#endif
  return rtval;
}

void setpos(void){
#if DEBUG >= 1 && DEBSERIAL == 1
  Serial.print("posxarr[i]: ");
#endif
  for(int i = 0; i < 7; i++){
    posxarr[i] = luposx + posxpitch * i;
    if(posxarr[i] >= DISPLAY_RESOLUTION_X){
      posxarr[i] = DISPLAY_RESOLUTION_X;
    }
#if DEBUG >= 1 && DEBSERIAL == 1
  Serial.print(String(posxarr[i])+",");
#endif
  }
#if DEBUG >= 1 && DEBSERIAL == 1
  Serial.println(" ");
#endif
#if DEBUG >= 1 && DEBSERIAL == 1
  Serial.print("posyarr[j]: ");
#endif
  for(int j = 0; j < 3; j++){
    posyarr[j] = luposy + posypitch * j;
    if(posyarr[j] >= DISPLAY_RESOLUTION_Y){
      posyarr[j] = DISPLAY_RESOLUTION_Y;
    }
#if DEBUG >= 1 && DEBSERIAL == 1
  Serial.print(String(posyarr[j])+",");
#endif
  }
#if DEBUG >= 1 && DEBSERIAL == 1
  Serial.println(" ");
#endif
}

/*
356,577  491,577 627,577 761,577 895,577 1029,577  1166,577
356,696 491,696 627,696 761,696 895,696 1029,696  1166,696
356,809 491,809 627,809 761,809 895,809 1029,809  1166,809
*/
