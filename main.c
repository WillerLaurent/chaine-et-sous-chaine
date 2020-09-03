#include <stdio.h>
#include <stdlib.h>

void verifSousChaine(char chaine[], char sousChaine[]);
int calculeLongueurMot(char *mot);
void enleveRetourLigne(char *mot);



int main()
{
    char mot1[50], mot2[50];

    printf("Entrez un mot : \n");
    fgets(mot1, 50, stdin);

    printf("Entrez un second mot : \n");
    fgets(mot2, 50, stdin);

    enleveRetourLigne(mot1);
    enleveRetourLigne(mot2);

    verifSousChaine(mot1, mot2);

    return 0;
}

void enleveRetourLigne(char *mot)
{
    int i = 0;
    char caractere = 0;

    do
    {
        caractere = mot[i];

        if(caractere == '\n')
        {
            mot[i] = '\0';
        }
        i++;
    }
    while(caractere != '\0');
}

int calculeLongueurMot(char *mot)
{
    int longueur = 0;
    char caractereActuel = 0;

    do
    {
        caractereActuel = mot[longueur];
        longueur++;
    }
    while(caractereActuel != '\0');
    longueur--;

    return longueur;
}

void verifSousChaine(char chaine[], char sousChaine[])
{
    int result = 1, i = 0, j = 0, n = 0, longueurSousChaine;

    longueurSousChaine = calculeLongueurMot(sousChaine);

    while(sousChaine[0] != chaine[n])
    {
        n++;

        if(chaine[n] == '\0')
        {
            result = 0;
        }
    }

    for(i=n, j=0; j<longueurSousChaine; i++,j++)
    {
        if(chaine[i] != sousChaine[j])
        {
            result = 0;
            break;
        }
    }

    if(result == 1)
    {
        printf("%s est une sous-chaine de %s.", sousChaine, chaine);
    }

     if(result == 0)
    {
        printf("%s n'est pas une sous-chaine de %s.", sousChaine, chaine);
    }



}
