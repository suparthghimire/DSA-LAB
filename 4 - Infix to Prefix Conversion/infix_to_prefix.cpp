#include<iostream>
#define MAX 100
using namespace std;

class Stack {
    int top = -1;
    char stack[MAX];
public:
    bool overflow() {
        return top == MAX;
    }
    bool underflow() {
        return top < 0;
    }

    bool isEmpty() {
        return top < 0;
    }

    char top_elem() {
        if (underflow()) {
            return '@';
        }
        return stack[top];
    }
    void push(int data) {
        if (!overflow()) {
            stack[++top] = data;
        }
    }
    char pop() {
        if (!underflow()) {
            char data = top_elem();
            top--;
            return data;
        }
    }
};


int checkPresidecy(char a) {
    if (a == '+' || a == '-') {
        return 1;
    }
    else if (a == '*' || a == '/') {
        return 2;
    }
    else if (a == '^') {
        return 3;
    }
    else if (a == '(') {
        return 0;
    }
    else {
        return -1;
    }
}

string reverseString(string str) {
    string temp;
    for (int j = str.length() - 1;j >= 0; j--) {
        temp += str[j];
    }
    return temp;
}

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == ')' || c == '(';
}

string infixToPrefix(string str) {
    Stack S;
    string ans;

    for (int i = 0;i < str.length();i++) {
        if (!isOperator(str[i])) {
            ans += str[i];
        }
        else {
            if (str[i] == ')') {
                S.push(str[i]);
            }
            else if (str[i] == '(') {
                char poppedElement = S.pop();
                ans += poppedElement;
                while (poppedElement != ')') {
                    poppedElement = S.pop();
                    if (poppedElement != ')')
                        ans += poppedElement;
                }
            }
            else {
                while (checkPresidecy(str[i]) < checkPresidecy(S.top_elem())) {
                    ans += S.pop();
                }
                if (checkPresidecy(str[i]) >= checkPresidecy(S.top_elem())) {
                    S.push(str[i]);
                }
            }
        }
    }
    while (!S.isEmpty()) {
        ans += S.pop();
    }
    return reverseString(ans);
}


int main() {
    string string = "K+L-M*N+(O^P)*W/U/V*T+Q";
    cout << "Answer: " << infixToPrefix(reverseString(string));
}