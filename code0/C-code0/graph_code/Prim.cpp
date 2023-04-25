#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct _edg_ {
    int start = 0;
    int end = 0;
    int weight = 0;
    _edg_* nxt = nullptr;
    _edg_(): start(0), end(0), weight(0), nxt(nullptr) {};
    _edg_(int s, int e, int w): start(s), end(e), weight(w) {};
};

int edg_count = 0;
vector<int> verts;
_edg_* edges;
vector<int> pres;
vector<bool> ved;
vector<bool> eved;
vector<int> dist;
vector<_edg_> tree;
vector<_edg_*> table;

int v_num, e_num;

bool cmp(const _edg_& lhs, const _edg_& rhs) {
    return lhs.weight < rhs.weight;
}

void pre_init(vector<int>& pres, vector<bool>& ved, int v_num) {
    pres.resize(v_num, -1);
    ved.resize(v_num, false);
    eved.resize(e_num, false);
    tree.resize(0);
    table.resize(v_num, nullptr);
}

void addedg(int start, int end, int weight) {
    _edg_* tmp = new _edg_(start, end, weight);
    tmp -> nxt = table[start];
    table[start] = tmp;
}

void prim() {
    ved[0] = true;
    for (int i = 0; i < verts[1]; ++i) {
        dist[i] = edges[i].weight;
    }
    int cur = 0, pre = -1;
    while (edg_count < v_num - 1) {
        int cursum = 1e5, index = 45325;
        for (int i = 0; i < dist.size(); ++i) {
            if (dist[i] < cursum && !eved[i] && !ved[edges[i].end]) {
                cursum = dist[i];
                index = i;
            }
        }
        eved[index] = true;
        tree.push_back(edges[index]);
        pre = cur;
        cur = edges[index].end;
        ved[cur] = true;
        edg_count++;
        for (int i = 0; i < v_num; ++i) {
            if (ved[i]) {
                for (int j = verts[i]; j < verts[i + 1]; ++j) {
                    if (dist[j] > edges[j].weight) {
                        dist[j] = edges[j].weight;
                    }
                }
            }
        }
    }
}

int main() {
    cin >> v_num >> e_num;
    verts.resize(v_num + 1);
    pre_init(pres, ved, v_num);
    edges = new _edg_[e_num];
    for (int i = 0; i <= v_num; ++i) {
        cin >> verts[i];
    }

    dist.resize(e_num, 1e6);

    for (int i = 0; i < e_num; ++i) {
        cin >> edges[i].end;
    }

    for (int i = 0; i < e_num; ++i) {
        cin >> edges[i].weight;
    }

    for (int i = 1; i <= v_num; ++i) {
        for (int j = verts[i - 1]; j < verts[i]; ++j) {
            edges[j].start = (i - 1);
            addedg(edges[j].start, edges[j].end, edges[j].weight);
        }
        sort(edges + verts[i - 1], edges + verts[i], cmp);
    }
    prim();

    int res = 0;
    for (int i = 0; i < tree.size(); ++i) {
        cout << "[" << tree[i].start << "->" << tree[i].end << "]";
        res += tree[i].weight;
    }
    cout << " " << res << endl;

    return 0;
}