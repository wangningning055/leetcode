#include<iostream>
#include<vector>
#include "head.h"
#include "math.h"
using namespace std;
class LinkListNode{
	public:
		int val;
		int length;
		LinkListNode* next;
		LinkListNode(int value): val(value), next(NULL){}
		~LinkListNode(){cout << "销毁" << endl;}
};
void ErgodicNodeList(LinkListNode *headNode)
{
	LinkListNode *currentNode = headNode->next;
	for(int i = 0; i < headNode->length; i++)
	{
		cout<< "node value is  " << currentNode->val << endl;
		currentNode = currentNode->next;
	}
}
void DeleteNodeList(LinkListNode *headNode)
{
	LinkListNode *nextNode = headNode->next;
	for(int i = 0; i < headNode->length; i++)
	{
		LinkListNode *currentNode = nextNode;
		nextNode = nextNode -> next;
		delete currentNode;
	}
	delete nextNode;
}
void AddNode(LinkListNode *headNode, int pos, int value)
{
	if(pos < 0) return;
	if(pos > headNode->length) pos = headNode->length;
	LinkListNode *currentNode = headNode;
	for(int i = 0; i < headNode->length; i++)
	{
		if(i == pos)
		{
			LinkListNode *newNode = new LinkListNode(value);
			newNode->next = currentNode->next;
			currentNode->next = newNode;
		}
		currentNode = currentNode->next;
		currentNode->length++;
	}
	headNode->length++;
}
void DeleteNode(LinkListNode *headNode, int pos)
{
	if(pos < 0) return;
	if(pos > headNode->length) pos = headNode->length;
	LinkListNode *currentNode = headNode;
	for(int i = 0; i < headNode->length; i++)
	{
		if(i == pos)
		{
			LinkListNode *deleteNode = currentNode->next;
			currentNode->next = deleteNode->next;
			delete deleteNode;
		}
		currentNode = currentNode->next;
		if(currentNode != 0)
			currentNode->length--;
	}
	headNode->length--;
}
void ReverseNodeList(LinkListNode *headNode)
{
	LinkListNode *curNode = headNode->next;
	LinkListNode *nextNode = curNode->next;
	curNode->next = NULL;
	for(int i = 1; i < headNode->length; i++)
	{
		LinkListNode *preNode = nextNode->next;
		nextNode->next = curNode;

		curNode = nextNode;
		nextNode = preNode;
	}
	headNode->next = curNode;
}
void ExchangeNeghibor(LinkListNode *headNode)
{
	LinkListNode *firstNode = headNode->next;
	LinkListNode *secNode = firstNode->next;
	headNode->next = secNode;
	for(int i = 0; i < (headNode->length) / 2; i++)
	{
		LinkListNode *preNode = secNode->next;
		firstNode->next = preNode == 0? NULL: preNode->next;
		secNode->next = firstNode;

		firstNode = preNode;
		secNode = firstNode == NULL? NULL: firstNode->next;
	}
}
int GetBackIndex(LinkListNode *headNode, int index)
{
	LinkListNode *curNode = headNode->next;
	LinkListNode *frontNode = headNode->next;
	for(int i = 0; i < headNode->length; i++)
	{
		if(i > index)
			frontNode = frontNode->next;
		curNode = curNode->next;
	}
	return frontNode->val;
}
//相交链表
void IntersectList(LinkListNode *head1, LinkListNode *head2)
{
	int linkALength = 0;
	int linkBLength = 0;

	LinkListNode *nextNode = head1->next;
	while(nextNode != 0)
	{
		linkALength++;
		nextNode = nextNode->next;
	}
	nextNode = head2->next;
	while(nextNode != 0)
	{
		linkBLength++;
		nextNode = nextNode->next;
	}
	cout << "长度为" << linkALength << "    " << linkBLength << endl;
	LinkListNode *longNode = (linkALength > linkBLength)? head1 : head2;
	LinkListNode *shotNode = (linkALength <= linkBLength)? head1 : head2;
	int i = 0;
	while(longNode->next != 0)
	{
		if(i >= abs(linkALength - linkBLength) && shotNode->next != 0)
		{
			if(shotNode == longNode)
			{
				cout << "有焦点: " << shotNode->val << endl;
				return;
			}
			shotNode = shotNode->next;
		}
		i++;
		longNode = longNode->next;
	}
}
//环形链表
void CircleLinkList(LinkListNode *head)
{
	LinkListNode *slowNode = head->next;
	LinkListNode *longNode = head->next;
	int i = 0;
	while(slowNode != longNode || i == 0)
	{
		i++;
		if(longNode->next == 0 || longNode->next->next == 0)
		{
			cout<< "不是环形链表" << endl;
			return;
		}
		slowNode = slowNode->next;
		longNode = longNode->next->next;
	}
	cout << i << endl;
	cout << (slowNode == longNode) << "   " << slowNode->val <<  endl;
	slowNode = head->next;
	i = 0;
	while (slowNode != longNode)
	{
		i++;
		slowNode = slowNode->next;
		longNode = longNode->next;
	}
	
	cout << "是环形 : " << i << endl;

}
// int main()
// {
// 	// vector<int> vectorTest = {3,3,3,1,2,1,1,2,3,3,4};
// 	LinkListNode headNode = LinkListNode(-1);
// 	headNode.length = 10;
// 	LinkListNode *lastNode = &headNode;
// 	for(int i = 0; i < 10; i++)
// 	{
// 		LinkListNode *node = new LinkListNode(i);
// 		node->length = 10;
// 		lastNode->next = node;
// 		lastNode = lastNode->next;
// 	}

// 	LinkListNode headCircleNode = LinkListNode(-1);
// 	LinkListNode *middleNode;
// 	lastNode = &headCircleNode;
// 	for(int i = 0; i < 10; i++)
// 	{
// 		LinkListNode *node = new LinkListNode(i);
// 		node->length = 10;
// 		lastNode->next = node;
// 		if(i == 3)
// 		{
// 			middleNode = node;
// 		}
// 		lastNode = lastNode->next;
// 	}
// 	lastNode->next = middleNode;
// 	CircleLinkList(&headCircleNode);
// 	//ergodic
// 	// ErgodicNodeList(&headNode);
// 	// cout << "ergoEnd" << endl;
// 	//add
// 	// AddNode(&headNode, 8, 100);1 2 3 4  2 1 4 3
// 	// ErgodicNodeList(&headNode); 1 2 3 4 5   2 1 4 3

// 	//delete
// 	// DeleteNode(&headNode, 0);
// 	// ErgodicNodeList(&headNode);

// 	//reverse
// 	// ReverseNodeList(&headNode);
// 	// ErgodicNodeList(&headNode);

// 	//exchange neighbor
// 	// ExchangeNeghibor(&headNode);
// 	// ErgodicNodeList(&headNode);

// 	//getbackIndex
// 	// cout << GetBackIndex(&headNode, 0) << endl;

// 	//deleteList
// 	DeleteNodeList(&headNode);
// }