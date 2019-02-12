#include <stdio.h>
#include <stdlib.h>
#include "serveur.h"

int main() {
	char *message = NULL;

	Initialisation();

	while(1) {
		int fini = 0;

		AttenteClient();

		while(!fini)
		{
			message = Reception();

			if(message != NULL)
			{

				authentificationS(message);
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
