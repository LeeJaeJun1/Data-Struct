#include<iostream>
#include<vector>
using namespace std;

class node{
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

    void insert(int x, int y) {
        node* par = find(x);
        if(par == nullptr || find(y) != nullptr) {
            cout << -1 << "\n";
            return;
        }
        node* newNode = new node(par, y, par->depth+1);
        par->childList.push_back(newNode);
        nodeList.push_back(newNode);
    }

    void Delete(int x) {
        node* delNode = find(x);
        if(delNode == nullptr) {
            cout << -1 << "\n";
            return;
        }
        for(auto n : delNode->childList) {
            n->parent = delNode->parent;
            delNode->parent->childList.push_back(n);
        }

        for(int i = 0; i < delNode->parent->childList.size(); i++) {
            if(delNode->parent->childList[i] == delNode) {
                delNode->parent->childList.erase(delNode->parent->childList.begin() + i);
                break;
            }
        }

        for(int i = 0; i < nodeList.size(); i++) {
            if(nodeList[i]->value == x) {
                nodeList.erase(nodeList.begin() + i);
                break;
            }
        }
    }

    void parent(int x) {
        node* cur = find(x);
        if(cur == nullptr) {
            cout << -1 << "\n";
            return;
        }
        cout << cur->parent->value << "\n";
    }

    void child(int x) {
        node* ch = find(x);
        if(ch == nullptr || ch->childList.size() == 0) {
            cout << -1 << "\n";
            return;
        }
        for(auto n : ch->childList) {
            cout << n->value << " ";
        }
        cout << "\n";
    }

    void min_maxChild(int x) {
        node* cur = find(x);
        if(cur == nullptr || cur->childList.size() == 0) {
            cout << -1 << "\n";
            return;
        }
        else if(cur->childList.size()==1) {
            cout << cur->childList[0]->value << "\n";
        }
        else {
            int min = 10001;
            int max = 0;
            for (auto n: cur->childList) {
                if (n->value > max) {
                    max = n->value;
                }
                if (n->value < min) {
                    min = n->value;
                }
            }
            cout << max + min << "\n";
        }
    }
};

int main() {
    int n,m;
    Tree tr;

    cin >> n >> m;
    while(n--) {
        int par,chi;
        cin >> par >> chi;
        tr.insert(par,chi);
    }
    while(m--) {
        int left, right;
        cin >> left >> right;

        node* leftNode = tr.find(left);
        node* rightNode = tr.find(right);

        if(leftNode == nullptr || rightNode == nullptr) {
            cout << "error\n";
        }
        else {
            if(leftNode->value - rightNode->value < 0) {
                cout << leftNode->depth << " " << rightNode->depth << " " << -(leftNode->depth - rightNode->depth) << "\n";
            }
            else {
                cout << leftNode->depth << " " << rightNode->depth << " " << (leftNode->depth - rightNode->depth) << "\n";
            }
        }
    }
}