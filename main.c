#include <stdio.h>
#include <stdlib.h>

void hub();

void jeu();

void aide();

void scanfclear();

int main() {
    //hub();
    jeu();
    return 0;
}

/*
void hub() {
    //Initialisation des variables
    int choix;
    //Initialisation des variables

    do {
        printf("Bataille Navale!\n\n\n\n");
        printf("Options:\n");
        printf("1-jouer\n"
               "2-classement\n"
               "3-aide\n"
               "4-quitter");
        scanf("%d", &choix);
        scanfclear();
    } while (choix < 1 || choix > 3);
    switch (choix) {
        case 1:
            if (choix == 1)
                jeu();
            break;
        case 2:
            if (choix == 2)
                //classement();
                printf("classement");
            break;
        case 3:
            if (choix == 3)
                aide();
            break;
        case 4:
            if (choix == 4)
                system("pause");
            break;
        case 5:
            if (choix < 1 || choix > 5) {
                printf("Veillez entrer une valeur parmis celles notées dans les options.");
            }
            break;
    }
}

void aide() {
    int choix;
    system("cls");

    printf("Voici les regles du jeu:\n"
           "\n1."
           "\n2."
           "\n3."
           "\n4."
           "\n5."
           "\n6."
           "\n7."
           "\n8."
           "\n9."
           "\n10."
           "\n\n");

    printf("Voulez-vous quitter le jeu?\n"
           "\n1 - Revenir sur le menu principal"
           "\n2 - Quitter");
    scanfclear();
    scanf("%d", choix);
    switch (choix) {
        case 1:
            hub();
            break;
        case 2:
            system("pause");
            break;
    }
}
*/
void jeu(int table[10][10]) {

    printf("\n");
    printf("     A   B   C   D   E   F   G   H   I   J");
    printf("\n");
    printf("  ");
    for (int ligne = 0; ligne < 41; ++ligne) {
        printf("=");
    }
    printf("\n");
    for (int x = 0; x < 10; ++x) {
        printf("%3d", x + 1);
        for (int y = 0; y < 10; ++y) {
            switch (table[x][y]) {
                case 0:
                    printf("|   ");
                    break;

                case 1:
                    printf("|   ");
                    break;

                case 2:
                    printf("|   ");
                    break;

                case 3:
                    printf("|   ");
                    break;

                case 4:
                    printf("|   ");
                    break;
            }
        }
        printf("|\n");
        printf("  ");
        for (int col = 0; col < 41; ++col) {
            printf("=");
            //printf("\n");
        }
        printf("\n");
        printf(" ");
    }
}

void scanfclear() {
    int voider;
    while ((voider = getchar()) != EOF && voider != '\n');
}