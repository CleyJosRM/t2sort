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

/*---------------quick-------------------*/
int partition(int* array, int left, int right){
    int pivot = array[right];
    int i = left -1;
    int j = left;
    for(;j < right; j++){
        if(array[j] < pivot){
            i++;
            int aux = array[i];
            array[i] = array[j];
            array[j] = aux;
        }
    }
    array[right] = array[i + 1];
    array[i + 1] = pivot;

    return i + 1;
}

void quick_sort(int* array, int left, int right){
    if(left < right){
        int pivot = partition(array, left, right);
        quick_sort(array, left, pivot - 1);
        quick_sort(array, pivot + 1, right);
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
