#include<iostream>
using namespace std;

class ArrayStack {
public:
    int capacity;
    int topIndex;
    int* arr;

    ArrayStack() {
        topIndex = -1;
        capacity = 100000;
        arr = new int[capacity];
    }

    bool empty() {
        return topIndex == -1;
    };

    int size() {
        return topIndex+1;
    }

    void top() {
        if(empty()) {
            cout << "-1\n";
            return;
        }
        cout << arr[topIndex] << "\n";
    }

    void push(char x) {
        arr[topIndex+=1] = x;
    }

    void pop() {
        if(empty()) {
            cout << "-1\n";
            return;
        }
        cout << arr[topIndex] << "\n";
        topIndex--;
    }

    void pop_all() {
        if(empty()) {
            cout << "-1\n";
            return;
        }
        for(int i = 0; i <= topIndex; i++) {
            cout << arr[topIndex - i] << " ";
        }
        cout << "\n";
        topIndex=-1;
    }
};

int main() {
    int com;
}