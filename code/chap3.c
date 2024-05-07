#include <stdio.h> 
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h> 
int main(int argc, char *argv[]) { 
    /* crea un duplicato del padre */ 
    int pid=fork(); 
    if (pid < 0) { 
        fprintf(stderr, "Fork Failed\n"); 
        exit(1); 
    } 
    else if (pid == 0) { 
        /* processo figlio */

        /* viene eseguito un nuovo programma */ 
        execl("/bin/ls", "ls", NULL); 
    } 
    else { 
        /* processo padre */ 

        /* attende che il figlio termini */ 
        wait(NULL); 
        printf("Child Complete\n"); 
        exit(0); 
    } 
    return 1; /* non dovrebbe accadere */ 
}