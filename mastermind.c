#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

int i, j;
char c;
char colours[] = {'R','B','V','J','O','N'};


// nombre de couleurs à rentrer

int nb;
printf("entrez le nombre de couleurs à deviner :");
scanf("%d", &nb);

// génération aléatoire d'une chaîne de charactère 

char rand_string[nb];
srand(time(NULL));
for(int i=0; i<nb; i++)
{   
    j = rand()%6;
    rand_string[i] = colours[j];
}

// nombre d'essaies

int tries;
int turn=0;
printf("entrez un nombre d'essaies maximum :");
scanf("%d", &tries);

char player_string[nb];

while(turn < tries)
{

    // demander au joueur de rentrer une chaîne de caractères 
    printf("entrez une chaîne de charactère :");
    scanf("%s", player_string);

    // comparaison 

    int B = 0;
    int N = 0;

    int a=0;

    int cases_prises[nb]; /* pour que les couleurs qui sont bonnes ne puissent pas 
    être considérées comme "mal placées" */

    for(int h=0; h<nb; h++)
    {
        if(player_string[h] == rand_string[h])
        {
            B+=1;
            cases_prises[h]=1;
        }
        else{
            for(int q=0; q<nb; q++)
            {
                if(player_string[h] == rand_string[q] && cases_prises[q] != 1 )  
                {
                    N+=1;
                    break;
                }
            }
        }
    }

    for(int k=0; k<nb; k++)
    {
        cases_prises[k]=0;
    }

    for(int b=0; b<B; b++)
    {
        printf("B");
    }
    for(int n=0; n<N; n++)
    {
        printf("N");
    }
    printf("\n");

    if (nb == B)
    {
        printf("vous avez gagné\n");
    }

turn+=1;
}
printf("la réponse était : %s ", rand_string);
return 0;
}