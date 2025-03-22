#include<iostream>
using namespace std;

class arrayStack{
private:
    int capacity;
    int topIndex;
    int* arr;
public:
    arrayStack() {
        capacity = 100000;
        topIndex = -1;
        arr = new int[capacity];
    }
    int size() {
        return topIndex+1;
    };
    bool empty() {
        return topIndex==-1;
    }
    int top() {
        if(empty()) {
            return -1;
        }
        return arr[topIndex];
    }
    void push(char x) {
        arr[topIndex+=1] = x;
    }
    void pop() {
        if(empty()) {
            cout << -1 << "\n";
            return;
        }

        topIndex--;
    }
    void pop_all() {
        if(empty()) {
            cout << -1 << "\n";
            return;
        }
        int sum = 0;
        while(!empty()) {
            sum += top();
            topIndex--;
        }
        cout << sum << "\n";
    }
};

int main() {
    int q; string sa;
    cin >> q;
    int total = 0;
    while(q--) {
        arrayStack sta;
        cin >> sa;
        int len = sa.length();
        for(int i = 0; i < len; i++) {
            if(sa[i] == '(') {
                sta.push(sa[i]);
            }
            else {
                if(sta.empty()) {
                    total += 1;
                }
                else {
                    if(sta.top() == '(') {
                        sta.pop();
                    }
                    else{
                        total += 1;
                    }
                }
            }
        }
        total += sta.size();
        cout << total << "\n";
        total = 0;
    }
}