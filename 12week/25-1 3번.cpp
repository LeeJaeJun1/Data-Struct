#include<iostream>
#include<string>
using namespace std;

enum class Status { NOITEM, ISITEM, AVAILABLE };

struct Entry {
    int key;
    string value;
    Status status;

    Entry() {
        key = -1;
        status = Status::NOITEM;
    }

    Entry(int key, string& value) {
        this->key = key;
        this->value = value;
        status = Status::ISITEM;
    }

    void erase() {
        status = Status::AVAILABLE;
    }
};



//이중 해싱 해시테이블

int probing = 0;
bool Find = false;

class HTDoubleMap {
public:
    int hash_code(int key) {
        return key;
    }
    int compress(int hash) {
        return hash % capacity;
    }
    int hash2(int hash) {
        return divisor - (hash % divisor);
    }
    Entry* find_entry(int key, bool Find) {
        int hash = hash_code(key);
        int idx = compress(hash);
        int probe = 1;
        while (probe <= capacity && bucket[idx].status != Status::NOITEM) {

            if (bucket[idx].status == Status::ISITEM && key == bucket[idx].key) {
                if(Find) {
                   probing += probe;
                }
                return &bucket[idx];
            }
            idx = compress(idx + hash2(hash));
            ++probe;

        }
        if(Find) {
            probing += probe;
        }
        return nullptr;
    }

    int N;
    int capacity;
    Entry* bucket;
    int divisor;

    explicit HTDoubleMap(int capacity, int divisor) {
        this->N = 0;
        this->capacity = capacity;
        bucket = new Entry[capacity];
        this->divisor = divisor;
    }
    ~HTDoubleMap() {
        delete[] bucket;
    }

    int size() {
        return N;
    }
    bool empty() {
        return size() == 0;
    }
    string find(int key) {
        Entry* entry = find_entry(key,true);
        if (entry == nullptr) {
            return "-1";
        }
        return entry->value;
    }
    bool insert(int key, string value) {

        int hash = hash_code(key);
        int idx = compress(hash);

        while (bucket[idx].status == Status::ISITEM) {
            if (bucket[idx].key == key) {

                cout << compress(hash) << " " << -1 << "\n";
                return false;
            }
            idx = compress(idx + hash2(hash));
        }

        cout << compress(hash) << " " << idx << "\n";
        bucket[idx] = Entry(key, value);
        ++N;
        return true;
    }
    void erase(int key) {
        Entry* entry = find_entry(key,false);
        if (entry == nullptr) {
            cout << "-1\n";
            return;
        }
        cout << entry->value << "\n";
        entry->erase();
        --N;
    }

    void vacant() {
        int count = 0;
        for (int i = 0; i < capacity; i++) {
            if (bucket[i].status == Status::ISITEM) {

                count += 1;
            }
        }
        cout << count << "\n";
    }
};



int main() {
    int test, N, M, key; string comm, value;
    cin >> test >> N >> M;
    HTDoubleMap ha(N, M);
    while (test--) {
        cin >> comm;
        if (comm == "insert") {
            cin >> key >> value;
            ha.insert(key, value);
        }
        if (comm == "erase") {
            cin >> key;
            ha.erase(key);
        }
        if (comm == "find") {
            cin >> key;
            cout << ha.find(key) << "\n";
        }
        if (comm == "size") {
            ha.vacant();
        }
    }

    cout << probing << "\n";

}