#include<iostream>
#include<string>
using namespace std;

enum class Status {NOITEM, ISITEM, AVAILABLE};

int onlineCount;

struct Entry {
    string id;
    string pw;
    bool log;
    Status status;

    Entry() {
        id = "";
        pw = "";
        log = false;
        status = Status::NOITEM;
    }

    Entry(string id, string& pw) {
        this->id = id;
        this->pw = pw;
        log = false;
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


    int toKey(string s) {
        int code = 0;
        int multi = 1;
        for(int i = 0; i < s.length(); i++) {
            int digit = s[i] - 'A';
            code += digit * multi;
            multi *= 26;
        }
        return code;
    }


    void signup(string id, string pw) {
        int idx = compress(toKey(id));

        while(bucket[idx].status == Status::ISITEM) {
            if(bucket[idx].id == id) {
                cout << "Invalid\n";
                return;
            }
            idx = compress(idx+1);
        }
        bucket[idx] = Entry(id,pw);
        cout << "Submit\n";
    }

    void login(string id, string pw) {
        int idx = compress(toKey(id));

        while(bucket[idx].status == Status::ISITEM) {
            if(bucket[idx].id == id && bucket[idx].pw == pw && bucket[idx].log == true) {
                cout << "Already\n";
                return;
            }
            else if(bucket[idx].id == id && bucket[idx].pw == pw && bucket[idx].log == false) {
                bucket[idx].log = true;
                onlineCount++;
                cout << "Submit\n";
                return;
            }
            idx = compress(idx + 1);
        }
        cout << "Invalid\n";
    }

    void logout(string id) {
        int idx = compress(toKey(id));

        while(bucket[idx].status == Status::ISITEM) {
            if(bucket[idx].id==id) {
                bucket[idx].log = false;
                onlineCount--;
                cout << "Submit\n";
                return;
            }
            idx = compress(idx+1);
        }
    }
};


int main() {
    int test;
    cin >> test;
    string str,id, pw;
    HTLinearMap h = HTLinearMap(200000);

    while (test--) {
        cin >> str;

        if (str == "signup") {
            cin >> id >> pw;
            h.signup(id, pw);
        }
        if (str == "login") {
            cin >> id >> pw;
            h.login(id, pw);
        }
        if (str == "logout") {
            cin >> id;
            h.logout(id);
        }
        if (str == "online")
            cout << onlineCount << '\n';
    }
}