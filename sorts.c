#include <string.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*----------------bubble-------------------*/
void bubble_sort(int* array, int n){
    int swapped = 1; // 1
    for(int i = 0; i < n && swapped; i++){ // 2 + n + 1 + 2 + n + 1
        swapped = 0; // 1
        for(int j = 0; j < n - i - 1; j++){ // 2 + 
            if(array[j] > array[j + 1]){
                int aux = array[j + 1];
                array[j + 1] = array[j];
                array[j] = aux;
                swapped = 1;
            }
        }
    }
}

/*------------selection----------------*/
void selection_sort(int* array, int n){

    for(int i = 0; i < n - 1; i++){
        int min = i;
        for(int j = i + 1; j < n; j++){
            if(array[j] < array[min]){
                min = j;
            }
        }
        int aux = array[min];
        array[min] = array[i];
        array[i] = aux;
    }
}

/*-------------shell sort--------------*/
void shellSort(int* arr, int n){
    
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
            
            for(j = i; j >= gap && arr[j - gap] > temp; j -= gap){
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

/*---------------quick-------------------*/
int pivotMediana(int* array, int left, int right){

    int mid = left + (right - left) / 2;
    if(array[left] > array[mid]){
        swap(&array[left], &array[mid]);
    }
    if(array[left] > array[right]){
        swap(&array[left], &array[right]);
    }
    if(array[mid] > array[right]){
        swap(&array[mid], &array[right]);
    }

    swap(&array[mid], &array[right]);

    return array[right];
}

int partition(int* array, int left, int right){

    int pivot = pivotMediana(array, left, right);
    int i = left -1;
    int j = left;
    for(;j < right; j++){
        if(array[j] < pivot){
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[right]);

    return i + 1;
}

void quick_sort(int* array, int left, int right){
    if(left < right){
        int pivot = partition(array, left, right);
        quick_sort(array, left, pivot - 1);
        quick_sort(array, pivot + 1, right);
    }
}

/*---------------heap--------------------*/
void heapify(int* array, int k, int size){
    int l = 2*k + 1;
    int r = 2*k + 2;

    int max = k;

    if(l < size && array[l] > array[max]){
        max = l;
    }
    if(r < size && array[r] > array[max]){
        max = r;
    }
    if(max != k){
        int aux = array[k];
        array[k] = array[max];
        array[max] = aux;

        heapify(array, max, size);
    }
}

void build_max_heap(int* array, int size){
    int k = size/2 - 1;

    for(int i = k; i >= 0; i--){
        heapify(array, i, size);
    }
}

void heap_sort(int* array, int size){
    build_max_heap(array, size);

    for(int i = 0; i < size; i++){
        int aux = array[size - 1 - i];
        array[size - 1 - i] = array[0];
        array[0] = aux;
        heapify(array, 0, size - 1 - i);
    }
}

/*---------------merge--------------------*/
void merge(int v[], int esq, int meio, int dir){
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

void mergeSort(int v[], int inicio, int fim){
    int meio;
    if(inicio < fim){
        meio = (fim + inicio)/2;
        mergeSort(v, inicio, meio);
        mergeSort(v, meio + 1, fim);
        merge(v, inicio, meio, fim);
    }
}

/*---------------Counting--------------------*/
void countingSort(int v[], int size){
    //Procura o maior
    int maior = v[0];
    for(int i = 0; i < size; i++){
        if(v[i] > maior){
            maior = v[i];
        }
    }
    int aux[maior+1] = {}; //inicia com 0

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