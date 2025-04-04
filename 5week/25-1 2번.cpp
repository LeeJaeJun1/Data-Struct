#include<iostream>
using namespace std;

class Node{
public:
    int value;
    Node* prev;
    Node* next;

    Node() {
        value = 0;
        prev = next = NULL;
    }
};

class Iterator {
public:
    Node* node;
    Iterator() {
        node = NULL;
    }
    Iterator* operator++() {
        node = node->next;
        return this;
    }
    Iterator* operator--() {
        node = node->prev;
        return this;
    }
    void set(Node* node) {
        this->node = node;
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
        return tail->prev;
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
        if(p.node == tail->prev) {
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
    void odd(Iterator& p, int idx, int x) {
        int count = 0;
        p.set(begin());
        if(idx % 2 != 0) {
            for(int i = 0; i <= idx; i++) {
                nextP(p);
            }
            for(int j = 0; j < x; j++) {
                if(p.node->value % 2 != 0) {
                    cout << p.node->value << " ";
                    count++;
                }
                nextP(p);
            }

            if(count == 0) {
                cout << "-1\n";
                return;
            }
            cout << "\n";
        }
        else if(idx % 2 == 0) {
            p.set(begin());
            for(int j = 0;  j < idx-1; j++) {
                nextP(p);
            }
            for(int k = 0; k < x; k++) {
                if(p.node->value % 2 == 0) {
                    cout << p.node->value << " ";
                    count++;
                }
                prevP(p);
            }
            if(count == 0) {
                cout << "-1\n";
                return;
            }
            cout << "\n";
        }
    }
};

int main() {
    int T,N,Q,num,idx,x;
    string comm;
    cin >> T;
    while(T--) {
        Iterator p;
        Sequence sa;
        p.set(sa.begin());
        cin >> N >> Q;
        while(N--) {
            cin >> num;
            sa.insert(p,num);
        }
        p.set(sa.begin());
        while(Q--) {
            cin >> idx >> x;
            sa.odd(p,idx,x);
            p.set(sa.begin());
        }
    }
}
