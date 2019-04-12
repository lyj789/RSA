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

	cout << "请输入明文：";
	string message;// = "525341";RSA
	cin >> message;
	BigInt m(message, 16);

	cout << "明文为：" << message << endl;

	BigInt c = rsa.encrypt(m);
	cout << "密文为：" << c << endl;

	cout << "解密结果为：" << rsa.decode(c).toStr(16) << endl;

	system("pause");
}