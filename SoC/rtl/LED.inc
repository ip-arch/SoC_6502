/*******************************************************************************
*LED: LED control module
********************************************************************************
* 2011.09.11   Initial version  by Y. Okuyama
*******************************************************************************/

declare LED {
	input		adrs[2];
	input		datai[8];
	output		datao[8];
	output		LEDR[16];
	output		LEDG[10];
	func_in		write(adrs,datai);
	func_in		read(adrs):datao;
}
