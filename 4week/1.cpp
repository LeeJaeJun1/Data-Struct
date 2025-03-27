#include<iostream>
using namespace std;

class node{
private:
    int data;
    node* next;
public:
    node(int x) {
        data = x;
        next = NULL;
    }
    friend class linkedArray;
};

class linkedArray {
private:
    node* front;
    node* rear;
    int size;
public:
    linkedArray() {
        front = rear = NULL;
        size = 0;
    }
    bool isEmpty() {
        return size == 0;
    }
    int Size() {
        return size;
    };
    void Rear() {
        if(isEmpty()) {
            cout << "Empty" << "\n";
            return;
        }
        cout << rear->data << "\n";
    }
    void enqueue(int value) {
        node* newNode = new node(value);
        if(Size()==0) {
            front = rear = newNode;
        }
        else{
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }
    void dequeue() {
        if(isEmpty()) {
            cout << "Empty" << "\n";
            return;
        }
        node* del = front;
        cout << del->data << "\n";
        front = front->next;
        delete del;
        size--;
    }
    void frontNsum(int num) {
        if(isEmpty()) {
            cout << "Empty" << "\n";
            return;
        }
        if(Size() < num) {
            cout << "error" << "\n";
            return;
        }
        int total = 0;
        while(num--) {
            total += front->data;
            front = front->next;
        }
        cout << total << "\n";
    }
};

int main() {
    int N; string s;
    cin >> N;
    linkedArray qu;
    while(N--) {
        cin >> s;
        if(s=="size") {
            cout << qu.Size() << endl;
        }
        else if(s=="isEmpty") {
            if(qu.isEmpty()) {
                cout << "True" << endl;
            }
            else
                cout << "False" << endl;
        }

        else if(s=="rear") {
            qu.Rear();
        }
        else if(s=="frontNsum") {
            int num; cin >> num;
            qu.frontNsum(num);
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