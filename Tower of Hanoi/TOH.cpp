#include<iostream>
using namespace std;


void TOH(int n, string src, string aux, string dest) {
    if (n == 1) {
        cout << "Move disk " << n << " from " << src << " to " << dest << endl;
        return;
    }
    else {
        TOH(n - 1, src, dest, aux);
        cout << "Move disk " << n << " from " << src << " to " << dest << endl;
        TOH(n - 1, aux, src, dest);
        return;
    }
}


int main() {
    system("cls");
    int n = 3;
    TOH(n, "T1", "T2", "T3");
}