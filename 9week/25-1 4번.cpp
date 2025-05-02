#include<iostream>
#include<list>
#include<vector>
#include<string>

using namespace std;

struct Compare {
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
        return size() == 0;
    }

    void push(int value) {
        elements.push_back(value);
    }

    int top() {
        if (empty()) {
            return -1;
        }
        list<int>::iterator res, it;
        res = it = elements.begin();
        while (it != elements.end()) {
            if (comp(*it, *res)) {
                res = it;
            }
            ++it;
        }
        return *res;
    }

    void pop() {
        if (empty()) {
            cout << "empty\n";
            return;
        }
        list<int>::iterator res, it;
        res = it = elements.begin();
        while (it != elements.end()) {
            if (comp(*it, *res)) {
                res = it;
            }
            ++it;
        }
        elements.erase(res);
    }
    void print() {
        if (empty()) {
            cout << "empty\n";
            return;
        }

        list<int> copy = elements;  // 원본 리스트 복사
        while (!copy.empty()) {
            // 최소값을 찾는다
            list<int>::iterator minIt = copy.begin();
            for (auto it = copy.begin(); it != copy.end(); ++it) {
                if (comp(*it, *minIt)) {
                    minIt = it;
                }
            }
            cout << *minIt << " ";
            copy.erase(minIt); // 출력 후 제거
        }
        cout << "\n";
    }
};

int main() {
    int length,num;
    cin >> length;
    UnsortedSequencePQ pq;

    vector<int> v;
    vector<int> vv;
    for (int i = 0; i < length; i++) {
        cin >> num;
        v.push_back(num);
    }


    for (int j = 0; j < length; j++) {
        if (v[j] % 2 != 0) {
            pq.push(v[j]);
        }

        cout << "PQ: ";
        for (auto a : pq.elements) {
            cout << a << " ";
        }
        cout << "\n";
    }

    v.erase(v.begin(), v.begin() + length);
    while (!pq.empty()) {

        cout << "PQ: ";
        v.push_back(pq.top());
        pq.pop();

        for (auto b : pq.elements) {
            cout << b << " ";
        }
        cout << "\n";
    }

    int si = v.size();
    cout << "S: ";
    for (int i = 0; i < si; i++) {
        cout << v[i] << " ";
    }
}