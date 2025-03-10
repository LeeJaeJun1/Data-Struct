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

        print();
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
};

int main() {
    int M,x,idx;
    string s;
    cin >> M;
    singlyLinkedList list;
    while(M--) {
        cin >> s;
        if(s=="Print") {
            list.print();
        }
        else if(s=="Append") {
            cin >> x;
            list.append(x);
        }
        else if(s=="Delete") {
            cin >> idx;
            list.deletion(idx);
        }
        else if(s=="AfterMax") {
            cin >> idx;
            list.AfterMax(idx);
        }
        else if(s=="Sum") {
            list.Sum();
        }
    }

}