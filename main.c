#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "menu.h"
#include "lepesstruct.c"
#include "palyastruct.c"
Palya palya;
Lepes koord;
int main()
{

    int valasztas;
    valasztas=printfmenu();
    while(valasztas != 3)
    {
        if(valasztas==1)
        {
            palya.meret=0;
            palya.nehezseg=valasztasnehezseg();
            palya.meret=palyafoglal();
            palya.meret=palyafel();
            jelenlegiallas(&koord);

        }
        else if(valasztas==2)
        {
            while(!jatekbetoltes())
            {
                if(jatekbetoltes())
                {
                    break;
                }
            }
            jelenlegiallas(&koord);
        }
        valasztas=printfmenu();
    }
    return 0;
}
