void maxHeapify(vector<int>& arr, const int kHeapSize, int idx) {
    int left = (idx << 1) + 1;
    int right = (idx << 1) + 2;
    int largestIndex = idx;
    
    if(left < kHeapSize && arr[left] > arr[largestIndex])
        largestIndex = left;
    if(right < kHeapSize && arr[right] > arr[largestIndex])
        largestIndex = right;
    
    if(largestIndex != idx) {
        swap(arr[idx], arr[largestIndex]);
        maxHeapify(arr, kHeapSize, largestIndex);
    }
}    
void heapsort(vector<int>& arr) {
    //Parent = (x-1)/2
    int n = arr.size();
    //start is parent of n-1 index which is (n-2)/2
    for(int i = n/2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);
    
    for(int i = n-1; i > 0; i--) {
        swap(arr[0], arr[i]);
        maxHeapify(arr, i, 0);
    }
}
