#include<iostream>
using namespace std;

// 자연수 저장하는 단일 연결 리스트 2개 생성
// L1, L2를 만들고 병합해서 L3를 만들고 특정 값 e를 찾은 다음, 그 노드 앞에 v를 포함하는 노드 추가하고 출력

struct Node{
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;
    Node* tail;
    int listSize;
public:
    LinkedList() {
        head = NULL;
        tail = NULL;
        listSize = 0;
    }

    Node* hd() {
        return head;
    }

    Node* tl() {
        return tail;
    }

    void apd(Node* n) {
        tail->next = n;
    }

    int rsize() {
        return listSize;
    }

    void changesize(int k) {
        listSize+= k;
    }

    void Print() {
        Node* curNode = head;
        while(curNode != NULL) {
            cout << curNode->data << " ";
            curNode = curNode->next;
        }
        cout << endl;
    }

    bool empty() {
        if(listSize == 0) {
            return true;
        }
        else {
            return false;
        }
    }

    void Append(int data) {
        Node* newNode = new Node;
        newNode-> data = data;
        newNode->next = NULL;
        if(empty()) {
            head = tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
        listSize++;
        return;
    }

    void add(int e, int v) {
        Node* newNode = new Node;
        newNode->data = v;
        Node* curNode = head;
        if(e == curNode->data) { // e값이 헤드일 때
            newNode->next = head;
            head = newNode;
        }
        else {
            Node *preNode = head;
            for (int i = 0; i < listSize; i++) {
                if (e == curNode->data) {
                    preNode->next = newNode;
                    newNode->next = curNode;
                }
                preNode = curNode;
                curNode = curNode->next;
            }
        }
        listSize++;
        Print();
        return;
    }
};

int main() {
    int m = 0;
    int x,e,v,n;
    int M; cin >> M;
    while(M--) {
        LinkedList list1; LinkedList list2;

        cin >> n;
        while(n--) {
            cin >> x;
            list1.Append(x);
        }

        cin >> n;
        while(n--) {
            cin >> x;
            list2.Append(x);
        }

        Node* curNode = list2.hd();
        list1.apd(curNode);
        list1.changesize(list2.rsize());
        list1.Print();

        cin >> e >> v;
        list1.add(e,v);
    }
    return 0;
}