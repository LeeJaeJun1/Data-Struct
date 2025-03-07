#include<iostream>
using namespace std;

class Array {
private:
    int* arr;
    int arraySize;

public:
    Array(int s) {
        this->arraySize = s;
        this->arr = new int[arraySize];
        for(int i = 0; i < arraySize; i++) {
            arr[i] = 0;
        }
    }

    int at(int i) {
        return arr[i];
    }

    void insert(int idx, int x) {
        for(int i = arraySize-1; i > idx; i--) {
            arr[i] = arr[i-1];
        }
        arr[idx] = x;
    }

    void erase(int idx) {
        for(int i = idx; i < arraySize-1; i++) {
            arr[i] = arr[i+1];
        }
        arr[arraySize-1] = 0;
    }

    void set(int i, int x) {
        arr[i] = x;
    }

    void print() {
        for(int i = 0; i < arraySize; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }

    void change_max(int x) {
        int max = 0;
        int idx = 0;
        for(int i = 0; i < arraySize; i++) {
            if(max < arr[i]) {
                max = arr[i];
                idx = i;
            }
        }
        arr[idx] = x;
    }
};

int main() {
    int T,N,Q,idx,x;
    string s;
    cin >> T;
    while(T--) {
        cin >> N >> Q;
        Array a(N);
        while(Q--) {
            cin >> s;
            if(s=="at") {
                cin >> idx;
                cout << a.at(idx) << "\n";
            }
            else if(s=="insert") {
                cin >> idx >> x;
                a.insert(idx,x);
            }
            else if(s=="erase") {
                cin >> idx;
                a.erase(idx);
            }
            else if(s=="set") {
                cin >> idx >> x;
                a.set(idx,x);
            }
            else if(s=="change_max") {
                cin >> x;
                a.change_max(x);
            }
            else if(s=="print") {
                a.print();
            }
        }
    }
}

/*
2
10 3
set 1 6
at 1
print
10 12
insert 6 3
insert 5 7
insert 0 2
print
erase 6
set 1 16
print
insert 2 2
insert 3 2
at 0
change_max 6
*/