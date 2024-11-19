#include <stdio.h>
#include <stdlib.h>


void imprime_histograma(char *a[], int vendas[], int produto){

    for(int i = 0; i < produto; i++){

        printf("%d ", vendas[i]);

        for(int j = 0; j < vendas[i]; j++){

            printf("%c", a[i][j]);
        }

        printf("\n");
    }
}

void v_histograma(char *a[], int q, int vendidos){

    for(int i = 0; i < q; i++){

        a[vendidos][i] = '*';
    }
}


int main(void){

    int i, p;
    
    scanf("%d", &p);

    int vendas[p];
    char *a[p];

    for(i = 0; i < p; i++){

        scanf("%d", &vendas[i]);
        
        if (vendas[i] == 0){

        a[i] = NULL;

        }else{

            a[i] = (char *)malloc( vendas[i] * sizeof(char) );

            v_histograma(a, vendas[i], i);
        }
    }


    imprime_histograma(a, vendas, p);
    
    for(i = 0; i < p; i++){
        free(a[i]);
    }

    return 0;
}
