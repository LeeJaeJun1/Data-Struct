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
    void Front() {
        if(empty()) {
            cout << -1 << "\n";
            return;
        }
        cout << arr[front] << "\n";
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
        cout << arr[front] << "\n";
        front = (front + 1) % capacity;
        n--;
    }
    void print_sum() {
        if(empty()) {
            cout << -1 << "\n";
            return;
        }
        int total = 0;
        for(int i = front; i < rear; i++) {
            total += arr[i];
        }
        cout << total << "\n";
    }
};

int main() {
    int t,q; string comm;
    cin >> t;
    while(t--) {
        arrayQueue qu;
        cin >> q;
        while(q--) {
            cin >> comm;
            if(comm == "empty") {
                if(qu.empty()) {
                    cout << 1 << "\n";
                }
                else{
                    cout << 0 << "\n";
                }
            }
            else if(comm == "size") {
                cout << qu.size() << "\n";
            }
            else if(comm=="front") {
                qu.Front();
            }
            else if(comm=="push") {
                int x; cin>> x;
                qu.push(x);
            }
            else if(comm=="pop") {
                qu.pop();
            }
            else if(comm=="print_sum") {
                qu.print_sum();
            }
        }
    }
}

