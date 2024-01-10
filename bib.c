#include <stdio.h>
#include <stdlib.h>
#include "bib.h"

int saisirEntier() {
    int n;
    while (1) {
        scanf("%d", &n);
        if (n > 0) break;
    }
    return n;
}

DEPARTEMENT *remplissageDepartement(int n) {
    DEPARTEMENT *TABDep;
    printf("\n************************************ REMPLISSAGE PRINCIPALE ************************************\n");
    TABDep = (DEPARTEMENT *) malloc(n * sizeof(DEPARTEMENT));
    if (!TABDep) exit(-1);
    DEPARTEMENT *p = TABDep;
    putchar('\n');
    for (int i = 0; i < n; i++) {
        printf("\n------------------ Saisie de departement num: %d------------------\n", i + 1);
        *(p + i) = saisieDepartement(i);
    }
    putchar('\n');
    return TABDep;
}

DEPARTEMENT *ajoutDepartement(DEPARTEMENT *TABDep, int n) {
    DEPARTEMENT *TABDep2;
    printf("\n------------------ AJOUT DEPARTEMENT ------------------\n");
    // Utilisation du realloc
    TABDep2 = (DEPARTEMENT *) realloc(TABDep, (n + 1) * sizeof(DEPARTEMENT));
    if (!TABDep2) exit(-1);
    putchar('\n');
    DEPARTEMENT *newDepartement = TABDep2 + n;
    printf("\n------------------ Saisie de departement num: %d------------------\n", n + 1);
    *newDepartement = saisieDepartement(n);
    putchar('\n');
    return TABDep2;
}

DEPARTEMENT saisieDepartement(int k) {
    DEPARTEMENT departement;
    DEPARTEMENT *dep;
    dep = &departement;
    printf("\n donnez code de departement : ");
    scanf("%d", &dep->codeDep);
    printf("\n donnez le nom de departement : ");
    scanf("%s", dep->nom);
    printf("\n donnez la capacite de departement : ");
    scanf("%d", &dep->capacite);
    printf("\ndonnez les nombres des clients : ");
    scanf("%d", &dep->nbr_client);
    dep->client = (CLIENT *) malloc(dep->nbr_client * sizeof(CLIENT));
    if (!dep->client) exit(-2);
    putchar('\n');
    for (int l = 0; l < dep->nbr_client; l++) { *(dep->client + l) = saisieClient(l, *dep); }
    return departement;
}

CLIENT saisieClient(int k, DEPARTEMENT departement) {
    CLIENT client;
    CLIENT *cl;
    cl = &client;
    DEPARTEMENT *dep;
    dep = &departement;
    printf("\n------------------ SAISIE du client %d dans le departement %s ------------------\n", k + 1,
           departement.nom);
    printf("\nDonnez code de client : ");
    scanf("%d", &cl->codeClient);
    printf("\nDonnez le nom de client : ");
    scanf("%s", cl->nom);
    printf("\nDonnez l'age de client : ");
    scanf("%d", &cl->age);
    printf("\nDonnez le moyenne de client : ");
    scanf("%f", &cl->moyenne);
    printf("\nDonnez le nombre de formation de client : ");
    scanf("%d", &cl->nbFormations);
    cl->formation = (FORMATION *) malloc(cl->nbFormations * sizeof(FORMATION));
    if (!cl->formation) exit(-3);
    putchar('\n');
    for (int i = 0; i < cl->nbFormations; i++) { *(cl->formation + i) = saisieFormation(i, *cl, *dep); }
    return client;
}

FORMATION saisieFormation(int k, CLIENT client, DEPARTEMENT departement) {
    FORMATION formation;
    FORMATION *fo;
    fo = &formation;
    DEPARTEMENT *dep;
    dep = &departement;
    printf("\n------------------ SAISIE de la formation %d de client %s dans le departement %s ------------------\n",
           k + 1, client.nom, dep->nom);
    printf("\nDonnez le code de formation : ");
    scanf("%d", &fo->codeFormation);
    printf("\nDonnez le nom de formation : ");
    scanf("%s", &fo->nom);
    printf("\nDonnez le prix de formation : ");
    scanf("%f", &fo->prix);
    printf("\nDonnez la note de formation : ");
    scanf("%f", &fo->note);
    return formation;
}

void affichageDepartement(DEPARTEMENT departement) {
    DEPARTEMENT *dep;
    dep = &departement;
    printf("\n------------------ AFFICHAGE du departement %s ------------------\n", dep->nom);
    printf("\nCode Departement: %d\n", dep->codeDep);
    printf("\nNom de Departement: %s\n", dep->nom);
    printf("\nCapacite de Departement: %d\n", dep->capacite);
    printf("\nNombre des clients dans le Departement: %d\n", dep->nbr_client);
    CLIENT *poi = dep->client;
    for (int i = 0; i <
                    dep->nbr_client; i++) //affichage des clients
    { affichageClient(i, *(poi + i), departement); }
    putchar('\n');
}

void affichageClient(int k, CLIENT client, DEPARTEMENT departement) {
    CLIENT *cli;
    cli = &client;
    DEPARTEMENT *depa;
    depa = &departement;
    printf("\n------------------ AFFICHAGE du client %d dans le departement %s ------------------\n", k + 1, depa->nom);
    printf("\nCode Client: %d\n", cli->codeClient);
    printf("\nNom du Client: %s\n", cli->nom);
    printf("\nAge du Client: %d\n", cli->age);
    printf("\nMoyenne du Client: %.2f\n", cli->moyenne);
    printf("\nNombre de formations du Client: %d\n", cli->nbFormations);
    for (int i = 0; i < cli->nbFormations; i++) {
        FORMATION *currentFormation = cli->formation + i;
        affichageFormation(i, *currentFormation, client, departement);
    }
    putchar('\n');
}

void affichageFormation(int k, FORMATION formation, CLIENT client, DEPARTEMENT departement) {
    CLIENT *clie;
    clie = &client;
    DEPARTEMENT *depar;
    depar = &departement;
    FORMATION *forma;
    forma = &formation;
    printf("\n------------------ AFFICHAGE de la formation %d de client %s dans le departement %s ------------------\n",
           k + 1, clie->nom, depar->nom);
    printf("\nCode de Formation: %d\n", forma->codeFormation);
    printf("\nNom de Formation: %s\n", forma->nom);
    printf("\nPrix de Formation: %.3f Dt\n", forma->prix);
    printf("\nNote de Formation: %.3f\n", forma->note);
}

// TRAITEMENT 1: Affichage de la formation la plus chere
void traitement_1(int n, DEPARTEMENT *TABDep) {
    FORMATION *max;
    printf("\n------------------- TRAITEMENT 1: Affichage de la formation la plus chere -------------------\n");
    putchar('\n');
    max = (TABDep->client + 0)->formation;
    for (int i = 0; i < n; i++) {
        DEPARTEMENT *currentDep = TABDep + i;
        for (int j = 0; j < currentDep->nbr_client; j++) {
            CLIENT *currentClient = currentDep->client + j;
            for (int k = 0; k < currentClient->nbFormations; k++) {
                FORMATION *currentFormation = currentClient->formation + k;
                if (max->prix < currentFormation->prix) { max = currentFormation; }
            }
        }
    }
    printf("\n la formation la plus chere avec le code = %d et de nom : %s \n", max->codeFormation, max->nom);
    putchar('\n');
}

//TRAITEMENT 2: Affichage des bilans des clients
void traitement_2(int n, DEPARTEMENT *TABDep) {
    float prix_totale = 0;
    printf("\n------------------- TRAITEMENT 2: Affichage des bilans des clients -------------------\n");
    putchar('\n');
    printf("\n ------Voici les bilans des clients------\n");
    putchar('\n');
    for (int i = 0; i < n; i++) {
        DEPARTEMENT *currentDep = TABDep + i;
        printf("\n -----voici les bilants des client de departement %d-----\n", i + 1);
        for (int j = 0; j < currentDep->nbr_client; j++) {
            CLIENT *currentClient = currentDep->client + j;
            printf("\n------bilan de client %d------\n", j + 1);
            printf("\n le code de client %d est egale a %d \n", j + 1, currentClient->codeClient);
            printf("\n le nom de client %d c'est %s \n", j + 1, currentClient->nom);
            printf("\n l'age de client %d : %d \n", j + 1, currentClient->age);
            printf("\n la moyenne de client %d est egale a %.3f \n", j + 1, currentClient->moyenne);
            printf("\n le nombre de formation de client %d est egale a %d \n", j + 1, currentClient->nbFormations);
            for (int k = 0; k < currentClient->nbFormations; k++) {
                FORMATION *currentFormation = currentClient->formation + k;
                prix_totale += currentFormation->prix;
            }
            printf("\n le cout totale de ses formation est egale a : %.3f dt", prix_totale);
            prix_totale = 0;
            putchar('\n');
        }
    }
    putchar('\n');
}


//TRAITEMENT 3: Affichage de meilleur client d'un departement
void traitement_3(int n, DEPARTEMENT *TABDep) {
    int indice_client = 0, indice_departement = 0, code;
    float max_moy;
    printf("\n------------------- TRAITEMENT 3: Affichage de meilleur client d'un departement -------------------\n");
    putchar('\n');
    printf("\nDonner le code de departement: ");
    scanf("%d", &code);
    for (int i = 0; i < n; ++i) {
        DEPARTEMENT *currentDep = TABDep + i;
        if (code == currentDep->codeDep) {
            max_moy = (currentDep->client + i)->moyenne;
            for (int j = 1; j < currentDep->nbr_client; ++j) {
                CLIENT *currentClient = currentDep->client + j;
                if (max_moy < currentClient->moyenne) {
                    max_moy = currentClient->moyenne;
                    indice_client = j;
                    indice_departement = i;
                }
            }
        }
    }
    printf("\nLe meilleur client de departement %d avec le code %d est %s et son propre code est egale à %d",
           indice_departement + 1, code, (TABDep[indice_departement].client + indice_client)->nom,
           (TABDep[indice_departement].client + indice_client)->codeClient);
}


//TRAITEMENT 4: Tableau dynamique d'adresses de RESULTAT
void traitement_4(int n, DEPARTEMENT *TABDep) {
    RESULTAT **tabResultats;
    int i;
    printf("\n------------------- TRAITEMENT 4: Tableau dynamique d'adresses de RESULTAT -------------------\n");
    tabResultats = (RESULTAT **) malloc(n * sizeof(RESULTAT *));
    if (!tabResultats) exit(-1);
    for (i = 0; i < n; i++) {
        *(tabResultats + i) = (RESULTAT *) malloc(sizeof(RESULTAT));
        if (!*(tabResultats + i)) exit(-2);
        (*(tabResultats + i))->codeClient = (*(TABDep + i)).client->codeClient;
        (*(tabResultats + i))->moyenne = (*(TABDep + i)).client->moyenne;
    }
    printf("\n-------------------------------\n");
    for (i = 0; i < n; i++) {
        printf("\n\n RESULTAT d'indice %d", i);
        printf("\n Code du client: %d", (*(tabResultats + i))->codeClient);
        printf("\n Moyenne: %5.2f", (*(tabResultats + i))->moyenne);
    }
    for (i = 0; i < n; i++) { free(*(tabResultats + i)); }
    free(tabResultats);
}

FORMATIONFICHIER saisieFormationFichier() {
    FORMATIONFICHIER formationFichier;
    FORMATIONFICHIER *fo = &formationFichier;
    printf("\n------------------ SAISIE de la formationFichier ------------------\n");
    printf("\nDonnez le code de formationFichier : ");
    scanf("%d", &fo->codeFormation);
    printf("\nDonnez le nom de formationFichier : ");
    scanf("%s", fo->nom);
    printf("\nDonnez le nombre de notes de formationFichier : ");
    scanf("%f", &fo->nbNotes);
    fo->notes = (float *) malloc(fo->nbNotes * sizeof(float));
    if (!fo->notes) {
        fprintf(stderr, "Memory allocation failed for notes array.\n");
        exit(-1);
    }
    printf("\nSaisir les notes de formationFichier : \n");
    for (int i = 0; i < fo->nbNotes; i++) {
        printf("Note %d: ", i + 1);
        scanf("%f", &fo->notes[i]);
    }
    return formationFichier;
}

void afficherFormation(FORMATIONFICHIER form) {
    printf("\nCode de Formation: %d", form.codeFormation);
    printf("\nNom de Formation: %s", form.nom);
    printf("\nNombre de Notes: %f", form.nbNotes);
    printf("\nNotes:");
    float *currentNote = form.notes;
    for (int i = 0; i < form.nbNotes; ++i) {
        printf(" %.2f", *currentNote);
        ++currentNote;
        printf("\n\n");
    }
}

void ecrireUneFormationDansFichier(FILE *fp, FORMATIONFICHIER form) {
    fwrite(&form, sizeof(FORMATIONFICHIER), 1, fp);
    fwrite(&(form.nbNotes), sizeof(float), 1, fp);
    fwrite(form.notes, sizeof(float), form.nbNotes, fp);
}

void creerFichierFormationIndex(FILE **fp, FILE **fi) {
    *fp = fopen("d:\\fichierFormation", "wb+");
    if (!*fp) exit(-1);
    *fi = fopen("d:\\fichierIndex", "wb+");
    if (!*fi) exit(-1);
}

void remplirFichierFormationINdex(FILE *fp, FILE *fi) {
    int x;
    FORMATIONFICHIER form;
    do {
        form = saisieFormationFichier();
        if (form.codeFormation == 0) {
            printf("\nFin de saisie.\n");
            break;
        }
        x = ftell(fp);
        fwrite(&x, sizeof(int), 1, fi);
        ecrireUneFormationDansFichier(fp, form);
        printf("\nVoulez-vous ajouter une autre formation ? (1 pour Oui, 0 pour Non): ");
        scanf("%d", &x);
    } while (x != 0);
}

FORMATIONFICHIER lireUneFormationDuFichier(FILE *fp) {
    FORMATIONFICHIER form;
    fread(&form, sizeof(FORMATIONFICHIER), 1, fp);
    fread(&(form.nbNotes), sizeof(float), 1, fp);
    form.notes = (float *) malloc(form.nbNotes * sizeof(float));
    fread(form.notes, sizeof(float), form.nbNotes, fp);
    return form;
}

void afficherFichierFormationIndex(FILE *fp, FILE *fi) {
    FORMATIONFICHIER form;
    int x;
    rewind(fi);
    rewind(fp);
    printf("\n -------------------------------------\n");
    printf("affichage fichier index\n");
    while (1) {
        fread(&x, sizeof(int), 1, fi);
        if (feof(fi))break;
        printf("\n %d", x);
    }
    rewind(fi);
    printf("\n -------------------------------------\n");
    printf("\n affichage fichier formation \n");
    while (1) {
        fread(&x, sizeof(int), 1, fi);
        if (feof(fi)) break;
        fseek(fp, x, 0);
        form = lireUneFormationDuFichier(fp);
        afficherFormation(form);
    }
}

//TRAITEMENT 5: Les fichiers binaires
void traitement_5() {
    printf("\n------------------- TRAITEMENT 5: Les fichiers binaires -------------------\n");
    FILE *fp;
    FILE *fi;
    creerFichierFormationIndex(&fp, &fi);
    remplirFichierFormationINdex(fp, fi);
    afficherFichierFormationIndex(fp, fi);
}