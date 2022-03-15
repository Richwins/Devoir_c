/*
3- Reprendre la question 2 de mani�re � ce que le p�re envoie
 un nombre secret au processus fils. (Vous pouvez utiliser les pipes)
 */
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

int main(int argc, char *argv[])
{
// on creer un tableau de deux entrer
    int p[2], result; 
    pid_t pid;
    /* demande de cr�ation du pipe au syst�me*/
    result = pipe(p); // creation du tunnel result
    if (result < 0)
    { /* Une erreur s'est produite lors de la cr�ation du pipe*/
        fprintf(stderr, "Erreur de cr�ation du pipe (%d)\n", errno);
        return 1;
    }

    pid = fork(); // cr�ation du processus fils
    if (pid < 0)
    { /* Une erreur s'est produite lors de la cr�ation du processus fils*/
        fprintf(stderr, "Erreur de cr�ation du fils(%d)\n", errno);
        return 1;
    }

    // Lecture du secret
    if (pid == 0)
    {             
    /*Dans le fils*/
        close(p[1]); /* l'extr�mit� d'�criture du pipe du fils est fermee*/
        char secret[BUFSIZ + 1];
        while (read(p[0], secret, BUFSIZ) != 0)
        { /* Lecture des donn�es du pipe par le fils*/
            printf("Fils : j'ai recus ce nombre secret de mon pere ( %s )\n", secret);
        }
        exit(0);
    }
    else
    {
        close(p[0]); /* l'extr�mit� de lecture du pipe* du pere est fermee*/
        char secret[BUFSIZ];
        printf("Le nombre secret a envoyer au fils :");/*l'utulisateur entre le nombre secret � envoyer*/
        scanf("%s", secret);                  /* Le p�re lit une chaine de caract�re saisie au clavier*/
        write(p[1], secret, strlen(secret)); /*�criture de la chaine de caract�re dans le pipe */
    }
}
