#include<iostream>
using namespace std;

class node{
public:
    int data;
    node* next;
    node(int d) {
        data = d;
        next = nullptr;
    }
};

class listQueue{
private:
    node* front;
    node* rear;
    int size;
public:
    listQueue() {
        front = rear = NULL;
        size = 0;
    }
    bool empty() {
        if(size==0) {
            return true;
        }
        return false;
    }
    int getSize() {
        return size;
    }
    int getfront() {
        if(empty())
            return -1;
        return front->data;
    }
    int getrear() {
        if(empty())
            return -1;
        return rear->data;
    }
    void enqueue(int v) {
        node* newNode = new node(v);
        if(size == 0) {
            front=rear=newNode;
        }
        else{
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }
    void dequeue() {
        if(empty()) {
            return;
        }
        node* del = front;
        front = front->next;
        delete del;
        size--;
    }
    void plusfront(int n) {
        if(empty()) {
            return;
        }
        front->data += n;
    }
};

int main() {
    int test, card, num,diff,last;
    cin >> test;
    while(test--) {
        listQueue l1,l2;
        int score1 = 0; int score2 = 0;
        cin >> card;
        for(int i = 0 ; i < card; i++) {
            cin >> num;
            l1.enqueue(num);
        }
        for(int i = 0; i < card; i++) {
            cin >> num;
            l2.enqueue(num);
        }
        for(int i = 1; i <= card; i++) {
            if(l1.getfront() > l2.getfront()) {
                score1++;
                cout << "Round" << i << " " << l1.getfront() << ">" << l2.getfront() << " " <<  score1 << ":" << score2 << endl;
                diff = l1.getfront() - l2.getfront();
                l1.dequeue();
                l2.dequeue();
                l1.plusfront(diff);
                if(i==card) {
                    last = 1;
                }
            }
            else if(l2.getfront() > l1.getfront()) {
                score2++;
                cout << "Round" << i << " " << l1.getfront() << "<" << l2.getfront() << " " <<score1 << ":" << score2 << endl;
                diff = l2.getfront() - l1.getfront();
                l1.dequeue();
                l2.dequeue();
                l2.plusfront(diff);
                if(i==card) {
                    last = 2;
                }
            }
            else{
                cout << "Round" << i << " " << l1.getfront() << "=" << l2.getfront() << " " << score1 << ":" << score2 << endl;
                l1.dequeue();
                l2.dequeue();
                if(i==card) {
                    last = 0;
                }
            }
        }
        if(score1 > score2) {
            cout << "Winner P1" << endl;
        }
        else if(score2 > score1) {
            cout << "Winner P2" << endl;
        }
        else{
            if(last==0) {
                cout << "Draw" << endl;
            }
            else if(last==1) {
                cout << "Winner P1" << endl;
            }
            else if(last==2) {
                cout << "Winner p2" << endl;
            }
        }
    }
}