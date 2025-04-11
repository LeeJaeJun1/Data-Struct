#include<iostream>
#include<list>
using namespace std;

class node {
public:
    int data;
    node* parent;
    list<node*> childList;

    node(node* parent, int data) {
        this->parent = parent;
        this->data = data;
    }
};

class Tree {
public:
    node* root;
    list<node*> nodeList;

    Tree() {
        root = new node(nullptr, 1);
        nodeList.push_back(root);
    }

    node* find(int x) {
        for(auto n : nodeList) {
            if(n->data == x) {
                return n;
            }
        }
        return nullptr;
    }

    void insert(int par, int chi) {
        node* p = find(par);
        if(p==nullptr || find(chi )!= nullptr) {
            cout << "-1\n";
            return;
        }
        node* newNode = new node(p,chi);
        p->childList.push_back(newNode);
        nodeList.push_back(newNode);
    }

    void erase(int x) {
        node* del = find(x);
        if(del==nullptr || del == root) {
            cout << "-1\n";
            return;
        }
        for(auto n : del->childList) {
            n->parent = del->parent;
            del->parent->childList.push_back(n);
        }
        for(auto it = del->parent->childList.begin(); it != del->parent->childList.end(); it++) {
            if(*it == del) {
                del->parent->childList.erase(it);
                break;
            }
        }
        for(auto it = nodeList.begin(); it!= nodeList.end(); it++) {
            if(*it == del) {
                nodeList.erase(it);
                break;
            }
        }
        delete del;
    }
    void parent(int x) {
        node* p = find(x);
        if(p==nullptr) {
            cout << "-1\n";
            return;
        }
        if(p==root) {
            cout << "0\n";
            return;
        }
        cout << p->parent->data << "\n";
    }

    void child(int x) {
        node* p = find(x);
        if(p==nullptr) {
            cout << "-1\n";
            return;
        }
        if(p->childList.empty()) {
            cout << "0\n";
            return;
        }
        for(auto n : p->childList) {
            cout << n->data << " ";
        }
        cout << "\n";
    }

    void Ancestor(int v)  {
        node* p = find(v);
        if(p==root) {
            cout << "0\n";
            return;
        }
        if(p==nullptr) {
            cout << "-1\n";
            return;
        }
        while(p!=root) {
            p = p->parent;
            cout << p->data << " ";
        }
        cout << "\n";
    }
};

int main() {
    int test,x,y; string comm;
    cin >> test;
    Tree t;
    while(test--) {
        cin >> comm;
        if(comm=="Insert") {
            cin >> x >> y;
            t.insert(x,y);
        }
        if(comm=="Delete") {
            cin >> x;
            t.erase(x);
        }
        if(comm=="Parent") {
            cin >> x;
            t.parent(x);
        }
        if(comm=="Children") {
            cin >> x;
            t.child(x);
        }
        if(comm=="Ancestor") {
            cin >> x;
            t.Ancestor(x);
        }
    }
}