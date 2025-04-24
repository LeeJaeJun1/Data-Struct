#include<iostream>
using namespace std;

class Array {
public:
    int size;
    int* arr;
    Array(int size) {
        this->size = size;
        arr = new int[size];
        for(int i = 1; i <= size; i++) {
            arr[i] = 0;
        }
    }

    void insert(int idx,int value) {
        arr[idx] = value;
    }

    void print() {
        for(int i = 1; i <= size; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }

    void change(int idx, int value) {
        if(idx > 0) {
            // 배열의 가장 왼쪽 인덱스 1로 시작
            arr[idx] = value;
        }
        if(idx < 0) {
            int index = idx+size+1;
            arr[index] = value;
        }
    }
};

int main() {
    int test,N,Q,x,idx;
    cin >> test;
    while(test--) {
        cin >> N >> Q;
        Array a(N);
        for(int i = 1; i <= N; i++) {
            cin >> x;
            a.insert(i,x);
        }
        while(Q--) {
            cin >> idx >> x;
            a.change(idx,x);
        }
        a.print();
    }
}