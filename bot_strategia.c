#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "palyastruct.c"
#include "lepesstruct.c"
#include "ellenorzofgk.h"

void lepes(Lepes *koord, int x, int y)
{
    koord->x=x;
    koord->y=y;
    return;
}


bool karakterszamlalas(Palya palya, int x, int y, char keresendo, int xnovelo, int ynovelo, int mennyi, Lepes *koord){
    int  db=1;
    x+=xnovelo;
    y+=ynovelo;
    while(db != mennyi)
    {
        if(x<palya.meret && y<2*palya.meret && y>0 && palya.terulet[x][y]==keresendo)
        {
            db++;
            x+=xnovelo;
            y+=ynovelo;
        }
        else
        {
            break;
        }
    }
    lepes(koord, x,y);
    if(db==mennyi)
    {
        return true;
    }
    return false;
}


bool bot_mozgas(Palya palya, Lepes *koord, char keresendo, int mennyi){
     for(int x=0; x<palya.meret; x++){
        for(int y=1; y<2*palya.meret+1; y+=2){
            if(palya.terulet[x][y]==keresendo)
            {
                if(karakterszamlalas(palya, x, y, keresendo, 0, 2, mennyi, koord))
                {
                    if(tehetunke_oda(palya,x,y-2)){
                        lepes(koord, x, y-2);
                        return true;
                    }
                    if(tehetunke_oda(palya,koord->x,koord->y)){
                        return true;
                    }
                }
                if(karakterszamlalas(palya, x, y, keresendo, 1, -2, mennyi, koord))
                {
                    if(tehetunke_oda(palya,x-1,y+2)){
                        lepes(koord, x-1, y+2);
                        return true;
                    }
                    if(tehetunke_oda(palya,koord->x, koord->y)){
                        return true;
                    }
                }
                if(karakterszamlalas(palya, x, y, keresendo, 1, 0, mennyi, koord)){
                    if(tehetunke_oda(palya,x-1,y)){
                        lepes(koord, x-1, y);
                        return true;
                    }
                    if(tehetunke_oda(palya, koord->x, koord->y)){
                        return true;
                    }
                }
                if(karakterszamlalas(palya, x, y, keresendo, 1, 2, mennyi, koord))
                {
                    if(tehetunke_oda(palya,x-1,y-2)){
                        lepes(koord, x-1, y-2);
                        return true;
                    }
                    if(tehetunke_oda(palya, koord->x, koord->y)){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

bool vedekezes3ra_ures_ures(Palya palya, Lepes *koord){
     for(int x=0; x<palya.meret; x++){
        for(int y=1; y<2*palya.meret+1; y+=2){
            if(palya.terulet[x][y]=='X')
            {
                 if(palya.terulet[x][y-2]==' ' && palya.terulet[x][y+2]=='X' && palya.terulet[x][y+4]=='X' && palya.terulet[x][y+6]==' ') //keresunk 3mat vizszintesen ami mind2 oldalrol ures
                 {
                     lepes(koord, x, y-2);
                     return true;
                 }
                 if(palya.terulet[x-1][y-2]==' ' && palya.terulet[x+1][y+2]=='X' && palya.terulet[x+2][y+4]=='X' && palya.terulet[x+3][y+6]==' ') //keresunk 3mat jobbra le ami mind2 oldalrol ures
                 {
                     lepes(koord, x-1, y-2);
                     return true;
                 }
                 if(palya.terulet[x-1][y+2]==' ' && palya.terulet[x+1][y-2]=='X' && palya.terulet[x+2][y-4]=='X' && palya.terulet[x+3][y-6]==' ') //keresunk 3mat balra le ami mind2 oldalrol ures
                 {
                     lepes(koord, x-1, y+2);
                     return true;
                 }
                 if(palya.terulet[x-1][y]==' ' && palya.terulet[x+1][y]=='X' && palya.terulet[x+2][y]=='X' && palya.terulet[x+3][y]==' ')       //keresunk 3mat fugg le ami mind2 oldalrol ures
                 {
                     lepes(koord, x-1, y);
                     return true;
                 }
            }
    }
    }
    return false;
}









