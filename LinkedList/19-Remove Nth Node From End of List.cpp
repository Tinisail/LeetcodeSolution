#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
private:
	struct ListNode * m_head;
public:
	ListNode* removeNthFromEnd(ListNode* head, int n);
	ListNode * reverseList(ListNode* head);

	struct ListNode * GetHead();

	Solution(int * p, int length);

	void DisPlayNode(ListNode * head);
};

ListNode * Solution::removeNthFromEnd(ListNode* head, int n)
{
	struct ListNode * former = NULL, *post = NULL;
	former = head;
	int length = 0;
	while (former != NULL)
	{
		length++;
		former = former->next;
	}

	int i = 0;
	former = post = head;
	if (n == length) // delete head
	{
		head = head->next;
		former->next = NULL;
	} 
	else
	{
		for (i = 0; i < (length - n - 1); i++)
		{
			former = former->next;
		}
		struct ListNode * p = former->next;
		post = former->next->next;
		former->next = post;
		p->next = NULL;
	}
	return head;

}

ListNode * Solution::reverseList(ListNode* head)
{
	struct ListNode *p, *q;
	p = head;
	q = head;
	while (q != NULL)
	{
		//Step1: get the first node and find the next node
		p = q;
		q = q->next;

		//Step2: link....
		if (p == head)
		{
			p->next = NULL;
		}
		else
		{
			p->next = head;
			head = p;
		}

	}
	this->m_head = head;
	return head;
}

Solution::Solution(int *p, int length)
{
	struct ListNode * tail = NULL;
	int i;
	this->m_head = NULL;
	for (i = 0; i < length; i++)
	{
		if (0 == i)
		{
			//m_head = &(ListNode::ListNode(p[i]));
			m_head = new ListNode(p[i]);
			m_head->next = NULL;
			tail = m_head;
		}
		else
		{
			//tail->next = &(ListNode::ListNode(p[i]));
			tail->next = new ListNode(p[i]);
			tail->next->next = NULL;
			tail = tail->next;

		}
	}

}

struct ListNode * Solution::GetHead()
{
	return this->m_head;
}

void Solution::DisPlayNode(ListNode * head)
{
	while (head != NULL)
	{
		cout << head->val << "---";
		head = head->next;
	}
	cout << endl;
}

int main()
{
	int data[3] = { 1, 2, 3 };
	Solution solution(data, 3);
	// 	int data[2] = {1,2};
	// 	Solution solution(data,2);
	//int data = 1;
	//Solution solution(&data, 1);
	solution.DisPlayNode(solution.GetHead());
	cout << "-------------Between-------------" << endl;
	struct ListNode * p = solution.reverseList(solution.GetHead());
	solution.DisPlayNode(p);

	p = solution.removeNthFromEnd(solution.GetHead(), 3);
	solution.DisPlayNode(p);
	system("pause");
	return 0;
}
