#include<iostream>
using namespace std;

class Array{
private:
    int size;
    int *arr;
public:
    Array(int sz) {
        this->size = sz;
        this->arr = new int[size];
        for(int i = 0; i < size; i++) {
            arr[i] = 0;
        }
    }

    void add(int i, int z) {
        for(int a = size-1; a > i; a--) {
            arr[a] = arr[a-1];
        }
        arr[i] = z;
    }

    void remove(int i) {
        for(int a = i+1; a < size; a++) {
            arr[a-1] = arr[a];
        }
        arr[size - 1] = 0;
    }

    void set(int i, int z) {
        arr[i] = z;
    }

    void print() {
        for(int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void find(int z) {
        int total = 0;
        for(int i = 0; i < size; i++) {
            if(arr[i] == z) {
                total += 1;
            }
        }
        cout << total << endl;
    }
};

int main() {
    int t,n;
    int io,zo;
    cin >> t >> n;
    string com;
    Array a(n);
    while(t--) {
        cin >> com;
        if(com == "add") {
            cin >> io >> zo;
            a.add(io,zo);
        }
        else if(com == "remove") {
            cin >> io;
            a.remove(io);
        }
        else if(com == "set") {
            cin >> io >> zo;
            a.set(io,zo);
        }
        else if(com == "print") {
            a.print();
        }
        else if(com =="find") {
            cin >> zo;
            a.find(zo);
        }
    }
}
