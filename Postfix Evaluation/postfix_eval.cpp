#include<iostream>
#define MAX 100
using namespace std;


class Stack {
    int top = -1;
    int stack[MAX];
public:
    bool overflow() {
        return top == MAX;
    }
    bool underflow() {
        return top < 0;
    }
    int top_element() {
        return stack[top];
    }
    void push(int data) {
        if (!overflow()) {
            stack[++top] = data;
        }
    }
    int pop() {
        if (!underflow()) {
            int data = top_element();
            top--;
            return data;
        }
    }
};


bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int postFixEvaluation(string str) {
    Stack S;
    int ans;
    for (int i = 0;i < str.length();i++) {
        if (!isOperator(str[i])) {
            S.push(str[i] - '0');
        }
        else {
            int dataA = S.pop();
            int dataB = S.pop();
            if (str[i] == '+') ans = dataB + dataA;
            else if (str[i] == '-') ans = dataB - dataA;
            else if (str[i] == '*') ans = dataB * dataA;
            else if (str[i] == '/') ans = dataB / dataA;
            S.push(ans);
        }
    }
    return ans;
}

int main() {
    string postFixString;
    postFixString = "4572+-*";
    cout << "answer: " << postFixEvaluation(postFixString);


}
