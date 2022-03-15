/*4- Ecrire un programme qui calcule le MD5 d'un fichier passé en paramètre.

#include <sys/types.h>
     #include <md5.h>*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include "md5.h"

int main(int argc, char *argv[])
{
      // Si l'utilisateur entre plus d'un fichier en paramètre , il y a erreur
    if (argc != 2)
    {
        fprintf(stderr, "Usage : %s <arg1>\n", argv[0]);
        return 1;
    }
    FILE *file = fopen(argv[1],"r");
    if(!file)
    {
        printf("\a ERREUR : ouverture de impossible\n");
        exit (0);
    }else
    {
    char *result;
    MD5File(argv[1],result);
    printf("le md5 du fichier est :%s",result);
    fclose(file);}
    return 0;
}
