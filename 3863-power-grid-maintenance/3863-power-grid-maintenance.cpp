

class DSU {
public:
    vector<int> parent;
    DSU(int n) {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }

    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
        }
    }
};

class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        DSU dsu(c);
        for (const auto& conn : connections) {
            dsu.unite(conn[0], conn[1]);
        }

        map<int, set<int>> components;
        for (int i = 1; i <= c; ++i) {
            components[dsu.find(i)].insert(i);
        }

        vector<int> ans;

        for (const auto& q : queries) {
            int type = q[0];
            int x = q[1];
            int root = dsu.find(x);

            if (type == 1) {
                if (components[root].count(x)) {
                    ans.push_back(x);
                } else {
                    if (components[root].empty()) {
                        ans.push_back(-1);
                    } else {
                        ans.push_back(*components[root].begin());
                    }
                }
            } else {
                components[root].erase(x);
            }
        }
        return ans;
    }
};