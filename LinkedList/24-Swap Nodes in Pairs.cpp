#include <iostream>
#include <vector>

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
	ListNode* swapPairs(ListNode* head);

	struct ListNode * GetHead();

	Solution(int * p, int length);

	void DisPlayNode(ListNode * head);
};

ListNode* Solution::swapPairs(ListNode* head)
{
	struct ListNode * pNode = head;
	vector<int> data;
	while (pNode!= NULL)
	{
		if (pNode->next != NULL)
		{
			data.push_back(pNode->next->val);
			data.push_back(pNode->val);
			pNode = pNode->next->next;
		} 
		else
		{
			data.push_back(pNode->val);
			pNode = pNode->next;
		}
	}
	
	pNode = head;
	int i = 0;
	while (pNode!=NULL)
	{
		pNode->val = data[i++];
		pNode = pNode->next;
	}
	return head;
}

Solution::Solution(int *p, int length)
{
	struct ListNode * tail;
	int i;
	this->m_head = NULL;
	for (i=0; i<length; i++)
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
	while (head!=NULL)
	{
		cout << head->val << "---";
		head = head->next;
	}
	cout << endl;
}

int main()
{
	int data[5] = {1,2,3,4,5};
	Solution solution(data,5);
	// 	int data[2] = {1,2};
	// 	Solution solution(data,2);
	//int data = 1;
	//Solution solution(&data, 1);
	solution.DisPlayNode(solution.GetHead());
	cout << "-------------Between-------------" << endl;
	struct ListNode * p = solution.swapPairs(solution.GetHead());
	solution.DisPlayNode(p);
	return 0;
}
