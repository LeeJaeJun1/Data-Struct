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
    }

    void Delete(int e) {
        node* curNode = head;
        node* preNode = head;
        for(int i = 0 ; i < listSize; i++) {
            if(curNode->data == e) {
                if(i==0) {
                    head = curNode->next;
                }
                else{
                    preNode->next = curNode->next;
                }
                listSize--;
                delete curNode;
                return;
            }
            preNode = curNode;
            curNode = curNode->next;
        }
    }

    void merge(LinkedList* l1, LinkedList* l2) {
        head = l1->head;
        node* curNode = head;
        while(curNode->next != NULL) {
            curNode = curNode->next;
        }
        curNode->next = l2->head;
        while(curNode->next != NULL) {
            curNode = curNode->next;
        }
        tail = curNode;
        curNode = head;
        listSize = l1->listSize + l2->listSize;
    }

    void search(int v) {
        node* curNode = head;
        for(int i = 0; i < listSize; i++) {
            if(curNode->data == v) {
                cout << i << endl;
                return;
            }
            curNode = curNode->next;
        }
    }
};

int main() {
    int M,e,v;
    cin >> M;
    while(M--) {
        LinkedList l1;
        LinkedList l2;
        LinkedList l3;
        int n1, num1, n2, num2;
        cin >> n1;
        for(int i = 0; i < n1; i++) {
            cin >> num1;
            l1.Append(num1);
        }
        cin >> n2;
        for(int j = 0; j < n2; j++) {
            cin >> num2;
            l2.Append(num2);
        }
        l3.merge(&l1, &l2);
        l3.Print();
        cin >> e;
        l3.Delete(e);
        l3.Print();
        cin >> v;
        l3.search(v);
    }
}