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
    int maxsize;
    listStack() {
        topNode = NULL;
        listSize = 0;
        maxsize = 0;
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
    char top() {
        if(empty()) {
            return -1;
        }
        return topNode->data;
    }
    void push(char x) {
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
    void pop() {
        if(empty()) {
            return;
        }
        node* curNode = topNode;
        topNode = topNode->next;
        delete curNode;
        listSize--;
    }
};

int main() {
    int t;
    string s;
    cin >> t;
    while(t--) {
        listStack ls;
        cin >> s;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] >= '1' && s[i] <= '9') {
                cout << s[i];
            }
            else if(s[i] == '+' || s[i] == '-') {
                while(!ls.empty()) {
                    cout << ls.top();
                    ls.pop();
                }
                ls.push(s[i]);
            }
            else if(s[i] == '*') {
                while(!ls.empty() && ls.top() == '*') {
                    cout << ls.top();
                    ls.pop();
                }
                ls.push(s[i]);
            }
            if(ls.size() >ls.maxsize) {
                ls.maxsize = ls.size();
            }
        }
        while(!ls.empty()) {
            cout << ls.top();
            ls.pop();
        }
        cout << ' ' << ls.maxsize << endl;
    }
}
