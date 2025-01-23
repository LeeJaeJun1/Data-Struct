#include<iostream>
using namespace std;


class listQueue{
private:
    int* arr;
    int size;
    int front;
    int rear;
    int capacity;
public:
    listQueue(int c) {
        capacity = c;
        arr = new int[capacity];
        front = rear = 0;
        size = 0;
    }
    bool empty() {
        if(size==0) {
            return true;
        }
        return false;
    }
    int getfront() {
        if(empty())
            return -1;
        return arr[front];
    }

    void enqueue(int v) {
        if(capacity<=size) {
            cout << "Full" << endl;
            return;
        }
        arr[rear] = v;
        rear = (rear+1) % capacity;
        size++;
    }
    void dequeue() {
        if(empty()) {
            cout << "Empty" << endl;
            return;
        }
        front = (front+1) % capacity;
        size--;
    }
    void plusfront(int n) {
        if(empty()) {
            return;
        }
        arr[front]+=n;
    }
};

int main() {
    int test, card, num,diff,last;
    cin >> test;
    while(test--) {
        int score1 = 0; int score2 = 0;
        cin >> card;
        listQueue l1(card);
        listQueue l2(card);
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
                l2.plusfront(diff);
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
                l1.plusfront(diff);
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