#include"SWITCH.h"
void setup() {
  volatile int outputmode=0xff,inputmode=0x00;
  volatile int x;
 init_PORTF(outputmode);
 init_PORTK(inputmode);
 while(1){
 *inputK=0x00;
  x=*inputK;
  if((x & 0x01)==0x01){
    while((x & 0x01)==0x01)
  {
    *outputF=0xff;
  }
}
}
}
void loop() {
  // put your main code here, to run repeatedly:

}

