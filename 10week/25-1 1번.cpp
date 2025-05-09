#include<iostream>
#include<list>
#include<vector>
using namespace std;

bool check = false;

struct Compare {
    bool operator()(int lhs, int rhs) {
        return lhs < rhs;
    }
};

class HeapPQ {
public:
    void swap(int idx1, int idx2) {
        int tmp = elements[idx1];
        elements[idx1] = elements[idx2];
        elements[idx2] = tmp;
    }

    void upHeap(int idx) { // 삽입 이후 idx번 노드와 그 부모 노드 간 힙 순서 보정
        if(idx==1) {
            return;
        }
        int parent_idx = idx / 2;

        if(!comp(elements[parent_idx], elements[idx])) {
            cout << "(" << parent_idx << ", " << idx << ")" << "\n";
            check = true;
        }
    }
    void downHeap(int idx) {
        int left_idx = idx * 2;
        int right_idx = idx * 2 + 1;

        int child_idx;
        if(left_idx > size()) {
            return;
        }
        if(left_idx == size()) {
            child_idx = left_idx;
        }
        else {
            if(comp(elements[left_idx], elements[right_idx])) {
                child_idx = left_idx;
            }
            else{
                child_idx = right_idx;
            }
        }

        if(!comp(elements[idx], elements[child_idx])) {
            swap(idx, child_idx);
            downHeap(child_idx);
        }
    }

    Compare comp;
    vector<int> elements;

    explicit HeapPQ() {
        elements.push_back(-1);
    }

    int size() {
        return elements.size() - 1;
    }

    bool empty() {
        return size()==0;
    }

    void push(int value) {
        elements.push_back(value);
        upHeap(size());
    }

    int top() {
        if(empty()) {
            return -1;
        }
        return elements[1];
    }

    void pop() {
        if(empty()) {
            cout << "empty\n";
            return;
        }
        swap(1,size());
        elements.pop_back();
        downHeap(1);
    }
};

int main() {
    int test,length,num;
    cin >> test;
    while(test--) {
        HeapPQ pq;
        cin >> length;
        cin >> num;
        for(int i = 1; i < length; i++) {
            cin >> num;
            pq.push(num);
        }
        if(!check) {
            cout << "(-1, -1)" << "\n";
        }
        check = false;
    }
}
