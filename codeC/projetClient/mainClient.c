#include <stdio.h>
#include <stdlib.h>
#include "client.h"

int main() {
	char *message;
    char *requete;
    requete=malloc(11);
/*****************phase de connection au serveur****************/
	if(Initialisation("localhost") != 1) {
		printf("Erreur d'initialisation\n");
		return 1;
	}

/*****************phase d'authentification au serveur****************/

	printf("entrez \n");
	EnvoiC(requete);
	free(requete);

	message = Reception();
	if(message != NULL) {
		printf("J'ai recu: %s\n", message);
		free(message);
	} else {
		printf("Erreur de réception\n");
		return 1;
	}



/*****************phase de commande****************/



	message = Reception();
	if(message != NULL) {
		printf("J'ai recu: %s\n", message);
		free(message);
	} else {
		printf("Erreur de réception\n");
		return 1;
	}

/*************************************************/
		message = Reception();
	if(message != NULL) {
		printf("J'ai recu: %s\n", message);
		free(message);
	} else {
		printf("Erreur de réception\n");
		return 1;
	}



	Terminaison();

	return 0;
}
