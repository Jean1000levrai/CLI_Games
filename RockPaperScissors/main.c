#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


int pierreFeuilleOuCiseaux();
int jeu(int j1, int j2);
void affichage(int *signe);

int main() {
    int signe;
    int nbPartie;
    printf("combien de partie: \n");
    scanf("%d", &nbPartie);
    for (int i = 0; i<nbPartie; i++) {
        affichage(&signe);
    }
    

    return 0;
}


int pierreFeuilleOuCiseaux(){
    /*
    0 : pierre; 1 : feuille; 2: ciseaux
    */

    srand(time(NULL));
    int truc = rand()%3;
    return truc;
}

int jeu(int j1, int j2){
    if (((j1 == 0) && (j2 == 2))){
        return 1;
    }else if ((j1 == 1) && (j2 == 0)) {
        return 1;
    }else if ((j1 == 2) && (j1 == 1)) {
        return 1;
    }
    else if (j1 == j2) {
        return 0;
    }else {
        return -1;
    }
}

void affichage(int *signe){
    int signeIa = pierreFeuilleOuCiseaux();

    printf("SHI! ");
    fflush(stdout);
    sleep(1);

    printf("FU!\n");
    fflush(stdout);
    sleep(1);

    printf("(SAISIR UN SIGNE:\n0: PIERRE\n1: FEUILLE\n2: CISEAUX\n)");
    fflush(stdout);
    scanf("%d", signe);

    printf("MI !");
    fflush(stdout);
    sleep(1);

    printf("l'ordinateur réfléchi ");
    fflush(stdout);
    for (int i = 0; i < 5; i++) {
        sleep(1);
        printf(".");
        fflush(stdout);
    }
    printf("\n");

    if (jeu(*signe, signeIa)>0) {
        printf("GAGNÉ !");
    }else if (jeu(*signe, signeIa)<0) {
        printf("PERDU !");
    }else {
        printf("Égalité");
    }
    printf("l'ordinateur a fait:");
    switch (signeIa){
        case 0:
            printf("pierre");
            break;
        case 1:
            printf("feuille");
            break;
        case 2:
            printf("ciseaux");
            break;
    }
    
    printf("\n");
}
