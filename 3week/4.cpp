#include<iostream>
using namespace std;

class arrayStack {
private:
    int capacity;
    int topIndex;
    int* arr;
public:
    int maxSize;
    arrayStack(int sz) {
        capacity = sz;
        topIndex = -1;
        arr = new int[capacity];
    }
    arrayStack() {
        capacity = 10000;
        topIndex = -1;
        arr = new int[capacity];
        maxSize = 0;
    }
    bool empty() {
        return topIndex==-1;
    }
    int size() {
        return topIndex+1;
    }
    char top() {
        if(empty()) {
            return -1;
        }
        return arr[topIndex];
    }
    void push(char x) {
        if(size() >= capacity) {
            cout << "FULL\n";
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
    int n; cin >> n;
    string s;

    while(n--) {
        arrayStack sta;
        cin >> s;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] >= '1' && s[i] <= '9') {
                cout << s[i];
            }
            else if(s[i] == '+' || s[i] == '-') {
                while(!sta.empty()) {
                    cout << sta.top();
                    sta.pop();
                }
                sta.push(s[i]);
            }
            else if(s[i] == '*' ||s[i] == '/') {
                while(!sta.empty() && (sta.top() == '*' || sta.top() == '/')) {
                    cout << sta.top();
                    sta.pop();
                }
                sta.push(s[i]);
            }
            if(sta.size() > sta.maxSize) {
                sta.maxSize = sta.size();
            }
        }
        while(!sta.empty()) {
            cout << sta.top();
            sta.pop();
        }
        cout << " " << sta.maxSize << "\n";
    }
}