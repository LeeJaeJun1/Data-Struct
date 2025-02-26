#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct node {
    int data;
    int depth;
    node* parent;
    vector<node*> childList;
    node(int data, node* parent) {
        this-> data = data;
        this->parent = parent;
        this->depth = parent->depth + 1;
    }
    node(int data, int depth) {
        this-> data = data;
        this-> parent = NULL;
        this->depth = depth;
    }
};

class Tree{
private:
    node* root;
    vector<node*> nodeList;
    int find(int data, vector<node*>& list) {
        for(int i = 0; i < list.size(); i++) {
            if(list[i]->data == data) {
                return i;
            }
        }
        return -1;
    }
public:
    Tree() {
        root = new node(1,0);
        nodeList.push_back(root);
    }
    // 노드 y를 노드 x의 자식으로 x -> y
    void insertNode(int x, int y) {
        int paridx = find(x, nodeList);
        if(paridx == -1 || find(y,nodeList) != -1) {
            cout << -1 << endl;
            return;
        }
        node* par = nodeList[paridx];
        node* newNode = new node(y, par);
        par->childList.push_back(newNode);
        nodeList.push_back(newNode);
    }

    void deleteNode(int x) {
        int idx = find(x, nodeList);
        if(idx == -1) {
            cout << -1 << endl;
            return;
        }
        node* del = nodeList[idx];
        vector<node*>& par_child = del->parent->childList;
        for(auto i : del->childList) {
            par_child.push_back(i);
            i->parent = del->parent;
        }
        for(int i = 0; i < par_child.size(); i++) {
            if(del == par_child[i]) {
                par_child.erase(par_child.begin() + i);
                break;
            }
        }
        for(int j = 0; j < nodeList.size(); j++) {
            if(del == nodeList[j]) {
                nodeList.erase(nodeList.begin() + j);
                break;
            }
        }
        delete del;
    }

    void Parent(int x) {
        int idx = find(x, nodeList);
        if(idx <= 0) {
            cout << -1 << endl;
            return;
        }
        node* printNode = nodeList[idx];
        cout << printNode->parent->data << endl;
    }

    void Child(int x) {
        int idx = find(x, nodeList);
        if(idx == -1 || nodeList[idx]->childList.empty()) {
            cout << -1 << endl;
            return;
        }
        node* printNode = nodeList[idx];
        for(auto i : printNode->childList) {
            cout << i->data << " ";
        }
        cout << endl;
    }

    void diff(int x, int y) {
        int idx = find(x, nodeList);
        int idy = find(y,nodeList);
        if(idx == -1 || idy ==- 1) {
            cout << "error" << endl;
            return;
        }
        node* nx = nodeList[idx]; node* ny = nodeList[idy];
        int result = nx->depth + ny->depth;
        cout << nx->depth << " " << ny->depth << " " << result << endl;
    }

};

int main() {
    int N, M, x, y;
    Tree tree;
    cin >> N >> M;
    while(N--) {
        cin >> x >> y;
        tree.insertNode(x,y);
    }
    while(M--) {
        cin >> x >> y;
        tree.diff(x,y);
    }
}