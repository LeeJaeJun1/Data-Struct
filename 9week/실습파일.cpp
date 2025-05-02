#include<iostream>
#include<list>
#include<vector>

using namespace std;

struct Compare{
    bool operator()(int lhs, int rhs) {
        return lhs < rhs;
    }
};

// 정렬되지 않은 시퀀스 기반

class UnsortedSequencePQ {
public:
    Compare comp;
    list<int> elements;

    UnsortedSequencePQ() = default;

    int size() {
        return elements.size();
    }

    bool empty() {
        return size()==0;
    }

    void push(int value) {
        elements.push_back(value);
    }

    int top() {
        if(empty()) {
            return -1;
        }
        list<int>:: iterator res, it;
        res = it = elements.begin();
        while(it != elements.end()) {
            if(comp(*it, *res)) {
                res = it;
            }
            ++it;
        }
        return *res;
    }

    void pop() {
        if(empty()) {
            cout << "empty\n";
            return;
        }
        list<int>:: iterator res,it;
        res = it = elements.begin();
        while(it != elements.end()) {
            if(comp(*it, *res)) {
                res = it;
            }
            ++it;
        }
        elements.erase(res);
    }

        void print() {
            if(empty()) {
                cout << "empty\n";
                return;
            }

            list<int> copy = elements;  // 원본 리스트 복사
            while(!copy.empty()) {
                // 최소값을 찾는다
                list<int>::iterator minIt = copy.begin();
                for(auto it = copy.begin(); it != copy.end(); ++it) {
                    if(comp(*it, *minIt)) {
                        minIt = it;
                    }
                }
                cout << *minIt << " ";
                copy.erase(minIt); // 출력 후 제거
            }
            cout << "\n";
        }

    };

class SortedSequencePQ {
public:
    Compare comp;
    list<int> elements;

    SortedSequencePQ() = default;

    int size() {
        return elements.size();
    }
    bool empty() {
        return size() == 0;
    }
    void push(int value) {
        list<int>::iterator it = elements.begin();
        while(it != elements.end() && comp(*it, value)) {
            ++it;
        }
        elements.insert(it, value);
    }
    int top() {
        if(empty()) {
            return -1;
        }
        return elements.front();
    }
    void pop() {
        if(empty()) {
            cout << "empty\n";
            return;
        }
        elements.pop_front();
    }
    void print() {
        if(empty()) {
            cout << "empty\n";
            return;
        }
        for(auto n : elements) {
            cout << n << " ";
        }
        cout << "\n";
    }
};

int main() {
    int test;
    cin >> test;
    UnsortedSequencePQ pq;
    while(test--) {
        string comm;
        cin >> comm;

        if(comm=="empty") {
            if(pq.empty()) {
                cout << "1\n";
            }
            else {
                cout << "0\n";
            }
        }
        if(comm=="push") {
            int e; cin >> e;
            pq.push(e);
        }
        if(comm=="pop") {
            pq.pop();
        }
        if(comm=="print") {
            pq.print();
        }
        if(comm=="top") {
           cout <<  pq.top() << "\n";
        }
    }
}