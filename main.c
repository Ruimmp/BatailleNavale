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
void play();
void aide();
void victory();
void identification();
void randomfile();
void map(int Cotes);
void logs();

//couleures
void red();
void blue();
void bluef();
void black();
void green();
void yellow();
void white();
void reset();
//couleures

int affgrille(int hauteur, int largeur);

int datagrille[10][10];

int compteurbateau1 = 0;
int compteurbateau2 = 0;
int compteurbateau3 = 0;
int compteurbateau4 = 0;
int compteurbateau5 = 0;

int points = 0;

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

char iden[24];

int main() {
    setbuf(stdout, 0);
    //Pour faire afficher tous les caractères spéciaux
    SetConsoleTitle("Bataille navale Monteiro Rui");
    SetConsoleOutputCP(CP_UTF8);
    identification();
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
        printf("  ██╔══██╗██╔══██╗╚══██╔══╝██╔══██╗██║██║     ██║     ██╔════╝    ████╗  ██║██╔══██╗██║   ██║██╔══██╗██║     ██╔════╝\n");
        printf("  ██████╔╝███████║   ██║   ███████║██║██║     ██║     █████╗      ██╔██╗ ██║███████║██║   ██║███████║██║     █████╗  \n");
        printf("  ██╔══██╗██╔══██║   ██║   ██╔══██║██║██║     ██║     ██╔══╝      ██║╚██╗██║██╔══██║╚██╗ ██╔╝██╔══██║██║     ██╔══╝  \n");
        printf("  ██████╔╝██║  ██║   ██║   ██║  ██║██║███████╗███████╗███████╗    ██║ ╚████║██║  ██║ ╚████╔╝ ██║  ██║███████╗███████╗\n");
        printf("  ╚═════╝ ╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝╚═╝╚══════╝╚══════╝╚══════╝    ╚═╝  ╚═══╝╚═╝  ╚═╝  ╚═══╝  ╚═╝  ╚═╝╚══════╝╚══════╝\n");
        reset();
        printf("\n\n\n");
        reset();
        printf("                                               Identifié en tant que: %s\n\n", iden);
        printf("                                                       Options:\n\n");
        printf("                                                       1-jouer\n");
        printf("                                                       2-classement\n");
        printf("                                                       3-aide\n");
        printf("                                                       4-quitter\n");
        printf("                                                       5-identification\n");
        printf("                                                       %c", 254);

        scanf("%d", &choix);
        fflush(stdin);
    } while (choix < 1 || choix > 5);
    switch (choix) {
//=== === === === === === === === === === === === === === === === === === === === === === === === ===
        //cas pour jouer à la bataille navale
        case 1:
            play();
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
    yellow();
    printf(" █████╗ ██╗██████╗ ███████╗\n"
           "██╔══██╗██║██╔══██╗██╔════╝\n"
           "███████║██║██║  ██║█████╗  \n"
           "██╔══██║██║██║  ██║██╔══╝  \n"
           "██║  ██║██║██████╔╝███████╗\n"
           "╚═╝  ╚═╝╚═╝╚═════╝ ╚══════╝\n\n");
    reset();
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n"
           "Au début du jeu, les bateaux du jeu seront déjà placés dans la grille donc votre tache,\n "
           "est de toucher tous les bateaux et lors que cela arrive, vou gagnerez le jeu."
           "Bien entendu, \nle joueur ne voit pas les bateaux de la grille adverse."
           "Pour tirer, \nil faut citer les coordonnées d’un emplacement comprenant un chiffre et une lettre à la fois.\n"
           "Par exemple:\n"
           "    > Tirez sur une des cases (lettre en premier et minuscule)\n"
           "        - a0\n"
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

void identification() {
    system("cls");

    printf("\n\n"
           "          ██╗██████╗ ███████╗███╗   ██╗████████╗██╗███████╗██╗ ██████╗ █████╗ ████████╗██╗ ██████╗ ███╗   ██╗\n"
           "          ██║██╔══██╗██╔════╝████╗  ██║╚══██╔══╝██║██╔════╝██║██╔════╝██╔══██╗╚══██╔══╝██║██╔═══██╗████╗  ██║\n"
           "          ██║██║  ██║█████╗  ██╔██╗ ██║   ██║   ██║█████╗  ██║██║     ███████║   ██║   ██║██║   ██║██╔██╗ ██║\n"
           "          ██║██║  ██║██╔══╝  ██║╚██╗██║   ██║   ██║██╔══╝  ██║██║     ██╔══██║   ██║   ██║██║   ██║██║╚██╗██║\n"
           "          ██║██████╔╝███████╗██║ ╚████║   ██║   ██║██║     ██║╚██████╗██║  ██║   ██║   ██║╚██████╔╝██║ ╚████║\n"
           "          ╚═╝╚═════╝ ╚══════╝╚═╝  ╚═══╝   ╚═╝   ╚═╝╚═╝     ╚═╝ ╚═════╝╚═╝  ╚═╝   ╚═╝   ╚═╝ ╚═════╝ ╚═╝  ╚═══╝\n\n\n");
    printf("                         Veuillez vou identifier en metant votre prénom sans espacements:\n");
    fflush(stdin);
    scanf("                                                      %s", iden);
    fflush(stdin);
    system("pause");
    menu();
}

void randomfile() {
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
        case 4: // si il y a un bateau
            printf(" ");
            break;
        case 5: // si il y a un bateau
            printf(" ");
            break;
        case 10://A l'eau
            blue();
            printf("%c", 219);
            bluef();
            break;
        case 11://touché
            yellow();
            printf("%c", 219);
            bluef();
            break;
        case 12://touché
            yellow();
            printf("%c", 219);
            bluef();
            break;
        case 13://touché
            yellow();
            printf("%c", 219);
            bluef();
            break;
        case 14://touché
            yellow();
            printf("%c", 219);
            bluef();
            break;
        case 15://touché
            yellow();
            printf("%c", 219);
            bluef();
            break;
        case 21://coulé
            red();
            printf("%c", 219);
            bluef();
            break;
        case 22://coulé
            red();
            printf("%c", 219);
            bluef();
            break;
        case 23://coulé
            red();
            printf("%c", 219);
            bluef();
            break;
        case 24://coulé
            red();
            printf("%c", 219);
            bluef();
            break;
        case 25://coulé
            red();
            printf("%c", 219);
            bluef();
            break;
            reset();
    }
}

//Formation de la grille
void top(int cotes) {
    bluef();
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
    reset();
}                       // └───┴───┘

void map(int Cotes) {
    bluef();
    printf("     A   B   C   D   E   F   G   H   I   J");
    top(Cotes);
    int j;
    int k = 0;
    for (j = 1; j < Cotes; j++) {
        mid(Cotes, j, j);
        midmid(Cotes);
        k = j;
    }
    mid(Cotes, j, k + 1);
    bootom(Cotes);
    printf("\n");
    reset();
}

void play() {
    printf("INISTALISATION...");
    randomfile();
    system("cls");
    char tir[5];
    int num = 0;
    int lettre;
    int gagner = 0;
    while (gagner == 0) {

        map(cote);

        // ajouter un syteme qui sait si on a donner la lettre en premier ou pas (A=97/Z=122)
        SetConsoleOutputCP(65001);
        printf("\n> Tirez sur une des cases (lettre en premier et minuscule)\n");
        do {
            tir[2] = 0;
            scanf("%s", &tir);
            if (tir[0] < 97 || tir[0] > 106 || tir[1] < 49 || tir[1] > 57 || tir[2] != 0) {
                printf("\n> Ce n'est pas une valeur d'une case !\n");
                printf("> Tirez sur une des cases (lettre en premier et minuscule)\n");
            }
        } while (tir[0] < 97 || tir[0] > 106 || tir[1] < 48 || tir[1] > 57);
        system("cls");
        lettre = tir[0] - 97;//97 ='a'
        num = tir[1] - 48;

        //si a l'eau
        if (datagrille[num][lettre] == 0) {
            system("cls");
            SetConsoleOutputCP(65001);
            printf("À l'eau !\n");
            datagrille[num][lettre] = 10;
        }
        //si toucher bateau1
        if (datagrille[num][lettre] == 1) {
            system("cls");
            map(cote);
            if (compteurbateau1 != 4) {
                SetConsoleOutputCP(65001);
                system("cls");
                printf("Touché \n");
                datagrille[num][lettre] = 11;
                compteurbateau1 += 1;
                if (compteurbateau1 == 2) {
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
        //si toucher bateau2
        if (datagrille[num][lettre] == 2) {
            system("cls");
            map(cote);
            SetConsoleOutputCP(65001);
            system("cls");
            printf("Touché \n");
            datagrille[num][lettre] = 12;
            compteurbateau2 += 1;
            if (compteurbateau2 == 3) {
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
        //si toucher bateau3
        if (datagrille[num][lettre] == 3) {
            system("cls");
            map(cote);
            SetConsoleOutputCP(65001);
            system("cls");
            printf("Touché \n");
            datagrille[num][lettre] = 13;
            compteurbateau3 += 1;
            if (compteurbateau3 == 3) {
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
        //si toucher bateau4
        if (datagrille[num][lettre] == 4) {
            system("cls");
            map(cote);
            SetConsoleOutputCP(65001);
            system("cls");
            printf("Touché \n");
            datagrille[num][lettre] = 14;
            compteurbateau4 += 1;
            if (compteurbateau4 == 4) {
                printf("coulé");
                for (int i = 0; i < cote; ++i) {
                    for (int j = 0; j < cote; ++j) {
                        if (datagrille[i][j] == 14) {
                            datagrille[i][j] = 24;
                        }
                    }
                }
            }
            printf(" !\n");
        }
        //si toucher bateau5
        if (datagrille[num][lettre] == 5) {
            system("cls");
            map(cote);
            SetConsoleOutputCP(65001);
            system("cls");
            printf("Touché \n");
            datagrille[num][lettre] = 15;
            compteurbateau5 += 1;
            if (compteurbateau5 == 5) {
                printf("coulé");
                for (int i = 0; i < cote; ++i) {
                    for (int j = 0; j < cote; ++j) {
                        if (datagrille[i][j] == 15) {
                            datagrille[i][j] = 25;
                        }
                    }

                }
            }
            printf(" !\n");
        }
        if (compteurbateau1 == 2 && compteurbateau2 == 3 && compteurbateau3 == 3 && compteurbateau4 == 4 &&
            compteurbateau5 == 5) {
            gagner += 1;
        }
    }
    victory();
}

void logs(char * argv[]) {

    FILE * file = NULL;

    if ((file = fopen("logs/name.txt", "w+"))){
        //gets(iden);
        fprintf(file, "Name \n", iden);
    }
}

void victory() {
    int rejoin = 0;

    system("cls");
    yellow();
    printf("\n\n\n"
           "                                   ██╗   ██╗██╗ ██████╗████████╗ ██████╗ ██╗██████╗ ███████╗\n"
           "                                   ██║   ██║██║██╔════╝╚══██╔══╝██╔═══██╗██║██╔══██╗██╔════╝\n"
           "                                   ██║   ██║██║██║        ██║   ██║   ██║██║██████╔╝█████╗  \n"
           "                                   ╚██╗ ██╔╝██║██║        ██║   ██║   ██║██║██╔══██╗██╔══╝  \n"
           "                                    ╚████╔╝ ██║╚██████╗   ██║   ╚██████╔╝██║██║  ██║███████╗\n"
           "                                     ╚═══╝  ╚═╝ ╚═════╝   ╚═╝    ╚═════╝ ╚═╝╚═╝  ╚═╝╚══════╝\n");
    reset();
    printf("\n\n\n");
    printf("Vou avez fait %d points.", points);
    printf("\n\n");
    printf("                                                     Voulez-vous rejouer?\n");
    green();
    printf("\n                                                     1-Oui.");
    red();
    printf("\n                                                     2-Non et retourner au menu principal.\n");
    reset();
    printf("\n                                                     %c", 254);
    scanf("%d", &rejoin);
    if (rejoin == 1) {
        play();
    } else if (rejoin == 2) {
        main();
    }
    sleep(10000);
}

void red() { printf("\033[1;31m"); }
void blue() { printf("\033[0;34m"); }
void bluef() { printf("\033[0;36m"); }
void black() { printf("\033[0;30m"); }
void green() { printf("\033[0;32m"); }
void yellow() { printf("\033[0;33m"); }
void white() { printf("\033[0;37m"); }
void reset() { printf("\033[0m"); }