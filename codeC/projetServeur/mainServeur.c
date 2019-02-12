#include <stdio.h>
#include <stdlib.h>
#include "serveur.h"

int main() {
	char *message = NULL;
	char *ID;
	char *CMD;
	char *nomFichier;
	unsigned long taillefichier;
	char *taillestr;

	Initialisation();

	while(1) {
		int fini = 0;

		AttenteClient();

		while(!fini)
		{
			message = Reception();

			if(message != NULL)
			{
                ID=malloc(9);
                CMD=malloc(3);
                nomFichier=malloc(16);
                /*on décompose la requete pour en extraire
                tous les elemens dont nous avons besoin*/
				Decomposition(message,ID,CMD,nomFichier);

				if(authentificationS(ID)==1)
				{
                    if(CommandeS(CMD)==1)
                    {
                        taillestr = Reception();
                        taillefichier=strtoul(taillestr,taillestr,10);


                        /*il faut que le serveur connaisse la
                        taille du fichier a upload*/

                        ReceptionUpload(nomFichier,taillefichier);
                    }
				}
				//free(message);

				//CommandeS(message);

				if(Emission("Test de message serveur.\n")!=1)
				{
					printf("Erreur d'emission\n");
				}
			} else
			{
				fini = 1;
			}
		}

		TerminaisonClient();
	}

	return 0;
}
