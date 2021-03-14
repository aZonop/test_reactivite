#include <16F887.h>
#fuses HS,NOWDT,NOPROTECT,NOLVP,NODEBUG,USBDIV,VREGEN
// To check
//#use delay(clock=24M)
//#use rs232(baud=115200,parity=N,xmit=PIN_C6,rcv=PIN_C7,bits=8,stream=RS232)



#define led PIN_D0
#define led_(x) output_bit(led,x)

#define LOW 0
#define HIGH 1