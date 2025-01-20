#include<iostream>
using namespace std;

class node{
private:
    int data;
    node* next;
public:
    node() {
        this-> data = 0;
        this->next = 0;
    }
    friend class LinkedList;
};

class LinkedList {
private:
    node* head;
    node* tail;
    int linkedSize;
public:
    LinkedList() {
        head = NULL;
        tail = NULL;
        linkedSize = 0;
    }

    bool empty() {
        if(linkedSize == 0) {
            return true;
        }
        return false;
    }

    void Print() {
        if(empty()) {
            cout << "empty";
        }
        node* curNode = head;
        while(curNode!=NULL) {
            cout << curNode->data << " ";
            curNode = curNode->next;
        }
        cout << endl;
        return;
    }

    void Append(int x) {
        node* newNode = new node;
        newNode->data = x;
        newNode->next = nullptr;
        if(empty()) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
        linkedSize++;
        Print();
        return;
    }

    void Delete(int i) {
        if(empty() || i >= linkedSize) {
            cout << -1 << endl;
            return;
        }
        node* curNode = head;
        if(i==0) {
            if(linkedSize == 1) {
                head = tail = nullptr;
            }
            else{
                head = head->next;
            }
        }
        else{
            node* preNode = head;
            for(int a = 0; a < i; a++) {
                preNode = curNode;
                curNode = curNode->next;
            }
            preNode->next = curNode->next;
            if(curNode==tail) {
                tail = preNode;
            }
            cout << curNode->data << endl;
            delete curNode;
        }
        linkedSize--;
    }

    void AfterMin(int i) {
        if(empty() || i >= linkedSize) {
            cout << "error" << endl;
            return;
        }
        node* curNode = head;
        for(int k = 0; k < i; k++) {
            curNode = curNode->next;
        }
        int min = curNode->data;
        curNode = curNode->next;
        while(curNode != NULL) {
            if(curNode->data < min) {
                min = curNode->data;
            }
            curNode = curNode->next;
        }
        cout << min << endl;
    }

    void Sum() {
        int total = 0;
        if(empty()) {
            cout << "0" << endl;
            return;
        }
        node* curNode = head;
        while(curNode != NULL) {
            total += curNode->data;
            curNode = curNode->next;
        }
        cout << total << endl;
        return;
    }
};

int main() {
    int m; string s;
    LinkedList list;
    cin >> m;
    while(m--) {
        cin >> s;
        if(s=="Print") {
            list.Print();
        }
        else if(s=="Append") {
            int io;
            cin >> io;
            list.Append(io);
        }
        else if(s=="Delete") {
            int io; cin >> io;
            list.Delete(io);
        }
        else if(s=="AfterMin") {
            int io; cin >> io;
            list.AfterMin(io);
        }
        else if(s=="Sum") {
            list.Sum();
        }
    }
}
