#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "serveur.h"

int main() {
	char *message = NULL;
	char *ID;
	char *CMD;
	char *EA;
	unsigned long taillefichier;
	char *taillestr;
	char *nom_fichier;
	char *nouveau_nom;
	int authmode;
	int ctrl;

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
                EA=malloc(20);
                taillestr=malloc(255);

                /*on décompose la requete pour en extraire
                tous les elemens dont nous avons besoin*/
				Decomposition(message,ID,CMD,EA);

				/*on s'authentifie et selon si on est
				superuser ou no les resultats seront
				differents*/
                authmode=authentificationS(ID);
                printf("authmode = %d\n", authmode);

                /*si on s'authentifie en tant que superuser*/
                if(authmode==2)
                {
                    printf("superuser connecte");
                    if(CommandeS(CMD)==3)
                    {
                        ajoutUser(EA);
                    }
				}

				/*si on s'authentifie en tant qu'user normal*/
				if(authmode==1)
				{
                    /*dans le cas d'un upload*/
                    if(CommandeS(CMD)==1)
                    {
                        taillestr = Reception();
                        taillefichier=strtoul(taillestr,taillestr,10);
                        /*il faut que le serveur connaisse la
                        taille du fichier a upload*/
                        ctrl=quota(ID,taillefichier);
                        if(ctrl==1)
                        {
                            ReceptionUpload(EA,taillefichier);
                        }

                    }
                    /*dans le cas d'un download*/
                    if(CommandeS(CMD)==2)
                    {
                        taillefichier=longueur_fichier(EA);
                        sprintf(taillestr,"%lu",taillefichier);
                        printf("taille str%s \n",taillestr);
                        strcat(taillestr,"\n");
                        Emission(taillestr);
                        Download(EA,taillefichier);

                    }
                    /*dans le cas d'un renommage de fichier*/
                    if(CommandeS(CMD)==4)
                    {
                        nom_fichier=malloc(10);
                        nouveau_nom=malloc(10);
                        /*on décompose l'element auxiliaire pour en extraire les elements
                        qui nous serviront a renommer le fichier*/
                        sscanf(EA,"%[^-]%s",nom_fichier,nouveau_nom);
                        printf("%s\n",nom_fichier);
                        printf("%s\n",nouveau_nom);
                        Renommer(nom_fichier,nouveau_nom);
                    }
                    /*dans le cas d'une suppression de fichier*/
                    if(CommandeS(CMD)==5)
                    {
                        Supprimer(EA);
                    }

				}



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
