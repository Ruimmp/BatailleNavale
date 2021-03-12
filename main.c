/*
 * @Title : Bataille Navale
 * @Author : MONTEIRO Rui
 * @Version : 0.1
 * @Date : 12.03.2021
 * @Date de fin (version 0.1) : 12.03.2021
 * @Description : Programme effectué dans le cadre du MA-20 et I-CT 431 du CPNV permettant de jouer à la bataille
 * navale en solo avec une grille de base et les bateaux placés déjà placés sur la grille.
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <unistd.h>

void hub();

void jeu();

void aide();

void scanfclear();

void table();

void victoire();

char iden[24];

void identification();

int main() {
    setbuf(stdout, 0);
    //Pour faire afficher tous les caractères spéciaux
    SetConsoleTitle("Bataille navale Monteiro Rui");
    SetConsoleOutputCP(CP_UTF8);

    hub();
    //jeu();
    return 0;
}

void hub() {
    system("cls");
    //Initialisation des variables
    int choix;
    //Initialisation des variables


    do {
        printf("Identifié en tant que: %s", iden);
        printf("\n\n\n\nBataille Navale!\n\n\n\n");
        printf("Options:\n");
        printf("1-jouer\n"
               "2-classement\n"
               "3-aide\n"
               "4-quitter\n"
               "\n%c", 254);
        scanf("%d", &choix);
        scanfclear();
    } while (choix < 1 || choix > 5);
    switch (choix) {
//=== === === === === === === === === === === === === === === === === === === === === === === === ===
        //cas pour jouer à la bataille navale
        case 1:
            jeu();
            break;
            //cas pour jouer à la bataille navale
//=== === === === === === === === === === === === === === === === === === === === === === === === ===
            //cas pour voir le classemnt
        case 2:
            printf("classement");
            break;
            //cas pour voir le classemnt
//=== === === === === === === === === === === === === === === === === === === === === === === === ===
            //cas pour afficher l'aide
        case 3:
            system("cls");
            aide();
            system("cls");
            break;
            //cas pour afficher l'aide
//=== === === === === === === === === === === === === === === === === === === === === === === === ===
            //cas pour sortir du jeu
        case 4:
            system("pause");
            break;
            //cas pour afficher sortir du jeu
//=== === === === === === === === === === === === === === === === === === === === === === === === ===
        case 5:
            identification();
            break;
//=== === === === === === === === === === === === === === === === === === === === === === === === ===
            //cas pour dire que la valeure entrée n'est pas valable
        default:
            printf("Veillez entrer une valeur parmis celles notées dans les options.");
            break;
            //cas pour dire que la valeure entrée n'est pas valable
//=== === === === === === === === === === === === === === === === === === === === === === === === ===
    }
}

void aide() {
    system("cls");

    int choix;

    printf("   _   _     _      \n"
           "  /_\\ (_) __| | ___ \n"
           " //_\\\\| |/ _` |/ _ \\\n"
           "/  _  \\ | (_| |  __/\n"
           "\\_/ \\_/_|\\__,_|\\___|\n\n");
    printf("Voici l'aide du jeu!'"
           "\n\n"
           "Au début du jeu, les bateaux du jeu seront déjà placés dans la grille donc votre tache,"
           "est de toucher tous les bateaux et lors que cela arrive, vou gagnerez le jeu."
           "Bien entendu, le joueur ne voit pas les bateaux de la grille adverse."
           "Pour tirer, il faut citer les coordonnées d’un emplacement comprenant un chiffre et une lettre à la fois.\n"
           "\n"
           "Par exemple:\n"
           "    > Choisissez une lettre entre A - J.\n"
           "        - 1"
           "    > Choisissez un chiffre entre 1 - 10.\n"
           "        - A"
           "Si le bateau de votre opposant se trouve à cette position alors il est touché"
           "Pour couler le navire, il faut le toucher entièrement.\n"
           "C’est-à-dire qu’un bateau prenant 5 cases doit être atteint en ses 5 cases pour être coulé.\n"
    );

    printf("Voulez-vous quitter le jeu?\n"
           "\n1 - Oui."
           "\n2 - Non et revenir au menu principal.\n"
           "\n➩");
    scanf("%d", &choix);
    switch (choix) {
        case 1:
            system("pause");
            break;
        case 2:
            hub();
            break;
    }
}


void table(int table[10][10]) {
    system("cls");

    printf("\n");
    printf("     A   B   C   D   E   F   G   H   I   J");
    printf("\n");
    printf("  ");
    for (int ligne = 0; ligne < 42; ++ligne) {
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
                    //cas pour dire que le bateau a été touché
                case 2:
                    printf("| ! ");
                    break;
                    //cas pour dire que le tire est à l'eau
                case 3:
                    printf("| ~ ");
                    break;
                    //cas pour dire que le bateau est coullé
                case 4:
                    printf("| 0 ");
                    break;
            }
        }
        printf("|\n");
        printf("  ");
        for (int col = 0; col < 42; ++col) {
            printf("=");
            //printf("\n");
        }
        printf("\n");
        printf(" ");
    }
}

void jeu() {
    system("cls");

    char hor = 0;
    int line;

    //création de la variable pour les bateuax du jeu
    int croiseur = 0;           //4 cases
    int porteavions = 0;        //5 cases
    int contretorpilleurs1 = 0; //3 cases
    int contretorpilleurs2 = 0; //3 cases
    int torpilleur = 0;         //2 cases
    //création de la variable pour les bateuax du jeu

    //céation du tableau
    int map1[10][10] = {0};
    //céation du tableau

    //Création de l'emplacement des bateuax
//=== === === === === === === === === === === === === === === === === === === === === === === === ===
    //croiseur
    map1[0][1] = 1;
    map1[0][2] = 1;
    map1[0][3] = 1;
    map1[0][4] = 1;
    //croiseur
//=== === === === === === === === === === === === === === === === === === === === === === === === ===
    //porteavions
    map1[5][1] = 1;
    map1[6][1] = 1;
    map1[7][1] = 1;
    map1[8][1] = 1;
    map1[9][1] = 1;
    //porteavions
//=== === === === === === === === === === === === === === === === === === === === === === === === ===
    //contretorpilleurs1
    map1[4][5] = 1;
    map1[4][6] = 1;
    map1[4][7] = 1;
    //contretorpilleurs1
//=== === === === === === === === === === === === === === === === === === === === === === === === ===
    //contretorpilleurs2
    map1[8][5] = 1;
    map1[8][6] = 1;
    map1[8][7] = 1;
    //contretorpilleurs2
//=== === === === === === === === === === === === === === === === === === === === === === === === ===
    //torpilleur
    map1[5][3] = 1;
    map1[5][4] = 1;
    //torpilleur
//=== === === === === === === === === === === === === === === === === === === === === === === === ===
    //Création de l'emplacement des bateuax

    do {
        table(map1);
        do {
            printf("Veillez entrer les cases que vous voulez toucher :"
                   //printf("Veillez entrer une valeur horizontale (1 - 10)"
                   "\n"
                   "➩ ");
            scanf("%d", &line);
            fflush(stdin);
        } while (line < 1 || line > 10);
        do {
            table(map1);
            printf("Veillez entrer une valeur horizontale (A - J)"
                   "\n"
                   "> ");
            scanf("%c", &hor);
            fflush(stdin);
        } while (hor < 65 || hor > 75);

        if (map1[line - 1][hor - 65] == 1) {
            map1[line - 1][hor - 65] = 2;
            printf("Bien joué, vous avez touché une partie du bateau!\n");
            //Petite pause pour afficher le printf et qu'on puisse le lire
            Sleep(1500);
            //Petite pause pour afficher le printf et qu'on puisse le lire
        }

        if (map1[line - 1][hor - 65] == 0) {
            map1[line - 1][hor - 65] = 3;
            printf("Bien essayé!\n");
            //Petite pause pour afficher le printf et qu'on puisse le lire
            Sleep(1500);
            //Petite pause pour afficher le printf et qu'on puisse le lire
        }
        if (map1[line - 1][hor - 65] == 0) {
            map1[line - 1][hor - 65] = 3;
            printf("\nEssayez a nouveau!\n");
            sleep(1500);
        }

        //Variables pour afficher dans la grille quand le bateau est completement abatu ou on la touché
//=== === === === === === === === === === === === === === === === === === === === === === === === ===
        if (map1[5][3] == 2 && map1[5][4] == 2) {
            map1[5][3] = 4;
            map1[5][4] = 4;
            torpilleur = 1;
        }
//=== === === === === === === === === === === === === === === === === === === === === === === === ===
        if (map1[4][5] == 2 && map1[4][6] == 2 && map1[4][7] == 2) {
            map1[4][5] = 4;
            map1[4][6] = 4;
            map1[4][7] = 4;
            contretorpilleurs1 = 1;
        }
//=== === === === === === === === === === === === === === === === === === === === === === === === ===
        if (map1[8][5] == 2 && map1[8][6] == 2 && map1[8][7] == 2) {
            map1[8][5] = 4;
            map1[8][6] = 4;
            map1[8][7] = 4;
            contretorpilleurs2 = 1;
        }
//=== === === === === === === === === === === === === === === === === === === === === === === === ===
        if (map1[0][1] == 2 && map1[1][2] == 2 && map1[1][3] == 2 && map1[1][4]) {
            map1[0][1] = 4;
            map1[0][2] = 4;
            map1[0][3] = 4;
            map1[0][4] = 4;
            croiseur = 1;
        }
//=== === === === === === === === === === === === === === === === === === === === === === === === ===
        if (map1[5][1] == 2 && map1[6][1] == 2 && map1[7][1] == 2 && map1[8][1] == 2 && map1[9][1] == 2) {
            map1[5][1] = 4;
            map1[6][1] = 4;
            map1[7][1] = 4;
            map1[8][1] = 4;
            map1[9][1] = 4;
            porteavions = 1;
        }
//=== === === === === === === === === === === === === === === === === === === === === === === === ===
    } while (croiseur != 1 && porteavions != 1 && contretorpilleurs1 != 1 && contretorpilleurs2 != 1 &&
             torpilleur != 1);
    victoire();
}

void victoire() {
    int rejoin = 0;

    system("cls");
    printf("        _      _        _          \n"
           " /\\   /(_) ___| |_ ___ (_)_ __ ___ \n"
           " \\ \\ / / |/ __| __/ _ \\| | '__/ _ \\\n"
           "  \\ V /| | (__| || (_) | | | |  __/\n"
           "   \\_/ |_|\\___|\\__\\___/|_|_|  \\___|\n"
           "                                   ");

    printf("\n\n\n\nVoulez-vous rejouer?\n"
           "\n1-Oui."
           "\n2-Non et retourner au menu principal.\n"
           "\n");
    scanf("%d", &rejoin);
    if (rejoin == 1) {
        jeu();
    } else if (rejoin == 2) {
        main();
    }
    sleep(10000);
}

void identification() {
    system("cls");

    printf("  _____    _            _   _  __ _           _   _             \n"
           "  \\_   \\__| | ___ _ __ | |_(_)/ _(_) ___ __ _| |_(_) ___  _ __  \n"
           "   / /\\/ _` |/ _ \\ '_ \\| __| | |_| |/ __/ _` | __| |/ _ \\| '_ \\ \n"
           "/\\/ /_| (_| |  __/ | | | |_| |  _| | (_| (_| | |_| | (_) | | | |\n"
           "\\____/ \\__,_|\\___|_| |_|\\__|_|_| |_|\\___\\__,_|\\__|_|\\___/|_| |_|\n"
           "                                                                \n\n\n\n\n");
    printf("Veuillez vou identifier en metant votre prénom sans espacements:\n");
    fflush(stdin);
    scanf("%s", iden);
    fflush(stdin);

    system("pause");

    hub();
}

void scanfclear() {
    int voider;
    while ((voider = getchar()) != EOF && voider != '\n');
}