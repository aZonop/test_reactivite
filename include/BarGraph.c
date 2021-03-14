//-----------------------------------------------------
//------------- Library BarreGraph   ------------------
//-----------------------------------------------------
//-- Projet: BarreGraph            	                 --
//-- Date:   24/02/2014                              --
//-- Progr:                							 --
//-- Auteurs: Daniel Binon              			 --
//-----------------------------------------------------
//-- 												 --
//-- 											     --
//-- 											     --
//-- InitHorBG = Initial. Horizontal BarreGraphe	 --
//-- InitVerBG = Initial. Vertical BarreGraphe		 --
//-- DrawHorBG(row,col,len,PCE)						 --
//-- Row & col -> Position, Len = Long en car	     --
//-- PCE = nombre de pixel -> max = 5 x len    	     --
//-- DrawVerBG(row,col,Height,PRE)					 --
//-- Row & col -> Position, Height = Hauteur en car  --
//-- -> maximum 2 pour un LCD 2 lignes			     --
//-- PRE = nombre de pixel -> max = 8 x Height	     --
//--         			         				     --
//----------------------------------------------------- 



//----------------------------------------------------- 
void initHorBG() {
BYTE i;

BYTE const LCD_HOR_CHARS[] = {
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // Barre graphe horizontal
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // Not used
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // Not used
0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10, // Not used
0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18, // Not used
0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C, // Not used
0x1E,0x1E,0x1E,0x1E,0x1E,0x1E,0x1E,0x1E, // Not used
0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F }; // Not used

	lcd_send_byte(0,LCD_CGRAM_BASE_ADDR);
	for (i=0;i<64;i++) {
		lcd_send_byte(1,LCD_HOR_CHARS[i]);
		delay_ms(3);
	}
	lcd_putc("\fInit. Horizont.\n");
	lcd_putc("Barre Graph. Ok");
	delay_ms(600);
	lcd_putc("\f");
}
//----------------------------------------------------- 
void initVerBG() {
BYTE i;

BYTE const LCD_VER_CHARS[] = {
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1F, // Barre graphe vertical
0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0x1F, // Not used
0x00,0x00,0x00,0x00,0x00,0x1F,0x1F,0x1F, // Not used
0x00,0x00,0x00,0x00,0x1F,0x1F,0x1F,0x1F, // Not used
0x00,0x00,0x00,0x1F,0x1F,0x1F,0x1F,0x1F, // Not used
0x00,0x00,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F, // Not used
0x00,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F, // Not used
0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F }; // Not used

	lcd_send_byte(0,LCD_CGRAM_BASE_ADDR);
	for (i=0;i<64;i++) {
		lcd_send_byte(1,LCD_VER_CHARS[i]);
		delay_us(40);
	}
	lcd_putc("\fInit. Vertical\n");
	lcd_putc("Barre Graph. Ok");
	delay_ms(600);
	lcd_putc("\f");
}
//----------------------------------------------------- 
void DrawHorBG(byte row,Byte col, Byte len, byte PCE) {
byte nfull,full,i;

	cursor(0);
	lcd_gotoxy(col,row);
	if ((PCE/5) > len) PCE = len * 5;
	full = PCE / 5;
	nfull = PCE - (full*5);
	for (i=0;i<full;i++) lcd_putc(7);
	lcd_putc(nfull+2);
	for (i=0;i<(len-full);i++) lcd_putc(1);
}
//----------------------------------------------------- 
void DrawVerBG(byte row,Byte col, Byte Height, byte PRE) {
byte nfull,full;

	cursor(0);
	lcd_gotoxy(col,row);
	if ((PRE/8) >= 2) PRE = 2 * 8;
	full = PRE / 9;
	nfull = (PRE -1) - (full*8);
	if (full > 0) {
		lcd_putc(7);
		lcd_gotoxy(col,1);
		lcd_putc(nfull);
	}else {
		lcd_putc(nfull);
		lcd_gotoxy(col,1);
		lcd_putc(" ");
	}
}