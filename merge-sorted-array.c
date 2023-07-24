// submission: https://leetcode.com/problems/merge-sorted-array/submissions/
// Time complexity: O(n log n)

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
  
int partition(int* arr, int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
  
void quicksort(int* arr, int low, int high)
{
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    for (int i = m; i < nums1Size; i++){
        nums1[i] = nums2[i-m];
    }
    quicksort(nums1,0,nums1Size-1);
}
