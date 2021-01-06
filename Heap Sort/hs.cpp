#include<iostream>
#define MAX 7
using namespace std;
int list[MAX] = { 10,20,15,12,40,25,18 };



void heapify(int i) {
    int largestIndex = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;


    if (left < MAX && list[left] > list[largestIndex]) {
        largestIndex = left;
    }


    if (right < MAX && list[right] > list[largestIndex]) {
        largestIndex = right;
    }

    if (largestIndex != i) {
        swap(list[i], list[largestIndex]);
        heapify(largestIndex);
    }

}

void heapSort() {
    for (int i = MAX - 1;i > 0;i--) {
        swap(list[0], list[i]);
        heapify(i);
    }
}
int main() {
    system("cls");

    for (int i = (MAX / 2) - 1;i >= 0;i--) {
        heapify(i);
    }


    cout << "Sorted Array:" << endl;
    for (int i = 0;i < MAX;i++) {
        cout << list[i] << " ";
    }

}