#include"BigInt2.h"
#include"RSA2.h"
#include"match.h"
#include<iostream>

using namespace std;
int main()
{
	cout << "hhhh" << endl;
	RSA2 rsa;
	rsa.init(512);

	cout << "���������ģ�";
	string message;// = "525341";RSA
	cin >> message;
	BigInt m(message, 16);

	cout << "����Ϊ��" << message << endl;

	BigInt c = rsa.encrypt(m);
	cout << "����Ϊ��" << c << endl;

	cout << "���ܽ��Ϊ��" << rsa.decode(c).toStr(16) << endl;

	system("pause");
}