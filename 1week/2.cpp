#include<iostream>
using namespace std;

class Array{
private:
    int* arr;
    int arraySize;
public:
    Array(int sz) {
        this->arraySize = sz;
        this->arr = new int[arraySize];
        for(int i = 0; i < arraySize; i++) {
            arr[i] = i;
        }
    }
    void shift(int io, int jo) {
        int jn = arr[jo];
        for(int i = jo; i > io; i--) {
            arr[i] = arr[i-1];
        }
        arr[io] = jn;
    }

    void swap(int io, int jo) {
        int in = arr[io];
        arr[io] = arr[jo];
        arr[jo] = in;
    }

    void print() {
        for(int i = 0; i < arraySize; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int T, N;
    string com;
    cin >> T >> N;
    Array arr(N);
    while(T--) {
        cin >> com;
        if(com == "shift") {
            int io, jo;
            cin >> io >> jo;
            arr.shift(io,jo);
        }
        else if(com == "swap") {
            int io, jo;
            cin >> io >> jo;
            arr.swap(io,jo);
        }
        else if(com == "print") {
            arr.print();
        }
    }
}