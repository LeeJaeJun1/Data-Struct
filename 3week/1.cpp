#include<iostream>
#include<string>
using namespace std;

class arrayStack {
private:
    int *arr;
    int capacity; // 최대 크기
    int topIndex;
public:
    arrayStack(int capacity);
    bool empty();
    int size();
    int top();
    void push(int data);
    int popsum(int s);
};

arrayStack::arrayStack(int capacity) {
    this->capacity = capacity;
    this->arr = new int[capacity];
    topIndex = -1;
}

bool arrayStack::empty() {
    if(topIndex == -1) {
        return true;
    }
    else{
        return false;
    }
}

int arrayStack::size() {
    return topIndex + 1;
}

int arrayStack::top() {
    if(empty()) {
        return -1;
    }
    return arr[topIndex];
}

void arrayStack::push(int data) {
    if(size() >= capacity) {
        cout << "FULL";
    }
    else{
        arr[topIndex + 1] = data;
        topIndex++;
    }
}

int arrayStack::popsum(int s) {
    int sum = 0;
    if(empty()) {
        return -1;
    }
    else if(s > size()) {
        for(int i = 0; i < size(); i++) {
            sum += arr[i];
        }
        topIndex = -1;
        return sum;
    }
    else{
        for(int i = 0; i < s; i++) {
            sum += arr[topIndex-i];
        }
        topIndex-=s;
        return sum;
    }
}

int main() {
    int t,N,data,s;
    string command;
    cin >> t >> N;
    arrayStack a(t);

    while(N--) {
        cin >> command;
        if(command == "empty") {
            cout << a.empty() << endl;
        }
        else if(command == "size") {
            cout << a.size() << endl;
        }
        else if(command == "push") {
            cin >> data;
            a.push(data);
        }
        else if(command == "popsum") {
            cin >> s;
            cout << a.popsum(s) << endl;
        }
        else{
            cout << a.top() << endl;
        }
    }
    return 0;
}
