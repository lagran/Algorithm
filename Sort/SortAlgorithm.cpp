#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 0x3f3f3f3f;

void BubbleSort(int arr[], int size){
    for(int i = 1; i < size; i++){
        bool flag = true;
        for(int j = 0; j < size-i; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                flag = false;
            }
        }
        if(flag){
            return;
        }
    }
}

void SelectionSort(int arr[], int size){
    for(int i = 0; i < size-1; i++){
        int min = arr[i], ind = i;
        for(int j = i+1; j < size; j++){
            if(arr[j] < min){
                min = arr[j];
                ind = j;
            }
        }
        swap(arr[i], arr[ind]);
    }
}

void InsertSort(int arr[], int size){
    for(int i = 0; i < size-1; i++){
        for(int j = i+1; j > 0 && arr[j] < arr[j-1]; j--){
            swap(arr[j], arr[j-1]);
        }
    }
}

void QuickSort(int arr[], int start, int end){
    if(start >= end){
        return;
    }
    int pivot = arr[start];
    int i = start, j = end;
    while(i < j){
        while(i < j && arr[j] > pivot){
            j--;
        }
        arr[i] = arr[j];
        while(i < j && arr[i] <= pivot){
            i++;
        }
        arr[j] = arr[i];
    }
    arr[i] = pivot;
    QuickSort(arr, start, i-1);
    QuickSort(arr, i+1, end);
}

void MergeSort(int arr[], int start, int end){
    if(start >= end){
        return;
    }
    int mid = (start + end)/2;
    MergeSort(arr, start, mid);
    MergeSort(arr, mid+1, end);
    int len = end - start + 1;
    int* tmp = new int[len];
    int i = start, j = mid + 1, k = 0;
    while(i <= mid || j <= end){
        if(i <= mid && j <= end){
            if(arr[i] < arr[j]){
                tmp[k++] = arr[i++];
            }else{
                tmp[k++] = arr[j++];
            }
        }else if(i <= mid){
            tmp[k++] = arr[i++];
        }else{
            tmp[k++] = arr[j++];
        }
    }
    for(i = 0; i < len; i++){
        arr[start + i] = tmp[i];
    }
    delete [] tmp;
}

void ShellSort(int arr[], int size){
    int gap = size / 2;
    while(gap > 0){
        for(int i = gap; i < size; i++){
            for(int j = i; j >= gap && arr[j] < arr[j-gap]; j -= gap){
                swap(arr[j], arr[j-gap]);
            }
        }
        gap /= 2;
    }
}

void max_heapfiy(int arr[], int start, int end){
    int parent = start;
    int son = start*2+1;
    while(son < end){
        if(son+1 < end && arr[son+1] > arr[son]){
            son++;
        }
        if(arr[parent] > arr[son]){
            return;
        }else{
            swap(arr[parent], arr[son]);
            parent = son;
            son = parent*2+1;
        }
    }
}

void HeapSort(int arr[], int size){
    if(size < 2)    return;
    for(int i = (size-1)/2; i >= 0; i--){
        max_heapfiy(arr, i, size);
    }
    for(int i = size-1; i > 0; i--){
        swap(arr[i], arr[0]);
        max_heapfiy(arr, 0, i);
    }
}

void CountingSort(int arr[], int size, int max_value){
    int* count = new int[max_value+1];
    memset(count, 0, sizeof(count));
    for(int i = 0; i < size; i++){
        count[arr[i]]++;
    }
    int cnt = 0;
    for(int i = 0; i <= max_value; i++){
        while(count[i]--){
            arr[cnt++] = i;
        }
    }
}

struct Node{
    int val;
    Node* next;
    Node() : val(), next(nullptr){}
    Node(int x, Node* n): val(x), next(n){}
};

void BucketSort(int arr[], int size, int bucket_size){
    if(size < 2)    return;
    int min = MAX, max = -MAX;
    for(int i = 0; i < size; i++){
        if(arr[i] > max){
            max = arr[i];
        }
        if(arr[i] < min){
            min = arr[i];
        }
    }
    int num = ceil((max + 1.0 - min)/bucket_size);
    Node* list = new Node[num];

    for(int i = 0; i < size; i++){
        int id = (arr[i] - min)/bucket_size;
        Node* rear = &list[id];
        while(rear->next != nullptr && rear->next->val < arr[i]){
            rear = rear->next;
        }
        Node* cur = new Node(arr[i], rear->next);
        rear->next = cur;
    }
    int cnt = 0;
    for(int i = 0; i < num; i++){
        Node* cur = list[i].next;
        while(cur != nullptr){
            arr[cnt++] = cur->val;
            Node* tmp = cur;
            cur = cur->next;
            delete tmp;
        }
    }
    delete [] list;
}

void RadixSort(int arr[], int size){
    int max = 0;
    for(int i = 0; i < size; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    int r = 0;
    while(max){
        max /= 10;
        r++;
    }
    vector<queue<int>> bucket(10);
    int radix = pow(10, r-1);
    for(int i = 1; i <= radix; i *= 10){
        for(int j = 0; j < size; j++){
            int cur = arr[j]/i%10;
            bucket[cur].push(arr[j]);
        }
        int cnt = 0;
        for(int j = 0; j < 10; j++){
            while(!bucket[j].empty()){
                arr[cnt++] = bucket[j].front();
                bucket[j].pop();
            }
        }
    }
}
