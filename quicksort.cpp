int partition(vector<int>& arr, int st, int end) {
    //invariant after processing jth element
    //small elements: [st, i], big elements: [i + 1 -> j]
    int pivot = arr[end], i = st - 1;
    for(int j = st; j < end; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[end]);
    return i + 1;
}
void quicksort(vector<int>& arr, int st, int end) {
    if(st < end) {
        int p = partition(arr, st, end);
        quicksort(arr, st, p - 1);
        quicksort(arr, p + 1, end);
    }
}