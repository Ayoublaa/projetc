1-ajouterProduit(FILE *fichierProduits) :
Cette fonction permet à l'utilisateur d'ajouter un nouveau produit au stock.
Elle prend en paramètre un pointeur vers le fichier des produits (fichierProduits) où les informations du produit seront stockées.
La fonction demande à l'utilisateur de saisir le nom du produit, sa description, le nom de l'utilisateur associé, le prix unitaire, la quantité en stock, et le seuil d'alerte de stock.
Elle utilise la fonction fprintf pour écrire les informations du produit dans le fichier CSV.


2-afficherProduits(FILE *fichierProduits) :
Cette fonction affiche la liste de tous les produits stockés dans le fichier.
Elle prend en paramètre un pointeur vers le fichier des produits (fichierProduits).
La fonction lit les informations de chaque produit à partir du fichier à l'aide de fscanf et les affiche à l'écran dans un format tabulaire.


3-rechercherProduitParNom(FILE *fichierProduits, char *nomProduit) :
Cette fonction permet à l'utilisateur de rechercher un produit par son nom.
Elle prend en paramètres un pointeur vers le fichier des produits (fichierProduits) et le nom du produit à rechercher (nomProduit).
La fonction parcourt le fichier pour trouver un produit ayant le nom spécifié, et si trouvé, affiche ses informations.


4-rechercherProduitParUtilisateur(FILE *fichierProduits, char *nomUtilisateur) :
Cette fonction permet à l'utilisateur de rechercher les produits associés à un utilisateur donné.
Elle prend en paramètres un pointeur vers le fichier des produits (fichierProduits) et le nom de l'utilisateur à rechercher (nomUtilisateur).
La fonction parcourt le fichier pour trouver tous les produits ayant le nom d'utilisateur spécifié, et si trouvé, affiche leurs informations.


5-trierProduitsParNom(FILE *fichierProduits) :
Cette fonction trie les produits dans le fichier par ordre alphabétique de leur nom. 
Elle prend en paramètre un pointeur vers le fichier des produits (fichierProduits).
La fonction lit tous les produits du fichier dans un tableau, les trie par nom à l'aide d'un simple algorithme de tri, puis affiche la liste triée à l'écran.


6-main() :
La fonction principale du programme qui contrôle le flux de l'application.
Elle ouvre le fichier des produits, affiche un menu à l'utilisateur pour choisir les actions à effectuer, puis appelle les fonctions correspondantes en fonction du choix de l'utilisateur.
Le programme continue de s'exécuter jusqu'à ce que l'utilisateur choisisse de quitter
