#include<iostream>
using namespace std;

class node{
private:
    node* next;
    char data;
public:
    node() {
        next = NULL;
        data = 0;
    }
    friend class listStack;
};

class listStack {
private:
    node* topNode;
    int listSize;
public:
    int maxSize = 0;
    listStack() {
        topNode = NULL;
        listSize = 0;
        maxSize = 0;
    }
    bool empty() {
        if(listSize == 0) {
            return true;
        }
        else{
            return false;
        }
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
        node* newNode = new node;
        newNode->data = x;
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
        node* del = topNode;
        topNode = topNode->next;
        delete del;
        listSize--;
    }
};

int main() {
    int n;
    string s;
    cin >> n;
    for (int j = 0; j < n; j++) {
        listStack l1;
        cin >> s;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '1' && s[i] <= '9') {
                cout << s[i];
            } else if (s[i] == '+' || s[i] == '-') {
                while (!l1.empty()) {
                    cout << l1.top();
                    l1.pop();
                }
                l1.push(s[i]);
            } else if (s[i] == '*') {
                while (!l1.empty() && l1.top() == '*') {
                    cout << l1.top();
                    l1.pop();
                }
                l1.push(s[i]);
            }
            if (l1.size() > l1.maxSize) {
                l1.maxSize = l1.size();
            }
        }
        while (!l1.empty()) {
            cout << l1.top();
            l1.pop();
        }
        cout << " " << l1.maxSize << endl;
    }
}
