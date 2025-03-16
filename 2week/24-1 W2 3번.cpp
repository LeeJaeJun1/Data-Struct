#include<iostream>
using namespace std;

class node{
private:
    int data;
    node* next;
public:
    node() {
        this->data = 0;
        this->next = 0;
    }
    node(int x) {
        data = x;
        next = nullptr;
    }
    friend class LinkedList;
};

class LinkedList {
private:
    int listSize;
    node* head;
    node* tail;
public:
    LinkedList() {
        head = NULL;
        tail = NULL;
        listSize = 0;
    }

    bool empty() {
        if(listSize==0) {
            return true;
        }
        else{
            return false;
        }
    }

    void Print() {
        if(empty()) {
            cout << "empty" << endl;
            return;
        }
        node* curNode = head;
        while(curNode != NULL) {
            cout << curNode->data << " ";
            curNode = curNode->next;
        }
        cout << endl;
    }

    void Append(int x) {
        node* newNode = new node(x);
        if(empty()) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
        listSize++;
        Print();
    }

    void Delete(int io) {
        if(empty() || io >= listSize) {
            cout << "-1" << endl;
            return;
        }
        node* curNode = head;
        if(io==0) {
            if(listSize == 1) {
                head = tail = nullptr;
            }
            else {
                head = head->next;
            }
            cout << curNode->data << endl;
        }
        else{
            node* preNode = head;
            for(int j = 0; j < io; j++) {
                preNode = curNode;
                curNode = curNode->next;
            }
            preNode->next = curNode->next;
            if(curNode == tail) {
                tail = preNode;
            }
            cout << curNode->data << endl;
            delete curNode;
        }
        listSize--;
    }
    void AfterMin(int io) {
        if(empty() || io>=listSize) {
            cout << "error" << endl;
            return;
        }
        node* curNode = head;
        for(int i = 0; i < io; i++) {
            curNode = curNode->next;
        }
        int min = curNode->data;
        while(curNode!=NULL) {
            if(curNode->data < min) {
                min = curNode->data;
            }
            curNode = curNode->next;
        }
        cout << min << endl;
    }
    void Sum() {
        if(empty()) {
            cout << "0" << endl;
            return;
        }
        int total = 0;
        node* curNode = head;
        while(curNode != NULL) {
            total += curNode->data;
            curNode = curNode->next;
        }
        cout << total << endl;
    }
};

int main() {
    int M; string command;
    LinkedList list;
    cin >> M;
    while(M--) {
        cin >> command;
        if(command == "Append") {
            int x;
            cin >> x;
            list.Append(x);
        }
        else if(command == "Delete") {
            int io;
            cin >> io;
            list.Delete(io);
        }
        else if(command == "AfterMin") {
            int io;
            cin >> io;
            list.AfterMin(io);
        }
        else if(command == "Sum") {
            list.Sum();
        }
        else if(command == "Print") {
            list.Print();
        }
    }
}