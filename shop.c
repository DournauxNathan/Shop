#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/*Structure des articles du magasin referencant leur nom et leurs prix*/
struct Objet{
	char nomObjet[30];
	int prixObjet;
};
typedef struct Objet objet;

int main()
{
	int choixJoueur;
	int monChoixArticle;
	int orJoueur;

	/*Liste des articles proposés dans le magasin*/
		//Consommable
		objet pomme = {"Pomme",5};
		objet eau =  {"Eau",2};
		objet potionRouge = {"Potion rouge",5};
		objet potionVerte = {"Potion vert",30};
		//Armes
		objet epee =  {"Epee en bois",40};
		//Armures
		objet bouclier = {"Bouclier en bois", 50}
	
	/*Pointeur redirigant vers le nom de l'objet*/
		void selectArticle(objet * monObjet)
		{
			orJoueur = orJoueur - (*monObjet).prixObjet;
		}

	/*Achat (Choix d'un article + Depense le prix indiqué)*/
		void Achat() 
		{
			while(orJoueur > 0)
			{
				printf("Or: %d\n\n", orJoueur);

				//Choix: Selectionner un article ou revenir au menu précédent
				printf("Selectionner [1]   Revenir [2]\n\n");
				printf("-- --\n");
				printf("Votre choix: "); scanf("%d", &choixJoueur);
				printf("-- --\n\n");

				switch (choixJoueur)
				{
					case 1 :
						printf("Selectionner un article: "); scanf("%d", &monChoixArticle);
						printf("-- --\n\n");
						if (monChoixArticle == 1)
						{
							printf("Vous avez choisi la %s\n\n",pomme.nomObjet);
							selectArticle(&pomme);
							printf("Vous achetez un pomme\n\n");
						}

					break;

					case 2 :
					break;
				}
			}
		}

	/*Choix du menu: Magasin, Inventaire et Quittez*/
		printf("Marchand: Bienvenue voyageur ! \n\n");
		printf("Que vendez-vous ? [1]\n\n");
		printf("-- --\n");
		printf("Votre choix: "); scanf("%d", &choixJoueur);
		printf("-- --\n\n");

	switch (choixJoueur) {
		case 1 :
			printf("Marchand: Des babioles, des petites choses...\n\n");
			printf("_____________________\n\n");
			printf("Or: %d\n\n", orJoueur);
			printf("-- -- -- -- -- -- --\n\n");
			printf("%s | Prix: %d |\n\n", pomme.nomObjet, pomme.prixObjet);
			printf("%s | Prix: %d |\n\n", eau.nomObjet, eau.prixObjet);
			printf("%s | Prix: %d |\n\n", potionRouge.nomObjet, potionRouge.prixObjet);
			printf("%s | Prix: %d |\n\n", potionVerte.nomObjet, potionVerte.prixObjet);
			printf("%s | Prix: %d |\n\n", epee.nomObjet, epee.prixObjet);
			printf("%s | Prix: %d |\n\n", bouclier.nomObjet, bouclier.prixObjet);
			printf("-- -- -- -- -- -- --\n\n");

			//Appel de la fonction Achat
			Achat();
		break;
	}

	return 0;
}