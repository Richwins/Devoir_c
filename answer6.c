/*4-calcul de md5 de 1000 fichiers*/
#include <stdio.h>
#include <sys/types.h>
#include "md5.h"
#include <pthread.h>
#include <unistd.h>
//déclaration d'une fonction de calcul de md5 d'un fichier

//chaque thread calcul le md5 de 100 fichiers
    pthread_mutex_t mutex;
    void * helloworld(void * arg) {
    int i;
    for (i = 0; i < 100; i++) {
        pthread_mutex_lock(&mutex);

        //Demander à l'utilisateur d'entrer le nom de fichier
        char *filname;
        printf("Donner le nom du fichier à manipuler");
        scanf("%s",filname);
        FILE *file = fopen(filname,"r");
        if(!outfile)
        {
            printf("\a ERREUR : ouverture impossible\n");
            exit(2);
        }
        else
        {
        char *result;
        MD5File(filname,result);
        printf("le md5 du fichier courant est :%s",result);
        fclose(file);
        }
        pthread_mutex_unlock(&mutex);
 }
return NULL;
 }

int main()
{
    int i, nb;
    int * args;
    pthread_t * threads;
    nb = 10;
    threads = malloc(nb * sizeof(pthread_t));
    args = malloc(nb * sizeof(int));
    pthread_mutex_init(&mutex, NULL);

    //creer 10 thread pour calcuer le md5 des 1000 fichiers
    for (i = 0; i < nb; i++) {
    args[i] = i;
    pthread_create(&threads[i], NULL, helloworld, &args[i]);
    }
    for (i = 0; i < nb; i++) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}
