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
	int orJoueur = 50;

	/*Compteur d'objet*/
	int nPomme = 0;
	int nEau = 0;
	int nPotionRouge = 0;
	int nPotionVerte = 0;
	int nEpee = 0;
	int nBouclier = 0;

	/*Liste des articles proposés dans le magasin*/
		//Consommable
		objet pomme = {"Pomme",5};
		objet eau =  {"Eau",2};
		objet potionRouge = {"Potion rouge",5};
		objet potionVerte = {"Potion vert",30};
		//Armes
		objet epee =  {"Epee en bois",40};
		//Armures
		objet bouclier = {"Bouclier en bois", 50};

	/*Pointeur redirigant vers le nom de l'objet*/
	void Achat(objet * monObjet)
	{
		orJoueur = orJoueur - (*monObjet).prixObjet;
	}

	/*Inventaire du joueur*/
	void Inventaire()
	{
		printf("Revenir [1]\n\n");

		printf("Or: %d\n\n", orJoueur);

		if (nPomme > 0)
		{
			printf("%s x %d\n\n", pomme.nomObjet,nPomme);
		}

		

		scanf("%d", &choixJoueur);
		if (choixJoueur == 1)
		{
			printf("Que vendez-vous ? [1]  Inventaire [2]  Quittez [3] \n\n");
			printf("-- --\n");
			printf("Votre choix: "); scanf("%d", &choixJoueur);
			printf("-- --\n\n");
			switch (choixJoueur) {
				case 1 :
					printf("Marchand: Des babioles, des petites choses...\n\n");
					printf("_____________________\n\n");
					printf("Or: %d\n\n", orJoueur);

					//Appel de la fonction Achat
					//Select();
				break;

				case 2 :
				Inventaire();
				break;

				case 3 :
					printf("Marchand: A bientot !\n\n");
					return;
				break;
			}
		}
	}


	/*Achat (Choix d'un article + Depense le prix indiqué)*/
	void Select() 
	{
		while(orJoueur >= 0 || orJoueur != 0)
		{

			printf("-- -- -- -- -- -- --\n\n");
			printf("%s | Prix: %d |\n\n", pomme.nomObjet, pomme.prixObjet);
			printf("%s | Prix: %d |\n\n", eau.nomObjet, eau.prixObjet);
			printf("%s     | Prix: %d |\n\n", potionRouge.nomObjet, potionRouge.prixObjet);
			printf("%s      | Prix: %d |\n\n", potionVerte.nomObjet, potionVerte.prixObjet);
			printf("%s     | Prix: %d |\n\n", epee.nomObjet, epee.prixObjet);
			printf("%s | Prix: %d |\n\n", bouclier.nomObjet, bouclier.prixObjet);
			printf("-- -- -- -- -- -- --\n\n");

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
						Achat(&pomme);
						printf("Vous achetez une %s\n\n"),pomme.nomObjet;
						nPomme++;
					}

					if (monChoixArticle == 2)
					{
						printf("Vous avez choisi l' %s\n\n",eau.nomObjet);
						Achat(&eau);
						printf("Vous achetez l'%s\n\n",eau.nomObjet);
						nEau++;
					}

					if (monChoixArticle == 3)
					{
						printf("Vous avez choisi la %s\n\n",potionRouge.nomObjet);
						Achat(&potionRouge);
						printf("Vous achetez la %s\n\n",potionRouge.nomObjet);
						nPotionRouge++;
					}

					if (monChoixArticle == 4)
					{
						printf("Vous avez choisi la %s\n\n",potionVerte.nomObjet);
						Achat(&potionVerte);
						printf("Vous achetez la %s\n\n",potionVerte.nomObjet);
						nPotionVerte++;
					}

					if (monChoixArticle == 5)
					{
						printf("Vous avez choisi l' %s\n\n",epee.nomObjet);
						Achat(&epee);
						printf("Vous achetez l'%s\n\n",epee.nomObjet);
						nEpee++;
					}

					if (monChoixArticle == 6)
					{
						printf("Vous avez choisi la %s\n\n",bouclier.nomObjet);
						Achat(&pomme);
						printf("Vous achetez un %s\n\n",bouclier.nomObjet);
						nBouclier++;
					}
				break;

				case 2 :
					printf("Que vendez-vous ? [1]  Inventaire [2]  Quittez [3] \n\n");
					printf("-- --\n");
					printf("Votre choix: "); scanf("%d", &choixJoueur);
					printf("-- --\n\n");
					switch (choixJoueur) {
						case 1 :
							printf("Marchand: Des babioles, des petites choses...\n\n");
							printf("_____________________\n\n");
							printf("Or: %d\n\n", orJoueur);

							//Appel de la fonction Achat
							Select();
						break;

						case 2 :
							//Appel de la fonction Inventaire
							Inventaire();
						break;

						case 3 :
							printf("Marchand: A bientot !\n\n");
							return;
						break;
					}
				break;
			}
		}	
	}

	
	/*Choix du menu: Magasin, Inventaire et Quittez*/
	printf("Marchand: Bienvenue voyageur ! \n\n");
	printf("Que vendez-vous ? [1]  Inventaire [2]  Quittez [3] \n\n");
	printf("-- --\n");
	printf("Votre choix: "); scanf("%d", &choixJoueur);
	printf("-- --\n\n");

	switch (choixJoueur) {
		case 1 :
			printf("Marchand: Des babioles, des petites choses...\n\n");
			printf("_____________________\n\n");
			printf("Or: %d\n\n", orJoueur);

			//Appel de la fonction Achat
			Select();
		break;

		case 2 :
			Inventaire();
		break;

		case 3 :
			printf("Marchand: A bientot !\n\n");
			return 1;
		break;
	}

	return 0;
}