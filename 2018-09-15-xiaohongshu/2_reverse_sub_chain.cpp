#include <iostream>

#include <vector>

using namespace std;

/*
题目：
    给出一个链表，每 k 个节点一组进行翻转，并返回翻转后的链表。
    k 是一个正整数，它的值小于或等于链表的长度。
    如果节点总数不是 k 的整数倍，那么将最后剩余节点保持原有顺序。
    说明：
        1. 你需要自行定义链表结构，将输入的数据保存到你的链表中；
        2. 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换；
        3. 你的算法只能使用常数的额外空间。
输入：
    第一行输入是链表的值；
    第二行输入是 k 的值，k 是大于或等于1的整数；
示例：
    输入：
        1 2 3 4 5
        2
    输出：
        2 1 4 3 5
*/

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

class Solution
{
public:
    void reverseSubChain(int k, int len, ListNode * head)
    {
        if (len <= 1)
            return;
        if (len < k)
            return;
        int num = len / k;
        ListNode * pre_head = NULL;
        ListNode * head_tmp = head;
        ListNode * rear_tmp = NULL;
        ListNode * rear_next = NULL;
        for (int i = 0; i < num; i++)
        {
            rear_tmp = head_tmp;
            for (int i = 1; i < k; i++)
                rear_tmp = rear_tmp->next;
            rear_next = rear_tmp->next;
            help(pre_head, head_tmp, rear_tmp, rear_next);
            pre_head = head_tmp;
            head_tmp = rear_next;
        }
    }
private:
    void help(ListNode * pre_head, ListNode * head, ListNode * rear, ListNode * rear_next)
    {
        if (NULL == head)
            return;
        ListNode * read_tmp = head;
        ListNode * rear_tmp = head;
        while(read_tmp != rear)
        {
            ListNode * tmp = read_tmp;
            read_tmp = read_tmp->next;
            tmp->next = head;
            head = tmp;
        }
        if (NULL != read_tmp)
        {
            read_tmp->next = head;
            head = read_tmp;
        }
        
        if (NULL != pre_head)
        {
            pre_head->next = head;
        }
        rear_tmp = rear_next;
    }
};

int main()
{
    Solution solution;
    int val;
    cin >> val;
    ListNode * head = new ListNode(val);
    int len = 1;
    ListNode * preNode = head;
    while(getchar() != '\n')
    {
        len++;
        cin >> val;
        ListNode * newNode = new ListNode(val);
        preNode ->next = newNode;
        preNode = newNode;
    }
    
    int k;
    cin >> k;
    solution.reverseSubChain(k, len, head);

    ListNode * tmp = head;
    while(NULL != tmp)
    {
        cout << tmp->val <<" ";
        tmp = tmp->next;
    }
    cout << endl;

    return 0;
}