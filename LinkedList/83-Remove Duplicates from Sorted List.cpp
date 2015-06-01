#include <iostream>
#include <map>

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
	ListNode* deleteDuplicates(ListNode* head);

	struct ListNode * GetHead();

	Solution(int * p, int length);

	void DisPlayNode(ListNode * head);
};

ListNode * Solution::deleteDuplicates(ListNode* head)
{
	struct ListNode * pNode = head;
	struct ListNode * qNode = NULL;
	map<int, int> data;
	map<int, int>::iterator itor;
	int i=0;
	if (pNode!=NULL)
	{
		data.insert(map<int,int>::value_type(pNode->val, pNode->val)); // head->val store

		while (pNode->next != NULL)
		{
			itor = data.find(pNode->next->val);
			if (itor == data.end()) //no find, it is a new value
			{
				data.insert(map<int,int>::value_type(pNode->next->val, pNode->next->val));
				pNode = pNode->next;
			} 
			else   
			{
				qNode = pNode->next;
				pNode->next = qNode->next;
				qNode->next = NULL;
			}
		}
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
	int data[5] = {1,1,2,3,3};
	Solution solution(data,5);
	// 	int data[2] = {1,2};
	// 	Solution solution(data,2);
	//int data = 1;
	//Solution solution(&data, 1);
	solution.DisPlayNode(solution.GetHead());
	cout << "-------------Between-------------" << endl;
	struct ListNode * p = solution.deleteDuplicates(solution.GetHead());
	solution.DisPlayNode(p);
	return 0;
}
