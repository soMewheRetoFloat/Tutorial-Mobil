#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <sstream>
using namespace std;

struct edg {
    int weight;
    int init_end;
    edg* nxt = nullptr;
};

struct mad {
    edg* ed;
    int init_sum;
};

struct graph {
    vector<mad> src; //初始图
    vector<int> into; //初始入度，要动
    vector<int> into2; //初始入度，不动
    vector<int> time; //点耗时
    vector<int> topo; //拓扑排序的PT顺序
    vector<int> max_pi; //正向路径
    vector<int> re_pi; //反向路径
    vector<vector<int>> pre; //前驱，index为顺序
    vector<int> path; //一条关键
    vector<vector<int>> res; //所有关键
    vector<int> delay; //可以延迟的时间
    int ress; //路径长度
};
graph G;
int n;


void graph_init(graph& G, int n) {
    G.src.resize(n + 2);
    G.into.resize(n + 2);
    G.into2.resize(n + 2);
    G.time.resize(n + 2);
    G.pre.resize(n + 2);
    G.max_pi.resize(n + 2);
    G.re_pi.resize(n + 2);
    G.delay.resize(n + 2);
    for (int i = 0; i < n + 2; ++i) {
        G.src[i].ed = nullptr;
        G.src[i].init_sum = i;
        G.max_pi[i] = 0;
        G.re_pi[i] = 0;
        G.into[i] = 0;
        G.into2[i] = 0;
        G.time[i] = 0;
        G.pre[i] = {};
    }
    G.topo.resize(n + 2);
}

void addedg1(graph& G, int cur, int pre) {
    G.into[cur]++;
    G.into2[cur]++;
    edg* tmp = new edg;
    tmp -> init_end = cur;
    tmp -> weight = 0;
    tmp -> nxt = G.src[pre].ed;
    G.src[pre].ed = tmp;
}
/*
void addedg2(graph& G, int cur, int pre, int pretend) {
    G.into[cur]++;
    edg* tmp = new edg;
    tmp -> end = cur;
    tmp -> weight = G.time[pretend];
    tmp -> nxt = G.dst[pre].ed;
    G.dst[pre].ed = tmp;
}
*/
void give_wei(graph& G, int n) {
    for (int i = 0; i < n; ++i) {
        if (G.into[i] == 0) {
            addedg1(G, i, n);
        }
        else if (!G.src[i].ed) {
            addedg1(G, n + 1, i);
        }
    }
    for (int i = 0; i < n + 1; ++i) {
        edg* tmp = G.src[i].ed;
        while (tmp) {
            tmp -> weight = G.time[i];
            tmp = tmp -> nxt;
        }
    }
}

void dst_init(graph& G, int n) { //开始做pt构建吧
    queue<int> q;
    int tt = 0;
    for (int i = 0; i < n + 2; ++i) {
        if (G.into[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        G.topo[tt] = x;
        ++tt;
        edg* tmp_edg = G.src[x].ed;
        while (tmp_edg) {
            int e = tmp_edg -> init_end;
            G.into[e]--;
            if (G.into[e] == 0) {
                q.push(e);
            }
            tmp_edg = tmp_edg -> nxt;
        }
    }
}

void outx(graph&, int, int);

void path_counting(graph& G, int n) {
    for (int i = 0; i < n + 1; ++i) {
        int k = G.topo[i];
        edg* tmp_edg = G.src[k].ed;
        while (tmp_edg) {
            int j = tmp_edg -> init_end;
            if (G.max_pi[j] == G.max_pi[k] + tmp_edg -> weight) {
                G.pre[j].push_back(k);
            }
            else if (G.max_pi[j] < G.max_pi[k] + tmp_edg -> weight) {
                G.pre[j].clear();
                G.max_pi[j] = G.max_pi[k] + tmp_edg -> weight;
                G.pre[j].push_back(k);
            }
            tmp_edg = tmp_edg -> nxt;
        }
    }

    G.ress = G.max_pi[n + 1];

    for (int i = 0; i < n + 2; ++i) {
        G.re_pi[i] = G.ress;
    }
    for (int i = n; i > -1; --i) {
        int k = G.topo[i];
        edg* tmp_edg = G.src[k].ed;
        while (tmp_edg) {
            int j = tmp_edg -> init_end;
            if (G.re_pi[k] > G.re_pi[j] - tmp_edg -> weight) {
                G.re_pi[k] = G.re_pi[j] - tmp_edg -> weight;
            }
            tmp_edg = tmp_edg -> nxt;
        }
    }

    for (int i = 0; i < n + 2; ++i) {
        G.delay[i] = G.re_pi[i] - G.max_pi[i];
    }

    outx(G, n + 1, n);

    cout << G.ress << endl;
    for (int i = G.res.size() - 1; i > -1; --i) {
        cout << "[";
        for (int j = G.res[i].size() - 2; j > -1; --j) {
            cout << G.res[i][j] << "->";
        }
        cout << "end]" << endl;
    }

    for (int i = 0 ; i < n; ++i) {
        cout << G.delay[i] << endl;
    }
}

void outx(graph& G, int pos, int n) {
    if (pos == n) {
        G.res.push_back(G.path);
    }
    for (int i = 0; i < G.pre[pos].size(); ++i) {
        int p = G.pre[pos][i];
        G.path.push_back(p);
        outx(G, p, n);
        G.path.pop_back();
    }
}

int main() {
    cin >> n;
    graph_init(G, n);
    int st = 0, we = 0;
    int xxx = n;
    while(xxx--) {
        cin >> st >> we;
        G.time[st] = we;
        if (getchar() == '\n') continue;
        vector<int> vectmp;
        vectmp.clear();
        string stmp;
        cin >> stmp;
        replace(stmp.begin(), stmp.end(), ',', ' ');
        stringstream ss;
        ss << stmp;
        int itmp;
        while (ss >> itmp) {
            vectmp.push_back(itmp);
        }
        for (int i = 0; i < vectmp.size(); ++i) {
            addedg1(G, st, vectmp[i]);
        }
    }

    give_wei(G, n);
    dst_init(G, n);
    path_counting(G, n);
    return 0;
}