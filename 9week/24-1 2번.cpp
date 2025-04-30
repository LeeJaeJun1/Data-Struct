#include<iostream>
#include<list>
#include<vector>

using namespace std;

int digit(int n) {
    int count = 0;
    while(n > 0) {
        count++;
        n /= 10;
    }
    return count;
}

struct Compare{
    bool operator()(int lhs, int rhs) {
        int a1 = digit(lhs);
        int a2 = digit(rhs);
        if(a1 != a2) {
            return a1 < a2;
        }
        return lhs > rhs;
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

int main() {
    int test, length, num;
    cin >> test;
    for(int i = 1; i <= test; i++) {
        UnsortedSequencePQ pq;
        cin >> length;
        for(int j = 0; j < length; j++) {
            cin >> num;
            pq.push(num);
        }

        cout << "Case #" << i << ".\n";

        while(!pq.empty()) {
            cout << pq.top() << " ";
            pq.pop();
        }
        cout << "\n";
    }
}
