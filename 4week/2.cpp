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
    int getFront() {
        return front->data;
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
        front = front->next;
        delete curNode;
        size--;
    }
    void plusFront(int num) {
        if(empty()) {
            return;
        }
        front->data += num;
    }
};

int main() {
    int T,N;
    cin >> T;
    while(T--) {
        listqueue l1,l2;
        cin >> N;
        int total1 = 0; int total2 = 0;
        int x1,y1,diff,last;
        for(int i = 0; i < N; i++) {
            cin >> x1;
            l1.enqueue(x1);
        }
        for(int i = 0; i < N; i++) {
            cin >> y1;
            l2.enqueue(y1);
        }
        for(int j = 1; j <= N; j++) {
            if(l1.getFront() > l2.getFront()) {
                total1++;
                cout << "Round" << j << " " << l1.getFront() << ">" << l2.getFront()
                     << " " << total1 << ":" << total2 << endl;
                diff = l1.getFront() - l2.getFront();
                l1.dequeue(); l2.dequeue();
                l1.plusFront(diff);
                if(j==N) {
                    last = 1;
                }
            }
            else if(l1.getFront() < l2.getFront()) {
                total2++;
                cout << "Round" << j << " " << l1.getFront() << "<" << l2.getFront()
                     << " " << total1 << ":" << total2 << endl;
                diff = l2.getFront() - l1.getFront();
                l1.dequeue(); l2.dequeue();
                l2.plusFront(diff);
                if(j==N) {
                    last = 2;
                }
            }
            else{
                cout << "Round" << j << " " << l1.getFront() << "=" << l2.getFront()
                     << " " << total1 << ":" << total2 << endl;
                l1.dequeue(); l2.dequeue();
                if(j==N) {
                    last = 0;
                }
            }
        }
        if(total1 > total2) {
            cout << "Winner P1" << endl;
        }
        else if(total1 < total2) {
            cout << "Winner P2" << endl;
        }
        else{
            if(last==1) {
                cout << "Winner P1" << endl;
            }
            else if(last == 2) {
                cout << "Winner P2" << endl;
            }
            else{
                cout << "Draw" << endl;
            }
        }
    }
}