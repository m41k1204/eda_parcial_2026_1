#include <bits/stdc++.h>
using namespace std;

using T = int;

struct PersistentSegmentTree {
    struct Node {
        T value;
        int left_child;
        int right_child;
    };

    int array_size;
    vector<Node> nodes;
    vector<int> version_root;

    PersistentSegmentTree(const vector<T>& array) : array_size(array.size()) {
        version_root.push_back(build(array, 0, array_size - 1));
    }

    int create_node(T value, int left_child, int right_child) {
        nodes.push_back({value, left_child, right_child});
        return (int)nodes.size() - 1;
    }

    int build(const vector<T>& array, int left, int right) {
        if (left == right) return create_node(array[left], 0, 0);
        int middle = (left + right) / 2;
        int left_node = build(array, left, middle);
        int right_node = build(array, middle + 1, right);
        return create_node(nodes[left_node].value + nodes[right_node].value, left_node, right_node);
    }

    int update(int node, int left, int right, int position, T value) {
        if (left == right) return create_node(value, 0, 0);
        int middle = (left + right) / 2;
        int left_node = nodes[node].left_child;
        int right_node = nodes[node].right_child;
        if (position <= middle) left_node = update(left_node, left, middle, position, value);
        else right_node = update(right_node, middle + 1, right, position, value);
        return create_node(nodes[left_node].value + nodes[right_node].value, left_node, right_node);
    }

    T query(int node, int left, int right, int query_left, int query_right) {
        if (query_right < left || right < query_left) return T(0);
        if (query_left <= left && right <= query_right) return nodes[node].value;
        int middle = (left + right) / 2;
        return query(nodes[node].left_child, left, middle, query_left, query_right)
             + query(nodes[node].right_child, middle + 1, right, query_left, query_right);
    }

    int update(int version, int position, T value) {
        version_root.push_back(update(version_root[version], 0, array_size - 1, position, value));
        return (int)version_root.size() - 1;
    }

    T query(int version, int query_left, int query_right) {
        return query(version_root[version], 0, array_size - 1, query_left, query_right);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int array_size;
    cin >> array_size;
    vector<T> array(array_size);
    for (auto& element : array) cin >> element;
    PersistentSegmentTree tree(array);
    int queries;
    cin >> queries;
    while (queries--) {
    }
    return 0;
}
