#ifndef __SERVEUR_H__
#define __SERVEUR_H__

/* Initialisation.
 * Creation du serveur.
 * renvoie 1 si �a c'est bien pass� 0 sinon
 */
int Initialisation();

int Recherche(char *fichier, char *mot);
int ReceptionUpload(char *nomFichier,unsigned long taille_fichier);
int CommandeS(char *requete);
int authentificationS(char *requete);


/* Initialisation.
 * Creation du serveur en pr�cisant le service ou num�ro de port.
 * renvoie 1 si �a c'est bien pass� 0 sinon
 */
int InitialisationAvecService(char *service);


/* Attends qu'un client se connecte.
 * renvoie 1 si �a c'est bien pass� 0 sinon
 */
int AttenteClient();

/* Recoit un message envoye par le client.
 * retourne le message ou NULL en cas d'erreur.
 * Note : il faut liberer la memoire apres traitement.
 */
char *Reception();

/* Envoie un message au client.
 * Attention, le message doit etre termine par \n
 * renvoie 1 si �a c'est bien pass� 0 sinon
 */
int Emission(char *message);

/* Recoit des donnees envoyees par le client.
 * renvoie le nombre d'octets re�us, 0 si la connexion est ferm�e,
 * un nombre n�gatif en cas d'erreur
 */

 int extraitFichier(char *requete, char *tableauNomFichier, int tailleTableauNomFichier);

/* extrait du nom du fichier demand� d'une requete HTTP
 * le nom sera copi� dans tableauNomFichier
 */

 unsigned long longueur_fichier(char *nomFichier);

/* calcule la longueur d'un fichier
 * retourne la taille du fichier
 */

 int envoyerContenuFichierTexte(char *nomFichier);
/* affiche le contenu d'un fichier
 * retourne le nombre de caract�res lus
 */

 int envoyerContenuFichierBinaire(char *nomFichier);
/* affiche une image
 * retourne le nombre de caract�res lus
 */

 int envoyerReponse200HTML(char *nomFichier);
/*renvoie une r�ponse http de type 200 OK
 *renvoie les entetes content type, content length, et la taille du fichier
 */

 int envoyerReponse200JPG(char *nomFichier);
/*renvoie une r�ponse JPG de type 200 OK
 *renvoie les entetes content type, content length, et la taille du fichier
 */

 int envoyerReponse200ICO(char *nomFichier);
/*renvoie une r�ponse ICO de type 200 OK
 *renvoie les entetes content type, content length, et la taille du fichier
 */

 int envoyerReponse404(char *nomFichier);
/*renvoie une r�ponse http de type 404 NOT FOUND
 *renvoie les entetes content type, content length, et la taille du fichier
 */

 int envoyerReponse500(char *message);
/*renvoie une r�ponse http de type 500 SERVER ERROR
 *renvoie les entetes content type, content length, et la taille du fichier
 */

int ReceptionBinaire(char *donnees, size_t tailleMax);

/* Envoie des donn�es au client en pr�cisant leur taille.
 * renvoie le nombre d'octets envoy�s, 0 si la connexion est ferm�e,
 * un nombre n�gatif en cas d'erreur
 */
int EmissionBinaire(char *donnees, size_t taille);


/* Ferme la connexion avec le client.
 */
void TerminaisonClient();

/* Arrete le serveur.
 */
void Terminaison();

#endif
