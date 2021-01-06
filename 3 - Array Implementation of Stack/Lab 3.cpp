
#include <iostream>
#include <conio.h>

#define MAX 4
using namespace std;

template <class T>
class _Stack {
	T stack[MAX];
	int top = -1;
public:
	bool overflow() {
		return top == MAX - 1;
	}
	bool underflow() {
		return top < 0;
	}
	T stack_top() {
		return stack[top];
	}
	void display() {
		int i = top;
		while (i >= 0) {
			cout << stack[i--] << endl;
		}
	}
	bool push(T data) {
		if (!overflow()) {
			stack[++top] = data;
			return true;
		}
		return false;
	}
	T pop() {
		if (!underflow()) {
			T data =  stack_top();
			top--;
			return data;
		}
		else cout<<"Underflow";
	}
	
	bool isPalindrome(){
		int i = 0;
		while(i<=top){
			if(stack[i++] != pop()){		
				return false;
			}
		}
		return true;
	}
	void view_status(){
		cout<<"Top Element:"<<stack_top()<<endl;
		cout<<"Top Index: "<<top<<endl;
		cout<<"Overflow: ";
		overflow() ? cout << "True" << endl : cout << "False" << endl;
		cout<<"Underflow: ";
		underflow() ? cout << "True" << endl : cout << "False" << endl;
	}
};

void menu(_Stack<int>);
void back(_Stack<int>);

int main() {
	_Stack<int> S;

	while (1) {
		menu(S);
	}

}

void options() {
	cout << "1. Push Items to Stack" << endl;
	cout << "2. Pop Items from Stack" << endl;
	cout << "3. Find Top Element" << endl;
	cout << "4. Check overflow" << endl;
	cout << "5. Check underflow" << endl;
	cout << "6. Display Items in Stack" << endl;
	cout << "7. Check Palindrome" << endl;
	cout << "8. Check Status"<<endl;
	cout << "9. Exit"<<endl;
	cout << "Node: Pressing any key other than 1 - 9 is invalid." << endl;
}

void push_stack(_Stack <int> S) {
	cout << "Enter data to push to stack: " << endl;
	int data;
	cin >> data;
	bool success = S.push(data);
	if(success) cout << "Data pushed to stack"<<endl;
	else cout << "Stack overflow" << endl;

	back(S);
}

void pop_stack(_Stack<int> S) {
	int data = S.pop();
	cout<<"Data: "<<data<<" has been popped";
	back(S);
}
void find_top(_Stack<int> S) {
	int data = S.stack_top();
	cout << "Data at top of stack is: " << data << endl;
	back(S);
}

void overflow(_Stack <int> S) {
	S.overflow() ? cout << "Stack has Overflown!" << endl : cout << "Overflow condition has not met" << endl;

	back(S);
}
void underflow(_Stack <int> S) {
	S.underflow() ? cout << "Stack has Underflown!" << endl : cout << "Underflow condition has not met" << endl;
	back(S);
}
void display(_Stack <int> S) {
	cout << "Contents in Stack: " << endl;
	S.display();
	back(S);
}

void checkPalindrome(_Stack<int> S){
	if(S.isPalindrome()) cout<<"Stack is palindrome"<<endl;
	else cout<<"Stack is not palindrome"<<endl;
	back(S);
}
void status(_Stack<int> S){
	S.view_status();
	back(S);
}

void menu(_Stack<int> S) {
	system("cls");
	options();
	int ch;
	cin >> ch;
	cout<<endl<<"__________________"<<endl<<endl;
	switch (ch) {
	case 1:
		push_stack(S);
		break;
	case 2:
		pop_stack(S);
		break;
	case 3:
		find_top(S);
		break;
	case 4:
		overflow(S);
		break;
	case 5:
		underflow(S);
		break;
	case 6:
		display(S);
		break;
	case 7:
		checkPalindrome(S);
		break;
	case 8:
		status(S);
		break;
	
	case 9:
		exit(0);
	default:
		cout<<"Invalid Input"<<endl;
		menu(S);
	}
}

void back(_Stack<int> S) {
	cout <<endl<< "Press any key to go back";
	getch();
	menu(S);
}
