Sure, I can help you with that. The provided IR code is for a function that takes a vector of integers as input and sorts it using the quicksort algorithm. Here's the decompiled C++ code:
```
void sort_array(vector<int>& arr) {
    int low = 0;
    int high = arr.size() - 1;
    quicksort(arr, low, high);
}

void quicksort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quicksort(arr, low, pivot - 1);
        quicksort(arr, pivot + 1, high);
    }
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    while (i <= j) {
        while (i <= j && arr[i] <= pivot) {
            i++;
        }
        while (i <= j && arr[j] >= pivot) {
            j--;
        }
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);
    return j;
}
```
Note that the decompiled code may not be exactly the same as the original source code, as the IR code may have been optimized or transformed in various ways during compilation. However, the decompiled code should still accurately represent the logic and behavior of the original program.