#include<iostream>
using namespace std;

class node{
public:
    string data;
    node* prev;
    node* next;
    node(string s) {
        this->data = s;
        prev = next = NULL;
    }
};

class Sequence {
public:
    int size;
    node* head;
    node* tail;
    node* position;

    Sequence() {
        head = new node(" ");
        tail = new node(" ");
        head->next = tail;
        tail->prev = head;
        head->prev = tail->next = NULL;
        size = 0;
    }
    bool empty() {
        return size==0;
    }
    void up(int x) {
        if(empty()) {
            return;
        }
        for(int i = 0; i  < x; i++) {
            if(position == head->next) {
                break;
            }
            position = position->prev;
        }
    }
    void down(int x) {
        if(empty()) {
            return;
        }
        for(int i= 0; i < x; i++) {
            if(position == tail->prev) {
                break;
            }
            position = position->next;
        }
    }
    void cut() {
        if(empty()) {
            return;
        }
        node* delNode = position;
        if(position==tail) {
            position = delNode->prev;
        }
        else {
            position = delNode->next;
        }
        delNode->prev->next = delNode->next;
        delNode->next->prev = delNode->prev;
        delete delNode;
        size--;
    }
    void append(string name) {
        node* newNode = new node(name);
        if(size==0) {
            newNode->next = tail;
            newNode->prev = head;
            head->next = newNode;
            tail->prev = head;
        }
        else {
            newNode->next = position->next;
            position->next->prev = newNode;
            position->next = newNode;
            newNode->prev = position;
        }
        position = newNode;
        size++;
    }
    void position_set(int m) {
        position = head->next;
        down(m);
    }
    void print() {
        if(empty()) {
            cout << "And Then Were None\n";
            return;
        }
        node* curNode = head->next;
        for(int i = 0; i < size; i++) {
            cout << curNode->data << " ";
            curNode = curNode->next;
        }
        cout << "\n";
    }
};

int main() {
    int t,n,m,k;
    cin >> t;
    while(t--) {
        Sequence l;
        string name,command;
        cin >> n >> m >> k;
        while(n--) {
            cin >> name;
            l.append(name);
        }
        l.position_set(k);
        for(int i = 0; i < m; i++) {
            cin >> command;
            if(command == "up") {
                int x; cin >> x;
                l.up(x);
            }
            else if(command == "down") {
                int x; cin >> x;
                l.down(x);
            }
            else if(command == "cut") {
                l.cut();
            }
            else if(command == "append") {
                cin >> name;
                l.append(name);
            }
        }
        l.print();
    }
}