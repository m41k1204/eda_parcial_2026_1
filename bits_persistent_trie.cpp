#include <bits/stdc++.h>
using namespace std;

using T = int;
const int BITS = 30;

struct PersistentTrie {
    struct Node {
        int child[2];
        int count;
    };

    vector<Node> nodes;
    vector<int> version_root;

    PersistentTrie(int operations = 0) {
        nodes.reserve(1 + operations * (BITS + 1));
        nodes.push_back(Node{});
        version_root.push_back(0);
    }

    int copy_node(int node) {
        Node copy = nodes[node];
        nodes.push_back(copy);
        return (int)nodes.size() - 1;
    }

    int copy_version(int version) {
        version_root.push_back(version_root[version]);
        return (int)version_root.size() - 1;
    }

    int update(int version, T value, int delta) {
        int old_node = version_root[version];
        int new_root = copy_node(old_node);
        int current = new_root;
        nodes[current].count += delta;
        for (int level = BITS - 1; level >= 0; level--) {
            int bit = (value >> level) & 1;
            int old_child = nodes[old_node].child[bit];
            int new_child = copy_node(old_child);
            nodes[current].child[bit] = new_child;
            nodes[new_child].count += delta;
            current = new_child;
            old_node = old_child;
        }
        version_root.push_back(new_root);
        return (int)version_root.size() - 1;
    }

    int insert(int version, T value) { return update(version, value, 1); }
    int erase(int version, T value) { return update(version, value, -1); }

    int size(int version) { return nodes[version_root[version]].count; }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int queries;
    cin >> queries;
    PersistentTrie trie(queries);
    while (queries--) {
    }
    return 0;
}
