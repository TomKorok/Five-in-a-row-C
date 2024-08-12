#include <stdio.h>
#include <stdlib.h>
#include "palyastruct.c"
#include "lepesstruct.c"
#ifndef MENU_H
#define MENU_H
int printfmenu();
int printfpalya();
int valasztasnehezseg();
int palyafel();
int palyafoglal();
void jelenlegiallas(Lepes *koord);
void lepesjatekos(Lepes *koord);
void lepesbotkonnyu(Lepes *koord);
void lepesbotkozepes(Lepes *koord);
void lepesbotnehez(Lepes *koord);
bool jatekbetoltes();
bool jatekmentes();
#endif
