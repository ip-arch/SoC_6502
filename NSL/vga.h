declare vga {
	func_out r,g,b;
	output h,v;
	input data[8];
	output adr[11];
	func_out mr(adr);
}
