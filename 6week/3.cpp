#include<iostream>
#include<vector>
using namespace std;

class node {
public:
    node* parent;
    vector<node*> childList;
    int data;
    int depth;
    node(node* parent, int data, int depth) {
        this->parent = parent;
        this->data = data;
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
            if(n->data == x) {
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
        node* newNode = new node(p, chi, p->depth + 1);
        p->childList.push_back(newNode);
        nodeList.push_back(newNode);
    }

    void remove(int x) {
        node* del = find(x);
        if(del == nullptr) {
            cout << "-1\n";
            return;
        }

        for(auto n : del->childList) {
            n->parent = del->parent;
            del->parent->childList.push_back(n);
        }

        for(int i = 0; i < del->parent->childList.size(); i++) {
            if(del->parent->childList[i] == del) {
                del->parent->childList.erase(del->parent->childList.begin() + i);
                break;
            }
        }
        for(int j = 0; j < nodeList.size(); j++) {
            if(nodeList[j]->data == x) {
                nodeList.erase(nodeList.begin() + j);
                break;
            }
        }
    }

    void parent(int x) {
        node* p = find(x);
        if(p==nullptr) {
            cout << "-1\n";
            return;
        }
        cout << p->parent->data << "\n";
    }

    void child(int x) {
        node* p = find(x);
        if(p==nullptr || p->childList.size() == 0) {
            cout << "-1\n";
            return;
        }
        for(auto n : p->childList) {
            cout << n->data << " ";
        }
        cout << "\n";
    }

    void min_maxChild(int x) {
        node* cur = find(x);
        if(cur==nullptr || cur->childList.size() == 0) {
            cout << "-1\n";
            return;
        }
        else if(cur->childList.size()==1) {
            cout << cur->childList[0]->data << "\n";
        }
        else {
            int min = 10001; int max = 0;
            for(auto n : cur->childList) {
                if(n->data > max) {
                    max = n->data;
                }
                if(n->data < min) {
                    min = n->data;
                }
            }
            cout << max - min << "\n";
        }
    }
};

int main() {
    int t,x,y; string comm;
    cin >> t;
    Tree tr;
    while(t--) {
        cin >> comm;
        if(comm=="insert") {
            cin >> x >> y;
            tr.insert(x,y);
        }
        else if(comm=="delete") {
            cin >> x;
            tr.remove(x);
        }
        else if(comm=="parent") {
            cin >> x;
            tr.parent(x);
        }
        else if(comm=="child") {
            cin >> x;
            tr.child(x);
        }
        else if(comm=="min_maxChild") {
            cin >> x;
            tr.min_maxChild(x);
        }
    }
}