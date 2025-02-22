#include<iostream>
#include<string>
using namespace std;

class node{
    node* next;
    node* prev;
    int data;

    node(int x) {
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
public:
    LinkedList() {
        header = new node(0);
        trailer = new node(0);
        size = 0;
        header->next = trailer;
        trailer->prev = header;
        header->prev = trailer->next = NULL;
    }
    bool empty() {
        if(size == 0) {
            return true;
        }
        return false;
    }

    void insert(int i, int x) {
        if(i<0 || i> size) {
            cout << "out_of_range" << endl;
            return;
        }
        node* curNode = header->next;
        for(int j = 0; j < i; j++) {
            curNode = curNode->next;
        }
        node* newNode = new node(x);
        newNode->next = curNode;
        newNode->prev = curNode->prev;
        curNode->prev->next = newNode;
        curNode->prev = newNode;
        size++;
    }

    void erase(int i) {
        if(i < 0 || i >= size) {
            cout << "out_of_range" << endl;
            return;
        }
        node* curNode = header->next;
        for(int j = 0; j < i; j++) {
            curNode = curNode->next;
        }
        curNode->prev->next = curNode->next;
        curNode->next->prev = curNode->prev;
        delete curNode;
        size--;
    }

    void find(int x) {
        node* curNode = header->next;
        for(int i = 0; i < size; i++) {
            if(curNode->data == x) {
                cout << i << endl;
                return;
            }
            curNode = curNode->next;
        }
        cout << "not_found" << endl;
    }

    void print(int m) {
        if(empty()) {
            cout << "empty" << endl;
            return;
        }

        if(m==0) {
            node* curNode = header->next;
            for(int i = 0; i < size; i++) {
                cout << curNode->data << " ";
                curNode = curNode->next;
            }
            cout << endl;
        }
        else if(m==1) {
            node* curNode = trailer->prev;
            for(int i = 0; i < size; i++) {
                cout << curNode->data << " ";
                curNode = curNode->prev;
            }
            cout << endl;
        }
    }
};

int main() {
    int n; string s;
    LinkedList l;
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