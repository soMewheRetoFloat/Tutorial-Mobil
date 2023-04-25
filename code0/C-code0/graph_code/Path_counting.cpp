#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int fix_start, fix_end, node_sum, edge_sum, total;

int matrix[110][110];
int res[110][110];

void multi(int matrix[110][110], int res[110][110], int node_sum) {
    int tmp = 0;
    for (int i = 1; i <= node_sum; ++i) {
        for (int j = 1; j <= node_sum; ++j) {
            for (int k = 1; k <= node_sum; ++k) {
                tmp += res[j][i] * matrix[i][k];
            }
            tmp %= 1000003;
            res[i][j] = tmp;
            tmp = 0;
        }
    }
}


int main() {
    cin >> node_sum >> edge_sum 
    >> fix_start >> fix_end >> total;
    int tmps, tmpe;
    for (int i = 0; i < edge_sum; ++i) {
        cin >> tmps >> tmpe;
        ++matrix[tmps][tmpe];
        ++res[tmps][tmpe];
    }
    total -= 2;
    while(--total) {
        multi(matrix, res, node_sum);
    }

    cout << (res[fix_start][fix_end] % 1000003) << endl;
    return 0;
}
