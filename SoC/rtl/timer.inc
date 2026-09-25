// 2014/03/11  Shimizu and Okuyama

declare timer {
	input		adrs[3];
	input		datai[8];
	output		datao[8];
	func_in		read(adrs):datao;
	func_in		write(adrs,datai);
	func_out	into();
}
