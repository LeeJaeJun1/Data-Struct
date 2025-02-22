#include<iostream>
#include<string>
using namespace std;

class node{
    node* next;
    node* prev;
    string data;

    node(string x) {
        data = x;
        next = prev = NULL;
    }
    friend class LinkedList;
};

class LinkedList {
private:
    node* header;
    node* trailer;
    int size;
    node* position;
public:
    LinkedList() {
        header = new node(" ");
        trailer = new node(" ");
        size = 0;
        header->next = trailer;
        trailer->prev = header;
        header->prev = trailer->next = NULL;
        position = header->next;
    }
    bool empty() {
        return (size == 0);
    }

    void up(int x) {
        if(empty()) {
            return;
        }
        for(int i = 0; i < x; i++) {
            if(position == header->next) {
                break;
            }
            position = position->prev;
        }
    }

    void down(int x) {
        if(empty()) {
            return;
        }
        for(int i = 0; i < x; i++) {
            if(position = trailer->prev) {
                break;
            }
            position = position->next;
        }
    }

    void cut() {
        if(empty()) {
            return;
        }
        node* curNode = position;
        if(position == trailer->prev) {
            position = curNode->prev;
        }
        else{
            position = curNode->next;
        }
        curNode->next->prev = curNode->prev;
        curNode->prev->next = curNode->next;
        delete curNode;
        size--;
    }

    void append(string name) {
        node* newNode = new node(name);
        if(empty()) {
            newNode->next = trailer;
            newNode->prev = header;
            header->next = newNode;
            trailer->prev = header;
        }
        else{
            newNode->next = position->next;
            newNode->prev = position;
            position->next->prev = newNode;
            position->next = newNode;
        }
        position = newNode;
        size++;
    }

    void position_set(int idx) {
        position = header->next;
        down(idx);
    }

    void print() {
        if (size <= 0) {
            cout << "And Then There Were None" << endl;
            return;
        } else {
            node *curNode = header->next;
            for (int i = 0; i < size; i++) {
                cout << curNode->data << " ";
                curNode = curNode->next;
            }
            cout << endl;
        }
    }
};

int main() {
    int t, n,m,k; string name,command;
    cin >> t;
    while(t--) {
        LinkedList l;
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