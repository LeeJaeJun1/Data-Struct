#include<iostream>
#include<vector>
#include<string>

using namespace std;

struct node{
    int data;
    int depth;
    node* parent;
    vector<node*> childList;
    node(int data, node* parent) {
        this->data = data;
        this->parent = parent;
        this->depth = parent->depth + 1;
    }
    node(int data, int depth) {
        this->data = data;
        this->parent = NULL;
        this->depth = depth;
    }
};

class Tree{
private:
    node* root;
    vector<node*> nodeList;
    node* find(int data) {
        for(auto i : nodeList) {
            if(i->data == data) {
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
        if(parNode==NULL || newNode!=NULL) {
            cout << -1 << endl;
            return;
        }
        newNode = new node(data,parNode);
        parNode->childList.push_back(newNode);
        nodeList.push_back(newNode);
    }
    void Delete(int data) {
        node* delNode = find(data);
        if(delNode == nullptr) {
            cout << -1 << endl;
            return;
        }
        vector<node*>& child = delNode->parent->childList;
        for(auto i : delNode->childList) {
            child.push_back(i);
            i->parent = delNode->parent;
        }
        for(int i = 0; i < child.size(); i++) {
            if(child[i] == delNode) {
                child.erase(child.begin()+i);
                break;
            }
        }
        for(int i = 0; i < nodeList.size(); i++) {
            if(nodeList[i] == delNode) {
                nodeList.erase(nodeList.begin() + i);
                break;
            }
        }
        delete delNode;
    }
    void parent(int data) {
        node* Node = find(data);
        if(Node == NULL) {
            cout << -1 << endl;
            return;
        }
        cout << Node->parent->data << endl;
    }
    void child(int data) {
        node* Node = find(data);
        if(Node == NULL || Node->childList.empty()) {
            cout << -1 << endl;
            return;
        }
        for(auto i : Node->childList) {
            cout << i->data << " ";
        }
        cout << endl;
    }
    void min_maxChild(int data) {
        node* Node = find(data);
        if(Node == nullptr || Node->childList.empty()) {
            cout << -1 << endl;
            return;
        }
        else if(Node->childList.size()==1) {
            cout << Node->childList[0]->data << endl;
            return;
        }
        else{
            int max = 0, min = 10000;
            for(auto i : Node->childList) {
                if(i->data > max) {
                    max = i->data;
                }
                if(i->data < min) {
                    min = i->data;
                }
            }
            cout << max - min << endl;
        }
    }
};

int main() {
    int t,x,y;
    Tree tree;
    string command;
    cin >> t;
    while(t--) {
        cin >> command;
        if(command=="insert") {
            cin >> x >> y;
            tree.insert(x,y);
        }
        else if(command=="delete") {
            cin >> x;
            tree.Delete(x);
        }
        else if(command=="parent") {
            cin >> x;
            tree.parent(x);
        }
        else if(command == "child") {
            cin >> x;
            tree.child(x);
        }
        else if(command == "min_maxChild") {
            cin >> x;
            tree.min_maxChild(x);
        }
    }
}