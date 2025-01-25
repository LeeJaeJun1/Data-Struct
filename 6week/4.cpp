#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct node{
    int data;
    int depth;
    node* parent;
    vector<node*> childList;
    node(int data, int depth) {
        this->data = data;
        this->depth = depth;
        this->parent = NULL;
    }
    node(int data, node* parent) {
        this->data=data;
        this->parent = parent;
        this->depth = parent->depth+1;
    }
};

class Tree{
private:
    node* root;
    vector<node*> nodeList;
    node* find(int value) {
        for(auto i : nodeList) {
            if(i->data == value) {
                return i;
            }
        }
        return NULL;
    }
public:
    Tree() {
        root = new node(1,0);
        nodeList.push_back(root);
    }
    void insert(int par, int data) {
        node* parNode = find(par);
        node* newNode = find(data);
        if(parNode==NULL || newNode != NULL) {
            cout << -1 << endl;
            return;
        }
        newNode = new node(data, parNode);
        parNode->childList.push_back(newNode);
        nodeList.push_back(newNode);
    }
    void Delete(int data) {
        node* delNode = find(data);
        if(delNode == nullptr) {
            cout << -1 << endl;
            return;
        }
        vector<node*> child = delNode->parent->childList;
        for(auto i : delNode->childList) {
            child.push_back(i);
            i->parent = delNode->parent;
        }
        for(int i = 0; i < child.size(); i++) {
            if(child[i] == delNode) {
                child.erase(child.begin() + i);
                break;
            }
        }
        for(int i = 0; i < nodeList.size(); i++) {
            if(nodeList[i] == delNode) {
                nodeList.erase(nodeList.begin()+i);
                break;
            }
        }
    }
    void parent(int data) {
        node* Node = find(data);
        if(Node == nullptr) {
            cout << -1 << endl;
            return;
        }
        cout << Node->parent->data << endl;
    }
    void child(int data) {
        node* Node = find(data);
        if(Node == nullptr || Node->childList.empty()) {
            cout << -1 << endl;
            return;
        }
        for(auto i : Node->childList) {
            cout << i->data << " ";
        }
        cout << endl;
    }
    void Depth(int a, int b) {
        node* A = find(a);
        node* B = find(b);
        if(A==nullptr || B==nullptr) {
            cout << "error" << endl;
            return;
        }
        int total = A->depth + B->depth;
        cout << A->depth << " " << B->depth << " " << total << endl;
    }
};

int main() {
    int n,m,par,child;
    cin >> n >> m;
    Tree tree;
    while(n--) {
        cin >> par >> child;
        tree.insert(par,child);
    }
    while(m--) {
        cin >> par >> child;
        tree.Depth(par,child);
    }
}