#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
    int data;
    int depth;
    Node* parent;
    vector<Node*> childList;
    Node(Node* p, int da, int dep) {
        this->parent = p;
        this->data = da;
        this->depth = dep;
    }
};

class Tree{
public:
    Node* root;
    vector<Node*> nodeList;
    Tree() {
        root = new Node(nullptr, 1, 0);
        nodeList.push_back(root);
    }
    Node* findNode(int x) {
        for(int i = 0; i < nodeList.size(); i++) {
            if(nodeList[i]->data == x) {
                return nodeList[i];
            }
        }
        return nullptr;
    }
    void insert(int x, int y) {
        Node* parNode = findNode(x);
        Node* chiNode = findNode(y);
        if(parNode == nullptr || chiNode != nullptr) {
            cout << "-1" << endl;
            return;
        }
        Node* newNode = new Node(parNode, y, parNode->depth+1);
        parNode->childList.push_back(newNode);
        nodeList.push_back(newNode);
    }
    void depMinus(int v, int w) {
        if(findNode(v) == nullptr || findNode(w) == nullptr) {
            cout << "-1" << endl;
            return;
        }
        int a = findNode(v)->depth;
        int b = findNode(w)->depth;
        cout << a << " " << b << " " << abs(a-b) << endl;
    }
};

int main() {
    int N, M;
    Tree t = Tree();
    cin >> N >> M;
    while(N--) {
        int x, y;
        cin >> x >> y;
        t.insert(x,y);
    }
    while(M--) {
        int v,w;
        cin >> v >> w;
        t.depMinus(v,w);
    }
}