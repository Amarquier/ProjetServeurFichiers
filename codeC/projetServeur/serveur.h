#ifndef __SERVEUR_H__
#define __SERVEUR_H__

/* Initialisation.
 * Creation du serveur.
 * renvoie 1 si ça c'est bien passé 0 sinon
 */
int Initialisation();


/**********************************************************************************/

/* Nom : Renommer
 * Role : Renomme un fichier
 * Renvoie : 1 si la commande s'est bien dÈroulÈe
 */
int Renommer (char* fichier, char* nom);

/* Nom : quota
 * Role : evalue le quota et l'augmente
 * Renvoie : 0 si le quota est dÈpassÈ, 1 sinon
 */
int quota(char *ID, unsigned long tailleFichier);

/* Nom : ajoutUser
 * Role : ajoute un utilisateur dans utilisateurs.txt
 * Renvoie : 1 si la commande s'est bien dÈroulÈe
 */
int ajoutUser(char *nom);

/* Nom : Decomposition
 * Role : dÈcompose une requete pour en extraire l'ID.mdp, la commande, et l'ÈlÈment auxiliaire
 * Renvoie : 1 si la commande s'est bien dÈroulÈe
 */
int Decomposition(char *requete, char *ID, char *CMD, char *EA);

/* Nom : Recherche
 * Role : cherche un certain mot dans un certain fichier au choix
 * Renvoie : -1 s'il ya un probleme a l'ouverture du fichier
 *           0 si le mot n'a pas ÈtÈ trouvÈ
 *           1 si le mot a ÈtÈ trouvÈ
 */
int Recherche(char *fichier, char *mot);

/* Nom : ReceptionUpload
 * Role : recoit les fichiers uploadÈs par l'utilisateur
 * Renvoie : -1 s'il ya un probleme a l'ouverture du fichier
 *            1 si la commande s'est bien dÈroulÈe
 */
int ReceptionUpload(char *nomFichier,unsigned long taille_fichier);

/* Nom : CommandeS
 * Role : permet d'appeler d'autres commandes selon le choix de l'utilisateur
 * Renvoie : 1 si upload
 *           2 si download
 *           3 si ajout d'utilisateur
 *           4 si renommage
 *           5 si suppression
 */
int CommandeS(char *requete);

/* Nom : authentificationS
 * Role : permet a un utilisateur de s'authentifier
 * Renvoie : 1 si connectÈ en user normal
 *           2 si connectÈ en superuser
 *           0 si ID.mdp erronÈ
 */
int authentificationS(char *requete);

/**********************************************************************************/

/* Initialisation.
 * Creation du serveur en précisant le service ou numéro de port.
 * renvoie 1 si ça c'est bien passé 0 sinon
 */
int InitialisationAvecService(char *service);


/* Attends qu'un client se connecte.
 * renvoie 1 si ça c'est bien passé 0 sinon
 */
int AttenteClient();

/* Recoit un message envoye par le client.
 * retourne le message ou NULL en cas d'erreur.
 * Note : il faut liberer la memoire apres traitement.
 */
char *Reception();

/* Envoie un message au client.
 * Attention, le message doit etre termine par \n
 * renvoie 1 si ça c'est bien passé 0 sinon
 */
int Emission(char *message);

/* Recoit des donnees envoyees par le client.
 * renvoie le nombre d'octets reçus, 0 si la connexion est fermée,
 * un nombre négatif en cas d'erreur
 */

 int extraitFichier(char *requete, char *tableauNomFichier, int tailleTableauNomFichier);

/* extrait du nom du fichier demandÈ d'une requete HTTP
 * le nom sera copiÈ dans tableauNomFichier
 */

 unsigned long longueur_fichier(char *nomFichier);

/* calcule la longueur d'un fichier
 * retourne la taille du fichier
 */

 int envoyerContenuFichierTexte(char *nomFichier);
/* affiche le contenu d'un fichier
 * retourne le nombre de caractËres lus
 */

 int envoyerContenuFichierBinaire(char *nomFichier);
/* affiche une image
 * retourne le nombre de caractËres lus
 */

 int envoyerReponse200HTML(char *nomFichier);
/*renvoie une rÈponse http de type 200 OK
 *renvoie les entetes content type, content length, et la taille du fichier
 */

 int envoyerReponse200JPG(char *nomFichier);
/*renvoie une rÈponse JPG de type 200 OK
 *renvoie les entetes content type, content length, et la taille du fichier
 */

 int envoyerReponse200ICO(char *nomFichier);
/*renvoie une rÈponse ICO de type 200 OK
 *renvoie les entetes content type, content length, et la taille du fichier
 */

 int envoyerReponse404(char *nomFichier);
/*renvoie une rÈponse http de type 404 NOT FOUND
 *renvoie les entetes content type, content length, et la taille du fichier
 */

 int envoyerReponse500(char *message);
/*renvoie une rÈponse http de type 500 SERVER ERROR
 *renvoie les entetes content type, content length, et la taille du fichier
 */

int ReceptionBinaire(char *donnees, size_t tailleMax);

/* Envoie des données au client en précisant leur taille.
 * renvoie le nombre d'octets envoyés, 0 si la connexion est fermée,
 * un nombre négatif en cas d'erreur
 */
int EmissionBinaire(char *donnees, size_t taille);


/* Ferme la connexion avec le client.
 */
void TerminaisonClient();

/* Arrete le serveur.
 */
void Terminaison();

#endif
