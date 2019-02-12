#include <stdio.h>
#include <stdlib.h>
#include "serveur.h"

int main() {
	char *message = NULL;
	char *ID;
	char *CMD;

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
				Decomposition(message,ID,CMD);

				authentificationS(ID);
				CommandeS(CMD);
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
