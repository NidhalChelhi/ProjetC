#include <stdio.h>
#include "bib.h"
#include <stdlib.h>
#include <conio.h>

void main() {
    DEPARTEMENT *TABDep;
    int n;
    printf("\nDonnez le nombre de departements: ");
    n = saisirEntier();
    int main_choice;
    int second_choice;
    menu_principale:
    printf("\n************************************ MENU ************************************");
    printf("\n1- Remplissage");
    printf("\n2- Affichage");
    printf("\n3- Traitement1");
    printf("\n4- Traitement2");
    printf("\n5- Traitement3");
    printf("\n6- Traitement4");
    printf("\n7- Traitement5");
    printf("\n8- QUITTER");
    printf("\nDonnez votre choix: ");
    scanf("%d", &main_choice);
    switch (main_choice) {
        case 1:
        menu_remplissage:
            printf("\n************************************ MENU Remplissage ************************************");
            printf("\n1- Remplissage Departement");
            printf("\n2- Ajout Departement");
            printf("\n3- RETOUR");
            printf("\n4- QUITTER");
            printf("\nDonnez votre choix: ");
            scanf("%d", &second_choice);
            switch (second_choice) {
                case 1:
                    TABDep = remplissageDepartement(n);
                    goto menu_remplissage;
                case 2:
                    TABDep = ajoutDepartement(TABDep, n);
                    n=n+1;
                    goto menu_remplissage;
                case 3:
                    goto menu_principale;
                case 4:
                    exit(0);
                default:
                    printf("\nchoix invalide\n");
            }
            break;
        case 2:
        menu_affichage:
            printf("\n************************************ MENU Affichage ************************************");
            printf("\n1- Affichage Departement");
            printf("\n2- RETOUR");
            printf("\n3- QUITTER");
            printf("\nDonnez votre choix: ");
            scanf("%d", &second_choice);
            switch (second_choice) {
                case 1:
                    for (int i = 0; i < n; i++) { affichageDepartement(TABDep[i]); }
                    goto menu_affichage;
                case 2:
                    goto menu_principale;
                case 3:
                    exit(0);
                default:
                    printf("\nchoix invalide\n");
            }
        case 3:
            traitement_1(n, TABDep);
            goto menu_principale;
        case 4:
            traitement_2(n, TABDep);
            goto menu_principale;
        case 5:
            traitement_3(n, TABDep);
            goto menu_principale;
        case 6:
            traitement_4(n, TABDep);
            goto menu_principale;
        case 7:
            traitement_5();
            goto menu_principale;
        case 8:
            exit(0);
        default:
            printf("\nchoix invalide\n");
    }
}