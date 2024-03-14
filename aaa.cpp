#include <iostream>
#include <cstring>
using namespace std;
struct FirstStrc{
	int aaa;
	int bbb;
	char ccc[10];
};
void ChangeStruct(FirstStrc *strc)
{
	strc->aaa = 10000000;
}
// int main()
// {
// 	cout << "aaaasddd";
// 	int a = 100;
// 	int b[] = {1,2,3,4};
// 	cout << "a的地址是" << &a << endl;
// 	cout << "b的地址是" << &b << endl;

// 	int *aDress;
// 	aDress = &a;
// 	cout << "指针指向的地址是：" << aDress << endl;
// 	cout << "指针指向的地址的值是" << *aDress << endl;

// 	int *emptyDress1;
// 	int *emptyDress2 = NULL;
// 	cout << "空指针一的地址是" << emptyDress1 << endl;
// 	cout << "空指针二的地址是" << emptyDress2 << endl;
// 	if(emptyDress2)
// 	{
// 		cout << "2不是空指针" << endl;
// 	}
// 	if(!emptyDress2)
// 	{
// 		cout << "2是空指针" << endl;
// 	}
// 	int adressArry[] = {11,33,44,66,77,88};
// 	int *arryAdress = adressArry;
// 	for(int i = 0; i < 6; i++)
// 	{
// 		cout << "index为" << i << "地址是" << arryAdress;
// 		cout << "值是" << *arryAdress << endl;
// 		arryAdress++;
// 	}

// 	char *stringArryAdress[5];
// 	char charA = 'a';
// 	char charB = 'b';
// 	char charC = 'c';
// 	char charD = 'd';
// 	char charE = 'e';

// 	stringArryAdress[0] = &charA;
// 	stringArryAdress[1] = &charB;
// 	stringArryAdress[2] = &charC;
// 	stringArryAdress[3] = &charD;
// 	stringArryAdress[4] = &charE;

// 	int dresstoDressInt = 1596;
// 	int *dresstoDress;
// 	int **dresstoDressto;
// 	dresstoDress = &dresstoDressInt;
// 	dresstoDressto = &dresstoDress;

// 	cout << "指向指针的指针的值是：" << dresstoDressto << endl;
// 	cout << "他指向的地址的值是：" << *dresstoDressto << endl;
// 	cout << "他指向的指针的值是：" << dresstoDress << endl;
// 	cout << "他指向的指针指向的地址的值是 ：" << **dresstoDressto << endl;
// 	cout << "int 的地址是" << &dresstoDressInt << endl;


// 	int numberText = 100;
// 	int *adressNumberText = &numberText;
// 	cout  << "当前数值：" << numberText << endl;
// 	numberText = 500;
// 	cout << "更改后是数值 ：" << numberText << endl;
// 	*adressNumberText = 600;
// 	cout << "更改二次后的数值: " << numberText << endl;


// 	FirstStrc fStrc;
// 	FirstStrc *fStrcAdress;

// 	fStrcAdress = &fStrc;
// 	fStrc.aaa = 100;
// 	fStrc.bbb = 200;
// 	strcpy(fStrc.ccc, "wqqwqe");

// 	cout << fStrc.aaa << endl;
// 	cout << fStrc.bbb<< endl; 
// 	cout << fStrc.ccc << endl; 
// 	cout << "aaaaaaaaaaaaaaaaaaaaaaaaaaaa" << endl; 
// 	cout << fStrcAdress->aaa << endl;
// 	cout << fStrcAdress->bbb<< endl; 
// 	cout << fStrcAdress->ccc << endl; 

// 	cout << "aaaaaaaaaaaaaaaaaaaaaaaaaaaa" << endl; 
// 	cout << (*fStrcAdress).aaa << endl;
// 	cout << (*fStrcAdress).bbb<< endl; 
// 	cout << (*fStrcAdress).ccc << endl; 

// 	cout << "aaaaaaaaaaaaaaaaaaaaaaaaaaaa" << endl; 
// 	fStrcAdress->aaa = 123456;

// 	cout << fStrc.aaa << endl;

// 	cout << "更改之前是结构体内的值为 ： " << fStrc.aaa << endl;

// 	ChangeStruct(&fStrc);

// 	cout << "更改之后的结构体内的值为：" << fStrc.aaa << endl;

// 	return 0;
// }

