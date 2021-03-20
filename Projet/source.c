#include "..\include\887_sv3_std.h"			// Entete standard pour carte Simius 887
#include <stdlib.h>		//Library to return a random number through rand() function

#define led PIN_D0

#define button PIN_D1

#define LOW 0
#define HIGH 1

void init(){
	output_drive(led);
	output_float(button);
}

void main(){
	int1 val;
	int16 rnd_time;
	//initialisation
	init()
	
	val=0;
	while(val==0){
		val=input_state(button)
		//L'utilisateur appuie une première fois sur le bouton poussoir
		//Quand ce sera un 1, on passera à la suite du programme
	}	
	

	//boucle de jeu
	while(true){
		//temps aléatoire entre 3 et 6 sec
		delay_ms(3000);
		
		rnd_time=rand()%3000; //Ne dépassera pas 3000 ms grâce au modulo
		
		delay_ms(rnd_time);
		//led s'allume + mesure du temps
		output_bit(led,HIGH)
		//attendre appui sur le bouton
		//led s'éteint + mesure du temps
		
		output_bit(led,LOW)
		//envoit du temps sur le pc
		
	}

}