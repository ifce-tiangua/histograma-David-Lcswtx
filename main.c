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

void v_histograma(char *a[], int q, int produto){

    for(int i = 0; i < q; i++){
        if(a[produto][i] >= 0)
        {
        a[produto][i] = '*';
        }
    }
}


int main(void){

    int i, p;
    
    scanf("%d", &p);
    if(p <= 0){
        return 0;
    }else{
    int vendas[p];
    char *hist[p];

    for(i = 0; i < p; i++){

        scanf("%d", &vendas[i]);
        
        if (vendas[i] == 0){

        hist[i] = NULL;

        }else
        {

            hist[i] = (char *)malloc(vendas[i] * sizeof(char));

            v_histograma(hist, vendas[i], i);
        }
    }


    imprime_histograma(hist, vendas, p);
    
    for(i = 0; i < p; i++){
        free(hist[i]);
    }
}
    return 0;
}
