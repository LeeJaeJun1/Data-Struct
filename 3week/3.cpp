#include<iostream>
using namespace std;

class node{
private:
    int data;
    node* next;
public:
    node(int x) {
        next = NULL;
        data = x;
    }
    friend class listStack;
};

class listStack{
private:
    node* topNode;
    int listSize;
public:
    listStack() {
        topNode = NULL;
        listSize = 0;
    }
    bool empty() {
        if(listSize == 0)
            return true;
        else
            return false;
    }
    int size() {
        return listSize;
    }
    int top() {
        if(empty()) {
            return -1;
        }
        return topNode->data;
    }
    void push(int x) {
        node* newNode = new node(x);
        if(empty()) {
            topNode = newNode;
        }
        else {
            newNode->next = topNode;
            topNode = newNode;
        }
        listSize++;
    }
    void pop(int s) {
        if(empty()) {
            cout << -1 << endl;
            return;
        }
        for(int i = 0; i < s; i++) {
            if(empty()) {
                break;
            }
            node* curNode = topNode;
            cout << topNode->data << " ";
            topNode = topNode->next;
            delete curNode;
            listSize--;
        }
        cout << endl;
    }
};

int main() {
    int n; string s;
    cin >> n;
    listStack st;
    while(n--) {
        cin >> s;
        if(s=="size") {
            cout << st.size() << endl;
        }
        else if(s=="empty") {
            if(st.empty()) {
                cout << 1 << endl;
            }
            else{
                cout << 0 << endl;
            }
        }
        else if(s=="top") {
            cout << st.top() << endl;
        }
        else if(s=="push") {
            int x; cin >> x;
            st.push(x);
        }
        else if(s=="pop") {
            int sw; cin >> sw;
            st.pop(sw);
        }
    }
}