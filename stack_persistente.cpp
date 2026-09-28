#include <bits/stdc++.h>
using namespace std;

using T = int;

struct PersistentStack {
    struct Node {
        T value;
        int next;
        int size;
    };

    vector<Node> nodes;
    vector<int> version_head;

    PersistentStack() {
        nodes.push_back({T(), 0, 0});
        version_head.push_back(0);
    }

    int push(int version, T value) {
        int head = version_head[version];
        nodes.push_back({value, head, nodes[head].size + 1});
        version_head.push_back((int)nodes.size() - 1);
        return (int)version_head.size() - 1;
    }

    int pop(int version) {
        version_head.push_back(nodes[version_head[version]].next);
        return (int)version_head.size() - 1;
    }

    T top(int version) { return nodes[version_head[version]].value; }
    int size(int version) { return nodes[version_head[version]].size; }
    bool empty(int version) { return version_head[version] == 0; }

    void print(int version) {
        for (int node = version_head[version]; node != 0; node = nodes[node].next) cout << nodes[node].value << '\n';
        cout << "END OF STACK\n";
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int queries;
    cin >> queries;
    PersistentStack stack;
    while (queries--) {
    }
    return 0;
}
