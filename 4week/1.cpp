#include<iostream>
using namespace std;

class node{
public:
    node* next;
    int data;
    node(int x) {
        next = NULL;
        data = x;
    }
};

class listqueue {
private:
    node* front;
    node* rear;
    int size;
public:
    listqueue() {
        front = rear = NULL;
        size = 0;
    }
    bool empty() {
        if(size == 0)
            return true;
        else
            return false;
    }
    int Size() {
        return size;
    }
    void frontNsum(int num) {
        if(empty()) {
            cout << "Empty" << endl;
            return;
        }
        if(num > Size()) {
            cout << "error" << endl;
            return;
        }

        int total = 0;
        node* curNode = front;
        for(int i = 0; i < num; i++) {
            total += curNode->data;
            curNode = curNode->next;
        }
        cout << total << endl;
    }
    int Rear() {
        if(empty()) {
            cout << "Empty" << endl;
        }
        cout << rear->data << endl;
    }
    void enqueue(int value) {
        node* newNode = new node(value);
        if(size == 0) {
            front = rear = newNode;
        }
        else{
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }
    void dequeue() {
        if(empty()) {
            cout << "Empty" << endl;
            return;
        }
        node* curNode = front;
        cout << front->data << endl;
        front = front->next;
        delete curNode;
        size--;
    }
};

int main() {
    int t; string s;
    cin >> t;
    listqueue qu;
    while(t--) {
        cin >> s;
        if(s=="size") {
            cout << qu.Size() << endl;
        }
        else if(s=="isEmpty") {
            if(qu.empty()) {
                cout << "True" << endl;
            }
            else{
                cout << "False" << endl;
            }
        }
        else if(s=="frontNsum") {
            int num;
            cin >> num;
            qu.frontNsum(num);
        }
        else if(s=="rear") {
            qu.Rear();
        }
        else if(s=="enqueue") {
            int value; cin >> value;
            qu.enqueue(value);
        }
        else if(s=="dequeue") {
            qu.dequeue();
        }
    }
}