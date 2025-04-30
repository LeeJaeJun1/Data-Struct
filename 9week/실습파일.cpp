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
};