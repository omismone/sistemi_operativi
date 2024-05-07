        #include <stdio.h>
        #include <stdlib.h>
        #include <pthread.h>

        void *test_thread(void *pt)
        {
            printf("thread: %s\n", (char *)pt);
            pthread_exit(pt);
        }

        void main()
        {
            pthread_t t;
            pthread_attr_t attr;
            void *res;
            char msg[6] = "hello";

            pthread_attr_init(&attr);

            /*
            * Crea un nuovo thread, simile ad una fork() seguita da una exec()
            *
            * 1 la struttura thread.
            * 2 la struttura attributi.
            * 3 puntatore a funzione che eseguira' il thread.
            * 4 argomento della funzione.
            * @return status
            */
            if(pthread_create(&t, &attr, test_thread, &msg[0]))
                exit(1);
            
            /*
            * Aspetta che il thread finisca, analogo di waitpid()
            * 
            * 1 il thread.
            * 2 variabile d'appoggio per la comunicazione con il thread figlio.
            */
            pthread_join(t, &res);
            if(res)
                printf("%s\n", (char *)res);
            return;
        }