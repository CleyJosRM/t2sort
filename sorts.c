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
