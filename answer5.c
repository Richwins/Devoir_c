/*5- Reprendre la question 1) et ajouter la possibilité de vérifier que la copie s'est bien passée
 @ en exploitant le code de la question 4).
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include "md5.h"

int main(int argc, char *argv[])
{
     // Si l'utilisateur entre plus de deux fichier en paramètre , il y a erreur
    if (argc != 3)
    {
        fprintf(stderr, "Usage : %s <arg1><arg2>\n", argv[0]);
        return 1;
    }

    // déclaration des fichiers
    FILE *fichier1, *fichier2;

     // ouverture du fichier en mode lecture
    fichier1 = fopen(argv[1],"r");
    char *res1;
    MD5File(argv[1],res1);
    printf("le md5 du fichier destination avant la copie est :%s",res1);
    if (fichier1 == NULL)
    {
        printf("ERREUR:ouverture impossible %s\n", argv[1]);
        exit(1);
    }
    
    // ouverture en mode d'écriture
    fichier2 = fopen(argv[2], "w");
    if (fichier2 == NULL)
    {
        fclose(fichier1);
        printf("ERREUR:ouverture impossible %s\n", argv[2]);
        exit(2);
    }
    else
    {
        int var = 0;
        while (1)
        {
            var = fgetc(fichier1);
            fputc(var, fichier2);
            printf("%c", var);
            if (var == EOF)
                break;
        }
    }
    printf("copie terminée.\n");
    char *res2;
    MD5File(argv[1],res2);
    printf("le md5 du fichier destination avant la copie est :%s",res2);
    
    /*vérification de l'intégrité de la copie*/
    if(res1!=res2)
    {
        printf("la copie s'est bien passé");
    }
    else
    {
        printf("la copie s'est mal terminé");
    }   
    fclose(fichier1);
    fclose(fichier2);
    return 0;
}
