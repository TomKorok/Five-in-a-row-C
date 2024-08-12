#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "palyastruct.c"
#include "lepesstruct.c"
#include "bot_strategia.h"
#include "ellenorzofgk.h"
Palya palya;
void lepesbotkonnyu(Lepes *koord)
{
    if(!bot_mozgas(palya, koord, 'X', 4) && !bot_mozgas(palya, koord, 'X', 3) && !bot_mozgas(palya, koord, 'X', 2))
    {
        srand(time(0));
        koord->x=rand()%palya.meret;
        koord->y=rand()%palya.meret;
        if(tehetunke_oda(palya, koord->x, koord->y))
        {
            palya.terulet[koord->x][(2*koord->y+1)]='O';
            return;
        }
        else
        {
            while(!tehetunke_oda(palya,koord->x, koord->y))
            {
                koord->x=rand()%palya.meret;
                koord->y=rand()%palya.meret;
            }
            palya.terulet[koord->x][(2*koord->y+1)]='O';
            return;
        }
    }
    int hanyra=4;
    while(hanyra>1)
    {
        if(bot_mozgas(palya, koord, 'X', hanyra))
        {
            palya.terulet[koord->x][koord->y]='O';
            return;
        }
        else
        {
            hanyra--;
        }
    }
}

void lepesbotkozepes(Lepes *koord)
{
    if(bot_mozgas(palya, koord, 'X', 4))
    {
        palya.terulet[koord->x][koord->y]='O';
        return;
    }
    else if(vedekezes3ra_ures_ures(palya, koord))
    {
        palya.terulet[koord->x][koord->y]='O';
        return;
    }
    int hanyra=3;
    while(hanyra>0)
    {
        if(bot_mozgas(palya, koord, 'X', hanyra))
        {
            palya.terulet[koord->x][koord->y]='O';
            return;
        }
        else
        {
            hanyra--;
        }
    }
}

void lepesbotnehez(Lepes *koord)
{
    if(bot_mozgas(palya, koord, 'X', 4))
    {
        palya.terulet[koord->x][koord->y]='O';
        return;
    }
    else if(vedekezes3ra_ures_ures(palya, koord))
    {
        palya.terulet[koord->x][koord->y]='O';
        return;
    }
    int hanyra=4;
    while(hanyra>0)
    {
        if(bot_mozgas(palya, koord, 'O', hanyra))
        {
            palya.terulet[koord->x][koord->y]='O';
            return;
        }
        else
        {
            hanyra--;
        }
    }
    hanyra=1;
    if(bot_mozgas(palya, koord, 'X', hanyra))
    {
            palya.terulet[koord->x][koord->y]='O';
            return;
    }
}



bool jatekmentes()
{
    FILE *fp;
    fp = fopen("palya.txt", "wt");
    if (fp == NULL)
    {
       return false;
    }
    for(int sor=0; sor<palya.meret; sor++)
    {
        for(int oszlop=0; oszlop<2*palya.meret+1; oszlop++)
        {
            fprintf(fp,"%c",palya.terulet[sor][oszlop]);
        }
        fprintf(fp,"\n");
    }
    fclose(fp);
    fp = fopen("adatok.txt", "wt");
    if (fp == NULL)
    {
    return false;
    }
    fprintf(fp, "%d %d", palya.nehezseg, palya.meret);
    fclose(fp);
    printf("jatek elmentve\n");
    return true;
}

bool lepesjatekos(Lepes *koord)
{
    scanf("%d %d",&koord->x,&koord->y);
    if(koord->x==-1 && koord->y==-1)
    {
        while(!jatekmentes())
        {
            if(jatekmentes())
            {
                break;
            }
        }
    }
    if(koord->x==-2 && koord->y==-2)
    {
        return false;
    }
    koord->y=(2*koord->y+1);
    if(tehetunke_oda(palya, koord->x, koord->y))
    {
        palya.terulet[koord->x][koord->y]='X';
    }
    else
    {
        printf("Adj meg masik helyet!\nMasik hely: ");
        scanf("%d %d",&koord->x,&koord->y);
        if(koord->x==-2 && koord->y==-2)
        {
        return false;
        }
        koord->y=(2*koord->y+1);
        while(!tehetunke_oda(palya, koord->x, koord->y))
        {
            printf("Adj meg masik helyet!\nMasik hely: ");
            scanf("%d %d",&koord->x,&koord->y);
             if(koord->x==-2 && koord->y==-2)
             {
                return false;
             }
            koord->y=(2*koord->y+1);
        }
        palya.terulet[koord->x][koord->y]='X';
    }
    return true;
}
int printfpalya()
{
    printf("\n    ");
    for(int x=0; x<palya.meret; x++)
    {
        if(x<10)
        {
            printf("%d   ",x);
        }
        else
        {
            printf("%d  ",x);
        }
    }
    printf("\n");
    int y=0;
    for(int sor=0; sor<palya.meret; sor++)
    {
        if(y<10)
        {
           printf("%d ",y);
        }
        else
        {
            printf("%d",y);
        }
        for(int oszlop=0; oszlop<2*palya.meret+1; oszlop++)
        {
                printf("%c ",palya.terulet[sor][oszlop]);
        }
        printf("\n");
        y++;
    }
    int meret=palya.meret;
    return meret;
}

void jelenlegiallas(Lepes *koord)
{
    palya.meret=printfpalya();
    while(!nyerte(palya, 'X') && !nyerte(palya, 'O'))
    {
        printf("\nEz a jelenlegi allas kerem a kovetkezo lepesed (forma: y x): ");
        if(lepesjatekos(koord))
        {

        }
        else
        {
            return;
        }
        if(!nyerte(palya, 'X'))
        {
            if(palya.nehezseg==1)
            {
                lepesbotkonnyu(koord);
            }
            if(palya.nehezseg==2)
            {
                lepesbotkozepes(koord);
            }
            if(palya.nehezseg==3)
            {
                lepesbotnehez(koord);
            }

        }
        palya.meret=printfpalya();
    }
    if(nyerte(palya, 'X'))
    {
        printf("Gratulalunk, nyertel!\n\n");
    }
    if(nyerte(palya, 'O'))
    {
        printf("Sajnos vesztettel, probald meg ujra!\n\n");
    }
    for(int i=0; i<palya.meret; i++)
    {
        free(palya.terulet[i]);
    }
    free(palya.terulet);
    return;
}
int palyafel()
{
    int meret=palya.meret;
    int sor=0;
    int oszlop=0;
    while(sor<palya.meret)
    {
        oszlop=0;
        while(oszlop<2*palya.meret+1)
        {
            palya.terulet[sor][oszlop]='|';
            palya.terulet[sor][oszlop+1]=' ';
            oszlop+=2;
        }
        sor++;
    }
    return meret;
}
int palyafoglal()
{
    int meret;
    if(palya.meret==0)
    {
        printf("\nHanyszor hanyas legyen a palya?(minimum 10x10, maximum 50x50-es) ");
        scanf("%d",&palya.meret);
    }
    while(palya.meret>50 || palya.meret<10)
    {
            printf("Adj meg egy masik meretet! ");
            scanf("%d",&palya.meret);
    }
    palya.terulet = (char**) malloc(palya.meret* sizeof(char*)+1);
    for(int i=0; i<palya.meret; i++)
    {
        palya.terulet[i]=(char*) malloc((2*palya.meret+1)*sizeof(char)+1);
    }
    meret=palya.meret;
    return meret;
}

bool jatekbetoltes()
{
    FILE *fp;
    fp=fopen("adatok.txt", "rt");
    if (fp == NULL)
    {
       return false;
    }
    fscanf(fp, "%d %d",&(palya.nehezseg), &(palya.meret));
    fclose(fp);
    int meret;
    meret=palyafoglal();
    meret++;
    fp=fopen("palya.txt", "rt");
    if (fp == NULL)
    {
       return false;
    }
    int sor=0;
    int oszlop=0;
    while(sor<palya.meret)
    {
        oszlop=0;
        while(oszlop<2*palya.meret+1)
        {
            fscanf(fp,"%c%c",&(palya.terulet[sor][oszlop]),&(palya.terulet[sor][oszlop+1]));
            oszlop+=2;
        }
        sor++;
    }
    fclose(fp);
    return true;
}

int valasztasnehezseg()
{
    int valasztas;
    printf("\n----------1. konnyu--------\n");
    printf("----------2. kozepes-------\n");
    printf("----------3. nehez---------\n");
    printf("Irja be annak a nehezsegnek a szamat amelyiken jatszani szeretne! ");
    scanf("%d",&valasztas);
    return valasztas;
}

int printfmenu()
{
    printf("--------------Menu--------------\n");
    printf("----------1. Uj jatek-----------\n");
    printf("-------2. Jatek betoltese-------\n");
    printf("-----------3. Kilepes-----------\n");
    printf("jatek elmentesehez adja meg a -1 -1-et a lepesenel\n");
    printf("adott jatekbol valo kilepeshez adja meg a -2 -2 a lepesnel\n\n");
    printf("Irja be annak a menupontnak a szamat amelyiket valasztani szeretne!");
    int valasztas;
    scanf("%d",&valasztas);
    return valasztas;
}
