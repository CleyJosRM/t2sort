#include "sorts.h"

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*----------------bubble-------------------*/
void bubble_sort(int* array, int n, long long int* counts){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i - 1; j++){
            counts[0]++;
            if(array[j] > array[j + 1]){
                swap(&array[j], &array[j + 1]);
                counts[1]++;
            }
        }
    }
}

/*------------selection----------------*/
void selection_sort(int* array, int n, long long int* counts){
    for(int i = 0; i < n - 1; i++){
        int min = i;
        for(int j = i + 1; j < n; j++){
            counts[0]++;
            if(array[j] < array[min]){
                min = j;
            }
        }
        swap(&array[min], &array[i]);
        counts[1]++;
    }
}

/*-------------insertion sort--------------*/
void insertion_sort(int* array, int n, long long int* counts){
    for(int i = 1; i < n; i++){
        int key = array[i]; 
        int j = i - 1;

        while(j >= 0){
            counts[0]++;

            if(array[j] > key){
                array[j + 1] = array[j];
                counts[1]++;
                j--;
            }else{
                break;
            }
        }
        array[j + 1] = key;
        counts[1]++;
    }
}

/*-------------shell sort--------------*/
void shellSort(int* arr, int n, long long int* counts){
    
    int seqSedgewick[] = {
    16764929, 9427969, 4188161, 2354689, 1045505, 
    587521, 260609, 146305, 64769, 36289, 16001, 8929, 
    3905, 2161, 929, 505, 209, 109, 41, 19, 5, 1
    };
    int lenSedgewick = 22;

    for(int k = 0; k < lenSedgewick; k++){
        int gap = seqSedgewick[k];

        if(gap >= n){
            continue;
        }
        for(int i = gap; i < n; i++){  
            int temp = arr[i];
            int j;
            
            for(j = i; j >= gap; j -= gap){
                counts[0]++;

                if(arr[j - gap] > temp){
                    arr[j] = arr[j - gap];
                    counts[1]++;
                }else{
                    break;
                }
            }            
            arr[j] = temp;
            counts[1]++;
        }
    }
}

/*---------------quick-------------------*/
int pivotMediana(int* array, int left, int right, long long int* counts){

    int mid = left + (right - left) / 2;
    if(array[left] > array[mid]){
        swap(&array[left], &array[mid]);
        counts[1]++;
    }
    if(array[left] > array[right]){
        swap(&array[left], &array[right]);
        counts[1]++;
    }
    if(array[mid] > array[right]){
        swap(&array[mid], &array[right]);
        counts[1]++;
    }

    swap(&array[mid], &array[right]);
    counts[0] += 3;
    counts[1]++;

    return array[right];
}

int partition(int* array, int left, int right, long long int* counts){

    int pivot = pivotMediana(array, left, right, counts);
    int i = left -1;
    int j = left;
    for(;j < right; j++){
        counts[0]++;
        if(array[j] < pivot){
            i++;
            swap(&array[i], &array[j]);
            counts[1]++;
        }
    }
    swap(&array[i + 1], &array[right]);
    counts[1]++;
    return i + 1;
}

void quick_sort(int* array, int left, int right, long long int* counts){
    if(left < right){
        int pivot = partition(array, left, right, counts);
        quick_sort(array, left, pivot - 1, counts);
        quick_sort(array, pivot + 1, right, counts);
    }
}

/*---------------heap--------------------*/
void heapify(int* array, int k, int size, long long int* counts){
    int l = 2*k + 1;
    int r = 2*k + 2;

    int max = k;

    if(l < size && array[l] > array[max]){
        max = l;
    }
    if(r < size && array[r] > array[max]){
        max = r;
    }
    counts[0] += 2;
    if(max != k){
        swap(&array[k], &array[max]);
        counts[1]++;
        heapify(array, max, size, counts);
    }
}

void build_max_heap(int* array, int size, long long int* counts){
    int k = size/2 - 1;

    for(int i = k; i >= 0; i--){
        heapify(array, i, size, counts);
    }
}

void heap_sort(int* array, int size, long long int* counts){
    build_max_heap(array, size, counts);

    for(int i = 0; i < size; i++){
        swap(&array[0], &array[size - 1 - i]);
        counts[1]++;
        heapify(array, 0, size - 1 - i, counts);
    }
}

/*---------------merge sort--------------------*/
void merge(int v[], int esq, int meio, int dir, int *counts){
    int n1 = meio - esq + 1;
    int n2 = dir - meio;

    int auxEsq[n1];
    int auxDir[n2];

    //Copia os valores para os vetores auxiliares
    memcpy(auxEsq, &v[esq], n1 * sizeof(int));
    memcpy(auxDir, &v[meio + 1], n2 * sizeof(int));

    int i = 0, j = 0, k = esq;

    //Entre os vetores, ordena selecionando o maior
    while(i < n1 && j < n2){
        if(auxEsq[i] <= auxDir[j]){
            v[k] = auxEsq[i];
            i++;
        }
        else{
            v[k] = auxDir[j];
            j++;
        }
        counts[0] += 1;
        k++;
    }

    //Garantimos que percorremos todos os indices
    while(i < n1){
        v[k] = auxEsq[i];
        i++;
        k++;
    }
    while(j < n2){
        v[k] = auxDir[j];
        j++;
        k++;
    }
}

void mergeSort(int v[], int inicio, int fim, int* counts){
    int meio;
    if(inicio < fim){
        meio = (fim + inicio)/2;
        mergeSort(v, inicio, meio, counts);
        mergeSort(v, meio + 1, fim, counts);
        merge(v, inicio, meio, fim, counts);
    }
}

/*---------------Counting sort--------------------*/
int Maior(int v[], int size, int *counts){
    int maior = v[0];
    for(int i = 0; i < size; i++){
        if(v[i] > maior){
            maior = v[i];
        }
        counts[0] += 1;
    }
    return maior;
}
void countingSort(int v[], int size, int *counts){ 
    int maior = Maior(v, size, counts);
    int aux[maior + 1];
    memset(aux, 0, sizeof(aux)); //Inicia com 0

    //Conta as aparições dos elementos
    for(int i = 0; i < size; i++){
        int index = v[i];
        //Se já existir um valor no indice
        if(aux[index]){
            aux[index] += 1;
        }
        else{
            aux[index] = 1;
        }
    }

    //Ordena o vetor
    int j = 0;
    for(int i = 0; i < maior+1; i++){
        while(aux[i] > 0){
            v[j] = i;
            j++;
            aux[i]--;
        }
    }
}

/*---------------Radix sort--------------------*/
typedef struct{
    int *lista;
    int tamanho;
} Bucket;

Bucket *Bucket_criar(int n){
    Bucket *buckets = (Bucket *) malloc(10* sizeof(Bucket));
    if(!buckets){
        printf("Erro ao alocar lista de Buckets!");
        exit(1);
    }
    for(int i = 0; i < 10; i++){
        buckets[i].lista = (int *) calloc(n, sizeof(int));
        if(!buckets[i].lista){
            printf("Erro ao alocar lista nos Buckets!");
            exit(1);
        }
        buckets[i].tamanho = 0;
    }
    return buckets;
}

void Bucket_excluir(Bucket *buckets){
    for(int i = 0; i< 10; i++){
        free(buckets[i].lista);
    }
    free(buckets);
}

void radix_sort(int v[], int n, int *counts){
    int k = Maior(v, n, counts); //pega o maior elemento

    Bucket *buckets = Bucket_criar(n);

    for(int base = 1; k/base > 0; base *= 10){
        //Pegando apenas ordens (unidade, dezena, centena...)
        //Recolhendo os números nos buckets correspondentes
        for(int i = 0; i < n; i++){
            int digito = (v[i]/base) % 10;
            int tam = buckets[digito].tamanho; //Auxiliar para evitar expressões muito longas
            buckets[digito].lista[tam] = v[i];
            buckets[digito].tamanho++;
        }

        int index = 0;
        for(int i = 0; i < 10; i ++){
            //Percorre os buckets e insere no vetor
            for(int j = 0; j < buckets[i].tamanho; j++){
                v[index] = buckets[i].lista[j];
                index++;
            }
            buckets[i].tamanho = 0;
        }
    }

    Bucket_excluir(buckets); //Libera os buckets auxiliares
}



