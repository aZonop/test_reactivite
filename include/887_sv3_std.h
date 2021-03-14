#include <16F887.h>

#device ADC=8			// adc en mode résolution 10 bits
#fuses NOWDT, HS, NOPUT, NOPROTECT, NOBROWNOUT, NOLVP, NOCPD, NOWRT, NODEBUG
#use delay(clock=20M)

//-----------------------DEFINITION--------------------
#DEFINE HIGH 1
#DEFINE LOW 0
