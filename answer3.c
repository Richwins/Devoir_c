/*
3- Reprendre la question 2 de manière à ce que le père envoie
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
    /* demande de création du pipe au système*/
    result = pipe(p); // creation du tunnel result
    if (result < 0)
    { /* Une erreur s'est produite lors de la création du pipe*/
        fprintf(stderr, "Erreur de création du pipe (%d)\n", errno);
        return 1;
    }

    pid = fork(); // création du processus fils
    if (pid < 0)
    { /* Une erreur s'est produite lors de la création du processus fils*/
        fprintf(stderr, "Erreur de création du fils(%d)\n", errno);
        return 1;
    }

    // Lecture du secret
    if (pid == 0)
    {             
    /*Dans le fils*/
        close(p[1]); /* l'extrémité d'écriture du pipe du fils est fermee*/
        char secret[BUFSIZ + 1];
        while (read(p[0], secret, BUFSIZ) != 0)
        { /* Lecture des données du pipe par le fils*/
            printf("Fils : j'ai recus ce nombre secret de mon pere ( %s )\n", secret);
        }
        exit(0);
    }
    else
    {
        close(p[0]); /* l'extrémité de lecture du pipe* du pere est fermee*/
        char secret[BUFSIZ];
        printf("Le nombre secret a envoyer au fils :");/*l'utulisateur entre le nombre secret à envoyer*/
        scanf("%s", secret);                  /* Le père lit une chaine de caractère saisie au clavier*/
        write(p[1], secret, strlen(secret)); /*écriture de la chaine de caractère dans le pipe */
    }
}
