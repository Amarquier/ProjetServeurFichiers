#include <stdio.h>
#include <stdlib.h>
#include "client.h"
#include <string.h>

int main() {
	char *message;
    char *requete;
    char *ID;
    char *CMD;
    char *Fichier;
    char *taillestr;
    unsigned long taille;

    ID=malloc(9);
    CMD=malloc(3);
    Fichier=malloc(16);
    requete=malloc(30);
    taillestr=malloc(255);

/*****************phase de connection au serveur****************/
	if(Initialisation("localhost") != 1) {
		printf("Erreur d'initialisation\n");
		return 1;
	}

/****************************************************************/
	printf("entrez \n");
	EnvoiC(requete);

	sscanf(requete,"%*s %s %s",CMD,Fichier);
	printf("CMD : %s\n", CMD);
	printf("fichier : %s\n", Fichier);



	if(strcmp("upl",CMD)==0)
	{ //en cours de test, va passer en fonction une fois fini
        taille=longueur_fichier(Fichier);
        printf("la taille du fichier est de %lu \n", taille);
        sprintf(taillestr,"%lu",taille);
        printf("taille str%s \n",taillestr);

        strcat(taillestr,"\n");
        Emission(taillestr);

        Upload(Fichier,taille);
    }
    if(strcmp("dld",CMD)==0)
    {
        taillestr = Reception();
        printf("taillestr= %s \n",taillestr);
        taille=strtoul(taillestr,taillestr,10);
        printf("taille : %lu\n", taille);

        /*il faut que le client connaisse la
        taille du fichier a download*/

        ReceptionDownload(Fichier,taille);

    }
	message = Reception();
	if(message != NULL) {
		printf("J'ai recu: %s\n", message);
		free(message);
	} else {
		printf("Erreur de réception\n");
		return 1;
	}



	message = Reception();
	if(message != NULL) {
		printf("J'ai recu: %s\n", message);
		free(message);
	} else {
		printf("Erreur de réception\n");
		return 1;
	}













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
