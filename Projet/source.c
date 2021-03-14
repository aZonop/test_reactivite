#include <16F887.h>
#fuses HS,NOWDT,NOPROTECT,NOLVP,NODEBUG,USBDIV,VREGEN
// To check
#use delay(clock=20M)            //on définit une horloge de 20 MHz  pour le 16F887
//#use rs232(baud=115200,parity=N,xmit=PIN_C6,rcv=PIN_C7,bits=8,stream=RS232)



#define led PIN_D0
#define led_(x) output_bit(led,x)

#define button PIN_D1
#define button_(x) input_bit(button,x)

#define LOW 0
#define HIGH 1

void main(){
	
	//initialisation
	
	//L'utilisateur appuie une première fois sur le bouton poussoir

	//boucle de jeu
	while(true){
		//temps aléatoire entre 3 et 6 sec
		//led s'allume + mesure du temps
		//attendre appui sur le bouton
		//led s'éteint + mesure du temps
		//envoit du temps sur le pc
		
	}

}