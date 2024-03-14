#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

void ReplaceNumber(string str)
{
	int numberCount = 0;
	int oldSize = str.size() - 1;
	for(int i = 0; i < str.size(); i++)
	{
		if(str[i] >= '0' && str[i] <= '9')
		{
			numberCount++;
		}
	}
	str.resize(str.size() + numberCount * 5);
	for(int head = oldSize, tail = str.size() - 1; head >= 0; head--)
	{
		if(str[head] >= '0' && str[head] <= '9')
		{
			str[tail] = 'r';
			str[tail - 1] = 'e';
			str[tail - 2] = 'b';
			str[tail - 3] = 'm';
			str[tail - 4] = 'u';
			str[tail - 5] = 'n';
			tail = tail - 6;
		}
		else
		{
			str[tail] = str[head];
			tail--;
		}
	}
	cout << "replace number str is :" << str << endl;
}
void ReverseWord(string str)
{
	int slowIndex = 0, fastIndex = 0;
	int newSize = 0;
	bool isTwoSpace = false;
	for(; fastIndex < str.size() ; fastIndex++)
	{
		//aaa aa
		if(str[fastIndex] != ' ')
		{
			isTwoSpace = false;
			str[slowIndex] = str[fastIndex];
			slowIndex++;
		}
		else
		{
			if(!isTwoSpace && slowIndex != 0)
			{
				str[slowIndex++] = ' ';
				isTwoSpace = true;
			}
		}
	}
	str.resize(slowIndex);
	cout <<  str << endl;
	for(int i = 0; i < str.size() / 2; i++)
	{
		char head = str[i];
		char tail = str[str.size() - 1 - i];
		str[i] = tail;
		str[str.size() - 1 - i] = head;
	}
	cout <<  str << endl;
	slowIndex = 0;
	fastIndex = 0;
	for(; fastIndex <= str.size(); fastIndex++)
	{
		if(fastIndex == str.size() || str[fastIndex] == ' ')
		{
			//sa 3c1 dssb 1 dba
			reverse(str.begin() + slowIndex, str.begin() + fastIndex);
			slowIndex = fastIndex + 1;
		}
	}
	cout <<  str << endl;
}
void KMPForStrstr(string hayStack, string needle)
{

	vector<int> a;
	a.resize(needle.size());
	a[0] = 0;
	int j = 1;
	int i = 0;
	for(; j < needle.size(); j++)
	{
		if(needle[i] == needle[j])
		{
			i++;
			a[j] = i;
		}
		else
		{
			while(i > 0 && needle[i] != needle[j])
			{
				i = a[i-1];
			}
		}
	}
	for(i = 0; i < a.size(); i++)
	{
		cout << a[i] << endl;
	}
	//0123456
	//aabaabaafa
	//aacbaacf
	//01001230
	int index = 0;
	for(i = 0, j = 0; i < hayStack.size();)
	{
		if(hayStack[i] == needle[j])
		{
			if(j == needle.size() - 1)
			{
				cout << "已匹配到字符串 : " << index << endl; 
				return;
			}
			i++;
			j++;
		}
		else
		{
			if(j > 0)
			{
				index = i - a[j - 1];
				j = j- a[j - 1] - 1;
			}
			else
			{
				index++;
				i++;
			}
		}
	}
	cout << "匹配不到" << endl;
	return;
}
// int main()
// {
// 	// ReverseWord("  abd kjl uio bssd 1c3   a");
// 	KMPForStrstr("aabaabaafa", "aabaaf");
// 	return 0;
// }