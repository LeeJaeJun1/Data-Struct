#include<iostream>
using namespace std;

class Vector{
private:
    int* arr;
    int capacity;
    int size;
public:
    Vector() {
        capacity = 100000;
        arr = new int[capacity];
        size = 0;
    }
    void resize(int s);
    bool empty() {
        return size==0;
    }
    void print() {
        if(empty()) {
            cout << "empty\n";
        }
        for(int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    int Size() {
        return size;
    }
    void erase(int idx) {
        if(idx >= size) {
            cout << -1 << "\n";
            return;
        }
        for(int i = idx; i < capacity-1; i++) {
            arr[i] = arr[i+1];
        }
        --size;
    }
    void insert(int idx, int x) {
        if(size == capacity) {
            resize(2*capacity);
        }
        for(int i = capacity-1; i > idx; i--) {
            arr[i] = arr[i-1];
        }
        arr[idx] = x;
        ++size;
    }
    void print_odd(int idx) {
        int count = 0;
        if(idx >= size) {
            cout << "-1\n";
            return;
        }
        for(int i = idx+1; i< size; i++) {
            if(arr[i] % 2 != 0) {
                cout << arr[i] << " ";
                count+=1;
            }
        }
        if(count==0) {
            cout << "-1\n";
        }
        else{
            cout << "\n";
        }
    }
};

void Vector::resize(int s) {
    if(size<=capacity) {
        return;
    }
    int* new_arr = new int[s];
    if(arr != nullptr) {
        for(int i = 0; i < size; i++) {
            new_arr[i] = arr[i];
        }
        delete[] arr;
    }
    arr = new_arr;
    capacity = s;
}

int main() {
    int n,idx,x; string comm;
    cin >> n;
    Vector v;
    while(n--) {
        cin >> comm;
        if(comm=="Print") {
            v.print();
        }
        else if(comm=="Size") {
            cout << v.Size() << "\n";
        }
        else if(comm=="Erase") {
            cin >> idx;
            v.erase(idx);
        }
        else if(comm=="Insert") {
            cin >> idx >> x;
            v.insert(idx,x);
        }
        else if(comm=="Print_Odd") {
            cin >> idx;
            v.print_odd(idx);
        }
    }
}