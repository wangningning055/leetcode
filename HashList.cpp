#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

int FindSameChar(string s ,string t)
{
	int *hashArry = new int[26];
	for(int i = 0; i < 26; i++)
	{
		hashArry[i] = 0;
	}
	for(int i = 0; i < s.length(); i++)
	{
		hashArry[s[i] - 'a']++;
	}
	for(int i = 0; i < t.length(); i++)
	{
		hashArry[t[i] - 'a']--;
	}
	for(int i = 0; i < 26; i++)
	{
		if(hashArry[i] != 0) return 0;
	}
	return 1;
}

void FindArryIntersection(vector<int>& arry1, vector<int>& arry2)
{
	unordered_map<int, int> hash1;
	unordered_map<int, int> hash2;
	vector<int> findVec;
	vector<int>& longArry = arry1.size() >= arry2.size()? arry1:arry2;
	vector<int>& shortArry = arry1.size() >= arry2.size()? arry2:arry1;

	for(int i = 0; i < longArry.size(); i++)
	{
		hash1.insert({longArry[i], 0});
	}
	for(int i = 0; i < shortArry.size(); i++)
	{
		hash2.insert({shortArry[i], 0});
	}
	unordered_map<int, int>::iterator iterHash1 = hash1.begin();
	for(; iterHash1 != hash1.end(); iterHash1++)
	{
		unordered_map<int, int>::iterator find = hash2.find(iterHash1->first);
		if(find != hash2.end())
		{
			findVec.push_back(find->first);
		}
	}
	vector<int>::iterator findIter = findVec.begin();
	for(;findIter != findVec.end(); findIter++)
	{
		cout << *findIter << endl;
	}
}
void HappyNum(int num)
{
	// 123
	unordered_set<int> sumList;
	while(1)
	{
		int sum = 0;
		while(num != 0)
		{
			sum += (num % 10) * (num % 10);
			num /= 10;
		}
		// cout << "he wei " << sum << endl;
		if(sum == 1)
		{
			cout << "是" << endl;
			return;
		}
		if(sumList.find(sum) != sumList.end())
		{
			cout << "不是" << endl;
			return;
		}
		sumList.insert(sum);
		num = sum;
	}
}
void TwoSum(vector<int>& arry, int target)
{
	unordered_map<int, int> recorder;
	for(int i = 0; i < arry.size(); i++)
	{
		int mapTarget = target - arry[i];
		auto iter = recorder.find(mapTarget);
		if(iter != recorder.end())
		{
			cout << "Find : " << iter->second << " || " << i << endl;
			return;
		}
		recorder.insert({arry[i], i});
	}
	cout << "not Find" << endl;
}
void ForSumSimple(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D)
{
	unordered_map<int, int> AWithBSumArry;
	int zeroCount = 0;
	for(int a : A)
	{
		for(int b : B)
		{
			AWithBSumArry[a + b]++;
		}
	}
	for(int c : C)
	{
		for(int d : D)
		{
			if(AWithBSumArry.find(-(c + d)) != AWithBSumArry.end())
			{
				zeroCount += AWithBSumArry[-(c + d)];
			}
		}
	}
	cout << "sum count : " << zeroCount << endl;
}
void RansomNote(string ransomNote, string magazine)
{
	int arry[26] = {0};
	if(magazine.size() < ransomNote.size())
	{
		cout << "Not Find " << endl;
		return;
	}
	for(int i = 0; i < magazine.size(); i++)
	{
		arry[magazine[i]-'a']++;
	}
	for(int i = 0; i < ransomNote.size(); i++)
	{
		arry[ransomNote[i] - 'a']--;
		if(arry[ransomNote[i] - 'a'] < 0)
		{
			cout << "NotFind" << endl;
			return;
		}
	}
	cout << "Find" << endl;
}
void ReverseString(string str)
{
	for(int i = 0; i < str.size() / 2; i++)
	{
		char a = str[i];
		char b = str[str.size() - i - 1];
		char temp = a;
		str[i] = b;
		str[str.size() - i - 1] = a;
	}
	cout << str << endl;
}
void ReverseString(string str, int k)
{
	for(int i = 0; i < str.size(); i += 2*k)
	{
		if(str.size() < i)
		{
			if((str.size() - i) < k)
			{
				reverse(str.begin() + i - (2 * k), str.end());
			}
			else
			{
				reverse(str.begin() + i -(2 * k),str.begin() + i -(2 * k) + k);
			}
		}
		else
		{
			reverse(str.begin() + i, str.begin() + i + k);
		}
	}
	cout << "reverse string is : " << str << endl;

}
// int main()
// {
// 	// string s = "aasdertz";
// 	// string t = "rrtyrewd";
// 	// string a = "qqwerrta";
// 	// string b = "werrqqta";
// 	// int isFind1 = FindSameChar(s, t);
// 	// int isFind2 = FindSameChar(a, b);

// 	// cout << "str1:  " << isFind1 << endl;
// 	// cout << "str2   " << isFind2 << endl;

// 	// vector<int> a{1,1,12,3,4,5,6,7,234, 55};
// 	// vector<int> b{1,12,3,4,5,6,7,9,234};
// 	// FindArryIntersection(a, b);
// 	// cout << "this is HashList" << endl;
// 	// HappyNum(18);
// 	// TwoSum(a, 8);
// 	// vector<int> a{1,2};
// 	// vector<int> b{-2,-1};
// 	// vector<int> c{-1,2};
// 	// vector<int> d{0,2};

// 	// ForSumSimple(a,b,c,d);
// 	// RansomNote("aa", "ab");
// 	ReverseString("abcdefg", 2);
// 	return 0;
// }