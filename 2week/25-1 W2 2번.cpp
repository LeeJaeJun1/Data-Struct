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

    void Insert(int x) { // 커서의 왼쪽에 삽입하는 함수
        node* newNode = new node(x);
        if(cursor==head) {
            newNode->next = head;
            head = newNode;
        }
        else{
            node* preNode = head;
            while(preNode->next != cursor) {
                preNode = preNode->next;
            }
            preNode->next = newNode;
            newNode->next = cursor;
        }
        listSize++;
    }

    void Deletion() { // 커서의 왼쪽 노드 삭제
        if(cursor==head) {
            return;
        }
        node* delNode;
        if(head->next == cursor) { //head삭제 경우
            delNode = head;
            head = cursor;
        }
        else{
            node* preNode = head;
            while(preNode->next != cursor) {
                preNode = preNode-> next;
            }
            node* pre = head;
            while(pre->next != preNode) {
                pre = pre->next;
            }
            delNode = preNode;
            pre->next = cursor;
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