#include<iostream>
#include<algorithm>
#define MAX 5
using namespace std;


int binarySearch(int list[], int key, int low, int high) {
    if (low > high) return -1;

    int mid = low + (high - low) / 2;
    if (key == list[mid]) return mid;
    else if (key < list[mid]) {
        binarySearch(list, key, low, mid - 1);
    }
    else {
        binarySearch(list, key, mid + 1, high);
    }
}


int main() {
    int list[MAX] = { 10, 14, 13, 62, 0 };
    sort(list, list + MAX);
    int key = 62;
    int status = binarySearch(list, key, 0, MAX - 1);

    if (status != -1) {
        cout << key << " is at index: " << status << " of sorted array" << endl;
    }
    else {
        cout << key << " is not in array" << endl;
    }
}