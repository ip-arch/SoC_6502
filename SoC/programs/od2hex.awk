BEGIN{adr=0}
{
    x=1
    while(x<=NF){
        b  = strtonum("0x" $x)
        ah = int(adr/256)
        al = adr % 256
        s  = and(1+ah+al+b, 0xff)      # まず 0-255 に正規化
        cs = and(256-s, 0xff)          # その2の補数
        printf ":01%04X00%s%02X\n", adr, $x, cs
        x++; adr++
    }
}
END{print ":00000001FF"}
