#include<iostream>
#include<string>
using namespace std;

int Itotal = 0;
int Stotal = 1;

class Node {
public:
    int key;
    string value;
    Node* parent;
    Node* left;
    Node* right;

    explicit Node(int key, string& value, Node* parent)
            : key(key), value(value), parent(parent), left(nullptr),right(nullptr) {}

    friend class BSTMap;
};

class BSTMap {
public:
    Node* find_entry(int key) {
        Node* cur_Node = root;

        while(cur_Node != nullptr) {
            if(key == cur_Node->key) {
                return cur_Node;
            }
            if(key < cur_Node->key) {
                Stotal++;
                cur_Node = cur_Node->left;
            }
            else {
                Stotal++;
                cur_Node = cur_Node->right;
            }
        }
        return nullptr;
    }

    Node* get_successor(Node* node) {
        if(node->right) {
            Node* curr = node->right;
            while(curr->left) {
                curr = curr->left;
            }
            return curr;
        }
        Node* curr = node;
        Node* parent = node->parent;
        while(parent && curr == parent->right) {
            curr = parent;
            parent = parent->parent;
        }
        return parent;
    }

    bool erase(Node* node) {
        if(node == nullptr) { // 삭제할 노드 존재하는지
            return false;
        }

        if(node->left != nullptr && node->right != nullptr) { // 삭제할 노드에 두 자식이 모두 존재
            Node* successor = get_successor(node); // 후행자의 key, value값을 삭제할 노드에 복사시킨다.
            node->key = successor->key;
            node->value = successor->value;
            node = successor; // 삭제할 노드를 후행자로 변경
        }

        Node* child_node; // 삭제할 노드의 자식 1개 혹은 0개
        if(node->left != nullptr) {
            child_node = node->left;
        }
        else {
            child_node = node->right;
        }

        if(node==root) {
            root = child_node; // 자식 노드 루트로 변경
            if (child_node != nullptr) {
                child_node->parent = nullptr; // 부모 포인터 초기화
            }
        }
        else {
            Node* parent_node = node->parent;
            if(child_node != nullptr) { // 부모 연결 갱신
                child_node->parent = parent_node;
            }
            if(node==parent_node->left) { // 자식 연결 갱신
                parent_node->left = child_node;
            }
            else {
                parent_node->right = child_node;
            }
        }

        delete node;
        --N;
        return true;
    }

    void clear(Node* node) {
        if(node->left != nullptr) {
            clear(node->left);
        }
        if(node->right != nullptr) {
            clear(node->right);
        }
        delete node;
    }

    int N;
    Node* root;

    BSTMap() {
        N = 0;
        root = nullptr;
    }

    ~BSTMap() {
        if(!empty()) {
            clear(root);
        }
    }

    int size() {
        return N;
    }

    bool empty() {
        return size() == 0;
    }

    string find(int key) {
        Node* node = find_entry(key);
        if(node== nullptr) {
            return "";
        }
        return node->value;
    }

    bool insert(int key, string value) {
        if(empty()) {
            root = new Node(key, value, nullptr);
            ++N;
            return true;
        }

        Node* cur_node = root;
        Node* parent_node = nullptr;

        while(cur_node != nullptr) {
            if(key == cur_node->key) { // 이미 해당 key 가지는 엔트리 존재
                return false;
            }

            parent_node = cur_node; // 부모노드 저장

            if(key < cur_node->key) {
                Itotal++;
                cur_node = cur_node->left;
            }
            else {
                Itotal++;
                cur_node = cur_node->right;
            }
        }

        Node* new_node = new Node(key, value, parent_node);
        if(key < parent_node->key) {// 새로운 노드 키 부모 키보다 작으면

            parent_node->left = new_node;
        }
        else {

            parent_node->right = new_node;
        }
        ++N;
        return true;
    }

    bool erase(int key) {
        return erase(find_entry(key));
    }

    void Parent(int x) {
        Node* par = find_entry(x);
        if(par== nullptr) {
            cout << "-1\n";
            return;
        }
        if(par->parent == nullptr) {
            cout << "-2\n";
            return;
        }
        cout << par->parent << "\n";
    }

    void Child(int x) {
        Node* par = find_entry(x);
        if(par== nullptr) {
            cout << "-1\n";
            return;
        }
        if(par->right == nullptr) {
            cout << "-2\n";
            return;
        }
        cout << par->right->key << "\n";
    }
};

int main() {
    int test, num,x; string comm,location;
    cin >> test;
    while(test--) {
        BSTMap map;
        cin >> num;

        while(num--) {
            cin >> comm;
            if(comm=="insert") {
                cin >> x >> location;
                map.insert(x,location);
                cout << Itotal << "\n";
                Itotal = 0;
            }
            if(comm=="search") {
                cin >> x;
                map.find_entry(x);
                if(map.empty()) {
                    cout << "empty\n";
                }
                cout << Stotal << "\n";
                Stotal = 0;
            }
            if(comm=="parent") {
                cin >> x;
                map.Parent(x);
            }
            if(comm=="child") {
                cin >> x;
                map.Child(x);
            }
        }
    }
}