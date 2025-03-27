#include<iostream>
using namespace std;

class arrayQueue {
private:
    int* arr;
    int front;
    int rear;
    int size;
    int capacity;
public:
    arrayQueue(int sz) {
        front = 0;
        rear = 0;
        size = 0;
        capacity = sz;
        arr = new int[capacity];
    }
    bool isEmpty() {
        return size==0;
    }
    int Size() {
        return size;
    }
    void full() {
        if(capacity <= Size()) {
            cout << "True" << "\n";
            return;
        }
        cout << "False" << "\n";
    }
    void Front() {
        if(isEmpty()) {
            cout << "Empty" << "\n";
            return;
        }
        cout << arr[front] << "\n";
    }
    void enqueue(int value) {
        if(capacity <= Size()) {
            cout << "Full" << "\n";
            return;
        }
        arr[rear] = value;
        rear = (rear+1) % capacity;
        size++;
    }
    void dequeue() {
        if(isEmpty()) {
            cout << "Empty" << "\n";
            return;
        }
        cout << arr[front] << "\n";
        front = (front+1) % capacity;
        size--;
    }
    void rearNsum(int num) {
        if(isEmpty()) {
            cout << "Empty" << "\n";
            return;
        }
        if(num > Size()) {
            cout << "error" << "\n";
            return;
        }
        int total = 0;
        for(int i = num; i > 0; i--) {
            total += arr[(rear-i+capacity) % capacity];
        }
        cout << total << "\n";
    }
};

int main() {
    int N,T; string s;
    cin >> N >> T;
    arrayQueue qu(N);
    while(T--) {
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
        else if(s=="full") {
            qu.full();
        }
        else if(s=="front") {
            qu.Front();
        }
        else if(s=="rearNsum") {
            int num; cin >> num;
            qu.rearNsum(num);
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