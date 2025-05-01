#include<iostream>
#include<list>
#include<vector>

using namespace std;

struct Compare{
    bool operator()(int lhs, int rhs) {
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
    int test, length, num,step;
    cin >> test;
    while(test--) {
        UnsortedSequencePQ pq;
        vector<int> v;

        cin >> length;

        for(int i = 0; i < length; i++) {
            cin >> num;
            v.push_back(num);
        }

        cin >> step;

        if(step > length) {
            int fi = step-length;
            for(int j = 0; j < v.size(); j++) {
                pq.push(v[j]);
            }
            v.erase(v.begin(), v.begin() + (int)v.size());

            for(int k = 0; k < fi; k++) {
                v.push_back(pq.top());
                pq.pop();
            }

            cout << "S : ";
            for(int a = 0; a < (int)v.size(); a++) {
                cout << v[a] << " ";
            }
            cout << "\n";

            cout << "PQ : ";
            for(int e : pq.elements) {
                cout << e << " ";
            }
            cout << "\n";
        }
        else {
            for(int q = 0; q < step; q++) {
                pq.push(v[q]);
            }
            v.erase(v.begin(), v.begin() + step);

            cout << "S : ";
            for(int w = 0; w < v.size(); w++) {
                cout << v[w] << " ";
            }
            cout << "\nPQ : ";
            for(int e : pq.elements) {
                cout << e << " ";
            }
            cout << "\n";
        }
    }
}