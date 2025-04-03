#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        this->data = x;
        next = prev = NULL;
    }
};

class doubly{
private:
    int size;
    Node* head;
    Node* tail;
public:
    doubly() {
        head = new Node(0);
        tail = new Node(0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    bool empty() {
        return size==0;
    }
    void insert(int idx, int x) {
        if(idx < 0 || idx > size) {
            cout << "out_of_range" << "\n";
            return;
        }
        Node* newNode = new Node(x);
        Node* curNode = head->next;
        for(int i = 0; i < idx; i++) {
            curNode = curNode->next;
        }
        newNode->next = curNode;
        newNode->prev = curNode->prev;
        curNode->prev->next = newNode;
        curNode->prev = newNode;
        size++;
    }
    void erase(int idx) {
        if(idx < 0 || idx >= size) {
            cout << "out_of_range" << "\n";
            return;
        }
        Node* delNode = head->next;
        for(int i = 0; i < idx; i++) {
            delNode = delNode->next;
        }
        delNode->prev->next = delNode->next;
        delNode->next->prev = delNode->prev;
        delete delNode;
        size--;
    }
    void find(int x) {

        Node* curNode = head->next;
        for(int i = 0; i < size; i++) {
            if(curNode->data == x) {
                cout << i << "\n";
                return;
            }
            curNode = curNode->next;
        }
        cout << "not_found\n";
    }
    void print(int m) {
        if(empty()) {
            cout << "empty\n";
            return;
        }
        if(m==0) {
            Node* curNode = head->next;
            for(int i = 0; i < size; i++) {
                cout << curNode->data << " ";
                curNode= curNode->next;
            }
            cout << "\n";
        }
        else if(m==1) {
            Node* curNode = tail->prev;
            for(int i = 0; i < size; i++) {
                cout << curNode->data << " ";
                curNode = curNode->prev;
            }
            cout << "\n";
        }
    }
};

int main() {
    int n; string s;
    doubly l;
    cin >> n;
    while(n--) {
        cin >> s;
        if(s=="empty") {
            if(l.empty()) {
                cout << "true" << endl;
            }
            else{
                cout << "false" << endl;
            }
        }
        else if(s=="insert") {
            int i,x;
            cin >> i >> x;
            l.insert(i,x);
        }
        else if(s=="erase") {
            int i; cin >> i;
            l.erase(i);
        }
        else if(s=="find") {
            int x; cin >> x;
            l.find(x);
        }
        else if(s=="print") {
            int m; cin >> m;
            l.print(m);
        }
    }
}