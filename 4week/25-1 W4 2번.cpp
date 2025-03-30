#include<iostream>
using namespace std;

class arrayQueue {
private:
    int* arr;
    int front;
    int rear;
    int capacity;
    int n;
public:
    arrayQueue() {
        capacity = 10000;
        front = rear = 0;
        n = 0;
        arr = new int[capacity];
    }
    bool empty() {
        return n == 0;
    }
    int size() {
        return n;
    }
    int Front() {
        if(empty()) {
            return -1;
        }
        return arr[front];
    }
    void push(int x) {
        arr[rear] = x;
        rear = (rear+1) % capacity;
        n++;
    }
    void pop() {
        if(empty()) {
            cout << -1 << "\n";
            return;
        }

        front = (front + 1) % capacity;
        n--;
    }
    void print_all() {
        if(empty()) {
            cout << -1 << "\n";
            return;
        }
        for(int i = front; i < rear; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};

int main() {
    int arr1[101];
    int t,n,num,M;
    cin >> t;
    while(t--) {
        arrayQueue qu;
        cin >> n;
        for(int i = 1; i <= n; i++) {
            qu.push(i);
        }
        for(int k = 1; k < n; k++) {
            cin >> num;
            for(int j = 1; j <= num; j++) {
                int b = qu.Front();
                qu.pop();
                qu.push(b);
            }
            arr1[k] = qu.Front();
            qu.pop();
        }
        cout << qu.Front() << "\n";
    }
}

