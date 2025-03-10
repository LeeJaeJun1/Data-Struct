#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

class singlyLinkedList {
private:
    node* head;
    node* tail;
    int listSize;
public:
    singlyLinkedList() {
        head = NULL;
        tail = NULL;
        listSize = 0;
    }
    bool empty() {
        if(listSize == 0) {
            return true;
        }
        else{
            return false;
        }
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
    void insertion(int i, int data) {
        if(i < 0 || i > listSize) {
            return;
        }
        else if(i == listSize) {
            append(data);
        }
        else if(i==0) {
            node* newNode = new node;
            newNode->data = data;
            newNode->next = head;
            head = newNode;
            listSize++;
        }
        else{
            node* newNode = new node;
            newNode->data = data;
            node* curNode = head;
            for(int k = 1; k < i; k++) {
                curNode = curNode->next;
            }
            newNode->next = curNode->next;
            curNode->next = newNode;
            listSize++;
        }
    }
    void deletion(int i) {
        if(empty() || i < 0 || i >= listSize) {
            cout << -1 << "\n";
            return;
        }
        node* curNode = head;
        if(i==0) {
            if(listSize==1) {
                head = tail = NULL;
            }
            else{
                head = head->next;
            }
            cout << curNode->data << endl;
        }
        else{
            node* preNode = head;
            for(int k = 0; k < i; k++) {
                preNode = curNode;
                curNode = curNode->next;
            }
            preNode->next = curNode->next;
            if(curNode==tail) {
                tail = preNode;
            }
            cout << curNode->data << "\n";
            delete curNode;
        }
        listSize--;
    }
    void print() {
        if(empty()) {
            cout << "empty" << "\n";
            return;
        }
        node* curNode = head;
        while(curNode!= NULL) {
            cout << curNode->data << " ";
            curNode = curNode->next;
        }
        cout << endl;
    }
    void Sum() {
        if(empty()) {
            cout << "0" << endl;
            return;
        }
        else{
            int sum = 0;
            node* curNode = head;
            while(curNode != NULL) {
                sum += curNode->data;
                curNode = curNode->next;
            }
            cout << sum << "\n";
        }
    }
    void AfterMax(int i) {
        if(empty() || i >= listSize) {
            cout << "error" << "\n";
            return;
        }

        node* curNode = head;
        for(int k = 0; k < i; k++) {
            curNode = curNode->next;
        }
        int max = curNode->data;
        while(curNode != NULL) {
            if(max < curNode->data) {
                max = curNode->data;
            }
            curNode = curNode->next;
        }
        cout << max << "\n";
    }
    void merge(singlyLinkedList* s1, singlyLinkedList* s2) {
        head = s1->head;
        node* curNode = head;
        while(curNode->next != NULL) {
            curNode = curNode->next;
        }
        curNode->next = s2->head;
        while(curNode->next!=NULL) {
            curNode = curNode->next;
        }
        tail = curNode;
        curNode = head;
        listSize = s1->listSize + s2->listSize;
        print();
    }

    void plus(int e, int v) {
        node* curNode = head;
        node* preNode = head;
        node* addNode = new node;
        addNode->data = v;
        addNode->next = NULL;
        while(curNode!=NULL) {
            if(curNode->data == e) {
                if(curNode == head) {
                    addNode->next = head;
                    head = addNode;
                    print();
                    return;
                }
                else {
                    preNode->next = addNode;
                    addNode->next = curNode;
                    print();
                    return;
                }
            }
            preNode = curNode;
            curNode = curNode->next;
        }
    }
};

int main() {
    int M,n1,n2,num,e,v;
    cin >> M;
    while(M--) {
        singlyLinkedList s1;
        singlyLinkedList s2;
        singlyLinkedList s3;
        cin >> n1;
        for(int i = 0; i < n1; i++) {
            cin >> num;
            s1.append(num);
        }
        cin >> n2;
        for(int j = 0; j < n2; j++) {
            cin >> num;
            s2.append(num);
        }
        s3.merge(&s1,&s2);
        cin >> e >> v;
        s3.plus(e,v);
    }
}
