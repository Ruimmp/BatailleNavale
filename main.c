#include <stdio.h>
#include <windows.h>

void hub() {
    //Initialisation des variables
    int choix;
    //Initialisation des variables

    do {
        printf("Bataille Navale!\n\n\n\n");
        printf("Options:\n");
        printf("1-jouer\n2-classement\n3-aide\n4-quitter");
        scanf("%d", &choix);
    } while (choix < 1 || choix > 3);
    switch (choix) {
        case 1:
            if (choix == 1)
                //jeu();
                printf("Jeu");
            break;
        case 2:
            if (choix == 2)
                //classement();
                printf("classement");
            break;
        case 3:
            if (choix == 3)
                //aide();
                printf("aide");
            break;
        case 4:
            if (choix == 4)
                system("pause");
            break;
        case 5:
            if (choix < 1){
                printf("Veillez entrer une valeur parmis celles notées dans les options.");
            }
            break;
    }
}


int main() {
    hub();
    return 0;
}
