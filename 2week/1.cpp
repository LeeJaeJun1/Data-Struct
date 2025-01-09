#include<iostream>
#include<string>
using namespace std;
class Node{
private:
    int data;
    Node* next;

private:
    Node() {
        this->data = 0;
        this->next = 0;
    }
    friend class LinkedList;
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

    bool empty() const {
        if(listSize == 0) {
            return true;
        }
        else{
            return false;
        }
    }

    void Print() {
        if(empty()) {
            cout << "empty";
        }
        Node* curNode = head;
        while(curNode != NULL) {
            cout << curNode->data << " ";
            curNode = curNode->next;
        }
        cout << "\n";
        return;
    }

    void Append(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;
        if(empty()) {
            head = tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
        listSize++;
        Print();
        return;
    }

    void Delete(int i) {
        if(empty() || i < 0 || i >= listSize) {
            cout << "-1" << endl;
            return;
        }
        Node* curNode = head; // 삭제할 노드
        if(i==0) {
            if(listSize == 1) {
                head = tail = nullptr;
            }
            else{
                head = head->next;
            }
            cout << curNode->data << endl;
        }
        else{
            Node* preNode = head; // 현재 노드의 이전 노드 추적
            for(int k = 0; k < i; k++) {
                preNode = curNode;
                curNode = curNode->next;
            }
            preNode->next = curNode->next;
            if(curNode== tail) {
                tail = preNode;
            }
            cout << curNode->data << endl;
            delete curNode;
        }
        listSize--;
    }

    void AfterMax(int i) {
        if(empty() || i>=listSize) {
            cout << "error" << endl;
            return;
        }
        Node* curNode = head;
        for(int k = 0; k < i; k++) {
            curNode = curNode->next;
        }
        int maxVal = curNode->data;
        curNode = curNode->next;
        while(curNode != NULL) {
            if(curNode->data > maxVal) {
                maxVal = curNode->data;
            }
            curNode = curNode->next;
        }
        cout << maxVal << endl;
    }

    void Sum() {
        int total = 0;
        Node* curNode = head;
        while(curNode!= NULL) {
            total += curNode->data;
            curNode = curNode->next;
        }
        cout << total << "\n";
    }
};

int main() {
    int M; string command;
    cin >> M;
    LinkedList list;
    int data, j;

    for(int i = 0; i < M; i++) {
        cin >> command;
        if(command == "Print") {
            list.Print();
        }
        else if(command == "Append") {
            cin >> data;
            list.Append(data);
        }
        else if(command == "Delete") {
            cin >> j;
            list.Delete(j);
        }
        else if(command == "AfterMax") {
            cin >> j;
            list.AfterMax(j);
        }
        else{
            list.Sum();
        }
    }
    return 0;

}