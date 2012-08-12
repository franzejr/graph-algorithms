#include <time.h>
#include <stdio.h>
#include <stdlib.h>


struct neighbor {
   int    id;
   int    weight;
   struct neighbor *next;
};

struct vertex {
   int    id;
   int    pai;
   int    cor;
   int    dist;
   struct neighbor *adj_list;
};

int uniforme (int i, int j)
{
    return(i + rand () % j);
}

int geometrica (int m)
{
    int v = 0;
    int aux;
    
    do {
        v++;
        aux = rand () % m;
    } while (aux != 0);

    return(v);
}

int main (int argc, char *argv[])
{
    int  i,j,k,count;

    struct vertex* G;      // graph represented by adjacency list
    int     n = 8;        // number of vertices in G
    double  vm = 4;        // numero medio de vizinhos

    int    no_viz, *vizs, flag;
    struct neighbor *aux, *viz;


    // Inicializacao

    if (argc > 1) {
       n = atoi(argv[1]);
       vm = atoi(argv[2]);
    } 

    srand((unsigned)time(NULL));

    vizs = (int *) malloc (sizeof (int) * n);
    G = (struct vertex *) malloc (sizeof (struct vertex) * n);
    for ( i = 0; i < n; i++ ) {
          G[i].id = i+1;
          G[i].adj_list = NULL;
    }


    // Geracao aleatoria do grafo G

    for ( i = 0; i < n; i++ ) {

        no_viz = geometrica(vm); 

        for ( j = 0; j < no_viz; j++ ) {

            viz  = (struct neighbor *) malloc (sizeof(struct neighbor));

            do{ 
               viz->id  = uniforme (1,n);          // verifica repeticoes 
               flag = 0;
               for (k=0;k<j;k++)  if (vizs[k] == viz->id)  flag = 1;
            } while(flag == 1);
            vizs[j] = viz->id;

            viz->weight = geometrica((int)n/vm); 

            aux = G[i].adj_list;
            viz->next = aux;
            G[i].adj_list = viz;
        }
    }


    // Imprime o grafo G

    printf ("%d\n",n);
    for ( i = 0; i < n; i++ ) {

          printf ("v%d,", G[i].id);

          aux = G[i].adj_list;
          while (aux != NULL) {
                printf ("v%d", G[aux->id].id);
		aux = aux->next;
                if (aux != NULL)
                   printf (",");
          }

          aux = G[i].adj_list;
          if (aux != NULL)
             printf ("/");
          while (aux != NULL) {
                printf ("%d", aux->weight);
		aux = aux->next;
                if (aux != NULL)
                   printf (",");
          }
          printf ("\n");

    }
}

