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
    arrayStack() {
        capacity = 100;
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
};

int main() {
    int t,K; string s;
    cin >> t;
    arrayStack a;
    for(int i = 0 ; i < t; i++) {
        cin >> s >> K;
        for(int j = 0; j < s.size(); j++) {
            if(s[j] >= '1' && s[j] <= '9') {
                a.push(s[j]-'0');
            }
            else if(s[j] == '*' || s[j] == '+' || s[j] == '-') {
                int second = a.top();
                a.pop();
                int first = a.top();
                a.pop();
                if(s[j] == '+') {
                    a.push(first+second);
                }
                if(s[j] == '-') {
                    a.push(first-second);
                }
                if(s[j] == '*') {
                    a.push(first * second);
                }
            }
        }
        if(a.top() > 0) {
            cout << a.top() % K << endl;
        }
        else{
            cout << -a.top() % K << endl;
        }
    }
}

