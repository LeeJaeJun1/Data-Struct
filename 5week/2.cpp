#include<iostream>
#include<string>
using namespace std;

class node{
    node* prev;
    node* next;
    string data;
    node(string d) {
        this->data = d;
        prev=next=NULL;
    }
    friend class linkedList;
};

class linkedList {
private:
    node* header;
    node* trailer;
    int size;
    node* position;
public:
    linkedList() {
        header = new node(" ");
        trailer = new node(" ");
        size = 0;
        header->next = trailer;
        trailer->prev = header;
        header->prev = trailer->next = NULL;
        position = header->next;
    }
    bool emtpy() {
        return (size==0);
    }
    void up(int x) {
        if(emtpy()) {
            return;
        }
        for(int i = 0; i < x; i++) {
            if(position == header->next) {
                break;
            }
            position = position->prev;
        }
    }
    void down(int x) {
        if(emtpy()) {
            return;
        }
        for(int i = 0; i < x; i++) {
            if(position == trailer->prev) {
                break;
            }
            position = position->next;
        }
    }
    void cut() {
        if(emtpy()) {
            return;
        }
        node* del = position;
        if(position == trailer->prev) {
            position = del->prev;
        }
        else{
            position = del->next;
        }
        del->prev->next = del->next;
        del->next->prev = del->prev;
        delete del;
        size--;
    };
    void append(string name) {
        node* newNode = new node(name);
        if(emtpy()) {
            newNode->next = trailer;
            newNode->prev = header;
            header->next = newNode;
            trailer->prev = newNode;
        }
        else{
            newNode->next = position->next;
            newNode->prev = position;
            position->next->prev = newNode;
            position->next = newNode;
        }
        position = newNode;
        size++;
    }
    void print() {
        if(size<=0) {
            cout << "And Then There Were None" << endl;
        }
        else{
            node* curNode = header->next;
            for(int i = 0; i < size; i++) {
                cout << curNode->data << " ";
                curNode = curNode->next;
            }
            cout << endl;
        }
    }
    void position_location(int idx) {
        position = header->next;
        down(idx);
    }
};

int main() {
    int t,n,m,k,idx;
    string name;
    string command;
    cin >> t;
    while(t--) {
        linkedList l1;
        cin >> n >> m >> k;
        for(int i = 0; i < n; i++) {
            cin >> name;
            l1.append(name);
        }
        l1.position_location(k);
        for(int j = 0; j < m; j++) {
            cin >> command;
            if(command == "up") {
                cin >> idx;
                l1.up(idx);
            }
            else if(command == "down") {
                cin >> idx;
                l1.down(idx);
            }
            else if(command == "cut"){
                l1.cut();
            }
            else if(command == "append") {
                cin >> name;
                l1.append(name);
            }
        }
        l1.print();
    }
}