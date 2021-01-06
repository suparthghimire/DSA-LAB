#include<iostream>
using namespace std;

int fact(int n) {
    return (n <= 1) ? 1 : n * fact(n - 1);
}

int main() {
    int num = 5;
    cout << "Factorial of " << num << " is: " << fact(num);
}