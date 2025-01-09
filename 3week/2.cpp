#include <iostream>
#include <string>
using namespace std;

struct node {
    int data;
    node* next;
};

class listStack {
public:
    listStack();
    int size();
    int top();
    void push(int data);
    int pop();
private:
    node* topNode;
    int listSize;
};
listStack::listStack() {
    topNode = NULL;
    listSize = 0;
}


int listStack::size() {
    return listSize;
}
int listStack::top() {
    return topNode->data;
}
void listStack::push(int data) {
    node* newNode = new node();
    newNode->data = data;
    newNode->next = topNode;
    topNode = newNode;
    listSize++;
}

int listStack::pop() {
    int top = topNode->data;
    node* curNode = topNode;
    topNode = topNode->next;

    delete curNode;
    listSize--;
    return top;
}

int main() {
    int t, n, a, b, x;
    int k;
    int ans;
    string s;
    listStack lis;
    cin >> t;

    while (t--) {
        cin >> s >> k;
        for (int j = 0; j < s.length(); j++) {
            if (s[j] >= '1' && s[j] <= '9') {
                n = s[j] - '0';
                lis.push(n);
            }
            else if (s[j] == '+') {
                a = lis.pop();
                b = lis.pop();
                x = b + a;
                lis.push(x);
            }
            else if (s[j] == '-') {
                a = lis.pop();
                b = lis.pop();
                x = b - a;
                lis.push(x);
            }
            else if (s[j] == '*') {
                a = lis.pop();
                b = lis.pop();
                x = b * a;
                lis.push(x);
            }
            else if (s[j] == '/') {
                a = lis.pop();
                b = lis.pop();
                x = b / a;
                lis.push(x);
            }
        }
        ans = lis.pop();
        if (ans < 0) {
            ans = -ans;
        }
        cout << ans % k << '\n';
    }
    return 0;
}