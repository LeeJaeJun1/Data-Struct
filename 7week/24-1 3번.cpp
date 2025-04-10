#include<iostream>
using namespace std;

class node {
public:
    node* parent;
    vector<node*> childList;
    int value;
    int depth;

    node(node* parent, int value, int depth) {
        this->parent = parent;
        this->value = value;
        this->depth = depth;
    }
};

class Tree {
public:
    node* root;
    vector<node*> nodeList;

    Tree() {
        root = new node(nullptr, 1, 0);
        nodeList.push_back(root);
    }

    node* find(int x) {
        for(auto n : nodeList) {
            if(n->value == x) {
                return n;
            }
        }
        return nullptr;
    }

    void insert(int par, int chi) {
        node* p = find(par);
        if(p == nullptr || find(chi) != nullptr) {
            cout << "-1\n";
            return;
        }
        node* newNode = new node(p, chi, p->depth+1);
        p->childList.push_back(newNode);
        nodeList.push_back(newNode);
    }

    void postOrder(node* n) {
        if(n->childList.empty()) {
            cout << n->depth << " ";
            return;
        }
        int curMin = n->childList[0]->value;

        for(auto a : n->childList) {
            postOrder(a);
            curMin = min(curMin, a->value);
        }

        cout << curMin << " ";
    }
};

int main() {
    int test, nodes;
    cin >> test;

    while (test--) {
        cin >> nodes;

        Tree t = Tree();

        while (--nodes) {
            int par, chi;
            cin >> par >> chi;

            t.insert(par, chi);
        }

        t.postOrder(t.root);
        cout << '\n';
    }
}