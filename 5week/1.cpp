#include<iostream>
using namespace std;

struct node{
    int data;
    node* prev; // 이전 노드
    node* next; // 다음 노드
};

class nodeList{
public:
    nodeList();
    node* begin();
    bool empty();
    node* end();
    void insert(node* pos, int data);
    void erase(node* pos);
    void findmultiple(int data);
private:
    node* header;
    node* trailer;
    int n;
};

nodeList::nodeList() {
    header = new node();
    trailer = new node();
    header->next = trailer;
    trailer->prev = header;
    header->prev = trailer->next = NULL;
    n = 0;
}

node *nodeList::begin() {
    return header->next;
}

bool nodeList::empty() {
    return n == 0;
}

node* nodeList::end() {
    return trailer;
}

void nodeList::insert(node *pos, int data) {
    node* newNode = new node();
    newNode->data = data;
    newNode->prev = pos->prev;
    newNode->next = pos;
    pos->prev->next = newNode;
    pos->prev = newNode;
    n++;
}

void nodeList::erase(node *pos) {
    if(empty() || pos == NULL) {
        cout << "empty" << endl;
        return;
    }
    if(pos == trailer) {
        return;
    }
    pos->prev->next = pos->next;
    pos->next->prev = pos->prev;
    delete pos;
    n--;
}

void nodeList::findmultiple(int data) {
    int index = 0;
    node* current = header->next;
    bool found = false;
    while(current != trailer) {
        if(current->data % data == 0) {
            cout << index << " ";
            found = true;
        }
        current = current->next;
        index++;
    }
    if(!found)
        cout << -1;
    cout << endl;
}
int main() {
    int N,e;
    nodeList list;
    node* p = list.begin();
    string s;
    cin >> N;
    while(N--) {
        cin >> s;
        if(s == "begin") {
            list.begin();
        }
        else if(s== "end") {
            list.end();
        }
        else if(s=="insert") {
            cin >> e;
            list.insert(p, e);
        }
        else if(s=="erase") {
            list.erase(p);
            p = list.begin();
        }
        else if(s== "nextP") {
            if(p!=list.end()) {
                p = p->next;
            }
        }
        else if(s == "prevP") {
            if(p!= list.begin()) {
                p = p->prev;
            }
        }
        else if(s=="findmultiple") {
            cin >> e;
            list.findmultiple(e);
        }
    }
}