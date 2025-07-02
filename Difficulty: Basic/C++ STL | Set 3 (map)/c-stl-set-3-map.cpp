void add_value(map<int, int> &m, int x, int y) {
    m[x] = y;
}

int find_value(map<int, int> &m, int x) {
    if (m.find(x) != m.end()) {
        return m[x];
    }
    return -1;
}

void print_contents(map<int, int> &m) {
    for (auto &p : m) {
        cout << p.first << " " << p.second << " ";
    }
}