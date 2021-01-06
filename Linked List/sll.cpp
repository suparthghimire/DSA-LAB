#include<iostream>
#include<conio.h>

using namespace std;

struct Node {
    int sn;
    string name;
    string branch;
    int sem;
    long long phoneNo;

    struct Node* next;
};

class LinkedList {
    int sn_no = 0;

    struct Node* getNode(struct Node data) {
        struct Node* newNode = new Node;
        newNode->sn = sn_no;
        newNode->name = data.name;
        newNode->branch = data.branch;
        newNode->sem = data.sem;
        newNode->phoneNo = data.phoneNo;

        newNode->next = NULL;
        return newNode;
    };

    struct Node* rootNode;
public:
    LinkedList() {
        rootNode = NULL;
    }

    void insertBeg(struct Node data) {
        sn_no++;
        struct Node* newNode = getNode(data);
        if (rootNode == NULL)
            rootNode = newNode;
        else {
            newNode->next = rootNode;
            rootNode = newNode;
        }
    }
    void insertEnd(struct Node data) {
        sn_no++;
        struct Node* newNode = getNode(data);
        if (rootNode == NULL) {
            rootNode = newNode;
        }
        else {
            struct Node* tempRoot = rootNode;
            while (tempRoot->next != NULL) {
                tempRoot = tempRoot->next;
            }
            tempRoot->next = newNode;
        }
    }
    void displayLinkedList() {
        if (rootNode == NULL) {
            cout << endl << "List is empty" << endl;
        }
        else {
            struct Node* tempRoot = rootNode;
            while (tempRoot != NULL) {
                cout << "---------------------------" << endl;
                cout << "SN: " << tempRoot->sn << endl;
                cout << "Name: " << tempRoot->name << endl;
                cout << "Branch: " << tempRoot->branch << endl;
                cout << "Semester: " << tempRoot->sem << endl;
                cout << "Phone No:" << tempRoot->phoneNo << endl;
                cout << "---------------------------" << endl << endl;
                tempRoot = tempRoot->next;
            }
        }
    }
    void deleteEnd() {
        if (rootNode == NULL) {
            cout << "List is Empty. Cannot Delete" << endl;
        }
        else {
            sn_no--;
            struct Node* tempRoot = rootNode;
            if (tempRoot->next == NULL) {
                rootNode = NULL;
                delete tempRoot;
            }
            else {
                while (tempRoot->next->next != NULL) {
                    tempRoot = tempRoot->next;
                }
                struct Node* nextNode = tempRoot->next;
                tempRoot->next = NULL;
                delete nextNode;
            }
        }
    }
    void deleteBeg() {
        if (rootNode == NULL) {
            cout << "List is Empty. Cannot Delete" << endl;
        }
        else {
            sn_no--;
            struct Node* tempRoot = rootNode;
            rootNode = rootNode->next;
            tempRoot->next = NULL;
            delete tempRoot;
        }
    }
    void status() {
        cout << endl << "List Status:" << endl;
        cout << "Node Count: " << sn_no << endl;
    }
    void stack() {
        cout << "To Implement stack" << endl;
        cout << "For push Operation, choose option: Insert End (Oprtion number 2) " << endl;
        cout << "For pop Operation, choose option: Delete End (Oprtion number 5) " << endl;
    }
    void queue() {
        cout << "To implement queue" << endl;
        cout << "For Enqueue operation, choose operation: Insert Beginning (Option number 1)" << endl;
        cout << "For Dequeue operation, choose operation: Delete at End (Option number 5)" << endl;
    }
};

void menu(LinkedList L);
void back(LinkedList L);


int main() {
    LinkedList L;

    while (true) {
        menu(L);
    }
}

struct Node getData() {
    struct Node data;
    cout << "Enter name of student: ";
    cin >> data.name;
    cout << "Enter branch of student: ";
    cin >> data.branch;
    cout << "Enter semester of student: ";
    cin >> data.sem;
    cout << "Enter phone number of student: ";
    cin >> data.phoneNo;
    return data;
}

void insertNStudents(LinkedList L) {
    system("cls");
    int num;
    cout << "Enter number of students to add at beginning: ";
    cin >> num;
    for (int i = 0; i < num; i++) {
        cout << " -------------------" << endl;
        cout << "| For Student: " << i + 1 << "    |" << endl;
        cout << " -------------------" << endl;

        struct Node data = getData();
        L.insertBeg(data);

        cout << "-----------------------------" << endl << endl;
    }
    cout << endl << num << " Amount of data inserted at beginning of list successfully!" << endl;
    back(L);
}

void insertEnd(LinkedList L) {
    system("cls");
    struct Node data = getData();
    L.insertEnd(data);
    cout << endl << "Data Insertion Successful" << endl;
    back(L);
}

void insertBeg(LinkedList L) {
    system("cls");
    struct Node data = getData();
    L.insertBeg(data);
    cout << endl << "Data Insertion Successful" << endl;
    back(L);
}

void displayAll(LinkedList L) {
    system("cls");
    cout << "Data of All Students: " << endl;
    L.displayLinkedList();
    back(L);
}

void deleteBeg(LinkedList L) {
    system("cls");
    L.deleteBeg();
    cout << "Data Deleted from beginning of linked list" << endl;
    back(L);
}

void deleteEnd(LinkedList L) {
    system("cls");
    L.deleteEnd();
    cout << endl << "Data deleted from end of Linked List" << endl;
    back(L);
}

void displayStatus(LinkedList L) {
    system("cls");
    L.status();
    back(L);
}
void demo_stack(LinkedList L) {
    system("cls");
    L.stack();
    back(L);
}
void demo_queue(LinkedList L) {
    system("cls");
    L.queue();
    back(L);

}

void options() {
    cout << "1. Insert N Nodes at Beginning" << endl;

    cout << "2. Insert Node at Beginning" << endl;

    cout << "3. Insert Node at End" << endl;

    cout << "4. Display All Nodes in List" << endl;

    cout << "5. Delete Node at Beginning" << endl;

    cout << "6. Delete Node at end" << endl;

    cout << "7. Display Status of List" << endl;

    cout << "8. Demo for Stack" << endl;

    cout << "9. Demo for Queue" << endl;

    cout << "10. Exit" << endl;
}

void menu(LinkedList L) {
    system("cls");

    options();

    cout << endl << "Enter your choice: " << endl;
    int ch;
    cin >> ch;

    switch (ch) {
    case 1:
        insertNStudents(L);
        break;
    case 2:
        insertBeg(L);
        break;
    case 3:
        insertEnd(L);
        break;
    case 4:
        displayAll(L);
        break;
    case 5:
        deleteBeg(L);
        break;
    case 6:
        deleteEnd(L);
        break;
    case 7:
        displayStatus(L);
        break;
    case 8:
        demo_stack(L);
        break;
    case 9:
        demo_queue(L);
        break;
    case 10:
        exit(0);
        break;
    }
}

void back(LinkedList L) {
    cout << endl << "Press any key to go back!" << endl;
    getch();
    menu(L);
}
