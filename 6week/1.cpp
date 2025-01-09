#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
    Node* parent;
    int value;
    vector<Node*>childList;

    Node(Node* parent, int value) {
        this->parent = parent;
        this->value = value;
    }
};

class Tree{
public:
    Node* root;
    vector<Node*>nodeList;

    Tree(int x) {
        root = new Node(nullptr, x);
        nodeList.push_back(root);
    }

    Node* findNode(int x) {
        for(int i = 0; i < nodeList.size(); i++) {
            if(nodeList[i]->value == x) {
                return nodeList[i];
            }
        }
        return nullptr;
    }

    void insertNode(int x, int y) {
        Node* node = findNode(x);
        bool a = false;

        if(node == nullptr) { // x가 트리에 존재하지 않을 경우
            cout << -1 << endl;
            return;
        }

        for(int i = 0; i < nodeList.size(); i++) {
            if(nodeList[i]->value == y) {
                a = true;
            }
        }

        if(a == true) { // y가 이미 트리에 존재할 때
            cout << -1 << endl;
            return;
        }

        Node* newNode = new Node(node, y);
        node->childList.push_back(newNode);
        nodeList.push_back(newNode);
    }

    void deleteNode(int x) {
        Node* node = findNode(x);
        if(node == nullptr) {
            cout << -1 << endl;
        }
        else{
            for(int i = 0; i < node->childList.size(); i++) {
                node->parent->childList.push_back(node->childList[i]);
                node->childList[i]->parent = node->parent;
            }

            for(int i = 0; i < node->parent->childList.size(); i++) {
                if(node->parent->childList[i] == node) {
                    node->parent->childList.erase(node->parent->childList.begin() + i);
                    break;
                }
            }

            for(int i = 0; i < nodeList.size(); i++) {
                if(nodeList[i] == node) {
                    nodeList.erase(nodeList.begin() + i);
                    break;
                }
            }
            delete node;
        }
    }

    void min_maxChild(int x) {
        Node* node = findNode(x);
        if(node == nullptr || node->childList.size() < 2) {
            cout << -1 << endl;
            return;
        }
        else {
            int max = node->childList[0]->value;

            for(int i = 0; i < node->childList.size(); i++) {
                if(node->childList[i]->value > max) {
                    max = node->childList[i]->value;
                }
            }

            int min = node->childList[0]->value;

            for(int i = 0; i < node->childList.size(); i++) {
                if(node->childList[i]->value < min) {
                    min = node->childList[i]->value;
                }
            }
            int total = max + min;
            cout << total << endl;
        }
    }

    void parent(int x) {
        Node* node = findNode(x);
        if(node == nullptr) {
            cout << -1 << endl;
        }
        else {
            cout << node->parent->value << endl;
        }
    }

    void child(int x) {
        Node* node = findNode(x);

        if(node == nullptr || node->childList.size() == 0) {
            cout << "-1" << endl;
            return;
        }

        for(int i = 0; i < node->childList.size(); i++) {
            cout << node->childList[i]->value << " ";
        }
        cout << endl;
    }
};

int main() {
    int T; cin >> T;
    string s;
    Tree tree(1);

    while(T--) {
        cin >> s;
        int x,y;
        if(s=="insert") {
            cin >> x >> y;
            tree.insertNode(x,y);
        }
        else if(s == "delete") {
            cin >> x;
            tree.deleteNode(x);
        }
        else if(s=="parent") {
            cin >> x;
            tree.parent(x);
        }
        else if(s=="child") {
            cin >> x;
            tree.child(x);
        }
        else if(s=="min_maxChild") {
            cin >> x;
            tree.min_maxChild(x);
        }
    }
}