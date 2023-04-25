#include <bits/stdc++.h>
using namespace std;
const int MAX_VERTEX_NUM = 100; //图论常数

//有向图部分
struct _Edge { //边
    string _info_;
    int _vert_start, _vert_end; //start和end顾名思义
    struct _Edge* next_same_start, *next_same_end; //next_same_start存储一条同起点的边地址，next_same_end存储一条同终点的边地址
};

struct Vert { //结点
    string _info_;
    _Edge* _edge_in; //_edge_in_是最后录入的入边
    _Edge* _edge_out; //_edge_out_是最后录入的出边
};

typedef struct oLGraph { //有向图框架
   Vert xlist[MAX_VERTEX_NUM]; //顶点结点(表头向量)      
   int vertnum, edgenum; //有向图的当前顶点数和边数
} OL_Graph; //OLGraph为别名

void CreatDG(OL_Graph &G) {
    cin >> (G.vertnum) >> (G.edgenum);
    for (int i = 0; i < G.vertnum; ++i) { //初始化每条边
        cin >> (G.xlist[i]._info_);
        G.xlist[i]._edge_in = G.xlist[i]._edge_out = NULL;
    }
    for (int i = 0; i < G.edgenum; ++i) {
        int st, en;
        //2个暂时的参数
        cin >> st >> en;
        _Edge* tmp = new _Edge;
        //分配一块新内存放十字表
        tmp -> _vert_start = st;
        //传参
        tmp -> _vert_end = en;
        //传参
        tmp -> next_same_start = G.xlist[st]._edge_out;
        //同一条起点的边直接找起点的出边
        tmp -> next_same_end = G.xlist[en]._edge_in;
        //同一条终点的边直接找终点的入边
        G.xlist[st]._edge_out = tmp;
        //这条边的起点的最新出边更新为这条边
        G.xlist[en]._edge_in = tmp;
        //这条边的终点的最新入边更新为这条边
    }
} //创建有向图

//无向图就简单多了，不分出入边

struct Dirless_Edge { //边
	string _info_;
	int _vert_a, _vert_b; // a与b两头分别是两个点
	struct Dirless_Edge *_a_link, *_b_link; //每个头的link指向依附于其的下一条边
	
};

struct Dirless_Vert { //结点
	string _info_;
	Dirless_Edge* next; //next指最新更新的依附边
};

typedef struct UgGraph { //无向图框架
	Dirless_Vert Vert_List[MAX_VERTEX_NUM]; //顶点结点(表头边)
	int vertnum, edgenum; //无向图的当前顶点数和边数
} UG_Graph;

void CreateUG(UG_Graph &G) {
	for (int i = 0; i < G.vertnum; ++i) {
		cin >> (G.Vert_List[i]._info_);
		G.Vert_List[i].next = NULL;
	}
	for (int i = 0; i < G.edgenum; ++i) {
		Dirless_Edge *tmp = new Dirless_Edge;
		int a, b;
		//左右点
		cin >> a >> b;
		//传参
		tmp -> _vert_a = a;
		//标记a点
		tmp -> _vert_b = b;
		//标记b点
		tmp -> _a_link = G.Vert_List[a].next;
		tmp -> _b_link = G.Vert_List[b].next;
		//加入依附边链表
		G.Vert_List[b].next = tmp;
		G.Vert_List[b].next = tmp;
		//更新最新依附边
	}
} //创建无向图

int main () {
	return 0;
}