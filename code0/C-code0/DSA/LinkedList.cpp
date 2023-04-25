#include <bits/stdc++.h>
using namespace std;

class MyLinkedList {
 public:
	struct ListNode { //基本结构
    	int val;
	    ListNode *next;
    	ListNode(int x) : val(x), next(NULL) {} //数据结构定义
	};

	MyLinkedList() { //初始化
		_dummyhead = new ListNode(0);
	}

	void NoteAddHead(int val) { //头部加元素
		ListNode* new1 = new ListNode(val);
		new1 -> next = _dummyhead -> next;
		_dummyhead -> next = new1;
		_size++;
	}

	void NoteAddTail(int val) { //尾部加元素
		ListNode* new1 = new ListNode(val);
		ListNode* cur = _dummyhead;
		while (cur -> next != nullptr) {
			cur = cur -> next;
		}
		cur -> next = new1;
		new1 -> next = NULL;
		_size++;
	}

	void NodeDel(int id) { //删
		if(id > _size || id < 0) return;
		ListNode* cur = _dummyhead;
		while (id--) {
			cur = cur -> next;
		}
		ListNode* temp =cur -> next;
		cur -> next = cur -> next -> next;
		delete temp;
		_size--;
	}

	void NodeAdd(int id, int val) { //中间加
		if(id > _size || id<0) return;
		ListNode* new1 = new ListNode(val);
		ListNode* cur = _dummyhead;
		while (id--) {
			cur = cur -> next;
		}
		new1 -> next = cur -> next;
		cur -> next = new1;
		_size++;
	}

	void ListPrint() { //打印链表
		ListNode* cur = _dummyhead;
		while (cur -> next != nullptr) {
			cout<<cur -> next -> val<<" ";
			cur = cur -> next;
		}
		cout<<endl;
	}

	ListNode* reverseListNode(ListNode* head) { //反转链表
    	ListNode* temp;
    	ListNode* cur = head;
    	ListNode* pre = NULL;
    	while (cur) {
    	    temp = cur -> next;
    	    cur -> next = pre;
    	    pre = cur;
    	    cur = temp;
    	}
    	return pre;
	}

	ListNode* swap(ListNode* head) { //两两交换
    	ListNode* dummyhead = new ListNode(0);
    	dummyhead -> next = head;
    	ListNode* cur = dummyhead;
    	while (cur -> next != nullptr && cur -> next -> next != nullptr) {
    	    ListNode* temp1 = cur -> next;
    	    ListNode* temp2 = cur -> next -> next -> next;
    	    cur -> next = cur -> next -> next;
    	    cur -> next -> next = temp1;
    	    cur -> next -> next -> next = temp2;
    	    cur = cur -> next -> next;
    	}
    	return dummyhead->next;
	}

 private: //小维护
	int _size;
	ListNode* _dummyhead; 
};

int main() {
    return 0;
}