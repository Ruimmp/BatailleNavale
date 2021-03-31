/*
 * @Title : Bataille Navale
 * @Author : MONTEIRO Rui
 * @Version : 0.1
 * @Date de début de projet : 17.02.2021
 * @Date : 12.03.2021
 * @Date de fin (version 0.1) : 12.03.2021
 * @Description : Programme effectué dans le cadre du MA-20 et I-CT 431 du CPNV permettant de jouer à la bataille
 * navale en solo avec une grille de base et les bateaux placés déjà placés sur la grille.
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <unistd.h>
#include <conio.h>
#include <time.h>

void menu();
void jeu();
void aide();
void table();
void Victory();
void Identification();
void red();
void blue();
void black();
void green();
void yellow();
void white();
void reset();
void RandomFile();
void map(int Cotes);

int affgrille(int hauteur, int largeur);

#pragma execution_character_set("utf-8")
#define STLC 218 // ┌, Single Top Left Corner
#define STRC 191 // ┐, Single Top Right Corner
#define SBLC 192 // └, Single Bottom Left Corner
#define SBRC 217 // ┘, Single Bottom Right Corner
#define SVSB 179 // │, Single Vertical Simple Border
#define SVRB 180 // ┤, Single Vertical Right Border
#define SVLB 195 // ├, Single Vertical Left Border
#define SHSB 196 // ─, Single Horizontal Simple Border
#define SHBB 193 // ┴, Single Horizontal Bottom Border
#define SHTB 194 // ┬, Single Horizontal Top Border
#define SC   197 // ┼, Single Center

#define cote 10

int datagrille[10][10]; ///bato 1= 1 / compteurbato1   bato2= 2 / compteurbato2   bato3= 3 / compteurbato3

char iden[24];

int main() {
    setbuf(stdout, 0);
    //Pour faire afficher tous les caractères spéciaux
    SetConsoleTitle("Bataille navale Monteiro Rui");
    SetConsoleOutputCP(CP_UTF8);
    menu();
    return 0;
}

void menu() {
    system("cls");

    //Initialisation des variables
    int choix;
    //Initialisation des variables

    do {
        printf("\n\n\n\n\n");
        blue();
        printf("  ██████╗  █████╗ ████████╗ █████╗ ██╗██╗     ██╗     ███████╗    ███╗   ██╗ █████╗ ██╗   ██╗ █████╗ ██╗     ███████╗\n");
        red();
        printf("  ██╔══██╗██╔══██╗╚══██╔══╝██╔══██╗██║██║     ██║     ██╔════╝    ████╗  ██║██╔══██╗██║   ██║██╔══██╗██║     ██╔════╝\n");
        blue();
        printf("  ██████╔╝███████║   ██║   ███████║██║██║     ██║     █████╗      ██╔██╗ ██║███████║██║   ██║███████║██║     █████╗  \n");
        red();
        printf("  ██╔══██╗██╔══██║   ██║   ██╔══██║██║██║     ██║     ██╔══╝      ██║╚██╗██║██╔══██║╚██╗ ██╔╝██╔══██║██║     ██╔══╝  \n");
        blue();
        printf("  ██████╔╝██║  ██║   ██║   ██║  ██║██║███████╗███████╗███████╗    ██║ ╚████║██║  ██║ ╚████╔╝ ██║  ██║███████╗███████╗\n");
        red();
        printf("  ╚═════╝ ╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝╚═╝╚══════╝╚══════╝╚══════╝    ╚═╝  ╚═══╝╚═╝  ╚═╝  ╚═══╝  ╚═╝  ╚═╝╚══════╝╚══════╝\n");
        blue();
        printf("\n\n\n");
        reset();
        printf("                                               ");
        printf("Identifié en tant que: %s\n\n"
               "                                                       ");
        printf("Options:\n\n"
               "                                                       ");
        printf("1-jouer\n"
               "                                                       ");
        printf("2-classement\n"
               "                                                       ");
        printf("3-aide\n"
               "                                                       ");
        printf("4-quitter\n\n"
               //pour afficher un caractére invisible
               "%c", iden, 254
                //pour afficher un caractére invisible
        );
        scanf("%d", &choix);
        fflush(stdin);
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
            Identification();
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

void RandomFile () {
    int nombrealeatoire; //nombre aléatoire
    char c;

    srand((unsigned) time(NULL));
    nombrealeatoire = 1 + rand() % 4; //Choisit un nombre aléatoire entre 1 et 4
    FILE *fichier = NULL;
    switch (nombrealeatoire) {
        //Choix d'une des 4 grille
        case 1:
            fichier = fopen("Grilles/1.txt", "r");
            break;
        case 2:
            fichier = fopen("Grilles/2.txt", "r");
            break;
        case 3:
            fichier = fopen("Grilles/3.txt", "r");
            break;
        case 4:
            fichier = fopen("Grilles/4.txt", "r");
            break;
        case 5:
            fichier = fopen("Grilles/5.txt", "r");
            break;
    }
}


int affgrille(int hauteur, int largeur) {
    switch (datagrille[hauteur - 1][largeur - 1]) {
        case 0:
            printf(" "); //cas standard
            break;
        case 1: // si il y a un bateau
            printf(" ");
            break;
        case 2: // si il y a un bateau
            printf(" ");
            break;
        case 3: // si il y a un bateau
            printf(" ");
            break;
        case 10://A lo
            printf("O");
            break;
        case 11://touché
            printf("X");
            break;
        case 12://touché
            printf("X");
            break;
        case 13://touché
            printf("X");
            break;
        case 21://coulé
            printf("%c", 219);
            break;
        case 22://coulé
            printf("%c", 219);
            break;
        case 23://coulé
            printf("%c", 219);
            break;
    }
}


void top(int cotes) {
    SetConsoleOutputCP(437); // For semi-graphic characters
    printf("\n");
    printf("   %c", STLC);
    for (int i = 0; i <= cotes - 2; i++) {
        printf("%c%c%c%c", SHSB, SHSB, SHSB, SHTB);
    }
    printf("%c%c%c%c", SHSB, SHSB, SHSB, STRC);
}                          // ┌───┬───┐

int mid(int cotes, int i, int ligne) {
    int a = 1;
    if (i <= 9) {
        printf("\n %d %c", i - 1, SVSB);
    } else if (i == 10) {
        printf("\n %d %c", i - 1, SVSB);
    }
    for (int i = -1; i <= cotes - 3; i++) {
        printf(" ");
        affgrille(ligne, a);
        printf(" %c", SVSB);
        a++;
    }
    printf(" ");
    affgrille(ligne, a);
    printf(" %c", SVSB);

}         // │   │   │

void midmid(int cotes) {
    printf("\n   %c", SVLB);
    for (int i = 0; i <= cotes - 2; i++) {
        printf("%c%c%c%c", SHSB, SHSB, SHSB, SC);
    }
    printf("%c%c%c%c", SHSB, SHSB, SHSB, SVRB);
}                       // ├───┼───┤

void bootom(int cotes) {
    printf("\n   %c", SBLC);
    for (int i = 0; i <= cotes - 2; i++) {
        printf("%c%c%c%c", SHSB, SHSB, SHSB, SHBB);
    }
    printf("%c%c%c%c", SHSB, SHSB, SHSB, SBRC);
}                       // └───┴───┘

void map(int Cotes) {
    printf("     A   B   C   D   E   F   G   H   I   J");
    top(Cotes);///OK
    int j;
    int k = 0;
    for (j = 1; j < Cotes; j++) {
        mid(Cotes, j, j);    ///OK
        midmid(Cotes); ///OK
        k = j;
    }

    mid(Cotes, j, k + 1);///OK
    bootom(Cotes); ///OK
    printf("\n");
}

void jouer() {
    printf("INISTALISATION...");
    shipfich();
    system("cls");
    char tir[5];
    int num = 0;
    int lettre;
    int gagner = 0;
    int compteurbato1 = 0;
    int compteurbato2 = 0;
    int compteurbato3 = 0;
    while (gagner == 0) {

        grille(cote);
        // ajouter un syteme qui sait si on a donner la lettre en premier ou pas (A=97/Z=122)
        SetConsoleOutputCP(65001);
        printf("Où voulez-vous tirer ?\n");
        printf("La lettre en premier\n");
        do {
            tir[2] = 0;
            scanf("%s", &tir);
            if (tir[0] < 97 || tir[0] > 106 || tir[1] < 49 || tir[1] > 57 || tir[2] != 0) {
                printf("Ce n'est pas une valeur d'une case !\n");
                printf("Où voulez-vous tirer ?\n");
                printf("La lettre en premier\n");
            }
        } while (tir[0] < 97 || tir[0] > 106 || tir[1] < 48 || tir[1] > 57);
        system("cls");
        lettre = tir[0] - 97;//97 ='a'
        num = tir[1] - 48;


        //si a lo
        if (datagrille[num][lettre] == 0) {
            system("cls");
            SetConsoleOutputCP(65001);
            printf("À l'eau !\n");
            datagrille[num][lettre] = 10;
        }
        //si toucher bato1
        if (datagrille[num][lettre] == 1) {
            system("cls");
            grille(cote);
            if (compteurbato1 != 4) {
                SetConsoleOutputCP(65001);
                system("cls");
                printf("Touché \n");
                datagrille[num][lettre] = 11;
                compteurbato1 += 1;
                if (compteurbato1 == 4) {
                    printf("coulé");
                    for (int i = 0; i < cote; ++i) {
                        for (int j = 0; j < cote; ++j) {
                            if (datagrille[i][j] == 11) {
                                datagrille[i][j] = 21;
                            }
                        }

                    }
                }
                printf(" !\n");
            }
        }
        //si toucher bato2
        if (datagrille[num][lettre] == 2) {
            system("cls");
            grille(cote);
            SetConsoleOutputCP(65001);
            system("cls");
            printf("Touché \n");
            datagrille[num][lettre] = 12;
            compteurbato2 += 1;
            if (compteurbato2 == 3) {
                printf("coulé");
                for (int i = 0; i < cote; ++i) {
                    for (int j = 0; j < cote; ++j) {
                        if (datagrille[i][j] == 12) {
                            datagrille[i][j] = 22;
                        }
                    }

                }
            }
            printf(" !\n");
        }
        //si toucher bato3
        if (datagrille[num][lettre] == 3) {
            system("cls");
            grille(cote);
            SetConsoleOutputCP(65001);
            system("cls");
            printf("Touché \n");
            datagrille[num][lettre] = 13;
            compteurbato3 += 1;
            if (compteurbato3 == 2) {
                printf("coulé");
                for (int i = 0; i < cote; ++i) {
                    for (int j = 0; j < cote; ++j) {
                        if (datagrille[i][j] == 13) {
                            datagrille[i][j] = 23;
                        }
                    }

                }
            }
            printf(" !\n");
        }
        if (compteurbato1 == 4 && compteurbato2 == 3 && compteurbato3 == 2) {
            gagner += 1;
        }
    }
    printf("Vous avez gagner !");
    system("pause");
    menu();
}

//------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------

void aide() {
    system("cls");

    int choix;
    yellow();
    printf("   _   _     _      \n"
           "  /_\\ (_) __| | ___ \n"
           " //_\\\\| |/ _` |/ _ \\\n"
           "/  _  \\ | (_| |  __/\n"
           "\\_/ \\_/_|\\__,_|\\___|\n\n");
    reset();
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n"
           "Au début du jeu, les bateaux du jeu seront déjà placés dans la grille donc votre tache,\n "
           "est de toucher tous les bateaux et lors que cela arrive, vou gagnerez le jeu."
           "Bien entendu, \nle joueur ne voit pas les bateaux de la grille adverse."
           "Pour tirer, \nil faut citer les coordonnées d’un emplacement comprenant un chiffre et une lettre à la fois.\n"
           "Par exemple:\n"
           "    > Choisissez une lettre entre 1 - 10.\n"
           "        - 1\n"
           "    > Choisissez un chiffre entre A - J.\n"
           "        - A\n"
           "Si le bateau de votre opposant se trouve à cette position alors il est touché"
           "Pour couler le navire,\nil faut le toucher entièrement.\n"
           "C’est-à-dire qu’un bateau prenant 5 cases doit être atteint en ses 5 cases pour être coulé.\n\n");
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n");
    yellow();
    printf("Voulez-vous quitter le jeu?\n");
    green();
    printf("\n1 - Non, revenir au menu principal.");
    red();
    printf("\n2 - Oui.\n"
           //pour afficher un caractére invisible
           "%c", 254);
    //pour afficher un caractére invisible
    reset();
    scanf("%d", &choix);
    switch (choix) {
        case 1:
            menu();
            break;
        case 2:
            system("pause");
            break;
    }
}
/*
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
                    //cas pour les coordonnées du bateau
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
            printf("\nVeillez entrer les cases que vous voulez toucher (vertical):"
                   "\n"
                   //pour afficher un caractére invisible
                   "%c", 254);
            //pour afficher un caractére invisible
            scanf("%d", &line);
            fflush(stdin);
        } while (line < 1 || line > 10);
        do {
            table(map1);
            printf("Veillez entrer les cases que vous voulez toucher (horizontal):"
                   "\n"
                   //pour afficher un caractére invisible
                   "%c", 254);
            //pour afficher un caractére invisible
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
        if (map1[0][1] == 2 && map1[0][2] == 2 && map1[0][3] == 2 && map1[0][4]) {
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
    Victory();
}

void Victory() {
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
           "%c", 254);
    scanf("%d", &rejoin);
    if (rejoin == 1) {
        jeu();
    } else if (rejoin == 2) {
        main();
    }
    sleep(10000);
}

void Identification() {
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

    menu();
}

    // pour eviter que le retour a ligne ou tout autre caractere non souhaiter soit pris avec
    for (int i = 0; i < cote; ++i) {
        for (int j = 0; j < cote; ++j) {
            do {
                c = fgetc(fichier);
                datagrille[i][j] = c - 48;
            } while (c <= 32);
        }
    }
    fclose(fichier);
}
*/
void red() { printf("\033[1;31m"); }

void blue() { printf("\033[0;34m"); }

void black() { printf("\033[0;30m"); }

void green() { printf("\033[0;32m"); }

void yellow() { printf("\033[0;33m"); }

void white() { printf("\033[0;37m"); }

void reset() { printf("\033[0m"); }