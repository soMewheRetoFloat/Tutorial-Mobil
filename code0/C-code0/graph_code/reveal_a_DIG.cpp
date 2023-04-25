#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int edge_sum = 0, node_sum = 0;

struct _edge {
    int start;
    int end;
    int weight;
};

struct ListNode {
    int end;
    int weight;
    int edge_val;
    ListNode* next; 
};


int main () {
    cin >> node_sum >> edge_sum;
    vector<_edge> table(edge_sum, {0, 0, 0});
    
    for (int idx = 0; idx < edge_sum; ++idx) {
        cin >> table[idx].start >> table[idx].end >> table[idx].weight;
    }
    //初始化完成

    //part1 邻接矩阵
    vector<vector<int>> matrix(node_sum + 1, vector<int>(node_sum + 1, 0));
    for (int idx = 0; idx < edge_sum; ++idx) {
        int ru = table[idx].start, chu = table[idx].end, 
        w = table[idx].weight;

        if (matrix[ru][chu] == -1) continue;

        if (matrix[ru][chu] != 0) {
            matrix[ru][chu] = -1;
        }
        else
        matrix[ru][chu] = w;
    }

    for (int i = 1; i <= node_sum; ++i) {
        for (int j = 1; j <= node_sum; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    //part2 邻接表
    
    vector<ListNode> visit(node_sum + 1, {0, 0, 0, nullptr});
    vector<ListNode> all(edge_sum);
    for (int idx = 0; idx < edge_sum; ++idx) {

        all[idx].weight = table[idx].weight;
        all[idx].end = table[idx].end; 
        //以上两个都是直接赋值
        all[idx].edge_val = idx + 1;
        //边的序号
        all[idx].next = visit[table[idx].start].next;
        ListNode *tmp = &all[idx]; 
        visit[table[idx].start].next = tmp;
        //插入链表中
    }

    for (int i = 1; i <= node_sum; ++i) {
        if (visit[i].next)
        cout << visit[i].next -> edge_val << endl;
        else cout << 0 << endl;
    }

    for (int i = 0; i < edge_sum; ++i) {
        cout << all[i].end << " " 
        << all[i].weight << " ";
        if (all[i].next)
        cout << all[i].next -> edge_val << endl;
        else cout << 0 << endl;
    }

    return 0;
}