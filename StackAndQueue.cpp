#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<stdlib.h>
#include<unordered_map>
using namespace std;

class SimulateQueue
{
	// 1 2 3 4 5 6
	// 6 5 4 3 2 1
	public:
		stack<int> stackIn;
		stack<int> stackOut; 
		void updateOutStack()
		{
			if(stackOut.empty())
			{
				while(!stackIn.empty())
				{
					stackOut.push(stackIn.top());
					stackIn.pop();
				}
			}
		}
		void push(int val)
		{
			stackIn.push(val);
		}
		void pop()
		{
			if(isEmpty())
			{
				cout << "队列为空" << endl;
				return;
			}
			updateOutStack();
			stackOut.pop();
		}
		int peek()
		{
			if(isEmpty())
			{
				cout << "队列为空" << endl;
				return 0;

			}
			updateOutStack();

			int val = stackOut.top();
			stackOut.pop();
			return val;
		}
		bool isEmpty()
		{
			return stackIn.empty() && stackOut.empty();
		}
};
class SimulateStack
{
	queue<int> queueMain;
	public:
		void updateQueueMain()
		{
			queue<int> queueRec;
			while(queueMain.size() > 1)
			{
				int val = queueMain.front();
				queueRec.push(val);
				queueMain.pop();
			}
			queueMain = queueRec;
		}
		void push(int val)
		{
			queueMain.push(val);
		}
		void pop()
		{
			if(empty())
			{
				cout << "栈为空" << endl;
				return;
			}
			updateQueueMain();
		}
		int top()
		{
			if(empty())
			{
				cout << "栈为空" << endl;
				return 0;
			}
			int val = queueMain.back();
			updateQueueMain();
			return val;
		}
		bool empty()
		{
			return queueMain.empty();
		}

};
void matchBracket(string str)
{
	stack<char> charStack;
	for(int i = 0; i < str.size(); i++)
	{
		
		if(str[i] == '(')
			charStack.push(')');
		else if(str[i] == '{')
			charStack.push('}');
		else if(str[i] == '[')
			charStack.push(']');
		else if(charStack.empty() || str[i] != charStack.top())
		{
			cout << "不匹配" << endl;
			return;
		}
		else
			charStack.pop();
	}
	if(charStack.empty())
		cout << "匹配" << endl;
	else
		cout << "不匹配" << endl;
	
	return;
}
void DeleteRepeat(string str)
{
	stack<char> charStack;
	for(int i = 0; i < str.size(); i++)
	{
		if(charStack.empty() || charStack.top() != str[i])
		{
			charStack.push(str[i]);
		}
		else
		{
			charStack.pop();
		}
	}
	while(!charStack.empty())
	{
		cout<< charStack.top() << endl;
		charStack.pop();
	}
}
void middleConfigue(vector<string>& str)
{
	stack<int> strStack;
	for(int i = 0; i < str.size(); i++)
	{
		if(str[i] == "+" ||str[i] == "-" ||str[i] == "*" ||str[i] == "/")
		{
			int numB = strStack.top();
			strStack.pop();
			int numA = strStack.top();
			strStack.pop();
			int newNum = 0;
			if(str[i] == "+")
				newNum = numA + numB;
			if(str[i] == "-")
				newNum = numA - numB;
			if(str[i] == "*")
				newNum = numA * numB;
			if(str[i] == "/")
				newNum = numA / numB;
			strStack.push(newNum);
		}
		else
		{
			strStack.push(atoi(str[i].c_str()));
		}
	}
	cout << "结果是 ： " << strStack.top() << endl;
}
void findSliderWindowMax(vector<int>& nums, int winLength)
{
	deque<int> tediousQueue;
	for(int i = 0; i < winLength; i++)
	{
		if(tediousQueue.empty() || nums[i] <= tediousQueue.back())
		{
			tediousQueue.push_back(nums[i]);
		}
		else
		{
			//2
			//2,1,3
			while(!tediousQueue.empty() && nums[i] > tediousQueue.back())
			{
				tediousQueue.pop_back();
			}
			tediousQueue.push_back(nums[i]);
		}
	}
	cout << "第一个窗口最大值是： " << tediousQueue.front() << endl;

	for(int i = winLength; i < nums.size(); i++)
	{
		if(tediousQueue.empty() || nums[i] <= tediousQueue.back())
		{
			tediousQueue.push_back(nums[i]);
		}
		else
		{
			while(!tediousQueue.empty() && nums[i] > tediousQueue.back())
			{
				tediousQueue.pop_back();
			}
			tediousQueue.push_back(nums[i]);
		}
		cout << "当前窗口最大值是： " << tediousQueue.front() << endl;
	}
}

void GetNumsInNums(vector<int> nums, int k)
{
	struct compare
	{
		public:
		bool operator()(pair<int, int>& a, pair<int,int>& b)
		{
			return a.second > b.second;
		}
	};
	
	unordered_map<int, int> map;
	for(int i = 0; i < nums.size(); i++)
	{
		map[nums[i]]++;
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>, compare> queue;

	for(unordered_map<int, int>::iterator iter = map.begin(); iter != map.end(); iter++)
	{
		// cout << iter->first << " || " << iter->second << endl;
		queue.push(*iter);
		if(queue.size() > k)
			queue.pop();
	}

	while(!queue.empty())
	{
		cout<< queue.top().first << " || " << queue.top().second << endl;
		queue.pop();
	}

}
// int main()
// {
	// SimulateQueue simulateQueue;
	// simulateQueue.push(1);
	// simulateQueue.push(2);
	// simulateQueue.push(3);
	// simulateQueue.push(4);
	// simulateQueue.push(5);

	// cout << simulateQueue.peek() << endl;
	// simulateQueue.pop();
	// cout << simulateQueue.peek() << endl;
	// cout << simulateQueue.peek() << endl;
	// cout << simulateQueue.peek() << endl;
	// cout << simulateQueue.peek() << endl;
	// cout << simulateQueue.peek() << endl;
	
	// SimulateStack simulateStack;
	// simulateStack.push(1);
	// simulateStack.push(2);
	// simulateStack.push(3);
	// simulateStack.push(4);
	// simulateStack.push(5);
	// simulateStack.push(6);

	// cout << simulateStack.top() << endl;

	// simulateStack.pop();
	// simulateStack.pop();
	// simulateStack.pop();

	// cout << simulateStack.top() << endl;
	// simulateStack.pop();
	// simulateStack.pop();
	// simulateStack.pop();
	// simulateStack.pop();
	// simulateStack.pop();

	// matchBracket("(){[]}");
	// DeleteRepeat("abbaca");
	// vector<string> vec = {"4", "13", "5", "/", "+"};
	// middleConfigue(vec);

// 	vector<int> vec = {1, 3, 1, 3, 5, 3, 5, 5, 5, 8, 7, 9};
// 	// findSliderWindowMax(vec, 3);
// 	GetNumsInNums(vec, 3);
// 	return 0;
// }