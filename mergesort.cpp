//Call: mergesort(arr, 0, arr.size() - 1)
void mergesort(vector<int>& arr, int st, int end) {
    if(st < end) {
        int mid = (st + end) / 2;
        mergesort(arr, st, mid);
        mergesort(arr, mid + 1, end);
        vector<int> res(end - st + 1);
        for(int in = 0, l = st, r = mid + 1; l <= mid || r <= end; in++) {
            if(l > mid) {
                res[in] = arr[r];
                r++;
            } else if(r > end) {
                res[in] = arr[l];
                l++;
            } else {
                if(arr[l] <= arr[r]) {
                    res[in] = arr[l];
                    l++;
                } else {
                    res[in] = arr[r];
                    r++;
                }
            }
        }
        copy(res.begin(), res.end(), arr.begin() + st);
    }
}