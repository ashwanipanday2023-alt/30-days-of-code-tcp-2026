class Solution {
public:
    void mergesort(vector<int>& arr, int l, int r) {
        int i = l;
        int j = (l + r) / 2 + 1;
        
        vector<int> temp;
        
        while (i <= (l + r) / 2 && j <= r) {
            if (arr[i] <= arr[j]) {
                temp.push_back(arr[i]);
                i++;
            } else {
                temp.push_back(arr[j]);
                j++;
            }
        }
        
        while (i <= (l + r) / 2) {
            temp.push_back(arr[i]);
            i++;
        }
        
        while (j <= r) {
            temp.push_back(arr[j]);
            j++;
        }
        
        for (int k = 0; k < temp.size(); k++) {
            arr[l + k] = temp[k];
        }
    }
    
    void mergeSort(vector<int>& arr, int l, int r) {
        if (l >= r)
            return;
        
        mergeSort(arr, l, (l + r) / 2);
        mergeSort(arr, (l + r) / 2 + 1, r);
        
        mergesort(arr, l, r);
    }
};
