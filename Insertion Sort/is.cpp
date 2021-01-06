#include<iostream>
#define MAX 5
using namespace std;
int list[MAX] = { 5,4,3,2,1 };

void insertion() {
    int value;
    for (int i = 0;i < MAX;i++) {
        value = list[i];
        int j = i;
        while (j > 0 && list[j - 1] > value) {
            list[j] = list[j - 1];
            j--;
        }
        list[j] = value;
    }
}


int main() {
    insertion();
    cout << "Sorted List is: " << endl;
    for (int i = 0;i < MAX;i++) {
        cout << list[i] << " ";
    }

}