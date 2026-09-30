#include <bits/stdc++.h>
using namespace std;

const int ALPHABET_SIZE = 26;
const char FIRST_LETTER = 'a';

struct PersistentTrie {
    struct Node {
        int child[ALPHABET_SIZE];
        int end_count;
        int prefix_count;
    };

    vector<Node> nodes;
    vector<int> version_root;

    PersistentTrie(int total_characters = 0) {
        nodes.reserve(1 + total_characters);
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

    int insert(int version, const string& word) {
        int old_node = version_root[version];
        int new_root = copy_node(old_node);
        int current = new_root;
        nodes[current].prefix_count++;
        for (char character : word) {
            int letter = character - FIRST_LETTER;
            int old_child = nodes[old_node].child[letter];
            int new_child = copy_node(old_child);
            nodes[current].child[letter] = new_child;
            nodes[new_child].prefix_count++;
            current = new_child;
            old_node = old_child;
        }
        nodes[current].end_count++;
        version_root.push_back(new_root);
        return (int)version_root.size() - 1;
    }

    int find_node(int version, const string& word) {
        int node = version_root[version];
        for (char character : word) {
            node = nodes[node].child[character - FIRST_LETTER];
            if (node == 0) return 0;
        }
        return node;
    }

    bool contains(int version, const string& word) {
        return nodes[find_node(version, word)].end_count > 0;
    }

    int count_prefix(int version, const string& prefix) {
        return nodes[find_node(version, prefix)].prefix_count;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int queries;
    cin >> queries;
    PersistentTrie trie;
    while (queries--) {
    }
    return 0;
}
