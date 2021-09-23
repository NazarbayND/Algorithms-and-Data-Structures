#include <iostream>
#include <vector>

using namespace std;

class Node {
    public:
    int data;
    Node *next, *prev;

    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

class LinkedList {
    public:
    Node *front, *tail;

    LinkedList() {
        front = NULL;
        tail = NULL;
    }

    void push_back(int data) {
        Node *node = new Node(data);

        if (tail == NULL) {
            tail = node;
            front = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }

    void push_front(int data) {
        Node *node = new Node(data);

        if (front == NULL) {
            front = node;
            tail = node;
        } else {
            front->prev = node;
            node->next = front;
            front = node;
        }
    }

    void print() {
        Node *node = front;
        while (node != NULL) {
            cout << node->data << " ";
            node = node->next;
        }
    }
    void printReverse() {
        Node *node = tail;
        while (node != NULL) {
            cout << node->data << " ";
            node = node->prev;
        }
    }

    void pop_back() {
        if (tail != NULL) {
            tail = tail->prev;
            if (tail != NULL) {
                tail->next = NULL;
            } else {
                front = NULL;
            }
        }
    }

    void pop_front() {
        if (front != NULL) {
            front = front->next;
            if (front != NULL)
                front->prev = NULL;
            else
                tail = NULL;
        }
    }

    void insert(Node *a, int data) {
        if (a == tail) {
            push_back(data);
            return;
        }
        Node *b = a->next;

        Node *node = new Node(data);
        a->next = node;
        node->prev = a;
        b->prev = node;
        node->next = b;
    }

    Node* find_el(int data) {
        Node *node = front;
        while (node != NULL) {
            if (node->data == data)
                return node;
            node = node->next;
        }
        return NULL;
    }

    void delete_el(Node *node) {
        if (node == tail)
            pop_back();
        else if (node == front)
            pop_front();
        else {
            Node *a = node->prev;
            Node *b = node->next;
            a->next = b;
            b->prev = a;
        }
    }
};


int main() {
    LinkedList *ll = new LinkedList();
    int N;
    cin>>N;
    bool front = true;
    for (int i = 0; i< N; i++){
        int num;
        int ele;
        cin>>num;
        if(num == 1){
            cin>>ele;
            if(front){
                ll->push_back(ele);
            }
            else {
                ll->push_front(ele);
            }
        }
        else if (num == 2) {
            front = !front;
        }
    }
    if(front){
        ll->print();
    }
    else{
        ll->printReverse();
    }

    
   return 0;
}