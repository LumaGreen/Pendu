#include<stdlib.h>
#include<stdio.h>
#include"jeu.h"
#include"dico.h"

char lireCaractere()
{
    char caractere = 0;

    caractere = getchar();
    caractere = toupper(caractere);

    while (getchar() != '\n');

    return caractere;
}

/*-------------------------------------------------------------------------------------*/

void affiche(char tableau[], int tailleTableau)
{
    int i;

    for (i = 0; i < tailleTableau; i++)
    {
        printf("%c", tableau[i]);
    }
}

/*-------------------------------------------------------------------------------------*/

void initialiserMotTrouve(char *mot, char *motTrouve)
{
    int i = 0;
    strcpy(motTrouve, mot);
    for (i = 0; i < strlen(motTrouve); i++)
    {
        motTrouve[i] = '*';
    }
    
}

/*-------------------------------------------------------------------------------------*/

void lettreDansMot(char lettre, char *motTrouve, const char *mot, int *compteurPtr)
{
    int i = 0;
    int verifPourDesincrementer = 0;
    for (i = 0; i < strlen(motTrouve); i++)
    {
        if (mot[i] == lettre)
        {
            motTrouve[i] = lettre;
            verifPourDesincrementer = 1;
        }
    }
    if (verifPourDesincrementer == 0)
    {
        *compteurPtr = *compteurPtr - 1;
    }
}

/*-------------------------------------------------------------------------------------*/

void affichageDemande(char *motTrouve, const char *mot, int compteur, int *compteurPtr)
{
    printf("\nIl vous reste %d coups à jouer\n", compteur);
    printf("Quel est le mot secret ? %s\n", motTrouve);
    printf("Proposez une lettre : ");
    char lettreUser = lireCaractere();
    lettreDansMot(lettreUser, motTrouve, mot , compteurPtr);

}

/*-------------------------------------------------------------------------------------*/

void menu(int *choix)
{
    printf("Bienvenue dans le Pendu !\n\n");
    printf("|------MENU-------|\n");
    printf("|[1] Solo (défaut)|\n");
    printf("|[2] Duo          |\n");           
    printf("|-----------------|\n\n");
    printf("Quel mode choisissez vous ?\n");
    scanf("%d", choix);
}

/*-------------------------------------------------------------------------------------*/

void soloMode()
{   
    char running = 'y'; 
    printf(" ____   ___  _     ___\n");
    printf("/ ___| / _ \\| |   / _ \\\n");
    printf("\\___ \\| | | | |  | | | |\n");
    printf(" ___) | |_| | |__| |_| |\n");
    printf("|____/ \\___/|_____\\___/\n");
    printf("Vous avez 10 coups pour trouver le mot mystère !\nLe mot mystère comporte uniquement des lettres en majuscules.\n");



    while (running != 'n')
        {
            char mot[100] = {0};
            choisirMot(mot);
            int taille = strlen(mot) +1;
            int compteur = 10;
            int *compteurPtr = &compteur;
            char *motTrouve = NULL;
            motTrouve = malloc(taille * sizeof(char));
            
            if (motTrouve == NULL )
            {
                printf("L'allocation a échoué.");
                exit(0);
            }
            initialiserMotTrouve(mot, motTrouve);
            while (strcmp(mot, motTrouve) != 0 && compteur > 0)
            {
                affichageDemande(motTrouve, mot, compteur, compteurPtr);
            }

            if (strcmp(mot, motTrouve) == 0)
            {
                printf("\n\nGagné ! Le mot secret était bien : %s\n\n", mot);
            }
            else
            {
                printf("\n\nPerdu ! Le mot secret était : %s\n\n", mot);
            }

            free(motTrouve);

            printf("\n\nVoulez-vous refaire une partie ? (Y/n)\n");
            scanf("%c", &running);
        }
        printf("\n\nA bientot !\n");
}

/*-------------------------------------------------------------------------------------*/

void duoMode()
{
    char joueur1[50], joueur2[50];    
    char mot[100];
    char *motTrouve = NULL;
    int compteur = 10;
    int *compteurPtr = &compteur;

    printf(" ____  _   _  ___\n");
    printf("|  _ \\| | | |/ _ \\ \n");
    printf("| | | | | | | | | |\n");
    printf("| |_| | |_| | |_| |\n");
    printf("|____/ \\___/ \\___/\n");
    printf("Quel est est le Pseudo du joueur 1 ?\n");
    scanf("%s", joueur1);
    printf("Quel est le pseudo du joueur 2 ?\n");
    scanf("%s", joueur2);
    printf("Bonjour %s et %s !\n\n", joueur1, joueur2);
    printf("%s tape le mot mystère (en majuscule). %s ferme les yeux...\n", joueur1, joueur2);
    scanf("%s", mot);
    maj(mot);
    int taille = strlen(mot) +1;
    motTrouve = malloc(taille * sizeof(char));
    initialiserMotTrouve(mot, motTrouve);
    while (strcmp(mot, motTrouve) != 0 && compteur > 0)
            {
                affichageDemande(motTrouve, mot, compteur, compteurPtr);
            }

            if (strcmp(mot, motTrouve) == 0)
            {
                printf("\n\nGagné ! Le mot secret était bien : %s\n\n", mot);
            }
            else
            {
                printf("\n\nPerdu ! Le mot secret était : %s\n\n", mot);
            }

            free(motTrouve);

}

/*-------------------------------------------------------------------------------------*/

void maj(char mot[])
{
    int i = 0;
    for (i = 0; i < strlen(mot); i++)
    {
        mot[i] = toupper(mot[i]);
    }
}