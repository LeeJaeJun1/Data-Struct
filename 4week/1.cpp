#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

class listQueue {
private:
    node* frontNode;
    node* rearNode;
    int n;
public:
    listQueue();
    bool empty();
    int size();
    void rear();
    void enqueue(int data);
    void dequeue();
    void frontNsum(int num);
};

listQueue::listQueue() {
    frontNode = NULL;
    rearNode == NULL;
    n = 0;
}

bool listQueue::empty() {
    return n == 0;
}

int listQueue::size() {
    return n;
}

void listQueue::rear() {
    if(empty()) {
        cout << "Empty" << endl;
        return;
    }
    else {
        cout << rearNode->data << endl;
    }
}

void listQueue::enqueue(int data) {
    node* newNode = new node;
    newNode->data = data;
    newNode->next = NULL;
    if(empty()) {
        frontNode = rearNode = newNode;
    }
    else{
        rearNode->next = newNode;
        rearNode = newNode;
    }
    n++;
}

void listQueue::dequeue() {
    if(empty()) {
        cout << "Empty" << endl;
        return;
    }
    node* curNode = frontNode;
    if(size()==1) {
        frontNode = rearNode = NULL;
    }
    else{
        frontNode = frontNode->next;
    }
    cout << curNode->data << endl;
    delete curNode;
    n--;
    return;
}

void listQueue::frontNsum(int num) {
    int sum = 0;
    if(empty()) {
        cout << "Empty" << endl;
    }
    else if (num < 0) {
        return;
    }
    else if(num > n) {
        cout << "error" << endl;
    }
    else{
        node* curNode = frontNode;
        for(int i = 0; i < num; i++) {
            sum += curNode->data;
            curNode = curNode->next;
        }
        cout << sum << endl;
    }
}

int main() {
    string c;
    listQueue q;
    int T, data, n; cin >> T;
    while(T--) {
        cin >> c;
        if(c=="isEmpty") {
            if(q.empty()) {
                cout << "True" << endl;
            }
            else{
                cout << "False" << endl;
            }
        }
        else if(c=="size") {
            cout << q.size() << endl;
        }
        else if(c == "dequeue") {
            q.dequeue();
        }
        else if(c=="enqueue") {
            cin >> data;
            q.enqueue(data);
        }
        else if(c == "frontNsum") {
            cin >> n;
            q.frontNsum(n);
        }
        else if(c=="rear") {
            q.rear();
        }
    }
}