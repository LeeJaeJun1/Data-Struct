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
        node* curNode = front;
        while(num--) {
            total += curNode->data;
            curNode = curNode->next;
        }
        cout << total << "\n";
    }
    int Front() {
        return front->data;
    }
    void plus(int di) {
        if(isEmpty()) {
            return;
        }
        front->data += di;
    }
};

int main() {
    int t,N;
    cin >> t;
    while(t--) {
        int n1,n2,diff;
        int last = 0;
        int w1 = 0; int w2 = 0;
        cin >> N;
        linkedArray l1; linkedArray l2;
        for(int i = 0; i < N; i++) {
            cin >> n1;
            l1.enqueue(n1);
        }
        for(int i = 0; i < N; i++) {
            cin >> n2;
            l2.enqueue(n2);
        }
        for(int i = 1; i <= N; i++) {
            if(l1.Front() > l2.Front()) {
                w1+=1;
                cout << "Round" << i << " " << l1.Front() << ">" << l2.Front() << " " << w1 << ":" << w2 << "\n";
                diff = l1.Front() - l2.Front();
                l1.dequeue(); l2.dequeue();
                l1.plus(diff);
                if(i==N) {
                    last = 1;
                }
            }
            else if(l1.Front() < l2.Front()){
                w2+=1;
                cout << "Round" << i << " " << l1.Front() << "<" << l2.Front() << " " << w1 << ":" << w2 << "\n";
                diff = l2.Front() - l1.Front();
                l1.dequeue(); l2.dequeue();
                l2.plus(diff);
                if(i==N) {
                    last = 2;
                }
            }
            else {
                cout << "Round" << i << l1.Front() << "=" << l2.Front() << " " << w1 << ":" << w2 << "\n";
                l1.dequeue(); l2.dequeue();
                if(i==N) {
                    last = 3;
                }
            }
        }
        if(w1 > w2) {
            cout << "Winner P1" << "\n";
        }
        else if(w1 < w2) {
            cout << "Winner P2" << "\n";
        }
        else {
            if(last == 1) {
                cout << "Winner P1" << "\n";
            }
            else if(last == 2) {
                cout << "Winner P2" << "\n";
            }
            else{
                cout << "Draw" << "\n";
            }
        }
    }
}