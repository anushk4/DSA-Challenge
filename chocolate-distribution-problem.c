#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// simply sorting the array and finding a subset of size m with minimum difference of maximum and minimum values.
 
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
  
int partition(int arr[], int low, int high)
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

int main(){
    int n;
    int m;
    scanf("%d",&n);
    int* arr=(int*)malloc(n*sizeof(int));
    for (int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    scanf("%d",&m);
    quicksort(arr,0,n);
    int min_diff = INT_MAX;
    for (int i=0;i<=n-m;i++){
        int diff = arr[i+m-1] - arr[i];
        diff < min_diff ? min_diff = diff : printf(""); 
    } 
    // number of packets can't be less than number of students
    if (n < m){
       printf("-1");
    }else{
       printf("%d",min_diff);
    }
    return 0;
}
