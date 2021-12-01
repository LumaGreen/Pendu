#include"jeu.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"dico.h"

int nombreAuHasard(int nbMots)
{
    srand(time(NULL));
    int indice = (rand() % nbMots);
    return indice;
}

/*-------------------------------------------------------------------------------------*/

int choisirMot(char *mot)
{
    int nbMotsFichier = 0;
    FILE* fichier = NULL;
    fichier = fopen("dico.txt", "r");
    if (fichier != NULL)
    {
        int caractereActuel = 0;
        do
        {
            caractereActuel = fgetc(fichier);
            if (caractereActuel == '\n')
            {
                nbMotsFichier++;
            }
        } while (caractereActuel != EOF);

        int indice = nombreAuHasard(nbMotsFichier);
        rewind(fichier);
        while (indice > 0)
        {
            caractereActuel = fgetc(fichier);
            if (caractereActuel == '\n')
            {
                indice--;
            }
        }
        fgets(mot, 100, fichier);
        mot[strlen(mot)-1] = '\0';
        
        
        fclose(fichier);
    }
    else
    {
        printf("Impossible d'ouvrir le fichier liste_mots.txt\n");
    }

    return 1;
}

