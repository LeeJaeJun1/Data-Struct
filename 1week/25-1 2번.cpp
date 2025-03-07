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

    void insert(int a, int b) {
        for(int i = arraySize-1; i > a; i--) {
            arr[i] = arr[i-1];
        }
        arr[a] = b;
    }

    void print() {
        for(int i = 0; i < arraySize; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void change(int a, int b) {
        if(a > 0) {
            arr[a-1] = b;
        }
        else{
            arr[(a + arraySize)] = b;
        }
    }
};

int main() {
    int T,N,Q,a,b,num;
    cin >> T;
    while(T--) {
        cin >> N >> Q;
        Array A(N);
        for(int i = 0; i < N; i++) {
            cin >> num;
            A.insert(i,num);
        }
        while(Q--) {
            cin >> a >> b;
            A.change(a,b);
        }
        A.print();
    }
}