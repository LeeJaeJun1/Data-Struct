#include<iostream>
#include<string>
using namespace std;

enum class Status {NOITEM, ISITEM, AVAILABLE};

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

// 선형 조사법 해시테이블 기반

class HTLinearMap {
public:
    int hash_code(int key) {
        return key;
    }
    int compress(int hash) {
        return hash % capacity;
    }
    Entry* find_entry(int key) {
        int hash = hash_code(key);
        int idx = compress(hash);
        int probe = 1;
        while(probe <= capacity && bucket[idx].status != Status::NOITEM) {
            if(bucket[idx].key == key && bucket[idx].status == Status::ISITEM) {
                return &bucket[idx];
            }
            idx = compress(idx + 1);
            ++probe;
        }
        return nullptr;
    }

    int N;
    int capacity;
    Entry* bucket;

    explicit HTLinearMap(int capacity) {
        this->N = 0;
        this->capacity = capacity;
        bucket = new Entry[capacity];
    }
    ~HTLinearMap() {
        delete[] bucket;
    }

    int size() {
        return N;
    }
    bool empty() {
        return size()==0;
    }
    string find(int key) {
        Entry* entry = find_entry(key);
        if(entry == nullptr) {
            return "None";
        }
        return entry->value;
    }
    bool insert(int key, string value) {
        if(size() >= capacity) {
            return false;
        }

        int hash = hash_code(key);
        int idx = compress(hash);
        while(bucket[idx].status == Status::ISITEM) {
            if(key==bucket[idx].key) {
                return false;
            }
            idx = compress(idx + 1);
        }
        cout << compress(hash) << " " << idx << "\n";
        bucket[idx] = Entry(key,value);
        ++N;
        return true;
    }
    bool erase(int key) {
        Entry* entry = find_entry(key);
        if(entry == nullptr) {
            cout << "None" << "\n";
            return false;
        }
        cout << entry->value << "\n";
        entry->erase();
        --N;
        return true;
    }

    void vacant() {
        int total = 0;
        for(int i = 0; i < capacity; i++) {
            if(bucket[i].status != Status::ISITEM) {
                total += 1;
            }
        }
        cout << total << "\n";
    }
};

//이중 해싱 해시테이블

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
    Entry* find_entry(int key) {
        int hash = hash_code(key);
        int idx = compress(hash);
        int probe = 1;
        while(probe <= capacity && bucket[idx].status != Status::NOITEM) {
            if(bucket[idx].status == Status::ISITEM && key == bucket[idx].key) {
                return &bucket[idx];
            }
            idx = compress(idx + hash2(hash));
            ++probe;
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
        return size()==0;
    }
    string find(int key) {
        Entry* entry = find_entry(key);
        if(entry== nullptr) {
            return "";
        }
        return entry->value;
    }
    bool insert(int key, string value) {
        if(size() >= capacity) {
            return false;
        }
        int hash = hash_code(key);
        int idx = compress(hash);
        while(bucket[idx].status==Status::ISITEM) {
            if(bucket[idx].key == key) {
                return false;
            }
            idx = compress(idx + hash2(hash));
        }
        bucket[idx] = Entry(key, value);
        ++N;
        return true;
    }
    bool erase(int key) {
        Entry* entry = find_entry(key);
        if(entry==nullptr) {
            return false;
        }
        entry->erase();
        --N;
        return true;
    }

};

int main() {
    int test, N, key; string comm,value;
    cin >> test >> N;
    HTLinearMap ht(N);
    while(test--) {
        cin >> comm;
        if(comm=="put") {
            cin >> key >> value;
            ht.insert(key,value);
        }
        if(comm=="erase") {
            cin >> key;
            ht.erase(key);
        }
        if(comm=="find") {
            cin >> key;
            cout << ht.find(key) << "\n";
        }
        if(comm=="vacant") {
            ht.vacant();
        }
    }
}