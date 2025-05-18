
#include<iostream>
#include<string>
using namespace std;

int arr1[100001];
int total = 0;
class Node {
public:
    int key;
    int value;
    Node* parent;
    Node* left;
    Node* right;

    explicit Node(int key, int value, Node* parent)
            : key(key), value(value), parent(parent), left(nullptr), right(nullptr) {}

    friend class BSTMap;
};

class BSTMap {
public:
    int idx;

    Node* find_entry(int key) {
        Node* cur_Node = root;

        while (cur_Node != nullptr) {
            if (key == cur_Node->key) {
                return cur_Node;
            }
            if (key < cur_Node->key) {

                cur_Node = cur_Node->left;
            }
            else {

                cur_Node = cur_Node->right;
            }
        }
        return nullptr;
    }

    Node* get_successor(Node* node) {
        if (node->right) {
            Node* curr = node->right;
            while (curr->left) {
                curr = curr->left;
            }
            return curr;
        }
        Node* curr = node;
        Node* parent = node->parent;
        while (parent && curr == parent->right) {
            curr = parent;
            parent = parent->parent;
        }
        return parent;
    }

    bool erase(Node* node) {
        if (node == nullptr) { // 삭제할 노드 존재하는지
            return false;
        }

        if (node->left != nullptr && node->right != nullptr) { // 삭제할 노드에 두 자식이 모두 존재
            Node* successor = get_successor(node); // 후행자의 key, value값을 삭제할 노드에 복사시킨다.
            node->key = successor->key;
            node->value = successor->value;
            node = successor; // 삭제할 노드를 후행자로 변경
        }

        Node* child_node; // 삭제할 노드의 자식 1개 혹은 0개
        if (node->left != nullptr) {
            child_node = node->left;
        }
        else {
            child_node = node->right;
        }

        if (node == root) {
            root = child_node; // 자식 노드 루트로 변경
            if (child_node != nullptr) {
                child_node->parent = nullptr; // 부모 포인터 초기화
            }
        }
        else {
            Node* parent_node = node->parent;
            if (child_node != nullptr) { // 부모 연결 갱신
                child_node->parent = parent_node;
            }
            if (node == parent_node->left) { // 자식 연결 갱신
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
        if (node->left != nullptr) {
            clear(node->left);
        }
        if (node->right != nullptr) {
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
        if (!empty()) {
            clear(root);
        }
    }

    int size() {
        return N;
    }

    bool empty() {
        return size() == 0;
    }

    int find(int key) {
        Node* node = find_entry(key);
        if (node == nullptr) {
            return 0;
        }
        return node->value;
    }

    bool insert(int key, int value) { // 키가 상품번호, 값이 재고 수량
        if (empty()) {
            root = new Node(key, value, nullptr);
            ++N;
            return true;
        }

        Node* cur_node = root;
        Node* parent_node = nullptr;

        while (cur_node != nullptr) {
            if (key == cur_node->key) { // 이미 해당 key 가지는 엔트리 존재
                return false;
            }

            parent_node = cur_node; // 부모노드 저장

            if (key < cur_node->key) {

                cur_node = cur_node->left;
            }
            else {

                cur_node = cur_node->right;
            }
        }

        Node* new_node = new Node(key, value, parent_node);
        if (key < parent_node->key) {// 새로운 노드 키 부모 키보다 작으면

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



    int get_height(Node* node) {
        if (node == nullptr) return -1;// 빈 서브트리의 높이는 -1 (정의에 따라 0으로 설정해도 됨)
        total++;
        get_height(node->left);
        get_height(node->right);
        return total;
    }

    void Height(int key) {
        Node* node = find_entry(key);
        if (node == nullptr) {
            cout << "-1\n";  // 해당 노드가 없음
            return;
        }
        cout << get_height(node) << "\n";
    }



    void inorder(Node* node) {
        if(!node) {
            return;
        }

        inorder(node->left);
        arr1[idx++] = node->key;
        inorder(node->right);
    }

    void Next(int k, int s) {
        Node* node = find_entry(k);
        Node* f = get_successor(node);
        int count = 1;
        while(f && count < s) {
            count++;
            f = get_successor(f);
        }
        if(f) {
            cout << f->key << "\n";
        }
        else {
            cout << "-2\n";
        }
    }
};

int main() {
    int test,x,s,loc; string comm;
    cin >> test;
    BSTMap map;

    while (test--) {
        cin >> comm;
        if (comm == "Insert") {
            cin >> x >> loc;
            map.insert(x, loc);

        }
        if (comm == "Find") {
            cin >> x;
            cout << map.find(x) << "\n";

        }
        if (comm == "Erase") {
            cin >> x;
            map.erase(x);
        }
        if (comm == "SubtreeSize") {
            cin >> x;
            map.Height(x);
            total = 0;
        }
        if (comm == "Next") {
            cin >> x >> s;
            map.Next(x, s);
        }
    }

}