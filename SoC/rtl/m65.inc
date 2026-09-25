
declare m65 {
    input      data[8] ;
    output     datao[8] ;
    output     adrs[16] ;
    output     debug[16];
    func_in    irq, nmi, rdy, start;
    func_out   rd,wt;
    func_out   sync;
}
