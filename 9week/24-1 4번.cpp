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
        int n1 = digit(lhs);
        int n2 = digit(rhs);
        if(n1 != n2) {
            return n1 > n2;
        }
        return lhs < rhs;
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

int main() {
    int test, length, num;
    cin >> test;
    for(int j = 1; j <= test; j++) {
        SortedSequencePQ pq;
        cin >> length;

        for(int i = 0; i < length; i++) {
            cin >> num;
            pq.push(num);
        }

        cout << "Case #" << j << "." << "\n";

        while(!pq.empty()) {
            cout << pq.top() << " ";
            pq.pop();
        }
        cout << "\n";
    }
}