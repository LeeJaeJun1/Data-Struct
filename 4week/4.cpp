#include<iostream>
using namespace std;

class arrayQueue{
private:
    int* arr;
    int capacity;
    int front;
    int rear;
    int size;
public:
    arrayQueue(int c) {
        capacity = c;
        front = rear = 0;
        size = 0;
        arr = new int[capacity];
    }
    arrayQueue() {
        capacity = 100;
        front = rear = 0;
        size=0;
        arr = new int[capacity];
    }
    bool empty() {
        if(size==0) {
            return true;
        }
        return false;
    }
    int Size() {
        return size;
    }
    void full() {
        if(capacity <= Size()) {
            cout << "True" << endl;
        }
        else{
            cout << "False" << endl;
        }
    }
    void Front() {
        if(empty()) {
            cout << "Empty" << endl;
        }
        cout << arr[front] << endl;
    }

    void rearNsum(int num) {
        if(empty()) {
            cout << "Empty" << endl;
            return;
        }
        if(Size() < num) {
            cout << "error" << endl;
            return;
        }
        int total = 0;
        for(int i = num; i > 0; i--) {
            total += arr[(rear-i + capacity) % capacity];
        }
        cout << total << endl;
    }

    void enqueue(int value) {
        if(capacity <= size) {
            cout << "Full" << endl;
            return;
        }
        arr[rear] = value;
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
    int getFront() {
        return arr[front];
    }
    void plusFront(int n) {
        arr[front] += n;
    }
};

int main() {
    int T,N;
    cin >> T;
    while(T--) {
        cin >> N;
        arrayQueue a1;
        arrayQueue a2;
        int total1 = 0; int total2 = 0;
        int x1,y1,diff,last;
        for(int i = 0; i < N; i++) {
            cin >> x1;
            a1.enqueue(x1);
        }
        for(int i = 0; i < N; i++) {
            cin >> y1;
            a2.enqueue(y1);
        }
        for(int j = 1; j <= N; j++) {
            if(a1.getFront() > a2.getFront()) {
                total1++;
                cout << "Round" << j << " " << a1.getFront() << ">" << a2.getFront()
                     << " " << total1 << ":" << total2 << endl;
                diff = a1.getFront() - a2.getFront();
                a1.dequeue(); a2.dequeue();
                a2.plusFront(diff);
                if(j==N) {
                    last = 1;
                }
            }
            else if(a1.getFront() < a2.getFront()) {
                total2++;
                cout << "Round" << j << " " << a1.getFront() << "<" << a2.getFront()
                     << " " << total1 << ":" << total2 << endl;
                diff = a2.getFront() - a1.getFront();
                a1.dequeue(); a2.dequeue();
                a1.plusFront(diff);
                if(j==N) {
                    last = 2;
                }
            }
            else{
                cout << "Round" << j << " " << a1.getFront() << "=" << a2.getFront()
                     << " " << total1 << ":" << total2 << endl;
                a1.dequeue(); a2.dequeue();
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