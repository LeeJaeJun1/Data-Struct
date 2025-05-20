#include<iostream>
#define NOITEM 0
#define ISITEM 1
#define AVAILABLE 2

using namespace std;

class Entry {
public:
    int key;
    string value;
    int valid;

    Entry() {
        key = 0;
        value = "";
        valid = NOITEM;
    }

    Entry(int key, string value) {
        this->key = key;
        this->value = value;
        valid = ISITEM;
    }
};

class HashTable {
public:
    Entry* hashTable;
    int N, M;

    HashTable(int N, int M) {
        this->N = N;
        this->M = M;
        hashTable = new Entry[N];
    }

    int funcOne(int key) {
        return key % N;
    }

    int funcTwo(int key) {
        return M - (key % M);
    }

    void put(int key, string value) {
        int idx = funcOne(key);
        int probing = 0;
        while(hashTable[idx].valid == ISITEM && probing <= N) {
            idx = funcOne(idx + funcTwo(key));
            probing += 1;
        }

        if(probing > N) {
            return;
        }

        cout << funcOne(key) << " " << idx << "\n";
        hashTable[idx] = Entry(key,value);
    }

    void erase(int key) {
        int idx = funcOne(key);
        int probing = 0;
        while(hashTable[idx].valid != NOITEM && probing <= N) {
            if(hashTable[idx].valid == ISITEM && hashTable[idx].key == key) {
                hashTable[idx].valid = AVAILABLE;
                cout << hashTable[idx].value << "\n";
                return;
            }
            idx = funcOne(idx + funcTwo(key));
            probing += 1;
        }
        cout << "None\n";
    }

    void find(int key) {
        int idx = funcOne(key);
        int probing = 0;
        while(hashTable[idx].valid != NOITEM && probing <= N) {
            if(hashTable[idx].valid == ISITEM && hashTable[idx].key == key) {
                cout << hashTable[idx].value << "\n";
                return;
            }
            idx = funcOne(idx + funcTwo(key));
            probing+=1;
        }
        cout << "None\n";
    }

    void vacant() {
        int count = 0;
        for(int i = 0; i < N; i++) {
            if(hashTable[i].valid != ISITEM) {
                count += 1;
            }
        }
        cout << count << "\n";
    }
};

int main() {
    int test, N, M, key; string comm,value;
    cin >> test >> N >> M;
    HashTable ha(N,M);
    while(test--) {
        cin >> comm;
        if(comm=="put") {
            cin >> key >> value;
            ha.put(key,value);
        }
        if(comm=="erase") {
            cin >> key;
            ha.erase(key);
        }
        if(comm=="find") {
            cin >> key;
            ha.find(key);
        }
        if(comm=="vacant") {
            ha.vacant();
        }
    }
}
