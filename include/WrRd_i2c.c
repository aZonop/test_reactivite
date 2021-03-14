//-----------------------------------------------------
//----------- Library Ecriture/lecture I2C ------------
//-----------------------------------------------------
//-- Projet: Ecriture/lecture I2C  	                 --
//-- Date:   01/07/2014                              --
//-- Progr:                							 --
//-- Auteurs: Daniel Binon              			 --
//-----------------------------------------------------
//-- 												 --
//-- 											     --
//-- 											     --
//-- Function lec_i2c(device,addr,delay)             --
//--   -> return 1 byte data						 --
//-- Function lecdb_i2c(device,addr,delay)     		 --
//--   -> return 1 long data						 --
//-- ecr_i2c(device,address,data)				     --
//--         			         				     --
//----------------------------------------------------- 


//-------------Lecture  I2C------------------
signed byte lec_i2c(byte device, byte address, byte del) {
   signed BYTE data;

   i2c_start();
   i2c_write(device);
   i2c_write(address);
   if (del!=0) delay_ms(del);
   i2c_start();
   i2c_write(device | 1);
   data=i2c_read(0);
   i2c_stop();
   return(data);
}

//-------------Lecture  I2C  2 bytes -----------------
signed int16 lecdb_i2c(byte device, byte address, byte del) {
   BYTE dataM,dataL;
   int16 data;

   i2c_start();
   i2c_write(device);
   i2c_write(address);
   if (del!=0) delay_ms(del);
   i2c_start();
   i2c_write(device | 1);
   dataM = i2c_read(1);				// Read MSB
   dataL = i2c_read(0);				// Read LSB
   i2c_stop();
   data=((dataM*256)+dataL);		// True value
   return(data);
}

//-------------Ecriture  I2C------------------
void ecr_i2c(byte device, byte address, byte data) {
   i2c_start();
   i2c_write(device);
   i2c_write(address);
   i2c_write(data);
   i2c_stop();
}
