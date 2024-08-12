#include <stdbool.h>
#include "ellenorzofgk.h"
#include "lepesstruct.c"
#ifndef BOT_STRATAGIA_H
#define BOT_STRATEGIA_H
bool vedekezes3ra_ures_ures(Palya palya, Lepes *koord);
bool bot_mozgas(Palya palya, Lepes *koord, char keresendo, int mennyi);
void lepes(Lepes *koord, int x, int y);
void karakterszamlalas(Palya palya, int x, int y, char keresendo, int xnovelo, int ynovelo, int mennyi, Lepes *koord);
#endif


