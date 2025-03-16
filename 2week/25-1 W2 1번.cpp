#include<iostream>
using namespace std;

class node{
private:
    int data;
    node* next;
public:
    node(int x) {
        this->data = x;
        this->next = NULL;
    }
    friend class singlyList;
};

class singlyList {
private:
    node* head;
    node* tail;
    int listSize;
public:
    singlyList() {
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
    void Print() {
        if (empty()) {
            cout << "empty" << "\n";
            return;
        } else {
            node *curNode = head;
            while (curNode != NULL) {
                cout << curNode->data << " ";
                curNode = curNode->next;
            }
            cout << "\n";
        }
    }
    void Append(int x) {
        node* newNode = new node(x);
        if(listSize==0) {
            head = tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
        listSize++;

        Print();
    }

    void Delete(int idx) {
        if(empty() || idx >= listSize) {
            cout << -1 << "\n";
            return;
        }
        else{
            node* curNode = head;
            node* preNode = head;

            for(int i = 0; i < idx; i++) {
                preNode = curNode;
                curNode = curNode->next;
            }
            if(curNode == head) {
                head = head->next;
                cout << curNode->data << "\n";
                delete curNode;
                listSize--;
                return;
            }
            if(curNode == tail) {
                tail = preNode;
            }
            preNode->next = curNode->next;
            cout << curNode->data << "\n";
            delete curNode;
            listSize--;
        }
    }

    void Update(int idx, int x) {
        if(idx >= listSize) {
            cout << -1 << "\n";
            return;
        }
        else{
            node* curNode = head;
            for(int i = 0; i < idx; i++) {
                curNode = curNode->next;
            }
            curNode->data = x;
        }
    }

    void MinMax_Sum() {
        if(empty()) {
            cout << 0 << "\n";
            return;
        }
        else{
            node* curNode = head;
            int max = curNode->data; int min = curNode->data;
            while(curNode != NULL) {
                if(curNode->data > max) {
                    max  = curNode->data;
                }
                if(curNode->data < min) {
                    min = curNode->data;
                }
                curNode = curNode->next;
            }
            cout << max + min << "\n";
        }
    }
};

int main() {
    int M,idx,x; string s;
    singlyList list;
    cin >> M;
    while(M--) {
        cin >> s;
        if(s=="Print") {
            list.Print();
        }
        else if(s=="Append") {
            cin >> x;
            list.Append(x);
        }
        else if(s=="Delete") {
            cin >> idx;
            list.Delete(idx);
        }
        else if(s=="Update") {
            cin >> idx >> x;
            list.Update(idx,x);
        }
        else if(s=="MinMax_Sum") {
            list.MinMax_Sum();
        }
    }
}