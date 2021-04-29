#include "bits/stdc++.h"
#include "SortAlgorithm.h"

using namespace std;

int main(){
    int arr[] = { 22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70 };
    int len = sizeof(arr)/sizeof(*arr);
//    BubbleSort(arr, 5);
    //InsertSort(arr, 5);
//    QuickSort(arr, 0, len-1);
    //MergeSort(arr, 0 ,len-1);
    //ShellSort(arr, len);
    //HeapSort(arr, len);
    //CountingSort(arr, len, 100);
    //BucketSort(arr,len, 10);
    RadixSort(arr, len);
    for(auto i : arr){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
