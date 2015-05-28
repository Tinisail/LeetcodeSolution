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
	ListNode* removeElements(ListNode* head, int val);

	struct ListNode * GetHead();

	Solution(int * p, int length);

	void DisPlayNode(ListNode * head);
};

ListNode * Solution::removeElements(ListNode* head, int val)
{
	struct ListNode * former = NULL, *pNode = head;
	while (pNode!=NULL)
	{
		if (pNode==head && pNode->val == val)
		{
			head = head->next;
			pNode->next = NULL;
			pNode = head;
		} 
		else
		{
			if (pNode == head)
			{
				former = pNode;
				pNode = pNode->next;
			}

			if (pNode->val == val)
			{
				former->next = pNode->next;
				pNode->next = NULL;
				pNode = former->next;
			} 
			else
			{
				former = pNode;
				pNode = former->next;
			}
		}
	}
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

	solution.DisPlayNode(solution.GetHead());

	cout << "--------Between---------" << endl;

	ListNode *  p = solution.removeElements(solution.GetHead(), 1);
	solution.DisPlayNode(p);
	//	system("pause");
	return 0;
}
