#include <stdlib.h>
#include <stdio.h>

struct ListNode {
	int val;
	struct ListNode *next;
};
int calculateLength(struct ListNode * p)
{
	int i = 0;
	while (p!=NULL)
	{
		i++;
		p = p->next;
	}
	return i;
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	int lenth1 = calculateLength(l1);
	int lenth2 = calculateLength(l2);
	int length = 0;
	int sum = 0;
	int carry = 0;
	int i = 0;
	struct ListNode * head = NULL;
	struct ListNode * t = NULL;
	if (lenth1 < lenth2)  // l2: max length
	{
		t = l1;
		l1 = l2;
		l2 = t;
	}

	head = l1;

	while (l2!=NULL)
	{
		sum = l1->val + l2->val + carry;
		l1->val = sum % 10;
		carry = sum / 10;
		l1 = l1->next;
		l2 = l2->next;
	}

	while (l1 != NULL)
	{
		if (carry == 0)
		{
			break;
		}
		else
		{
			sum = l1->val + carry;
			l1->val = sum % 10;
			carry = sum / 10;
			l1 = l1->next;
		}
	}

	if (0 != carry)
	{
		l1 = head;
		length = calculateLength(head);
		i = 1;
		for (; i < length; i ++)
		{
			l1 = l1->next;
		}
		l1->next = (struct ListNode *)malloc(sizeof(struct ListNode));
		l1 = l1->next;
		l1->next = NULL;
		l1->val = carry; 
		printf("%d---\n", l1->val);
		carry = 0;
	}


	return head;

}

void DisplayLink(struct ListNode * p)
{
	while (p!= NULL)
	{
		printf("%d--->", p->val);
		p = p->next;
	}

}

int _tmain(int argc, _TCHAR* argv[])
{
	struct ListNode l1[4] = { 0 };
	l1[0].val = 5;
	l1[0].next = &l1[1];
	l1[1].val = 3;
	l1[1].next = &l1[2];
	l1[2].val = 6;
	l1[2].next = &l1[3];
	l1[3].val = 9;
	struct ListNode l2[3] = { 0 };
	l2[0].val = 9;
	l2[0].next = &l2[1];
	l2[1].val = 3;
	l2[1].next = &l2[2];
	l2[2].val = 8;
	DisplayLink(addTwoNumbers(l2, l1));

	return 0;
}
