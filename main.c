#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include "sorts.h"

int get_random(int *state, int max) {
    uint32_t x = (uint32_t) *state;
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
    *state = x;
    return (int)((x % max) + 1);
}

int main(){  
    int n, sel, sort;
    clock_t inicio, fim;
    double tempo_cpu;

    printf("Selecione o tamanho do vetor:\n");
    scanf("%d", &n);

    printf("Selecione o tipo de vetor:\n 1. Vetor ordenado \n 2. Vetor ordenado inverso\n 3. Vetor aleatório\n");
    scanf("%d", &sel);

    printf("Selecione o algoritmo:\n 1. Bubble Sort\n 2. Selection Sort\n 3. Insertion Sort\n 4. Shell Sort\n 5. Quick Sort\n 6. Heap Sort\n 7. Merge sort\n 8. Contagem de Menores\n 9. Radix sort\n");
    scanf("%d", &sort);

    int* arr = (int*)malloc(n * sizeof(int));
    if(arr == NULL) return 1;
    
    int* counts = (int*)malloc(2 * sizeof(int));
    if(counts == NULL) {free(arr); return 1;}

    counts[0] = 0; // Comparações
    counts[1] = 0; // Trocas

    switch(sel){
        case 1:
        for(int i = 0; i < n; i++){
            arr[i] = i + 1;
        }
        break;

        case 2: 
        for(int i = 0; i < n; i++){
            arr[i] = n - i;
        }
        break;

        case 3:
        int seed = 12345; //Não altere esse valor.
        for(int i = 0; i < n; i++){
            arr[i] = get_random(&seed, n);
        }
        break;
    }

    inicio = clock(); 
    switch(sort){
        case 1:
            bubble_sort(arr, n, counts);
            break;

        case 2:
            selection_sort(arr, n, counts);
            break;
        
        case 3:
            insertion_sort(arr, n, counts);
            break;

        case 4:
            shellSort(arr, n, counts);
            break;

        case 5:
            quick_sort(arr, 0, n - 1, counts);
            break;

        case 6:
            heap_sort(arr, n, counts);
            break;

        case 7:
            mergeSort(arr, 0, n - 1, counts);
            break;

        case 8:
            ContagemMenores(arr, n, counts);
            break;

        case 9:
            radix_sort(arr, n, counts);
            break;
            
        default:
            printf("Opcao invalida.\n");
    }

    fim = clock();
    tempo_cpu = ((double) (fim - inicio)) / CLOCKS_PER_SEC;

    printf("\n---------------- RESULTADOS ----------------\n");
    printf("Tempo de execucao: %f segundos\n", tempo_cpu);
    printf("Comparacoes:       %d\n", counts[0]);
    printf("Trocas/Movim.:     %d\n", counts[1]);
    printf("--------------------------------------------\n");

    free(arr);
    free(counts);
    return 0;
}
