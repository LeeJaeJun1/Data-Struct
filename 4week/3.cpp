#include<iostream>
using namespace std;

class arrayQueue {
public:
    arrayQueue(int capacity);
    bool isEmpty();
    int size();
    int front();
    void enqueue(int data);
    void dequeue();
    void rearNsum(int num);
private:
    int* arr;
    int capacity;
    int frontIndex;
    int rearIndex;
    int n;
};

arrayQueue::arrayQueue(int capacity) {
    this->capacity = capacity;
    arr = new int[capacity];
    frontIndex = rearIndex = 0;
    n = 0;
}

int arrayQueue::size() {
    return n;
}

bool arrayQueue::isEmpty() {
    return n == 0;
}
int arrayQueue::front() {
    return arr[frontIndex];
}

void arrayQueue::enqueue(int data) {
    if(capacity == n) {
        cout << "Full" << endl;
        return;
    }
    arr[rearIndex] = data;
    rearIndex = (rearIndex + 1) % capacity;
    n++;
}

void arrayQueue::dequeue() {
    if(isEmpty()) {
        cout << "Empty" << endl;
        return;
    }
    cout << arr[frontIndex] << endl;
    frontIndex = (frontIndex+1) % capacity;
    n--;
}

void arrayQueue::rearNsum(int num) {
    int sum = 0;
    if(isEmpty()) {
        cout << "Empty\n";
        return;
    }

    if(num > n) {
        cout << "error\n";
    }
    else{
        for(int i = 0; i < num; i++) {
            sum += arr[(rearIndex + capacity - i -1) % capacity];
        }
        cout << sum << endl;
    }
}

int main() {
    int N, T, num,data; cin >> N >> T;
    string command;
    arrayQueue arr(N);
    while(T--) {
        cin >> command;
        if(command == "isEmpty") {
            if(arr.isEmpty()) {
                cout << "True" << endl;
            }
            else{
                cout << "False" << endl;
            }
        }
        else if(command == "size") {
            cout << arr.size() << endl;
        }
        else if(command == "full") {
            if(arr.size() == N) {
                cout << "True" << endl;
            }
            else{
                cout << "False" << endl;
            }
        }
        else if(command == "front") {
            if(arr.isEmpty()) {
                cout << "Empty" << endl;
            }

            else{
                cout << arr.front() << endl;
            }
        }
        else if(command == "dequeue") {
            arr.dequeue();
        }
        else if(command == "enqueue") {
            cin >> data;
            arr.enqueue(data);
        }
        else if(command == "rearNsum") {
            cin >> num;
            arr.rearNsum(num);
        }
    }
}