#include<iostream>
#define MAX 5
using namespace std;

int list[MAX] = { 5,4,3,2,1 };

void selectionSort() {
    for (int i = 0;i < MAX - 1;i++) {
        int min = i;
        for (int j = i + 1;j < MAX;j++) {
            if (list[j] < list[min])
                min = j;
        }
        if (min != i) {
            swap(list[i], list[min]);
        }
    }
}

int main() {
    selectionSort();
    for (int i = 0;i < MAX;i++) {
        cout << list[i] << " ";
    }

    // cout << minArr();

}