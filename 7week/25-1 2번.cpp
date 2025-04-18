#include<iostream>
#include<list>
#include<vector>
using namespace std;

bool ch = false;
int sum = 0;

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
    Node *root_node;
    list<Node *> nodelist;

public:
    enum class Side {
        LEFT, RIGHT
    };

    BinaryTree() : root_node(nullptr) {};

    int size() {
        return static_cast<int>(nodelist.size());
    }

    bool empty() {
        return size() == 0;
    }

    Node *root() {
        return root_node;
    }

    Node *find(int value) {
        if (empty()) {
            return nullptr;
        }
        for (auto node: nodelist) {
            if (node->data == value) {
                return node;
            }
        }
        return nullptr;
    }


    void insert(Node *pos, int value, string s) {
        if (empty()) {
            Node *newNode = new Node(1, nullptr);
            root_node = newNode;
            nodelist.push_back(newNode);
            newNode->pos = nodelist.begin();
            return;
        }
        if (pos == nullptr) {
            cout << "-1\n";
            return;
        }
        if (s == "left" && pos->left != nullptr) {
            cout << "-1\n";
            return;
        }
        if (s == "right" && pos->right != nullptr) {
            cout << "-1\n";
            return;
        }

        Node *newNode = new Node(value, pos);
        if (s == "left") {
            pos->left = newNode;
        } else {
            pos->right = newNode;
        }
        nodelist.push_back(newNode); // 제일 마지막 원소
        newNode->pos = --nodelist.end(); // end()는 마지막의 다음 가리킴. end() 바로 전에 넣음
    }


    void erase(Node *pos) {
        if (pos == root()) {
            for (Node *i: nodelist) {
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
        } else {
            pos->parent->right = nullptr;
        }
        nodelist.erase(pos->pos);
        delete pos;

        // 삭제 시킨 다음에 nullptr로 초기화
    }


    void Order(Node* p, int x) {
        if(p==nullptr) {
            return;
        }

        if(p->left != nullptr) {
            Order(p->left,x);
        }

        if(ch) { // ch가 true로 바뀌면 멈춤
            return;
        }

        sum += p->data;

        if(sum > x) {
            cout << p->data << "\n";
            ch = true;
            return;
        }

        if(p->right != nullptr) {
            Order(p->right, x);
        }
    }

    void Order_sum(Node* p, int x) {
        ch = false;
        Order(p,x);
        if(!ch) {
            cout << "-1" << "\n";
        }
    }

    void LCA(int x, int y) {
        Node* A = find(x);
        Node* B = find(y);
        Node* finding = nullptr;

        // 해당 노드 a,b의 조상을 찾기 위해 벡터를 추가한다.
        vector<Node*> aAncestor,bAncestor;

        while(A != nullptr) {
            aAncestor.push_back(A);
            A = A->parent;
        }

        while(B!=nullptr) {
            bAncestor.push_back(B);
            B = B->parent;
        }

        for(int i = aAncestor.size()-1; i >= 0; i--) {
            for(int k = bAncestor.size()-1; k >= 0; k--) {
                if(aAncestor[i] == bAncestor[k]) {
                    finding = aAncestor[i];
                    break;
                }
            }
        }

        cout << finding->data << "\n";
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

        if(comm=="Order_sum") {
            int x;
            cin >> x;
            tree.Order_sum(tree.root(), x);
            sum = 0;
        }

        if(comm=="LCA") {
            int x,y;
            cin >> x >> y;
            tree.LCA(x,y);
        }
    }
}