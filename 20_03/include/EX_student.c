#ifdef led
#else
	#DEFINE led PIN_A4
#endif

#ifdef button
#else
	#DEFINE button PIN_B0
#endif

#DEFINE led_toggle output_bit(led,!input_state(led))
//-------------------------xxx------------------------
byte cp0=0,count,x=3;

//-------------------------xxx------------------------
#int_
void  RTCC_isr(void) {

}
//-------------------------xxx------------------------
void state_led(byte val) {

}
//-------------------------xxx------------------------

#INT_
void ext_isr() {

}
//-------------------------xxx------------------------
void initialisation() {

}