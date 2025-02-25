#include<iostream>
#include<string>
#include<vector>
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
        this->depth = depth;
        this->parent = NULL;
    }
};

class Tree {
private:
    node* root;
    vector<node*> nodeList;
    int find(int data, vector<node*>& list) {
        for (int i = 0; i < list.size(); i++) {
            if (list[i]->data == data)
                return i;
        }
        return -1;
    }
public:
    Tree() {
        root = new node(1,0);
        nodeList.push_back(root);
    }

    void insertNode(int x, int y) {
        int pindex = find(x,nodeList);
        if(pindex == -1 || find(y,nodeList) != -1) {
            cout << -1 << endl;
            return;
        }
        node* parent = nodeList[pindex];
        node* newNode = new node(y, parent);
        parent->childList.push_back(newNode);
        nodeList.push_back(newNode);
    }

    void deleteNode(int x) {
        int index = find(x,nodeList);
        if(index == -1) {
            cout << -1 << endl;
            return;
        }
        node* del = nodeList[index];
        vector<node*>& par_child = del->parent->childList;
        for(auto i : del->childList) {
            par_child.push_back(i);
            i->parent = del->parent;
        }
        for(int i = 0; i < par_child.size(); i++) {
            if(par_child[i] == del) {
                par_child.erase(par_child.begin()+i);
                break;
            }
        }
        for(int i = 0; i < nodeList.size(); i++) {
            if(nodeList[i] == del) {
                nodeList.erase(nodeList.begin() + i);
                break;
            }
        }
        delete del;
    }
    void Parent(int x) {
        int index = find(x,nodeList);
        if(index <= 0) {
            cout << -1 << endl;
            return;
        }
        node* childNode = nodeList[index];
        cout << childNode->parent->data << endl;
    }
    void Child(int x) {
        int index = find(x, nodeList);
        if(index == -1 || nodeList[index]->childList.empty()) {
            cout << -1 << endl;
            return;
        }
        node* printNode = nodeList[index];
        for(auto i : printNode->childList) {
            cout << i->data << " ";
        }
        cout << endl;
    }
    void min_maxChild(int x) {
        int index = find(x,nodeList);
        if(index == -1 || nodeList[index]->childList.empty()) {
            cout << -1 << endl;
            return;
        }
        node* parentNode = nodeList[index];
        if(parentNode->childList.size() == 1) {
            cout << parentNode->childList[0]->data << endl;
        }
        else{
            int max = 1; int min = 10000;
            for(auto i : parentNode->childList) {
                if(i->data > max) {
                    max = i->data;
                }
                if(i->data < min) {
                    min = i->data;
                }
            }
            cout << max + min << endl;
        }
    }
};

int main() {
    int t,x,y;
    string s;
    Tree tree;
    cin >> t;
    while(t--) {
        cin >> s;
        if(s=="insert") {
            cin >> x >> y;
            tree.insertNode(x,y);
        }
        else if(s=="delete") {
            cin >> x;
            tree.deleteNode(x);
        }
        else if(s=="parent") {
            cin >> x;
            tree.Parent(x);
        }
        else if(s=="child") {
            cin >> x;
            tree.Child(x);
        }
        else if(s=="min_maxChild") {
            cin >> x;
            tree.min_maxChild(x);
        }
    }
}