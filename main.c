#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"jeu.h"
#include"dico.h"


int main(void)
{
    int *choixPtr = NULL;
    int choix = 0;
    choixPtr = &choix; 
    menu(choixPtr);

    if (choix != 2)
    {
        soloMode();
    }
    else
    {
        duoMode();
    }

    return 0;
}