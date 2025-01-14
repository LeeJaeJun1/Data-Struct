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

    void add(int a, int b) {
        for(int i = arraySize-1; i > a; i--) {
            arr[i] = arr[i-1];
        }
        arr[a] = b;
    }

    void remove(int a) {
        for(int i = a; i < arraySize-1; i++) {
            arr[i] = arr[i+1];
        }
        arr[arraySize-1] = 0;
    }

    void set(int i, int z) {
        arr[i] = z;
    }

    void count(int z) {
        int total = 0;
        for(int i = 0; i < arraySize; i++) {
            if(arr[i] == z) {
                total += 1;
            }
        }
        if(total == 0) {
            cout << 0 << endl;
            return;
        }
        else{
            cout << total << endl;
        }
    }

    void print() {
        for(int i = 0; i < arraySize; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int t,n;
    string com;
    cin >> t >> n;
    Array arr(n);

    while(t--) {
        cin >> com;
        if(com=="at") {
            int num;
            cin >> num;
            cout << arr.at(num) << endl;
        }
        else if(com=="add") {
            int io,zo;
            cin >> io >> zo;
            arr.add(io,zo);
        }
        else if(com=="remove") {
            int io;
            cin >> io;
            arr.remove(io);
        }
        else if(com=="set") {
            int io,zo;
            cin >> io >> zo;
            arr.set(io,zo);
        }
        else if(com=="count") {
            int za;
            cin >> za;
            arr.count(za);
        }
        else if(com=="print") {
            arr.print();
        }
    }
}


