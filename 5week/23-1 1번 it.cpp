#include<iostream>
using namespace std;

class Node{
public:
    Node* next = nullptr;
    Node* prev = nullptr;
    int value;
};

class Iterator {
public:
    Node* node;
    Iterator() {
        node = nullptr;
    }
    void set(Node* node) {
        this->node = node;
    }
    Iterator* operator++() {
        node = node->next;
        return this;
    }
    Iterator* operator--() {
        node = node->prev;
        return this;
    }
};

class Sequence {
public:
    Node* head;
    Node* tail;
    int size;

    Sequence() {
        head = new Node;
        tail = new Node;
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    Node* begin() {
        return head->next;
    }
    Node* end() {
        return tail;
    }

    void insert(Iterator& p, int e) {
        Node* newNode = new Node;
        newNode->value = e;

        p.node->prev->next = newNode;
        newNode->prev = p.node->prev;
        newNode->next = p.node;
        p.node->prev = newNode;
        this->size++;
    }
    void erase(Iterator& p) {
        if(size==0 || p.node==tail) {
            return;
        }
        Node* delNode = p.node;
        delNode->prev->next = delNode->next;
        delNode->next->prev = delNode->prev;
        size--;
        delete delNode;
        p.set(begin());
    }
    void nextP(Iterator& p) {
        if(p.node == tail) {
            return;
        }
        ++p;
    }
    void prevP(Iterator& p) {
        if(p.node==head->next) {
            return;
        }
        --p;
    }
    void findmultiple(int e) {
        int idx = 0; int count = 0;
        Iterator q = Iterator();
        q.node = begin();

        while(q.node!= end()) {
            if(q.node->value % e == 0) {
                cout << idx << " ";
                count++;
            }
            idx++;
            nextP(q);
        }
        if(count==0) {
            cout << -1 << "\n";
        }
        else{
            cout << "\n";
        }
    }
};

int main() {
    int N; string comm;
    cin >> N;
    Sequence se;
    Iterator p;
    p.node = se.begin();

    while(N--) {
        cin >> comm;
        if(comm=="begin") {
            p.node = se.begin();
        }
        else if(comm=="end") {
            p.node = se.end();
        }
        else if(comm=="insert") {
            int e; cin >> e;
            se.insert(p,e);
        }
        else if(comm=="erase") {
            if(se.size == 0) {
                cout << "empty" << "\n";
            }
            se.erase(p);
        }
        else if(comm=="nextP") {
            se.nextP(p);
        }
        else if(comm=="prevP") {
            se.prevP(p);
        }
        else if(comm=="findmultiple") {
            int e; cin >> e;
            se.findmultiple(e);
        }
    }
}