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
    node* cursor;
    int listSize;
public:
    singlyList() {
        head = NULL;
        tail = NULL;
        cursor = NULL;
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
            cursor = head;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
        listSize++;
    }

    void Insert(int x) {
        node* newNode = new node(x);
        if(cursor==tail) {
            tail->next = newNode;
            tail = newNode;
        }
        else{
            newNode->next = cursor->next;
            cursor->next = newNode;

        }
        listSize++;
    }

    void Deletion() {
        if(cursor==tail) {
            return;
        }
        node* delNode = cursor;
        if(cursor==head) {
            head = head->next;
            cursor = head;
        }
        else{
            node* preNode = head;
            while(preNode->next != cursor) {
                preNode = preNode-> next;
            }
            preNode->next = delNode->next;
            if(cursor==tail) {
                tail = preNode;
            }
            cursor = cursor->next;
        }
        delete delNode;
        listSize--;
    }

    void Forward(int k) {
        if(listSize==0) {
            return;
        }
        else{
            for(int i = 0; i < k; i++) {
                if(cursor==tail) {
                    cursor = head;
                }
                else{
                    cursor = cursor->next;
                }
            }
        }
    }
};

int main() {
    int T,M,N,num,x;
    string s;
    cin >> T;
    while(T--) {
        cin >> N;
        singlyList list;
        while(N--) {
            cin >> num;
            list.Append(num);
        }
        cin >> M;
        while(M--) {
            cin >> s;
            if(s=="Insert") {
                cin >> x;
                list.Insert(x);
            }
            else if(s=="Delete") {
                list.Deletion();
            }
            else if(s=="Forward") {
                cin >> x;
                list.Forward(x);
            }
            else if(s=="Print") {
                list.Print();
            }
        }
    }
}