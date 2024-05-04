#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int jj, mm, aa;
} Date;

typedef struct {
    int ID;
    char Nom[50];
    char Description[100];
    char NomUtilisateur[50];
    float PrixUnitaire;
    int QuantiteStock;
    int SeuilAlerteStock;
    Date DateEntreeStock;
    Date DateSortieStock;
} Produit;

void ajouterProduit(FILE *fichierProduits) {
    Produit produit;
    printf("Nom du produit : ");
    scanf("%s", produit.Nom);
    printf("Description : ");
    scanf("%s", produit.Description);
    printf("Nom de l'utilisateur : ");
    scanf("%s", produit.NomUtilisateur);
    printf("Prix unitaire : ");
    scanf("%f", &produit.PrixUnitaire);
    printf("Quantite en stock : ");
    scanf("%d", &produit.QuantiteStock);
    printf("Seuil d'alerte de stock : ");
    scanf("%d", &produit.SeuilAlerteStock);

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    produit.DateEntreeStock.aa = tm.tm_year + 1900;
    produit.DateEntreeStock.mm = tm.tm_mon + 1;
    produit.DateEntreeStock.jj = tm.tm_mday;

    produit.DateSortieStock.aa = 0;

    fprintf(fichierProduits, "%d,%s,%s,%s,%.2f,%d,%d,%d/%d/%d,%d/%d/%d\n",
            produit.ID, produit.Nom, produit.Description, produit.NomUtilisateur,
            produit.PrixUnitaire, produit.QuantiteStock, produit.SeuilAlerteStock,
            produit.DateEntreeStock.jj, produit.DateEntreeStock.mm, produit.DateEntreeStock.aa,
            produit.DateSortieStock.jj, produit.DateSortieStock.mm, produit.DateSortieStock.aa);
    printf("Produit ajoute avec succes.\n");
}

void afficherProduits(FILE *fichierProduits) {
    rewind(fichierProduits);
    Produit produit;
    printf("\nListe des produits :\n");
    printf("ID | Nom | Description | Nom Utilisateur | Prix Unitaire | Quantite | Seuil | Date Entree | Date Sortie\n");
    printf("---------------------------------------------------------------------------------------------\n");
    while (fscanf(fichierProduits, "%d,%[^,],%[^,],%[^,],%f,%d,%d,%d/%d/%d,%d/%d/%d\n",
                  &produit.ID, produit.Nom, produit.Description, produit.NomUtilisateur,
                  &produit.PrixUnitaire, &produit.QuantiteStock, &produit.SeuilAlerteStock,
                  &produit.DateEntreeStock.jj, &produit.DateEntreeStock.mm, &produit.DateEntreeStock.aa,
                  &produit.DateSortieStock.jj, &produit.DateSortieStock.mm, &produit.DateSortieStock.aa) != EOF) {
        printf("%d | %s | %s | %s | %.2f | %d | %d | %d/%d/%d | %d/%d/%d\n",
               produit.ID, produit.Nom, produit.Description, produit.NomUtilisateur,
               produit.PrixUnitaire, produit.QuantiteStock, produit.SeuilAlerteStock,
               produit.DateEntreeStock.jj, produit.DateEntreeStock.mm, produit.DateEntreeStock.aa,
               produit.DateSortieStock.jj, produit.DateSortieStock.mm, produit.DateSortieStock.aa);
    }
    printf("---------------------------------------------------------------------------------------------\n");
}

void rechercherProduitParNom(FILE *fichierProduits, char *nomProduit) {
    rewind(fichierProduits);
    Produit produit;
    int trouve = 0;
    while (fscanf(fichierProduits, "%d,%[^,],%[^,],%[^,],%f,%d,%d,%d/%d/%d,%d/%d/%d\n",
                  &produit.ID, produit.Nom, produit.Description, produit.NomUtilisateur,
                  &produit.PrixUnitaire, &produit.QuantiteStock, &produit.SeuilAlerteStock,
                  &produit.DateEntreeStock.jj, &produit.DateEntreeStock.mm, &produit.DateEntreeStock.aa,
                  &produit.DateSortieStock.jj, &produit.DateSortieStock.mm, &produit.DateSortieStock.aa) != EOF) {
        if (strcmp(produit.Nom, nomProduit) == 0) {
            printf("ID : %d | Nom : %s | Description : %s | Nom Utilisateur : %s | Prix Unitaire : %.2f | "
                   "Quantite : %d | Seuil : %d | Date Entree : %d/%d/%d | Date Sortie : %d/%d/%d\n",
                   produit.ID, produit.Nom, produit.Description, produit.NomUtilisateur,
                   produit.PrixUnitaire, produit.QuantiteStock, produit.SeuilAlerteStock,
                   produit.DateEntreeStock.jj, produit.DateEntreeStock.mm, produit.DateEntreeStock.aa,
                   produit.DateSortieStock.jj, produit.DateSortieStock.mm, produit.DateSortieStock.aa);
            trouve = 1;
        }
    }
    if (!trouve) {
        printf("Aucun produit correspondant trouve pour le nom : %s\n", nomProduit);
    }
}

void rechercherProduitParUtilisateur(FILE *fichierProduits, char *nomUtilisateur) {
    rewind(fichierProduits);
    Produit produit;
    int trouve = 0;
    while (fscanf(fichierProduits, "%d,%[^,],%[^,],%[^,],%f,%d,%d,%d/%d/%d,%d/%d/%d\n",
                  &produit.ID, produit.Nom, produit.Description, produit.NomUtilisateur,
                  &produit.PrixUnitaire, &produit.QuantiteStock, &produit.SeuilAlerteStock,
                  &produit.DateEntreeStock.jj, &produit.DateEntreeStock.mm, &produit.DateEntreeStock.aa,
                  &produit.DateSortieStock.jj, &produit.DateSortieStock.mm, &produit.DateSortieStock.aa) != EOF) {
        if (strcmp(produit.NomUtilisateur, nomUtilisateur) == 0) {
            printf("ID : %d | Nom : %s | Description : %s | Nom Utilisateur : %s | Prix Unitaire : %.2f | "
                   "Quantite : %d | Seuil : %d | Date Entree : %d/%d/%d | Date Sortie : %d/%d/%d\n",
                   produit.ID, produit.Nom, produit.Description, produit.NomUtilisateur,
                   produit.PrixUnitaire, produit.QuantiteStock, produit.SeuilAlerteStock,
                   produit.DateEntreeStock.jj, produit.DateEntreeStock.mm, produit.DateEntreeStock.aa,
                   produit.DateSortieStock.jj, produit.DateSortieStock.mm, produit.DateSortieStock.aa);
            trouve = 1;
        }
    }
    if (!trouve) {
        printf("Aucun produit correspondant trouve pour l'utilisateur : %s\n", nomUtilisateur);
    }
}

void trierProduitsParNom(FILE *fichierProduits) {
    rewind(fichierProduits);
    Produit *produits = (Produit *)malloc(100 * sizeof(Produit));
    int nbProduits = 0;
    while (fscanf(fichierProduits, "%d,%[^,],%[^,],%[^,],%f,%d,%d,%d/%d/%d,%d/%d/%d\n",
                  &produits[nbProduits].ID, produits[nbProduits].Nom, produits[nbProduits].Description,
                  produits[nbProduits].NomUtilisateur, &produits[nbProduits].PrixUnitaire,
                  &produits[nbProduits].QuantiteStock, &produits[nbProduits].SeuilAlerteStock,
                  &produits[nbProduits].DateEntreeStock.jj, &produits[nbProduits].DateEntreeStock.mm,
                  &produits[nbProduits].DateEntreeStock.aa, &produits[nbProduits].DateSortieStock.jj,
                  &produits[nbProduits].DateSortieStock.mm, &produits[nbProduits].DateSortieStock.aa) != EOF) {
        nbProduits++;
    }
int i,j;
    for ( i = 0; i < nbProduits - 1; i++) {
        for ( j = i + 1; j < nbProduits; j++) {
            if (strcmp(produits[i].Nom, produits[j].Nom) > 0) {
                Produit temp = produits[i];
                produits[i] = produits[j];
                produits[j] = temp;
            }
        }
    }

    printf("\nListe des produits tries par nom :\n");
    printf("ID | Nom | Description | Nom Utilisateur | Prix Unitaire | Quantite | Seuil | Date Entree | Date Sortie\n");
    printf("---------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < nbProduits; i++) {
        printf("%d | %s | %s | %s | %.2f | %d | %d | %d/%d/%d | %d/%d/%d\n",
               produits[i].ID, produits[i].Nom, produits[i].Description, produits[i].NomUtilisateur,
               produits[i].PrixUnitaire, produits[i].QuantiteStock, produits[i].SeuilAlerteStock,
               produits[i].DateEntreeStock.jj, produits[i].DateEntreeStock.mm, produits[i].DateEntreeStock.aa,
               produits[i].DateSortieStock.jj, produits[i].DateSortieStock.mm, produits[i].DateSortieStock.aa);
    }
    printf("---------------------------------------------------------------------------------------------\n");

    free(produits);
}

int main() {
    FILE *fichierProduits;
    fichierProduits = fopen("produits.csv", "a+");

    if (fichierProduits == NULL) {
        printf("Erreur lors de l'ouverture du fichier produits.csv.\n");
        return 1;
    }

    int choix;
    char nomProduit[50];
    char nomUtilisateur[50];

    printf("Entrez votre nom pour commencer a utiliser l'application : ");
    scanf("%s", nomUtilisateur);

    do {
        printf("\nMenu :\n");
        printf("1. Ajouter un produit\n");
        printf("2. Modifier un produit\n");
        printf("3. Supprimer un produit\n");
        printf("4. Afficher la liste des produits\n");
        printf("5. Rechercher un produit par nom\n");
        printf("6. Rechercher un produit par nom d'utilisateur\n");
        printf("7. Trier les produits par nom\n");
        printf("8. Quitter\n");
        printf("Choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouterProduit(fichierProduits);
                break;
            case 2:
                printf("Fonctionnalite non implementee.\n");
                break;
            case 3:
                printf("Fonctionnalite non implementee.\n");
                break;
            case 4:
                afficherProduits(fichierProduits);
                break;
            case 5:
                printf("Nom du produit a rechercher : ");
                scanf("%s", nomProduit);
                rechercherProduitParNom(fichierProduits, nomProduit);
                break;
            case 6:
                rechercherProduitParUtilisateur(fichierProduits, nomUtilisateur);
                break;
            case 7:
                trierProduitsParNom(fichierProduits);
                break;
            case 8:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide. Veuillez ressayer.\n");
        }
    } while (choix != 8);

    fclose(fichierProduits);
    return 0;
}
