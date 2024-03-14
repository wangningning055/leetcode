#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include <string>
#include<limits.h>
#include<map>
using namespace std;

class TreeNode
{
	public:
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x): val(x), left(NULL), right(NULL){}
};
void Creat(TreeNode *node, vector<int>& treeNums, int i)
{
	if(i * 2 + 2 < treeNums.size()&& node != NULL)
	{
		TreeNode *left = treeNums[i * 2 + 1] == NULL? NULL : new TreeNode(treeNums[i * 2 + 1]);
		TreeNode *right = treeNums[i * 2 + 2] == NULL? NULL: new TreeNode(treeNums[i * 2 + 2]);
		node->left = left;
		node->right = right;
		Creat(left, treeNums, i * 2 + 1);
		Creat(right, treeNums, i * 2 + 2);
	}
}
TreeNode* CreatTree()
{
	// 			    20
	// 		16   	          29
	// 	12		  18         22		  31
	//11   13   17   19    21   23   30   35
	vector<int> treeNums1 = {20, 16, 29, 12, 18, 22, 31, 11, 13, 17, 19, 21, 23, 30, 35};


	// 			    20
	// 		16   	          29
	// 	12		16         22		  31
	//12   22   17   16    22   20   20   35
	vector<int> treeNums2 = {20, 16, 29, 12, 16, 22, 31, 12, 22, 17, 16, 22, 20, 20, 35};

	vector<int> treeNums = treeNums1;
	TreeNode *head = new TreeNode(treeNums[0]);
	Creat(head, treeNums, 0);
	return head;
}
TreeNode* CreatTree2()
{
	vector<int> treeNums = {6, 2, 8, 1, 4, NULL, NULL, NULL, NULL, 3, 5, NULL, NULL, NULL, NULL};
	TreeNode *head = new TreeNode(treeNums[0]);
	Creat(head, treeNums, 0);
	return head;
}
void FindFront(TreeNode *middle)
{
	cout << "nums: " << middle->val << endl;
	if(middle->left != NULL)
	{
		FindFront(middle->left);
	}
	if(middle->right != NULL)
	{
		FindFront(middle->right);
	}
}
void FindMiddle(TreeNode *middle)
{
	// 			    3
	// 		3 	 	          1
	// 	2		3         5		  7
	//2   7   9   3     6   8   2   4
	if(middle->left != NULL)
	{
		FindMiddle(middle->left);
		cout << "nums: " << middle->val << endl;
		FindMiddle(middle->right);
	}
	else
	{
		cout << "nums: " << middle->val << endl;
	}
}
void FindBehind(TreeNode *middle)
{
	if(middle->left != NULL)
	{
		FindBehind(middle->left);
		FindBehind(middle->right);
		cout << "nums: " << middle->val << endl;
	}
	else
	{
		cout << "nums: " << middle->val << endl;
	}
}
void FindFront2(TreeNode *node)
{
	// 			    3
	// 		3 	 	          1
	// 	2		3         5		  7
	//2   7   9   3     6   8   2   4
	stack<TreeNode*> st;
	st.push(node);
	while(!st.empty())
	{
		TreeNode* top = st.top();
		cout << "nums: " << top->val << endl;
		st.pop();
		if(top->right != NULL) st.push(top->right);
		if(top->left != NULL) st.push(top->left);

	}
}
void FindLevel(TreeNode *node)
{
	// 			    3
	// 		3 	 	          1
	// 	2		3         5		  7
	//2   7   9   3     6   8   2   4
	queue<TreeNode*> queue;
	queue.push(node);
	int deep = 0;
	while(!queue.empty())
	{
		int size = queue.size();
		deep++;

		for(int i = 0; i < size; i++)
		{
			TreeNode *node = queue.front();
			queue.pop();
			if(node != NULL)
			{
				cout << " " << node->val;
				if(node->left) queue.push(node->left);
				if(node->right) queue.push(node->right);
			}
		}

		cout << endl;
	}

}
void ReverseTreeRecur(TreeNode *node)
{
	// 			    3
	// 		1 	 	          3
	// 	3		2         7		  5
	//7   2   3   9     8   6   4   2
	TreeNode *temp = node->left;
	node->left = node->right;
	node->right = temp;
	// cout << node->val << endl;
	if(node->left != NULL)
		ReverseTreeRecur(node->left);
	if(node->right != NULL)
		ReverseTreeRecur(node->right);
}
bool AsemmetricalTree(TreeNode *nodeLeft, TreeNode *nodeRight)
{
	if(nodeLeft == NULL || nodeRight == NULL)
		return nodeLeft == nodeRight;
	int valLeft = nodeLeft->val;
	int valRight = nodeRight->val;
	if(valLeft != valRight)
	{
		return false;
	}
	AsemmetricalTree(nodeLeft->left, nodeRight->right);
	AsemmetricalTree(nodeLeft->right, nodeRight->left);
	return true;
}
void FindMostDeep(TreeNode *head)
{
	// 			    1
	// 		3 	 	          3
	// 	7		5         5		  7
	//4   7   8   6     6   8   7   4
	queue<TreeNode*> queue;
	queue.push(head);
	int deep = 0;
	while(!queue.empty())
	{
		deep++;
		int size = queue.size();
		for(int i = 0; i < size; i++)
		{
			TreeNode *node = queue.front();
			cout << " " << node->val ;
			queue.pop();
			if(node->left) queue.push(node->left);
			if(node->right) queue.push(node->right);
		}
		cout << endl;
	}
	cout << "deep is " << deep << endl;
}
int BalanceTree(TreeNode *node)
{
	// 			    1
	// 		2 	 	          3
	// 	4		5         6		  7
	//8   9   10   11     12   13   14   15
	if(node == NULL) return 0;
	// if(node->left == NULL && node->right == NULL)
	// {
	// 	if(big == -1) big = height;
	// 	if(big - height > 1) cout << "不是平衡的" << endl;
	// 	if(big < height) big = height;
	// }
	
	int leftHeight = BalanceTree(node->left);
	if(leftHeight == -1) return -1;
	
	int rightHeight = BalanceTree(node->right);
	if(rightHeight == -1) return -1;

	int result;
	if(abs(leftHeight - rightHeight) > 1)
		result = -1;
	else
		result = 1 + max(leftHeight, rightHeight);
	return result;
	// cout << " " << node->val  << "(" << height << ")";
}
void FindPath(TreeNode *node, vector<int>& curPath, vector<string>& result)
{
	// 			    1
	// 		2 	 	          3
	// 	4		5         6		  7
	//8   9   10   11     12   13   14   15
	if(node->left == NULL && node->right == NULL)
	{
		string res = "";
		curPath.push_back(node->val);
		for(int i = 0; i < curPath.size(); i++)
		{
			// if(i == 0)
			// cout << curPath[i] <<"  " << curPath.size() << "  "<< i << endl;
			res += to_string(curPath[i]) + " -> ";
		}
		result.push_back(res);

		curPath.pop_back();
	}
	if(node->left != NULL)
	{
		curPath.push_back(node->val);
		FindPath(node->left, curPath, result);
		curPath.pop_back();
	}
	if(node->right != NULL)
	{
		curPath.push_back(node->val);
		FindPath(node->right, curPath, result);
		curPath.pop_back();
	}
}
void FindLeftLeaf(TreeNode* node, int& result)
{
	// 			    1
	// 		2 	 	          3
	// 	4		5         6		  7
	//8   9   10   11     12   13   14   15
	if(node->left != NULL)
	{	
		if(node->left->left == NULL && node->left->right == NULL)
			result += node->left->val;
		else
			FindLeftLeaf(node->left, result);
	}
	if(node->right != NULL)
	{
		FindLeftLeaf(node->right, result);
	}
}
void FindLeftCorner(TreeNode* head)
{
	queue<TreeNode*> val_que;
	val_que.push(head);
	int left = -1;
	while(!val_que.empty())
	{
		int size = val_que.size();
		for(int i = 0; i < size; i++)
		{
			TreeNode* node = val_que.front();
			if(node->left != NULL) val_que.push(node->left);
			if(node->right != NULL) val_que.push(node->right);
			cout << "  " << node->val;
			if(i == 0) left = node->val;
			val_que.pop();
		}
		cout << endl;
		
	}
	cout << "leftCorner : " << left << endl;
}
void FindPathPlus(TreeNode* node, vector<int> result, int plus)
{
	// 			    1
	// 		2 	 	          3
	// 	4		5         6		  7
	//8   9   10   11     12   13   14   15
	if(node->left == NULL && node->right == NULL)
	{
		result.push_back(node->val);
		int cur = 0;
		string curStr = "";
		for(int i = 0; i < result.size(); i++)
		{
			cur += result[i];
			
			curStr += to_string(result[i]) + " -> ";
			// cout << result[i] << " -> ";
		}
		if(cur == plus)
		{
			cout << curStr << endl;
		}
		// cout << endl;
		result.pop_back();
	}
	if(node->left != NULL)
	{
		result.push_back(node->val);
		FindPathPlus(node->left, result, plus);
		result.pop_back();
	}
	if(node->right != NULL)
	{
		result.push_back(node->val);
		FindPathPlus(node->right, result, plus);
		result.pop_back();
	}
}
void CreatTreeMiddle(TreeNode* node, vector<int>& vec1, vector<int>& vec2)
{
	// 			    1
	// 		2 	 	              3
	// 	4		5            6		   7
	//8           11     12     13      	14
	// vector<int> vec1 = {8, 4, 2, 5, 11, 1, 12, 6, 13, 3, 7, 14};//左中右
	// vector<int> vec2 = {8, 4, 11, 5, 2, 12, 13, 6, 14, 7, 3, 1};//左右中

	int valMiddle = vec2[vec2.size() - 1];
	vec2.pop_back();
	int index = -1;
	for(int i = 0; i < vec1.size(); i++)
	{
		if(vec1[i] == valMiddle)
			index = i;
	}
	node->val = valMiddle;

	TreeNode* nodeLeft = new TreeNode(-1);
	TreeNode* nodeRight = new TreeNode(-1);
	// nodeLeft->val = vec1[index - 1];
	// nodeRight->val = vec2[vec2.size() - 1];
	node->left = nodeLeft;
	node->right = nodeRight;
	vector<int> vec1L(vec1.begin(), vec1.begin() + index);
	vector<int> vec2L(vec2.begin(), vec2.begin() + index);
	// vec1 = {8, 4, 2, 5, 11}
	// vec2 = {8, 4, 11, 5, 2}
	if(vec1L.size() > 1)
		CreatTreeMiddle(nodeLeft, vec1L, vec2L);
	else
	{
		if(vec1L.size() > 0)
			nodeLeft->val = vec1L[0];
		else
			nodeLeft->val = -5;
	}

	vector<int> vec1R(vec1.begin() + index + 1, vec1.end());
	vector<int> vec2R(vec2.begin() + index, vec2.end());
	// vec1 = {12, 6, 13, 3, 7, 14}
	// vec2 = {12, 13, 6, 14, 7, 3}
	if(vec1R.size() > 1)
		CreatTreeMiddle(nodeRight, vec1R, vec2R);
	else
	{
		if(vec1R.size() > 0)
			nodeRight->val = vec1R[0];
		else
			nodeRight->val = -5;
	}


	// for(int i = 0; i < vec1L.size(); i++)
	// {
	// 	cout << " ," << vec1L[i] ;
	// }
	// cout << endl;
	// 	for(int i = 0; i < vec2L.size(); i++)
	// {
	// 	cout << " ," << vec2L[i] ;
	// }
	// cout << endl;
	// 	for(int i = 0; i < vec1R.size(); i++)
	// {
	// 	cout << " ," << vec1R[i] ;
	// }
	// cout << endl;
	// 	for(int i = 0; i < vec2R.size(); i++)
	// {
	// 	cout << " ," << vec2R[i] ;
	// }
	// cout << endl;
	// cout << "_______________________________________" << endl;

}
void CreatBigestTree(TreeNode* node, vector<int>& vec)
{
	int num = -1;
	int index = -1;
	for(int i = 0; i < vec.size(); i++)
	{
		if(vec[i] > num)
		{
			num = vec[i];
			index = i;
		}
	}
	node->val = num;

	vector<int> leftVec(vec.begin(), vec.begin() + index);
	if(leftVec.size() > 1)
	{
		node->left = new TreeNode(-1);
		CreatBigestTree(node->left, leftVec);
	}
	else
	{
		if (leftVec.size() > 0)
			node->left = new TreeNode(leftVec[0]);
	}
	vector<int> rightVec(vec.begin() + index + 1, vec.end());
	if(rightVec.size() > 1)
	{
		node->right = new TreeNode(-1);
		CreatBigestTree(node->right, rightVec);
	}
	else
	{
		if (rightVec.size() > 0)
			node->right = new TreeNode(rightVec[0]);
	}
}
TreeNode* MergeTree(TreeNode* node1, TreeNode* node2)
{
	if(node1 == NULL && node2 == NULL)
	{
		return NULL;
	}
	if(node1 == NULL) return node2;
	if(node2 == NULL) return node1;
	node1->val += node2->val;
	node1->left = MergeTree(node1->left, node2->left);
	node1->right = MergeTree(node1->right, node2->right);
	return node1;
}
void SearchTree(TreeNode* node, int num)
{
	// 			    1
	// 		2 	 	          3
	// 	4		5         6		  7
	//8   9   10   11     12   13   14   15
	queue<TreeNode*> nodeVec;
	nodeVec.push(node);
	while(!nodeVec.empty())
	{
		int size = nodeVec.size();
		for(int i = 0; i < size; i++)
		{
			TreeNode* nodes = nodeVec.front();
			nodeVec.pop();
			if(nodes != NULL)
			{
				cout << "  " << nodes->val;
				if(nodes->val > num)
				{
					if(nodes->left != NULL) nodeVec.push(nodes->left);
				}
				if(nodes->val < num)
				{
					if(nodes->right != NULL) nodeVec.push(nodes->right);	
				}
				if(nodes->val == num)
				{
					cout << "找到目标" << endl;
					return;
				}
			}
		
		}
		cout << endl;
	}
}
void CheckIsSearchTree(TreeNode* node, vector<int>& vec)
{
	// 			      20
	// 		16   	             29
	// 	12		 18         22		  31
	//8   13   17   19    21   23   30   35
	//8, 12 13 16 17 18 19 20 21 22 23 29 30 31 35
	if(node->left != NULL) CheckIsSearchTree(node->left, vec);
	 
	vec.push_back(node->val);
	cout << node->val << " |" << (node->val < vec.back()) << "|    " ;
	if(node->right != NULL) CheckIsSearchTree(node->right, vec);

}
void FindSearchMins(TreeNode* node, vector<int> vec, int& min)
{
	if(node->left !=NULL) FindSearchMins(node->left,vec, min);
	if(vec.empty()) vec.push_back(node->val);
	else
	{
		int num = abs(vec.back() - node->val);
		min = num > min? num:min; 
		vec.push_back(node->val);
	}
	if(node->right != NULL) FindSearchMins(node->right, vec, min);
}
void FindPluralNormalTree(TreeNode* node, map<int, int>& map)
{
	// 			    20
	// 		16   	          29
	// 	12		16         22		  31
	//12   22   17   16    22   20   20   35
	map[node->val]++;
	if(node->left != NULL) FindPluralNormalTree(node->left, map);
	cout << node->val << " " ; 
	if(node->right != NULL) FindPluralNormalTree(node->right, map);

}
void FindPluralSearchTree(TreeNode* node, vector<int>& vec, int& maxCount, int& curCount)
{
	// 			    20
	// 		16   	          29
	// 	12		  18         22		  31
	//12   12   18   19    22   22   30   35

	//12 12 12 16 18 18 19 20 22 22 22 29 30 31 35
	if(node->left != NULL)
	{
		FindPluralSearchTree(node->left, vec, maxCount, curCount);
	}
	//operation
	if(vec.empty())
	{
		vec.push_back(node->val);
		curCount++;
	}
	else
	{
		int lastVal = vec.back();
		if(lastVal == node->val)
		{
			curCount++;
			if(maxCount < curCount)
			{
				maxCount = curCount;
			}
		}
		else
		{
			if(maxCount > curCount)
			{
				vec.pop_back();
			}
			curCount = 1;
			vec.push_back(node->val);
		}
		
	}
	if(node->right != NULL)
	{
		FindPluralSearchTree(node->right, vec, maxCount, curCount);
	}
}
bool sortMapFunc(pair<int, int> front, pair<int, int> back)
{
	return front.second > back.second;
}
bool FindMax(map<int, int>& maps)
{
	vector<pair<int, int>> vecMaps(maps.begin(), maps.end());
	sort(vecMaps.begin(), vecMaps.end(),sortMapFunc);
	cout << endl ;
	for(int i = 0; i != vecMaps.size(); i++)
	{
		cout << vecMaps[i].first << " |" << vecMaps[i].second << "|" << endl;
	}
}
void FindNearstParent(TreeNode* node, int p, int q)
{
	// 			    20
	// 		16   	          29
	// 	12		  18         22		  31
	//11   13   17   19    21   23   30   35

	// 11, 13, 12, 17, 19, 18, 16, 21, 23, 22, 30, 35, 31, 29, 20
	if(node->left != NULL) FindNearstParent(node->left, p, q);
	if(node->right != NULL) FindNearstParent(node->right, p, q);
	cout << node->val << " ";
}
int main()
{
	TreeNode *head = CreatTree();
	TreeNode *head2 = CreatTree2();
	// FindFront(head);
	// FindMiddle(head);
	// FindBehind(head);
	// FindFront2(head);
	// FindLevel(head);
	// ReverseTreeRecur(head);
	// FindLevel(head);
	// bool isAs = AsemmetricalTree(head->left, head->right);
	// cout << "result is " << isAs << endl;
	// FindMostDeep(head);
	// FindMostDeep(head2);

	// int a = BalanceTree(head);
	// vector<int> curPath;
	// vector<string> result;
	// cout << curPath.size() << endl;

	// FindPath(head, curPath, result);
	// for(int i = 0; i < result.size(); i++)
	// {
	// 	cout << result[i] << endl;
	// }
	// int result = 0;
	// FindLeftLeaf(head, result);
	// FindLeftCorner(head2);
	// vector<int> result;
	// FindPathPlus(head, result, 26);

	// vector<int> vec1 = {8, 4, 2, 5, 11, 1, 12, 6, 13, 3, 7, 14};//左中右
	// vector<int> vec2 = {8, 4, 11, 5, 2, 12, 13, 6, 14, 7, 3, 1};//左右中
	// TreeNode* nod = new TreeNode(-1);
	// CreatTreeMiddle(nod, vec1, vec2);
	// FindLevel(nod);

	// vector<int> vec = {3,2,1,6,0,5};
	// TreeNode* nod = new TreeNode(-1);
	// CreatBigestTree(nod, vec);
	// FindLevel(nod);
	// SearchTree(head, 17);
	// vector<int> vec;
	// CheckIsSearchTree(head, vec);
	// int num = INT_MIN;
	// FindSearchMins(head, vec, num);
	// map<int, int> maps;
	// FindPluralNormalTree(head, maps);
	// FindMax(maps);

	// vector<int> vec;
	// int max = 0;
	// int cur = 0;
	// FindPluralSearchTree(head, vec, max, cur);
	// for(int i = 0; i < vec.size(); i++)
	// {
	// 	cout << vec[i] << " " ;
	// }
	FindNearstParent(head);
	cout << "执行完毕 : " << endl;
	return 0;
}