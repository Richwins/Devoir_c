/*1- un programme qui copie le contenue
d'un fichier donn� en param�tre
 vers un autre fichier pass� en param�tre
 */
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
     // Si l'utilisateur entre plus de deux fichier en param�tre , il y a erreur
    if (argc != 3)
    {
        fprintf(stderr, "Usage : %s <arg1><arg2>\n", argv[0]);
        return 1;
    }

    // d�claration des fichiers
    FILE *file1, *file2;

     // ouverture du fichier en mode lecture
    file1 = fopen(argv[1], "r");
    if (file1 == NULL)
    {
        printf("ERREUR:ouverture impossible %s\n", argv[1]);
        exit(1);
    }

    // ouverture en mode d'�criture
    file2 = fopen(argv[2], "w");
    if (file2 == NULL)
    {
        fclose(file1);
        printf("ERREUR:ouverture impossible %s\n", argv[2]);
        exit(2);
    }
    else
    {
        int current_char = 0;
        while (1)
        {
            current_char = fgetc(file1);
            fputc(current_char, file2);
            printf("%c", current_char);
            if (current_char == EOF)
                break;
        }
    }
    printf("copie termin�e.\n");
    fclose(file1);
    fclose(file2);
    return 0;
}
