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

void v_histograma(char *a[], int venda, int produto){

    for(int i = 0; i < venda; i++){
        if(a[produto][i] >= 0)
        {
        a[produto][i] = '*';
        }
    }
}


int main(void){

    int i, produto;
    
    scanf("%d", &produto);
    if(produto <= 0){
        return 0;
    }else{
    int vendas[produto];
    char *hist[produto];

    for(i = 0; i < produto; i++){

        scanf("%d", &vendas[i]);
        
        if (vendas[i] == 0){

        hist[i] = NULL;

        }else
        {

            hist[i] = (char *)malloc((vendas[i] + 1) * sizeof(char));

            v_histograma(hist, vendas[i], i);
        }
    }


    imprime_histograma(hist, vendas, produto);
    
    for(i = 0; i < produto; i++){
        free(hist[i]);
    }
}
    return 0;
}
