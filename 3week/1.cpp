#include<iostream>
using namespace std;

class arrayStack {
private:
    int capacity;
    int topIndex;
    int *arr;
public:
    arrayStack(int sz) {
        capacity = sz;
        topIndex = -1;
        arr = new int[capacity];
    }
    bool empty() {
        if(topIndex == -1) {
            return true;
        }
        else{
            return false;
        }
    }

    int size() {
        return topIndex + 1;
    }

    int top() {
        if(empty()) {
            return -1;
        }
        else{return arr[topIndex];}
    }

    void push(int x) {
        if(capacity <= size()) {
            cout << "FULL" << endl;
            return;
        }
        arr[topIndex+=1] = x;
    }

    void pop() {
        if(empty()) {
            return;
        }
        topIndex--;
    }
    int popsum(int s) {
        if(empty()) {
            return -1;
        }
        else {
            int total = 0;
            for(int i = 0; i < s; i++) {
                total += top();
                pop();
                if(empty()) {
                    break;
                }
            }
            return total;
        }
    }
};

int main() {
    int t,n; string command;
    cin >> t >> n;
    arrayStack st(t);
    while(n--) {
        cin >> command;
        if(command == "empty") {
            if(st.empty()) {
                cout << 1 << endl;
            }
            else{
                cout << 0 << endl;
            }
        }
        else if(command == "size") {
            cout << st.size() << endl;
        }
        else if(command == "top") {
            cout << st.top() << endl;
        }
        else if(command == "push") {
            int x;
            cin >> x;
            st.push(x);
        }
        else if(command == "popsum") {
            int s;
            cin >> s;
            cout << st.popsum(s) << endl;
        }
    }
}