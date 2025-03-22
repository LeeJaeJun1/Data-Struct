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
    void push(int x) {
        arr[topIndex+=1] = x;
    }
    void pop() {
        if(empty()) {
            cout << -1 << "\n";
            return;
        }
        cout << top() << "\n";
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
    int t,q; string s;
    cin >> t;
    while(t--) {
        arrayStack sta;
        cin >> q;
        while(q--) {
            cin >> s;
            if(s=="size") {
                cout << sta.size() << "\n";
            }
            else if(s=="empty") {
                if(sta.empty()) {
                    cout << 1 << "\n";
                }
                else{
                    cout << 0 << "\n";
                }
            }
            else if(s=="top") {
                cout << sta.top() << "\n";
            }
            else if(s=="push") {
                int x; cin >> x;
                sta.push(x);
            }
            else if(s=="pop") {
                sta.pop();
            }
            else if(s=="pop_all") {
                sta.pop_all();
            }
        }
    }
}