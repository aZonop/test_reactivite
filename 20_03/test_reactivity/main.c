 //#DEVICE PIC16F887
#include "..\include\887_sv3_std.h"
#include <stdlib.h>

#use delay(clock=20M)
#use rs232(baud=115200,xmit=PIN_C6, rcv=PIN_C7, stream=RS232)


#DEFINE led PIN_A4
#DEFINE button PIN_E2


#define TICKS_BETWEEN_INTERRUPTS 5000
#define TMR1RESET (0xFFFF - TICKS_BETWEEN_INTERRUPTS)

//global variables
int comp;

#INT_TIMER1
void Timer1(void){
	comp++;
	//On incrémente le compteur des millisecondes à chaque fois que l'interruption est déclenchée
}


void init(){
	//initialisation des entrees/sorties
	output_drive(led);
	output_float(button);
	
	//initialisation du timer1
	setup_timer_1(T1_INTERNAL|T1_DIV_BY_1);
	set_timer1(TMR1RESET);
	enable_interrupts(global);
	enable_interrupts(INT_TIMER1);
	
	comp=0;
	
	//Visuel inutile
	delay_ms(2000);
	output_bit(led,HIGH);
	delay_ms(200);
	output_bit(led,LOW);
	delay_ms(200);
	output_bit(led,HIGH);
	delay_ms(200);
	output_bit(led,LOW);
	delay_ms(200);
	output_bit(led,HIGH);
	delay_ms(200);
	output_bit(led,LOW);
	delay_ms(1000);
}

void main(){
	init();
	
	int1 val;
	int temps_0;
	int mesure_1;
	
	int rnd_number;
	//test code for serial communication
	/*
	while(true){
		val=1;
		while(val==1){
			val=input_state(button);
			output_bit(led,HIGH);
			delay_ms(500);
			output_bit(led,LOW);
			delay_ms(500);
			printf("val=%u \t \n ",val);
			
		}
		output_bit(led,HIGH);
		delay_ms(200);
		output_bit(led,LOW);
		delay_ms(5000);
	}
	
	//test code for rand function (could be improved by initialising rand with the time
	while(true){
		rnd_number = rand()%3000;
		printf("rnd_number=%d \t \n \t",rnd_number);
		//printf("%d \t",rand());
		delay_ms(1000);
	}
	//test code for interrupts
	while(true){
		printf("%u \t",comp);
		delay_ms(100);
	}*/
	//Tourne à l'infini pour pouvoir rejouer au jeu
	while(true){
		
		comp=0;
		val=1;	//1 = on n'appuye pas sur le bouton
		//On attend que l'utilisateur appuie une première fois sur le bouton
		while(val==1){
			val=input_state(button);
			output_bit(led,LOW);	
		}
		val=1;
		delay_ms(3000); //On attend de toute façon au minimum 3 secondes
		
		
		rnd_number=rand()%3000;	//Tirage du nombre aléatoire entre 0 et 3000
		delay_ms(rnd_number);
		output_bit(led,HIGH);
		temps_0=comp; //démarrage du chrono
		
		//Attente de l'appui sur le bouton
		while(val==1){
			val=input_state(button);
		}
		temps_0=comp - temps_0;
		printf("Resultat : %d \t",temps_0);
		delay_ms(1000);
		
	}
		
} 