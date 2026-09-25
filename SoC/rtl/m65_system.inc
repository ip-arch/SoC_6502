declare    m65_system  {   
    input    datai[8]; 
    output    datao[8]; 
    output    adrs[16];	
    output    debug[16];
    func_out    memory_read(adrs); 
    func_out    memory_write(adrs,datao); 
    func_in	irq(),nmi();
} 
  
