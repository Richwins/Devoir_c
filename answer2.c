/*2- un programme qui cree un processus fils.
Le fils affiche le pid de son pere. Le pere affiche le pid de son fils.
*/
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
    pid_t pid_fils = fork();
    if (pid_fils < 0)
    {
        /* Il y a erreur*/
        fprintf(stderr, "Erreur de creation du processus (%d) (%d)\n", pid_fils, errno);
        return 1;
    }
    else if (pid_fils == 0)
    {
        /* le processus fils*/
        printf("je suis le fils .Mon PID est :(%d), celui de mon pere est :(%d)\n", getpid(), getppid());
    }
    else
    {
        /* le pere*/
        printf("Je suis le pere .Mon PID est :(%d) ,celui de mon fils est : (%d)\n",getpid(), pid_fils);
    }
    return 0;
}
