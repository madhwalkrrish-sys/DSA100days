#include <iostream>
#include <vector>
using namespace std;

class HashTable {
    int m;
    vector<int> table;

public:
    HashTable(int size) {
        m = size;
        table.assign(m, -1); // -1 means empty
    }

    void insert(int key) {
        int h = key % m;

        for(int i = 0; i < m; i++) {
            int idx = (h + i*i) % m;

            if(table[idx] == -1) {
                table[idx] = key;
                return;
            }
        }
    }

    bool search(int key) {
        int h = key % m;

        for(int i = 0; i < m; i++) {
            int idx = (h + i*i) % m;

            if(table[idx] == -1) return false;
            if(table[idx] == key) return true;
        }

        return false;
    }
};

int main() {
    int m, q;
    cin >> m >> q;

    HashTable ht(m);

    while(q--) {
        string op;
        int x;
        cin >> op >> x;

        if(op == "INSERT") {
            ht.insert(x);
        } else if(op == "SEARCH") {
            if(ht.search(x)) cout << "FOUND\n";
            else cout << "NOT FOUND\n";
        }
    }

    return 0;
}