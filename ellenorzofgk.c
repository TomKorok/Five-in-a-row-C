#include <stdbool.h>
#include "palyastruct.c"
#include "lepesstruct.c"
bool tehetunke_oda(Palya palya, int x, int y)
{
    if(x>-1 && x<palya.meret && y>0 && y<(2*palya.meret) && palya.terulet[x][y] !='X' && palya.terulet[x][y] !='O')
    {
        return true;
    }
    return false;
}
bool nyerte(Palya palya, char ki){
    for(int x=0; x<palya.meret; x++){
        for(int y=1; y<2*palya.meret+1; y+=2){
            if(palya.terulet[x][y]==ki){
                if(x<palya.meret && y+2<2*palya.meret && palya.terulet[x][y+2]==ki){
                    int db=2, x1=x, y1=y+4;
                    while(x1<palya.meret && y1<2*palya.meret && palya.terulet[x1][y1]==ki && db<5){
                        db++, y1+=2;
                    }
                    if(db>4){
                        return true;
                    }}
                if(x+1<palya.meret && y-2>0 && palya.terulet[x+1][y-2]==ki){
                    int db=2,x1=x+2, y1=y-4;
                    while(x1<palya.meret && y1>0 && palya.terulet[x1][y1]==ki && db<5){
                        db++, x1++, y1-=2;
                    }
                    if(db>4){
                        return true;
                    }}
                if(x+1<palya.meret && y<2*palya.meret && palya.terulet[x+1][y]==ki){
                    int db=2, x1=x+2, y1=y;
                    while(x1<palya.meret && y1<2*palya.meret && palya.terulet[x1][y1]==ki && db<5){
                        db++, x1++;
                    }
                    if(db>4){
                        return true;
                    }}
                if(x+1<palya.meret && y+2<2*palya.meret &&  palya.terulet[x+1][y+2]==ki){
                    int db=2, x1=x+2, y1=y+4;
                    while(x1<palya.meret && y1<2*palya.meret && palya.terulet[x1][y1]==ki && db<5){
                        db++, x1++, y1+=2;
                    }
                    if(db>4){
                        return true;
                    }}}}}
    return false;
}

