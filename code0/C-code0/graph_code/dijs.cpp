#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;
vector<string> res;
vector<int> path_len;
vector<int> pre;
stack<int> tmp_res;

struct _edge_
{
    int weight;
    int sum;
};

/*
bool check_empty(const vector<bool> &ved) {
    for (int i = 0; i < ved.size(); ++i) {
        if (!ved[i]) return false;
    }
    return true;
}
*/

void dijs(int start, int end, vector<bool> &ved, const vector<int> &vert, const vector<_edge_> &edge) {
    path_len[start] = 0;
    ved[start] = true;
    int tmp_min = INT32_MAX - 1, cur = start, prex = start;
    for (int i = vert[cur]; i < vert[cur + 1]; ++i) {
        path_len[edge[i].sum] = edge[i].weight;
        pre[edge[i].sum] = start;
    }

    while(true) { //(2)
        for (int i = 0; i < ved.size(); ++i) {
            if(ved[i]) continue;
            if (path_len[i] < tmp_min) {
                cur = i;
                tmp_min = path_len[i];
            }
        }

        ved[cur] = true;
        if (prex == cur) {
            break;
        }

        for (int i = vert[cur]; i < vert[cur + 1]; ++i) { //(3)
            int tmp_sum = edge[i].sum;
            if((edge[i].weight + path_len[cur] < path_len[tmp_sum]) && !ved[tmp_sum]) {
                path_len[tmp_sum] = edge[i].weight + path_len[cur];
                pre[tmp_sum] = cur;
            }
        }
        tmp_min = INT32_MAX - 1;
        prex = cur;
    }
    if (pre[end] == -1) {
        res.push_back("NO PATH");
        return;
    }
    else {
        int tc = end;
        while(tc != start) {
            tmp_res.push(tc);
            tc = pre[tc];
        }
        tmp_res.push(start);
        string s = "[";
        while (!tmp_res.empty()) {
            int rhs = tmp_res.top();
            tmp_res.pop();
            s += to_string(rhs);
            if (!tmp_res.empty()) {
                s += "->";
            }
        }
        s += " ";
        s += to_string(path_len[end]);
        s += "]";
        res.push_back(s);
    }
}

int v_sum, e_sum, solute;

int main() {
    cin >> v_sum >> e_sum;
    vector<int> vert(v_sum + 1, 0);
    vector<bool> ved(v_sum, false);
    vector<_edge_> edge(e_sum);
    path_len.resize(v_sum, INT32_MAX - 1);
    pre.resize(v_sum, -1);
    for (int i = 0; i <= v_sum; ++i) {
        cin >> vert[i];
    }
    for (int i = 0; i < v_sum; ++i) {
        for (int j = vert[i]; j < vert[i + 1]; ++j) {
            cin >> edge[j].sum;
        }
    }
    for (int i = 0; i < v_sum; ++i) {
        for (int j = vert[i]; j < vert[i + 1]; ++j) {
            cin >> edge[j].weight;
        }
    }
    cin >> solute;
    while (solute--) {
        int start, end;
        cin >> start >> end;
        dijs(start, end, ved, vert, edge);
        for (int i = 0; i < v_sum; ++i) {
            ved[i] = false;
            path_len[i] = INT32_MAX - 1;
            pre[i] = -1;
        }
    }

    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << endl;
    }
    return 0;
}