#include<iostream>
#define MAX 5
using namespace std;
int list[MAX] = { 5,4,3,2,1 };

int partition(int l, int h) {
    int p = list[h];
    int j = l;
    for (int i = l;i < h;i++) {
        if (list[i] <= p) {
            swap(list[i], list[j]);
            j++;
        }
    }
    swap(list[h], list[j]);
    return j;
}


void quickSort(int l, int h) {
    if (l < h) {
        int index = partition(l, h);
        quickSort(l, index - 1);
        quickSort(index + 1, h);
    }
}

int main() {
    cout << "Sorted array: " << endl;
    quickSort(0, MAX - 1);
    for (int i = 0;i < MAX;i++) {
        cout << list[i] << " ";
    }
}