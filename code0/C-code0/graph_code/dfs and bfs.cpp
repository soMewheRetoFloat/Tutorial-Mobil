#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAX_VERTEX_NUM = 200010;

int start_point; //全场唯一真起始点
vector<int> res; //存储bfs的结果
vector<int> res_dfs; //存储dfs的结果
vector<int> path;
vector<int> path2;

struct Edge {
    int end; //终点
    Edge* next; //下一个
};

struct OLGraph {
    int vert_num, edge_num; //顾名思义
    Edge* xlist[MAX_VERTEX_NUM]; //联接表头
};

OLGraph G = {0, 0, {}};

void AddEdge(int x, int y, OLGraph &G) {
    Edge *tmp = new Edge;
    tmp -> end = y;
    tmp -> next = G.xlist[x];
    G.xlist[x] = tmp;
}

vector<int> bfs(OLGraph &G, int start) {
    path.clear();
    vector<bool> ved(G.vert_num + 1, false);
    ved[start] = true;

    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        path.push_back(cur);
        Edge* tmp = G.xlist[cur];
        while (tmp) {
            int pro = tmp -> end;
            if (!ved[pro]) {
                ved[pro] = true;
                q.push(pro);
            }
            tmp = tmp -> next;
        }
    }

    return path;
}

void dfs(OLGraph &G, int cur, vector<bool>& ved) {
    
    if (path2.size() == G.vert_num) {
        res_dfs = path2;
        return;
    }
    if (ved[cur]) {
        return;
    }

    Edge* cur_node = G.xlist[cur];

    ved[cur] = true;
    path2.push_back(cur);
    for (; cur_node && !res_dfs.size(); cur_node = cur_node -> next) {
        dfs(G, cur_node -> end, ved);
    }
}


int main() {
    cin >> G.vert_num >> G.edge_num >> start_point;
    int sx, ex;
    for (int i = 1; i <= G.edge_num; ++i) {
        cin >> sx >> ex;
        AddEdge(sx, ex, G);
    }

    res = bfs(G, start_point);
    for (int i = 0; i< res.size(); ++i) {
        cout << res[i] << " ";
    } cout << endl;

    path2.clear();
    vector<bool> vedd(G.vert_num + 1, false);

    dfs(G, start_point, vedd);
    for (int i = 0; i< res_dfs.size(); ++i) {
        cout << res_dfs[i] << " ";
    } cout << endl;

    return 0;
}