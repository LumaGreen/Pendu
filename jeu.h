#ifndef DEF_JEU
#define DEF_JEU

#include<ctype.h>
#include <time.h>
#include<string.h>
char lireCaractere();
void affiche(char tableau[], int tailleTableau);
void initialiserMotTrouve(char *mot, char *motTrouve);
void lettreDansMot(char lettre, char *motTrouve, const char *mot, int *compteurPtr);
void affichageDemande(char *motTrouve, const char *mot, int compteur, int *compteurPtr);
void menu(int *choix);
void duoMode();
void soloMode();
void maj(char mot[]);

#endif
