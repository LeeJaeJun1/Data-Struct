#include<iostream>
#include<list>
using namespace std;

bool ans = false;

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

    int Size() {
        return static_cast<int>(nodeList.size());
    }


    void Postorder(node* p, int x) {
        int sum = 0;
        if(p==nullptr) {
            return;
        }

        for(auto n : p->childList) {
            Postorder(n,x);
        }

        for(auto a : p->childList) {
            sum += a->data;
        }

        if(sum==x && !ans) {
            cout << p->data  << "\n";
            ans = true;
        }
    }
};

int main() {
    int test, x, y;
    string comm;
    cin >> test;
    Tree t;
    while (test--) {
        cin >> comm;
        if (comm == "Insert") {
            cin >> x >> y;
            t.insert(x, y);
        }
        if(comm=="Post_order") {
            cin >> x;
            ans = false;
            t.Postorder(t.root,x);
            if(!ans) {
                cout << "-1\n";
            }
        }
    }
}