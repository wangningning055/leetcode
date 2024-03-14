#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void RemoveNumb(vector<int>& vec, int num)
{
	int slowIndex = 0;
	for(int i = 0; i < vec.size(); i++)
	{
		if(vec[i] != num)
		{
			vec[slowIndex++] = vec[i];
		}
	}

	for(int i = 0; i < slowIndex; i++)
	{
		cout << vec[i] << endl;
	}
	return;
}
void ReversString(string str)
{
	for(int i = 0, j = str.size() - 1; i < str.size() / 2 ; i++)
	{
		char temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		j--;
	}
	cout << str << endl;
}
void ReplaceNumbers(string str)
{
	int newSize = str.size();
	int sizeRec = newSize;
	for(int i = 0 ; i < str.size(); i++)
	{
		if(str[i] >= '0' && str[i] <= '9')
		{
			newSize += 5;
		}
	}
	str.resize(newSize);
	for(int i = sizeRec - 1,j =newSize - 1; i >= 0; i-- )
	{
		if(str[i] >= '0' && str[i] <= '9')
		{
			str[j--] = 'r';
			str[j--] = 'e';
			str[j--] = 'b';
			str[j--] = 'm';
			str[j--] = 'u';
			str[j--] = 'n';

		}
		else
		{
			str[j--] = str[i];
		}
	}
	cout << str << endl;
	return;
}
struct point{
	point* next;
	int val;
};
point* CreatChain(int length)
{
	point* head = new point();
	head->val = -1;
	point* lastPoint = head;
	for(int i = 0; i < length; i++)
	{
		point* poins = new point();
		poins->val = i;
		lastPoint->next = poins;
		lastPoint = poins;
	}
	return head;
}

point* ReverseChainForTwo(point* head)
{
	point* slow = NULL;
	point* fast = head;
	while (fast != NULL)
	{
		point* temp = fast->next;
		fast->next = slow;
		slow = fast;
		fast = temp;
	}
	return slow;
}
point* DeleteBehindPoint(point *head, int n)
{
	point* slow = head;
	point* fast = head;
	int i = 0;
	for(;fast->next != NULL; fast = fast->next)
	{
		if(i >= n)
		{
			slow = slow->next;
		}
		i++;
	}
	point* target = slow->next->next;
	slow->next = target;
	return head;
}
void FindChainInterSect(point* A, point* B)
{
	int lengthA = 0;
	int lengthB = 0;
	point* nextPoint = A;
	while(nextPoint->next != NULL)
	{
		nextPoint = nextPoint->next;
		lengthA++;
	}
	nextPoint = B;
	while(nextPoint->next != NULL)
	{
		nextPoint = nextPoint->next;
		lengthB++;
	}
	int longLength = lengthA >= lengthB? lengthA : lengthB;
	int shortLength = lengthA < lengthB? lengthA : lengthB;
	int i = 0;
	point* longChain = lengthA >= lengthB? A : B;
	nextPoint =  lengthA < lengthB? A : B;
	// cout << lengthA << "   | "  << lengthB <<endl;
	while(longChain->next != NULL)
	{
		//0 1 2 3 4 5
		//    4 3 4 5
		if(i >= longLength - shortLength)
		{
			if(nextPoint == longChain)
			{
				cout << "Find : " << i << endl;
				return;
			}
			nextPoint = nextPoint->next;
		}
		i++;
		longChain = longChain->next;
	}
}
void ThreeNumsPlus(vector<int>& nums, int target)
{
	int i = 0;
	int left = 1;
	int right = nums.size() - 1;
	sort(nums.begin(), nums.end());
	for(int j = 0; j < nums.size() ; j++)
	{
		cout << nums[j] << endl;
	}
	for(; left < nums.size(); )
	{
		while(left != right)
		{
			int sum = nums[i] + nums[left] + nums[right];
			if(sum == target)
			{
				cout << "Find : " << i << " " << left << " " << right << " " << endl;
				left++;
			}
			if(sum > target)
			{
				right--;
			}
			if(sum < target)
			{
				left++;
			}
		}
		i++;
		left = i + 1;
		right = nums.size() - 1;
	
	}
}
// int main()
// {
// 	vector<int> vec = {1,55,5,5,8,6,7};
// 	// vector<int> vec = {1,5,5,6,7,8,55};

// 	// RemoveNumb(vec, 5);
// 	string aaa = "   qwe   ert   tyu       ";
	
// 	point* head = CreatChain(5);
// 	point* find = head;
// 	while (find != NULL)
// 	{
// 		cout << find->val << endl;
// 		find = find->next;
// 	}
// 	// find = head;
// 	// find = DeleteBehindPoint(find, 1);
// 	// find = ReverseChainForTwo(find);
// 	// FindChainInterSect(find, head2);
// 	cout << "__________" << endl;

// 	// FindChainInterSect(head, head2);
// 	ThreeNumsPlus(vec, 65);
// 	return 0;
// }
