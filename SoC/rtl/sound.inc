/*******************************************************************************
*Sound: 4bit DAC control module
********************************************************************************
* 2014.12.24   Initial version  by T.Furukawa
*******************************************************************************/

declare sound {
	input		datai[8];
	output		datao[8];
	output		DAC[4];
	func_in		read():datao;
	func_in		write(datai);
}
