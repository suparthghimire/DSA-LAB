#include<iostream>
#define MAX 5
using namespace std;

int list[MAX] = { 5,4,3,2,1 };

void merge(int start, int end) {
    int mid = (start + end) / 2;
    int i = start;
    int j = mid + 1;
    int k = start;
    int temp[100];
    while (i <= mid && j <= end) {
        if (list[i] < list[j]) {
            temp[k++] = list[i++];
        }
        else {
            temp[k++] = list[j++];
        }
    }
    while (i <= mid) {
        temp[k++] = list[i++];
    }
    while (j <= end) {
        temp[k++] = list[j++];
    }
    for (int i = start;i <= end;i++) {
        list[i] = temp[i];
    }
}

void mergeSort(int start, int end) {
    if (start >= end) return;

    int mid = (start + end) / 2;
    mergeSort(start, mid);
    mergeSort(mid + 1, end);
    
    merge(start, end);
}

int main() {
    mergeSort(0, MAX - 1);
    cout << "Sorted Array: " << endl;
    for (int i = 0;i < MAX;i++) {
        cout << list[i] << " ";
    }
}
