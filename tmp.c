#include <stdio.h>

// Auxiliar para encontrar o maior elemento do vetor
int MaiorR(int v[], int size){
    int maior = v[0];
    for(int i = 0; i < size; i++){
        if(v[i] > maior){
            maior = v[i];
        }
    }
    return maior;
}

void raidix_sort(int v[], int n){
    int k = MaiorR(v, n); //pega o maior elemento
    
    for(int i = 1; k/i > 0; i *= 10){
        //buckets
    }

}