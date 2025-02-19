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
        cout << arr[front] << endl;
        front = (front+1) % capacity;
        size--;
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
            if(qu.empty()) {
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