#include<iostream>
using namespace std;
class ClassA{
	public:
		int a;
		int *b;
		static int x;
	public:
		int getAPlusB();
		ClassA();
		ClassA(const ClassA &a);
		~ClassA();
};
ClassA :: ClassA()
{
	cout << "调用了A的构造函数" << endl;
}
ClassA :: ~ClassA()
{

	cout << "调用了A的析构函数" << endl;
}
ClassA :: ClassA(const ClassA &a)
{
	cout << "调用了A的拷贝构造函数" << endl;
	b = new int;
	*b = *a.b;
	this->a = a.a;
}

int ClassA :: getAPlusB()
{
	return a + *b;
}

void ChangeClass(ClassA classIn)
{
	classIn.a = 789456;
	*classIn.b = 55556;
}

// int main()
// {
// 	ClassA classA1;
// 	ClassA classA2;
// 	classA1.a = 100;
// 	int b = 100;
// 	classA1.b = &b;
	
// 	classA2 = classA1;


// 	classA1.x = 100;

// 	cout << "更改前a的值为：" << classA1.a << endl;
// 	cout << "更改前b的值为：" << *classA1.b << endl;

// 	ChangeClass(classA1);
// 	cout << "更改后a的值为：" << classA1.a << endl;
// 	cout << "更改后b的值为：" << *classA1.b << endl;
	
// 	// cout << "和为：" << classA1.getAPlusB() << endl;

// 	// ClassA classA2 = classA1;

// 	// cout << "相加两个类以后和为" << classA2.getAPlusB() << endl;

// 	// b = 500;
// 	// cout << "更改B以后和为" << classA2.getAPlusB() << endl;

// 	// *classA1.b = 50;
// 	// cout << "更改类1的b以后和为" << classA2.getAPlusB() << endl;
	

// 	return 0;
// }