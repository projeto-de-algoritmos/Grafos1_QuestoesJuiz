#include <stdio.h>
#include <stdlib.h>

int main(){
    int M, N, i, j;
    short int **matrizAdj, A, B;

    matrizAdj = malloc (12 * sizeof (short int*)) ;

    for (i=0; i<12; i++){
        matrizAdj[i] = malloc (12 * sizeof (short int));
        for (int j=0; j<12; j++) 
            matrizAdj[i][j] = 0;
    }

    while (scanf("%d%d", &N, &M) != EOF){
        for(i=0; i<M; i++){
            scanf("%d%d", &A, &B);
            matrizAdj[A][B] = 1;
            matrizAdj[B][A] = 1;
        }
        
    }

    return 0;
}