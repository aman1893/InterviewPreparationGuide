int getRandom(int lo, int hi) {
    return lo + (rand() % (hi - lo + 1));
}
int partition(vector<int>& arr, int st, int end) {
    //Adding randomization to quicksort
    int randomIndex = getRandom(st, end);
    swap(arr[randomIndex], arr[end]);
    
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
//Adding tail call elimintaion to limit space complexity to O(log(n))
void quicksort(vector<int>& arr, int st, int end) {
    while(st < end) {
        int p = partition(arr, st, end);
        if(p - st < end - p) {
            quicksort(arr, st, p - 1);
            st = p + 1;
        } else {
            quicksort(arr, p + 1, end);
            end = p - 1;
        }
    }
}