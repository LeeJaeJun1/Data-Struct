#include<iostream>
#include<list>
#include<vector>

using namespace std;

struct Compare{
    bool operator()(int lhs, int rhs) {
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
    int back() {
        if(empty()) {
            return -1;
        }
        return elements.back();
    }
    void pop() {
        if(empty()) {
            cout << "empty\n";
            return;
        }
        elements.pop_front();
    }
    void popBack() {
        if(empty()) {
            cout << "empty\n";
            return;
        }
        elements.pop_back();
    }
};

int main() {
    int test, length, num,location;
    cin >> test;
    while(test--) {
        vector<int> S;
        SortedSequencePQ pq;
        cin >> length;

        for(int i = 0; i < length; i++) {
            cin >> num;
            S.push_back(num);
        }

        cin >> location;

        if(location > length) {
            for(int j = 0; j < (int)S.size(); j++) {
                pq.push(S[j]);
            }
            S.erase(S.begin(), S.begin() + (int)S.size());
            int step = location - length;

            for(int i = 0; i < step; i++) {
                S.push_back(pq.back());
                pq.popBack();
            }
            cout << "S : ";
            for(int a = 0; a < S.size(); a++) {
                cout << S[a] << " ";
            }
            cout << "\n";

            cout << "PQ : ";
            while(!pq.empty()) {
                cout << pq.top() << " ";
                pq.pop();
            }
            cout <<"\n";

        }
        else {
            for(int j = 0; j < location; j++) {
                pq.push(S[j]);
            }
            S.erase(S.begin(), S.begin() + location);

            cout << "S : ";
            for(int a = 0; a < S.size(); a++) {
                cout << S[a] << " ";
            }
            cout << "\n";

            cout << "PQ : ";
            while(!pq.empty()) {
                cout << pq.top() << " ";
                pq.pop();
            }
            cout <<"\n";
        }
    }
}