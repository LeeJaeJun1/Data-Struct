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
        while (it != elements.end() && comp(*it, value)) {
            ++it;
        }
        elements.insert(it, value);
    }
    int top() {
        if (empty()) {
            return -1;
        }
        return elements.front();
    }
    void pop() {
        if (empty()) {
            cout << "empty\n";
            return;
        }
        elements.pop_front();
    }
    void print_all() {
        if (empty()) {
            cout << "empty\n";
            return;
        }
        for (auto n : elements) {
            cout << n << " ";
        }
        cout << "\n";
    }
    void Print_avg() {
        if (empty()) {
            cout << "0\n";
            return;
        }
        int sum = 0;
        for (auto n : elements) {
            sum += n;
        }
        cout << sum / size() << "\n";
    }

    void Sum_high() {
        if (empty()) {
            cout << "0\n";
            return;
        }
        int sum = 0;
        for (auto n : elements) {
            sum += n;
        }
        int avg = sum / size();

        int total = 0;
        for (auto a : elements) {
            if (avg < a) {
                total += a;
            }
        }
        cout << total << "\n";
    }
};

// v.erase(v.begin(), v.begin() + k)

int main() {
    int test;
    cin >> test;
    SortedSequencePQ pq;
    while (test--) {
        string comm;
        cin >> comm;

        if (comm == "Push") {
            int e; cin >> e;
            pq.push(e);
        }
        if (comm == "Pop") {
            pq.pop();
        }
        if (comm == "Print_all") {
            pq.print_all();
        }
        if (comm == "Top") {
            cout << pq.top() << "\n";
        }
        if (comm == "Print_avg") {
            pq.Print_avg();
        }
        if (comm == "Sum_high") {
            pq.Sum_high();
        }
    }
}
