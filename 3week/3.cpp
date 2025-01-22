#include<iostream>
using namespace std;

class node{
private:
    node* next;
    int data;
public:
    node() {
        this->next = nullptr;
        data = 0;
    }
    friend class listStack;

};

class listStack {
private:
    node* topNode;
    int listsize;
public:
    listStack() {
        topNode = NULL;
        listsize = 0;
    }
    bool empty() {
        if(listsize==0) {
            return true;
        }
        else
            return false;
    }
    int size() {
        return listsize;
    }
    int top() {
        if(empty()) {
            return -1;
        }
        return topNode->data;
    }
    void push(int x) {
        node* newNode = new node;
        newNode->data = x;
        if(empty()) {
            topNode=newNode;
        }
        else {
            newNode->next = topNode;
            topNode = newNode;
        }
        listsize++;
    }
    void pop(int s) {
        if(empty()) {
            cout << -1 << endl;
            return;
        }
        if(s > listsize) {
            for(int i = 0; i < listsize; i++) {
                cout << topNode->data << " ";
                node* curNode = topNode;
                topNode = topNode->next;
                delete curNode;
            }
            listsize = 0;
            cout << endl;
        }
        else{
            for(int i = 0; i < s; i++) {
                cout << topNode->data << " ";
                node* curNode = topNode;
                topNode = topNode->next;
                delete curNode;
                listsize--;
            }
            cout << endl;
        }
    }
};

int main() {
    int n; cin >> n;
    string s;
    listStack l1;
    while(n--) {
        cin >> s;
        if(s == "size") {
            cout << l1.size() << endl;
        }
        else if(s=="empty") {
            if(l1.empty()) {
                cout << "1" << endl;
            }
            else{
                cout << "0" << endl;
            }
        }
        else if(s=="top") {
            cout << l1.top() << endl;
        }
        else if(s=="push") {
            int x; cin >> x;
            l1.push(x);
        }
        else if(s=="pop") {
            int S; cin >> S;
            l1.pop(S);
        }
    }
}
