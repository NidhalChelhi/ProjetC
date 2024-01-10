struct formation {
    int codeFormation;
    char nom[50];
    float prix;
    float note;
};
typedef struct formation FORMATION;
struct client {
    int codeClient;
    char nom[50];
    int age;
    int nbFormations;
    FORMATION *formation;
    float moyenne;
};
typedef struct client CLIENT;
struct departement {
    int codeDep;
    char nom[50];
    int capacite;
    int nbr_client;
    CLIENT *client;
};
typedef struct departement DEPARTEMENT;

// Structure Resultat à utiliser dans traitement 4
struct resultat {
    int codeClient;
    float moyenne;
};
typedef struct resultat RESULTAT;
// Structure formationFichier à utiliser dans traitement 5
struct formationFichier {
    int codeFormation;
    char nom[50];
    float nbNotes;
    float *notes;
};
typedef struct formationFichier FORMATIONFICHIER;

int saisirEntier();

DEPARTEMENT *remplissageDepartement(int n);

DEPARTEMENT saisieDepartement(int k);

CLIENT saisieClient(int k, DEPARTEMENT departement);

FORMATION saisieFormation(int k, CLIENT client, DEPARTEMENT departement);

void affichageDepartement(DEPARTEMENT departement);

void affichageClient(int k, CLIENT client, DEPARTEMENT departement);

void affichageFormation(int k, FORMATION formation, CLIENT client, DEPARTEMENT departement);

DEPARTEMENT *ajoutDepartement(DEPARTEMENT *TABDep, int n);

void afficherFormation(FORMATIONFICHIER form);

FORMATIONFICHIER saisieFormationFichier();

void creerFichierFormationIndex(FILE **, FILE **);

void remplirFichierFormationINdex(FILE *, FILE *);

void afficherFichierFormationIndex(FILE *, FILE *);

void traitement_1(int n, DEPARTEMENT *TABDep);

void traitement_2(int n, DEPARTEMENT *TABDep);

void traitement_3(int n, DEPARTEMENT *TABDep);

void traitement_4(int n, DEPARTEMENT *TABDep);

void traitement_5();