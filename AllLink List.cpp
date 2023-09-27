#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

void createNode(int n) {
    Node* newNode, * temp;
    int i;
    head = new Node;
    head->next = nullptr;
    cout << "\nEnter data for Node 1: ";
    cin >> head->data;
    temp = head;
    for (i = 2; i <= n; i++) {
        newNode = new Node;
        cout << "\nEnter data for Node " << i << ": ";
        cin >> newNode->data;
        newNode->next = nullptr;
        temp->next = newNode;
        temp = temp->next;
    }
}

void insertBeginning() {
    Node* newNode = new Node;
    cout << "\nEnter data for beginning node: ";
    cin >> newNode->data;
    newNode->next = head;
    head = newNode;
}

void insertEnd() {
    Node* temp, * newNode;
    newNode = new Node;
    cout << "\nEnter data for last node: ";
    cin >> newNode->data;
    temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = nullptr;
}

void display() {
    Node* temp;
    temp = head;
    cout << "\nYou have Successfully created the following linked list: \n";
    while (temp != nullptr) {
        cout << temp->data << "-> ";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}

void deleteFirst() {
    if (head == nullptr) {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }
    Node* temp;
    temp = head;
    head = temp->next;
    delete temp;
}

void deleteMiddle() {
    if (head == nullptr) {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }
    int pos, i = 1;
    Node* current, * temp, * prev;
    cout << "\nEnter the position of the node you want to delete: ";
    cin >> pos;
    temp = head;
    for (i = 1; i < pos; i++) {
        prev = temp;
        current = temp->next;
        temp = temp->next;
    }
    prev->next = current->next;
    delete current;
}

void deleteLast() {
    if (head == nullptr) {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }
    Node* temp, * prev;
    temp = head;
    while (temp->next != nullptr) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = nullptr;
    delete temp;
}

int main() {
    int n;
    cout << "\nEnter total number of nodes: ";
    cin >> n;
    createNode(n);
    display();
    cout << "\nInserting new node at the beginning...\n";
    insertBeginning();
    display();
    cout << "\nInserting new node at the end...\n";
    insertEnd();
    display();
    cout << "\nDeleting the first node...\n";
    deleteFirst();
    display();
    cout << "\nDeleting a middle node...\n";
    deleteMiddle();
    display();
    cout << "\nDeleting the last node...\n";
    deleteLast();
    display();
    return 0;
}

