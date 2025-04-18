#include<iostream>
#include<list>
using namespace std;

struct Node {
    int data;
    Node* parent;
    Node* left;
    Node* right;
    list<Node*>::iterator pos; // 전체 노드 리스트에서 해당 노드 위치

    Node(int data, Node* parent) {
        this->data = data;
        this->parent = parent;
        this->left = nullptr; // 자식 nullptr 초기화
        this->right = nullptr;
    }
};

class BinaryTree {
private:
    Node* root_node;
    list<Node*> nodelist;

public:
    enum class Side { LEFT, RIGHT };
    BinaryTree() : root_node(nullptr) {};

    int size() {
        return static_cast<int>(nodelist.size());
    }
    bool empty() {
        return size() == 0;
    }
    Node* root() {
        return root_node;
    }
    Node* find(int value) {
        if (empty()) {
            return nullptr;
        }
        for (auto node : nodelist) {
            if (node->data == value) {
                return  node;
            }
        }
        return nullptr;
    }

    void Finding(int x) {
        for (auto node : nodelist) {
            if (node->data == x) {
                cout << "1\n";
                return;
            }
        }
        cout << -1 << "\n";
    }

    void insert(Node* pos, int value, string s) {
        if (empty()) {
            Node* newNode = new Node(1, nullptr);
            root_node = newNode;
            nodelist.push_back(newNode);
            newNode->pos = nodelist.begin();
            return;
        }
        if (pos == nullptr) {
            cout << "-1\n";
            return;
        }
        if (s=="left" && pos->left != nullptr) {
            cout << "-1\n";
            return;
        }
        if (s == "right" && pos->right != nullptr) {
            cout << "-1\n";
            return;
        }

        Node* newNode = new Node(value, pos);
        if (s == "left") {
            pos->left = newNode;
        }
        else {
            pos->right = newNode;
        }
        nodelist.push_back(newNode); // 제일 마지막 원소
        newNode->pos = --nodelist.end(); // end()는 마지막의 다음 가리킴. end() 바로 전에 넣음
    }

    void Abstract(int v) {
        Node* p = find(v);
        int parent, child;
        int sum = 0;

        if (p == root_node) {
            parent = 0;
            if (p->left != nullptr && p->right == nullptr) {
                child = p->left->data;
            }
            if (p->left == nullptr && p->right != nullptr) {
                child = p->right->data;
            }
            if(p->left != nullptr && p->right != nullptr) {
                child = p->left->data + p->right->data;
            }

            sum = child - parent;
            cout << sum << "\n";
            return;
        }

        if (p->left == nullptr && p->right == nullptr) {
            parent = p->parent->data;
            child = 0;
            sum = child - parent;
            cout << sum << "\n";
            return;
        }

        if (p->left != nullptr && p->right == nullptr) {
            parent = p->parent->data;
            child = p->left->data;
            sum = child - parent;
            cout << sum << "\n";
            return;
        }

        if (p->left == nullptr && p->right != nullptr) {
            parent = p->parent->data;
            child = p->right->data;
            sum = child - parent;
            cout << sum << "\n";
            return;
        }

        if (p->left != nullptr && p->right != nullptr) {
            parent = p->parent->data;
            child = p->left->data + p->right->data;
            sum = child - parent;
            cout << sum << "\n";
            return;
        }

    }

    void erase(Node* pos) {
        if (pos == root()) {
            for (Node* i : nodelist) {
                delete i;
            }
            nodelist.clear();
            return;
        }
        if (pos->left != nullptr) {
            erase(pos->left);
        }
        if (pos->right != nullptr) {
            erase(pos->right);
        }

        if (pos->parent->left == pos) {
            pos->parent->left = nullptr;
        }
        else {
            pos->parent->right = nullptr;
        }
        nodelist.erase(pos->pos);
        delete pos;

        // 삭제 시킨 다음에 nullptr로 초기화
    }






};

int main() {
    int test;
    cin >> test;
    string comm;
    BinaryTree tree;
    while (test--) {
        cin >> comm;
        if (comm == "Insert") {
            int parent, value; string input;
            cin >> parent >> value >> input;
            Node* par = tree.find(parent);
            tree.insert(par, value, input);
        }

        if (comm == "Erase") {
            int value;
            cin >> value;
            Node* p = tree.find(value);
            tree.erase(p);
        }

        if (comm == "Find") {
            int x; cin >> x;
            tree.Finding(x);
        }

        if (comm == "Add") {
            int v; cin >> v;
            tree.Abstract(v);
        }
    }
}