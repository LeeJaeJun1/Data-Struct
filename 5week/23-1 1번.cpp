#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node() {
        data = 0;
        next = prev = NULL;
    }
    Node(int value) {
        data = value;
        next = prev = NULL;
    }
};

class doublyLinked {
public:
    Node* head;
    Node* tail;
    Node* p;
    int size;

    doublyLinked() {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail -> prev = head;
        p = head->next;
        size = 0;
    }
    Node* begin() {
        return head->next;
    }
    Node* end() {
        return tail;
    }
    void insert(int e) {
        Node* newNode = new Node(e);
        newNode->prev = p->prev;
        newNode->next = p;
        p->prev->next = newNode;
        p->prev = newNode;
        size++;
    }
    void erase() {
        if(size==0) {
            cout << "empty" << "\n";
            return;
        }
        if(p==tail) {
            return;
        }
        Node* delNode = p;
        delNode->next->prev = delNode->prev;
        delNode->prev->next = delNode->next;
        size--;
        delete delNode;
        p = begin();
    }
    void nextP() {
        if(p==tail) {
            return;
        }
        p = p->next;
    }
    void prevP() {
        if(p==head->next) {
            return;
        }
        p = p->prev;
    }
    void findmultiple(int e) {
        Node* temp = head->next;
        int index = 0; int found = 0;
        while(temp!= tail) {
            if(temp->data % e == 0) {
                cout << index << ' ';
                found = 1;
            }
            temp = temp->next;
            index++;
        }
        if(!found) {
            cout << -1;
        }
        cout << "\n";
    }
};

int main() {
    int n;
    cin >> n;
    doublyLinked dll;
    dll.p = dll.begin();
    while (n--) {
        string cmd;
        cin >> cmd;

        if (cmd == "begin")
            dll.p = dll.begin();
        else if (cmd == "end")
            dll.p = dll.end();
        else if (cmd == "insert") {
            int e;
            cin >> e;
            dll.insert(e);
        }
        else if (cmd == "erase")
            dll.erase();
        else if (cmd == "nextP")
            dll.nextP();
        else if (cmd == "prevP")
            dll.prevP();
        else if (cmd == "findmultiple") {
            int e;
            cin >> e;
            dll.findmultiple(e);
        }
    }
}