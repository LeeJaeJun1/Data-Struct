#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

class linkedList{
private:
    node* head;
    node* tail;
    int listSize;
public:
    linkedList() {
        this->head = NULL;
        this->tail = NULL;
        listSize = 0;
    }
    bool empty() {
        if(listSize == 0) {
            return true;
        }
        else {
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
    void append(int data) {
        node* newNode = new node;
        newNode->data = data;
        newNode->next = NULL;
        if(empty()) {
            head = tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
        listSize++;
    }

    void Delete(int e) {
        node* curNode = head;
        node* preNode = head;
        for(int k = 0; k < listSize; k++) {
            if(curNode->data == e) {
                if(k==0) {
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

    void search(int x) {
        node* curNode = head;
        for(int i = 0; i < listSize; i++) {
            if(curNode->data == x) {
                cout << i << endl;
                return;
            }
            curNode = curNode->next;
        }
    }

    void merge(linkedList* l1, linkedList* l2) {
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
        listSize = l1->listSize + l2->listSize;
    }
};

int main() {
    int m,n1,n2,num,e,s; cin >> m;


    while(m--) {
        linkedList list1;
        linkedList list2;
        linkedList list3;

        cin >> n1;
        for(int i = 0; i < n1; i++) {
            cin >> num;
            list1.append(num);
        }
        cin >> n2;
        for(int j = 0; j < n2; j++) {
            cin >> num;
            list2.append(num);
        }
        list3.merge(&list1,&list2);
        list3.Print();

        cin >> e;
        list3.Delete(e);
        list3.Print();

        cin >> s;
        list3.search(s);
    }
}