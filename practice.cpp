#include<iostream>
#include<vector>
#include "head.h"
#include<unordered_map>
using namespace std;


// int main()
// {
// 	int arrySet[] = {1,3,5,7,9,34,76,89,90};
// 	int target[] = {1,3,5,7,9,34,76,89,90};
// 	vector<int> vetorTest(arrySet, arrySet + 9);
// 	cout << "数组长度" << vetorTest.size() << endl;
// 	for(int i = 0; i < 9; i++)
// 	{
// 		int finalNum = GetHalfArryNum(vetorTest, target[i], 9, 0);
// 		cout<< "最后的下标为：" << finalNum << endl;
// 	}
// 	int finalNum = GetHalfArryNum(vetorTest, -44, 9, 0);
// 	cout<< "最后的下标为：" << finalNum << endl;
// 	return 0;
// }
void bbbaaa()
{
	cout << "bbbbsdfs"<< endl;
}

/// @brief 二分查找
/// @param arry 数组
/// @param target 目标值
/// @param arryLength 长度
/// @param curIndex 当前引用
/// @return 
int GetHalfArryNum(vector<int>& arry, int target, int arryLength, int curIndex)
{
	int arryAdress = curIndex;
	if(arryLength <= 1)
	{
		for(int i = 0; i < arryLength; i++)
		{
			if(target == arry.at(arryAdress))
			{
				cout<< "找到" << arryLength;
				return curIndex;
			}
			curIndex++;
			arryAdress++;
		}
		cout<< "没有找到" << arryLength;
		return --curIndex;
	}
	int x = arryLength % 2;
	int middleIndex = x == 0? arryLength / 2 : (arryLength - 1) / 2;
	arryAdress += middleIndex;

	if(target == arry.at(arryAdress))
		return curIndex + middleIndex;
	
	if(arry.at(arryAdress) > target)
	{
		arryLength = middleIndex + 1;
	}
	if(arry.at(arryAdress) < target)
	{
		curIndex += middleIndex + 1;
		arryLength = arryLength - (middleIndex + 1);
	}
	if(arryLength == 2) arryLength = 1;
	return GetHalfArryNum(arry, target, arryLength, curIndex);
}
/// @brief 循环二分查找
/// @param nums 
/// @param target 
/// @return 
int SearchInsert(vector<int>& nums, int target)
{
	int size = nums.size();
	int left = 0;
	int right = size - 1;
	while(left <= right)
	{
		int middle = (left + right) / 2;
		if(target > nums.at(middle))
		{
			left = middle + 1;
		}
		else if(target < nums.at(middle))
		{
			right = middle - 1;
		}
		else
		{
			cout<< "找到：";
			return middle;
		}

	}
	cout << "找不到： " ;
	return right + 1;
}

int GetSerialWhithTwo(vector<int>& nums, int target)
{
	int left = 0;
	int right = nums.size() - 1;
	while(left <= right)
	{
		int middle = (left + right) / 2;
		// int middle = left + ((right - left) / 2);
		if(target < nums.at(middle))
		{
			right = middle - 1;
		}
		else
		{
			left = middle + 1;
		}

	}
	return left;
}
int getSquareRoot(int targetL, int targetR, int target)
{
	int middleL = (targetL + targetR) / 2;
	int middleR = middleL + 1;
	if(middleR > target) middleR = target;
	float middleRPow = middleR * middleR;
	float middleLPow = middleL * middleL;
	// cout << "__________________________________________" << endl;


	if(middleRPow >= target && middleLPow <= target)
	{
		cout << "左" << middleL << endl;
		cout << "右" << middleR << endl;
		if(middleLPow == target) return middleL;
		if(middleRPow == target) return middleR;
		return middleL;
	}
	if(middleLPow > target)
	{
		return getSquareRoot(0, middleL, target);
	}
	if(middleRPow < target)
	{
		return getSquareRoot(middleR, target, target);
	}
	return 0;
}
int RemoveElement(vector<int>& nums, int target)
{
	int slowIndex = 0;
	for(int fastIndex = 0; fastIndex < nums.size(); fastIndex++)
	{
		if(target != nums[fastIndex])
		{
			nums[slowIndex++] = nums[fastIndex];
		}
		return slowIndex;
	}
	return 0;
}
int RemoveRepeatElement(vector<int>& nums)
{
	int slowIndex = 1;
	int last = 0;
	for(int fastIndex = 1; fastIndex < nums.size(); fastIndex++)
	{
		if(nums[fastIndex] != nums[last])
		{
			nums[slowIndex++] = nums[fastIndex];
		}
		last = fastIndex;
	}
	return slowIndex;
}
void EndTheZero(vector<int>& nums)
{
	int slowIndex = 0;
	for(int i = 0; i < nums.size(); i++)
	{
		if(nums[i] != 0)
			nums[slowIndex++] = nums[i];
	}
	for(int j = slowIndex; j < nums.size(); j++)
	{
		nums[j] = 0;
	}
}
bool CompareStr(string& str1, string& str2)
{
	int slowIndex = 0;
	for(int fastIndex = 0; fastIndex < str1.length(); fastIndex++)
	{
		// asdfghjkl#
		if(str1[fastIndex] != '#')
		{
			str1[slowIndex++] = str1[fastIndex]; 
		}
		else
		{
			str1[fastIndex] = '\0';
			--slowIndex > 0? str1[--slowIndex] = '\0' : slowIndex = 0;
		}
	}
	str1.resize(slowIndex);
	cout<<"字符串1 ： " << str1 << "|" << endl;
	slowIndex = 0;
	for(int fastIndex = 0; fastIndex < str2.length(); fastIndex++)
	{
		if(str2[fastIndex] != '#')
		{
			str2[slowIndex++] = str2[fastIndex]; 
		}
		else
		{
			str2[fastIndex] = '\0';
			--slowIndex > 0? str2[--slowIndex] = '\0' : slowIndex = 0;
		}
	}
	str2.resize(slowIndex);

	cout<<"字符串2 ： " << str2 << "|" << endl;
	return str1 == str2;
}
vector<int> SquareArry(vector<int>& nums)
{
	int indexL = 0;
	int indexR = nums.size() - 1;
	vector<int> newArry;
// -5, -3, -1, 0, 1, 2, 3, 5
	for(;indexL <= indexR;)
	{
		if(nums[indexL] * nums[indexL] > nums[indexR] * nums[indexR])
		{
			newArry.push_back(nums[indexL] * nums[indexL]);
			indexL++;
		}
		else
		{
			newArry.push_back(nums[indexR] * nums[indexR]);
			indexR--;
		}
	}
	return newArry;
}
int GetMinArryLength(vector<int>nums, int target)
{
	int leftIndex = 0;
	int arryLength = 0;
	int minArryLength = INT32_MAX;
	int sum = 0;
	for(int i = 0; i < nums.size(); i++)
	{
		sum += nums[i];
		arryLength++;
		if(sum > target)
		{
			while(sum > target)
			{
				sum -= nums[leftIndex];
				leftIndex++;
				arryLength--;
				minArryLength = minArryLength > arryLength? arryLength : minArryLength; 
			}
	
		}
	}
	return minArryLength == INT32_MAX? 0: minArryLength;
}
int GetMaxTwoNumbArry(vector<int>& fruits)
{
	if(fruits.size() < 3)
		return fruits.size();
	int leftIndex = 0;
	int fruit1 = fruits[0];
	int fruit2 = fruits[1];
	int maxLength = 2;
	int finalNum = 0;
	for(int rightIndex = 2; rightIndex < fruits.size();)
	{
		while(rightIndex < fruits.size() && fruit1 == fruit2)
		{
			fruit2 = fruits[rightIndex++];
			maxLength++;
		}
		while(rightIndex < fruits.size() && (fruit1 == fruits[rightIndex] || fruit2 == fruits[rightIndex]))
		{
			rightIndex++;
			maxLength++;
		}
		if(finalNum < maxLength) finalNum = maxLength;
		if(leftIndex < fruits.size() - 1)
		leftIndex++;
		fruit1 = fruits[leftIndex];
		fruit2 = fruits[leftIndex + 1];
		maxLength--;
	}
	return finalNum;
}
class MinCoverStr{
	public: 
	string GetMinCoverStr(string s, string t)
	{
		if(t.size() > s.size())
		{
			return "";
		}
		if(t.size() == s.size())
		{
			if(t == s) return t;
			return "";
		}
		unordered_map<char, int> map;
		int leftIndex = 0;
		int rightIndex = 0;
		int minLength = INT32_MAX;
		string minStr;

		string curStr;
		for(;rightIndex < s.length(); rightIndex++)
		{
			curStr.push_back(s[rightIndex]);
			if(FindStr(t, s[rightIndex]))
			{
			
				map[s[rightIndex]] = rightIndex;
				if(map.size() == t.size())
				{
					unordered_map<char, int> :: iterator x = map.begin();
					int maxIndex = x->second;
					int minIndex = INT32_MAX;
					for(;x != map.end(); x++)
					{
						cout<< "头引用" << x->first << "    " << x->second <<endl;
						if(minIndex > x->second)
						{
							minIndex = x->second;
						}
						// secondMinIndex = (x->second > minIndex && x->second < secondMinIndex)? x->second:secondMinIndex;
					}
					cout << "最大引用" << maxIndex << endl;
					if(minLength > maxIndex - minIndex + 1)
					{
						minLength = maxIndex - minIndex + 1;
						minStr = curStr.substr(minIndex);
					}
					cout << "最小引用" << minIndex << endl;
					cout << "当前最小长度是    " << minLength << endl;
					cout << "当前最小字符串是    " << minStr << endl;

					cout << "原str   " << curStr << endl;
					cout << "裁剪str  " << curStr.substr(minIndex) << endl;
					map.erase(s[minIndex]);
					cout << "------------------------------------------------------" << endl;
				}
			}
		}
		return minStr;
	}
	bool FindStr(string t, char st)
	{
		for(int i = 0; i < t.length(); i++)
		{
			if(t[i] == st) return true;
		}
		return false;
	}
};
//螺旋矩阵
void SpiralMatrix()
{
	int length = 5;
	int **matrix = new int*[length];
	vector<vector<int>> matrix2(10, vector<int>(10));
	int rowNum = 0;
	int columNum = 0;
	for(int i = 0; i < length; i++)
	{
		matrix[i] = new int[length];
	}

	for(int i = 0; i < length; i++)
	{
		for(int j = 0; j < length; j++)
		{
			matrix[i][j] = i * length + j + 1;
			matrix2[i][j] = matrix[i][j];
		}
	}
	int x = 1;
	while(rowNum <= length)
	{
		//遍历行
		for(int i = 0; i < length - columNum; i++)
		{
			if(rowNum % 2 == 0)
			{
				int indexRow = rowNum / 2;
				int indexColum = columNum / 2 + i;
				matrix2[indexRow][indexColum] = x;
			}
			else
			{
				int indexRow = length - (rowNum - 1) / 2 - 1;
				int indexColum = length - (columNum + 1) / 2 - 1 - i;
				matrix2[indexRow][indexColum] = x;
			}
			x++;
		}
		rowNum++;
		//遍历列
		for(int i = 0; i < length - rowNum; i++)
		{
			if(rowNum % 2 == 0)
			{
				int columIndex = rowNum / 2 -1;
				int rowIndex = length - rowNum / 2 - i - 1;
				matrix2[rowIndex][columIndex] = x;
			}
			else
			{
				int cloumIndex = length - (rowNum + 1) / 2;
				int rowIndex = (rowNum + 1) / 2 + i;
				matrix2[rowIndex][cloumIndex] = x;
			}
			x++;
		}
		columNum++;
	}


	for(int i = 0; i < length; i++)
	{
		for(int j = 0; j < length; j++)
		{
			cout << matrix[i][j] << "  ";
		}
		cout << endl;
	}

	cout << endl;
	cout << endl;
	cout << endl;

	for(int i = 0; i < length; i++)
	{
		for(int j = 0; j < length; j++)
		{
			cout << matrix2[i][j] << "  ";
		}
		cout << endl;
	}


	for(int i = 0; i < length; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}
void MisMatchStr(string s, string t)
{
	unordered_map<string, int> map;
	
}