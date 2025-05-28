#include <iostream>
#include <string>
using namespace std;

const int TABLE_SIZE = 500009;

struct Entry {
    string id;
    bool infected;

    Entry() {
        id = "";
        infected = false;
    }

    Entry(string id, bool infected) {
        this->id = id;
        this->infected = infected;
    }
};

class HTLinearMap {
private:
    Entry* bucket;

public:
    HTLinearMap() {
        bucket = new Entry[TABLE_SIZE];
    }

    ~HTLinearMap() {
        delete[] bucket;
    }

    long toKey(const string& s) {
        long code = 0;
        long mul = 1;
        for (int i = 0; i < s.length(); i++) {
            int digit = s[i] - 'a';
            code += digit * mul;
            mul *= 26;
        }
        return code;
    }

    int findIndex(const string& s) {
        long  rawHash = toKey(s);
        int hash = (int)(rawHash % TABLE_SIZE);
        while (bucket[hash].id != "" && bucket[hash].id != s) {
            hash = (hash + 1) % TABLE_SIZE;
        }
        return hash;
    }

    void insert(const string& s) {
        int idx = findIndex(s);
        if (bucket[idx].id == "") {
            bucket[idx].id = s;
            bucket[idx].infected = false;
        }
    }

    bool isInfected(const string& s) {
        int idx = findIndex(s);
        return bucket[idx].infected;
    }

    void setInfected(const string& s) {
        int idx = findIndex(s);
        bucket[idx].infected = true;
    }
};

int main() {
    int N;
    cin >> N;

    string first;
    cin >> first;

    HTLinearMap ht;

    ht.insert(first);
    ht.setInfected(first);
    cout << first << '\n';

    for (int i = 0; i < N; i++) {
        string a, b;
        cin >> a >> b;

        if (a == b) continue; // 자기 자신과의 악수는 무시

        ht.insert(a);
        ht.insert(b);

        bool aInfected = ht.isInfected(a);
        bool bInfected = ht.isInfected(b);

        if (aInfected && !bInfected) {
            ht.setInfected(b);
            cout << b << '\n';
        }
        if (!aInfected && bInfected) {
            ht.setInfected(a);
            cout << a << '\n';
        }
    }
}
