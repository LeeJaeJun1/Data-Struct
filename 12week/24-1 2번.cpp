#include<iostream>
#define NOITEM 0
#define ISITEM 1
#define AVALIABLE 2

using namespace std;

class Entry {
public:
    int key;
    string value;
    int valid;
    int count;

    Entry() {
        key = 0;
        value = "";
        valid = NOITEM;
        count = 0;
    }

    Entry(int key, string value) {
        this->key = key;
        this->value = value;
        count = 0;
        valid = ISITEM;
    }
};

class HashTable {
public:
    Entry* idTable;
    Entry* nameTable;
    int N;

    HashTable(int N) {
        this->N = N;
        idTable = new Entry[N];
        nameTable = new Entry[N];
    }

    int toKey(string s) {
        int code = 0;
        int multi = 1;

        for(int i = 0; i < 6; i++) {
            int digit = s[i] - 'a';
            code += digit * multi;
            multi * 26;
        }
        return code;
    }

    int hashFunc(int key) {
        return key % N;
    }

    void add(int key, string s) {
        int idIdx = hashFunc(key);
        int nameIdx = hashFunc(toKey(s));

        while(idTable[idIdx].valid == ISITEM) {
            idIdx = hashFunc(idIdx + 1);
        }
        idTable[idIdx] = Entry(key,s);

        while(nameTable[nameIdx].valid == ISITEM) {
            nameIdx = hashFunc(nameIdx + 1);
        }
        nameTable[nameIdx] = Entry(key,s);
    }

    void erase(int key) {
        int idIdx = hashFunc(key);
        string s;

        while(idTable[idIdx].valid != NOITEM) {
            if(idTable[idIdx].valid == ISITEM && idTable[idIdx].key == key) {
                s = idTable[idIdx].value;
                idTable[idIdx].valid = AVALIABLE;
                break;
            }
            idIdx = hashFunc(idIdx + 1);
        }

        int nameIdx = hashFunc(toKey(s));

        while(nameTable[nameIdx].valid != NOITEM) {
            if(nameTable[nameIdx].valid == ISITEM && nameTable[nameIdx].value == s) {
                nameTable[nameIdx].valid = AVALIABLE;
                return;
            }
            nameIdx = hashFunc(nameIdx + 1);
        }
    }

    string getName(int x) {
        int idIdx = hashFunc(x);
        string s;

        while(idTable[idIdx].valid != NOITEM) {
            if(idTable[idIdx].valid == ISITEM && idTable[idIdx].key == x) {
                s = idTable[idIdx].value;
                return s;
            }
            idIdx = hashFunc(idIdx + 1);
        }
    }

    int getID(string s) {
        int nameIdx = hashFunc(toKey(s));
        int id;

        while(nameTable[nameIdx].valid != NOITEM) {
            if(nameTable[nameIdx].valid==ISITEM && nameTable[nameIdx].value == s) {
                id = nameTable[nameIdx].key;
                return id;
            }
            nameIdx = hashFunc(nameIdx + 1);
        }
        return 0;
    }

    void present(string s) {
        int nameIdx = hashFunc(toKey(s));
        int id;
        bool found = false;

        while(nameTable[nameIdx].valid != NOITEM) {
            if(nameTable[nameIdx].valid == ISITEM && nameTable[nameIdx].value == s) {
                id = nameTable[nameIdx].key;
                cout << ++nameTable[nameIdx].count << "\n";
                found = true;
                break;
            }
            nameIdx = hashFunc(nameIdx + 1);
        }

        if(!found) {
            cout << -1 << "\n";
            return;
        }

        int idIdx = hashFunc(id);

        while(idTable[idIdx].valid != NOITEM) {
            if(idTable[idIdx].valid == ISITEM && idTable[idIdx].key == id) {
                ++idTable[idIdx].count;
                return;
            }
            idIdx = hashFunc(idIdx+1);
        }
    }

    int getCount(int x) {
        int idIdx = hashFunc(x);
        bool found = false;

        while(idTable[idIdx].valid != NOITEM) {
            if(idTable[idIdx].valid == ISITEM && idTable[idIdx].key == x) {
                return idTable[idIdx].count;
            }
            idIdx = hashFunc(idIdx + 1);
        }
        return -1;
    }
};

int main() {
    int test,x; string str,s;
    cin >> test;
    HashTable hash(200000);

    while(test--) {
        cin >> str;

        if(str=="add") {
            cin >> x >> s;
            hash.add(x,s);
        }
        if(str=="delete") {
            cin >> x;
            hash.erase(x);
        }
        if(str=="name") {
            cin >> x;
            cout << hash.getName(x) << "\n";
        }
        if(str=="number") {
            cin >> s;
            cout << hash.getID(s) << "\n";
        }
        if(str=="present") {
            cin >> s;
            hash.present(s);
        }
        if(str=="count") {
            cin >> x;
            cout << hash.getCount(x) << "\n";
        }
    }
}