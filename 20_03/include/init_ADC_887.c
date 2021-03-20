
void init_adc() {
	
	setup_adc_ports(sAN0|sAN1|sAN2|sAN3);
	setup_adc(ADC_CLOCK_INTERNAL);
#ifdef ADC_IN
	set_adc_channel(ADC_IN);
#else
	set_adc_channel(0);
#endif	
	delay_us(10);
}