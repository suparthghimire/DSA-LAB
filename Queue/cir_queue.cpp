#include<iostream>
#include<conio.h>
#define MAX 3

using namespace std;

template <class T>
class Queue {
    int rear = -1;
    int front = -1;
    T queue[MAX];
public:
    bool checkFull() {
        return (rear + 1) % MAX == front;
    }
    bool checkEmpty() {
        return (front == -1 && rear == -1);
    }
    bool enqueue(T data) {
        if (checkEmpty()) {
            front = rear = 0;
            queue[rear] = data;
            return true;
        }
        else if (checkFull()) {
            return false;
        }
        else {
            rear = (rear + 1) % MAX;
            queue[rear] = data;
            return true;
        }

    }

    T dequeue() {
        if (checkEmpty()) {
            return -1;
        }
        else if (front == rear) {
            T data = queue[front];
            front = rear = -1;
            return data;
        }
        else {
            T data = queue[front];
            front = (front + 1) % MAX;
            return data;
        }
    }

    void displayQueue() {
        if (checkEmpty()) {
            cout << "Queue is Empty" << endl;
        }
        else {
            int i = front;
            while (i != rear) {
                cout << queue[i] << endl;
                i = (i + 1) % MAX;
            }
            cout << queue[rear] << endl;
        }
    }

};
void menu(Queue<int>);
void back(Queue<int>);

int main() {
    Queue<int> Q;
    while (true) {
        menu(Q);
    }
}


void enqueue(Queue<int> Q) {
    cout << "Enter data: ";
    int data;
    cin >> data;
    if (Q.enqueue(data)) cout << "Data inserted Successfully!" << endl;
    else cout << "Overflow!" << endl;
    back(Q);
}
void dequeue(Queue<int> Q) {
    int data = Q.dequeue();
    if (data == -1) {
        cout << "Underflow" << endl;
    }
    else {
        cout << data << " was dqueued from Queue" << endl;
    }
    back(Q);
}

void checkOverflow(Queue<int> Q) {
    Q.checkFull()
        ? cout << "Overflow: True" << endl
        : cout << "Overflow: False";
    back(Q);
}

void checkUnderflow(Queue<int> Q) {
    Q.checkEmpty()
        ? cout << "Underflow: True" << endl
        : cout << "Underflow: False";
    back(Q);
}

void display(Queue<int> Q) {
    cout << "Contents of queue: " << endl;
    Q.displayQueue();
    back(Q);
}

void options() {
    cout << "1. Enqueue" << endl;
    cout << "2. Dequeue" << endl;
    cout << "3. Check Overflow" << endl;
    cout << "4. Check Underflow" << endl;
    cout << "5. Display Queue" << endl;
    cout << "6. Exit" << endl;
}

void menu(Queue <int> Q) {
    system("cls");
    options();
    cout << "Enter your choice: ";
    int option;
    cin >> option;

    switch (option)
    {
    case 1:
        enqueue(Q);
        break;
    case 2:
        dequeue(Q);
        break;
    case 3:
        checkOverflow(Q);
        break;
    case 4:
        checkUnderflow(Q);
        break;
    case 5:
        display(Q);
        break;
    case 6:
        exit(0);
        break;
    default:
        menu(Q);
        break;
    }
}

void back(Queue<int> Q) {
    cout << endl << "Press any key to go back" << endl;
    getch();
    menu(Q);
}