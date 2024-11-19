#include <stdio.h>
#include <stdlib.h>

void imprime_histograma(char* a[], int vendas[], int produto){
    
    for(int i = 0; i < produto; i++) {
        
        printf("%d ", vendas[i]);  
        
        for(int j = 0; j < vendas[i]; j++){
            
            printf("%c", a[i][j]); 
        }
        
        printf("\n");
    }
}

void v_histograma(char *a[], int vendas, int produto) {
    
    for(int i = 0; i < vendas; i++){
        if(a[produto][i] >= 0)
        {
        a[produto][i] = '*';
        }
    }
    if(a[produto][vendas]){
        
        a[produto][vendas] = '\0';

    }
}


int main(){
    
    int produto;
    
    scanf("%d", &produto);  
    
    if(produto <= 0){
        printf("vazio\n");
        return 0;
    }
    
    int vendas[produto];
    char* hist[produto];  

    for (int i = 0; i < produto; i++) {
        
        scanf("%d", &vendas[i]); 
        
        if (vendas[i] == 0){
            
            hist[i] = NULL;  
            
        }else
        {
            hist[i] = (char*)malloc((vendas[i] + 1) * sizeof(char));
            
            v_histograma(hist, vendas[i], i);  
        }
    }
    
    
    imprime_histograma(hist, vendas, produto);  
    
    for (int i = 0; i < produto; i++) {
        free(hist[i]);
}
    return 0; 
}
