#include<iostream>
#include<string>
using namespace std;

class node{
    node* next; // 다음 노드 가리키는 링크 필드
    node* prev; // 이전 노드 가리키는 링크 필드
    int data;
    node(int d) {
        this->data = d;
        next=prev=NULL;
    }
    friend class linkedList;
};

class linkedList {
private:
    node* header; // 헤더 노드 참조
    node* trailer; // 꼬리 노드 참조
    int n; // 원소의 개수 저장
public:
    linkedList() {
        header = new node(0);
        trailer = new node(0);
        n = 0;
        header->next = trailer;
        trailer->prev = header;
        header->prev = trailer->next = NULL;
    }
    bool empty() {
        return(n==0);
    }

    void insert(int i, int x) {
        if(i < 0 || i > n) {
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
        n++;
    }
    void erase(int i) {
        if(i < 0 || i >= n) {
            cout << "out_of_range" << endl;
            return;
        }
        node* curNode = header->next;
        for(int j = 0; j < i; j++) {
            curNode = curNode->next;
        }
        curNode->next->prev = curNode->prev;
        curNode->prev->next = curNode->next;
        delete curNode;
        n--;
    }
    void find(int x) {
        node* curNode = trailer->prev;
        for(int i = 0; i < n; i++){
            if(curNode->data == x) {
                cout << i << endl;
                return;
            }
            curNode = curNode->prev;
        }
        cout << "not_found" << endl;
    }

    void print(int m) {
        if(empty()) {
            cout << "empty" << endl;
            return;
        }

        if(m == 0) {
            node* curNode = header->next;
            for(int i = 0; i < n; i++) {
                cout << curNode->data << " ";
                curNode = curNode->next;
            }
            cout << endl;
        }
        else if(m==1){
            node* curNode = trailer->prev;
            for(int i = 0; i < n; i++) {
                cout << curNode->data << " ";
                curNode = curNode->prev;
            }
            cout << endl;
        }
    }
};

int main() {
    int n; string s;
    cin >> n;
    linkedList l1;
    while(n--) {
        cin >> s;
        if(s=="empty") {
            if(l1.empty()) {
                cout << "true" << endl;
            }
            else {
                cout << "false" << endl;
            }
        }
        else if(s=="insert") {
            int idx, x;
            cin >> idx >> x;
            l1.insert(idx, x);
        }
        else if(s=="erase") {
            int e;
            cin >> e;
            l1.erase(e);
        }
        else if(s=="find") {
            int f;
            cin >> f;
            l1.find(f);
        }
        else if(s=="print") {
            int m;
            cin >> m;
            l1.print(m);
        }
    }
}