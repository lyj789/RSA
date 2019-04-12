#include "RSA2.h"
#include"match.h"
#include<ctime>
#include<iostream>
#include<sstream>
#include <stdlib.h>
using namespace std;

RSA2::RSA2()
{
}

RSA2::~RSA2()
{
}

void RSA2::init(unsigned int n)
{
	//p,q,n,phi,e,d
	match mat;
	p = createPrime(n, 5); //���Լ���5�ξͿ���
	q = createPrime(n, 5);
	N = p * q;
	phi = (p - 1)*(q - 1);
	cout << "p:" << p << endl;
	cout << "q:" << q << endl;
	cout << "N:" << N << endl;
	cout << "phi:" << phi << endl;
	e = 65537;
	d = mat.inverse(e, phi); 
	cout << "e:" << e << endl;
	cout << "d:" << d<<endl;
	//d = e.extendEuclid(phi);
	cout << "---------׼���������------------" << endl;
	/*BigInt a(16);
	cout<<isPrime(a,4);*/
}

BigInt RSA2::encrypt(const BigInt & m)
{
	//c=m^e (modn)
	BigInt c;
	match mat;
	c = mat.mod_fast(m, e, N);
	return c;
}

BigInt RSA2::decode(const BigInt & c)
{
	//m=c^d(modn)
	BigInt m;
	match mat;
	m = mat.mod_fast(c, d, N);
	return m;
}
//����һ������
BigInt RSA2::createPrime(unsigned int n, unsigned int k)
{
	cout << "������������..." << endl;
	BigInt p = random_odd(n);
	//cout << "���ɵ��������Ϊ��" << p << endl;
	while (isPrime(p, k) == false)
	{
		p = p + BigInt(2);
		//cout << "p+2:" << p<<endl;
	}
	return p;
}

//��������
BigInt RSA2::random_odd(unsigned int n)
{
	n = n >> 2;   // ʮ����������,ÿλռ4λ������
	srand((unsigned)time(NULL));

	static unsigned char hex_table[] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
	if (n)
	{
		ostringstream oss;
		for (int i = 0; i < n - 1; i++)
		{			
			oss << hex_table[rand() % 16];
		}
			
		oss << hex_table[1];
		return BigInt(oss.str(),16);
	}
	else
		return BigInt(0);
}

//�ж��Ƿ�Ϊ����
bool RSA2::isPrime(const BigInt & n, unsigned int k)
{
	BigInt m = n - 1;
	string str=m.toStr(2);
	//cout << str << endl;
	for (int i = 0; i < k; i++)
	{
		//cout << "��" << i + 1<< "���ж�..." << endl;
		BigInt a = random_a(m);
		//cout << "���ɵ������aΪ��" << a << endl;
		BigInt d=1;
		for (int j = 0; j <str.size(); j++)
		{
			BigInt x = d;
			d = (d*d) % n;
			/*cout << "++++++  "<<d << endl;
			cout << "------  " << x << endl;*/
			if (d == BigInt(1) && x != BigInt(1) && x != m)
			{
				return false;
			}
		//	cout << "==="<<str[j] << endl;
			if (str[j]=='1')
			{
				d = (a*d) % n;
			}
		}
		if (d != BigInt(1))
		{
			return false;
		}
	}
	return true;
}

//���Լ�������Ҫ����һ������1С��n-1�������
BigInt RSA2::random_a(const BigInt & n)
{

	unsigned long t = 0;
	do
	{
		t = rand();
	} while (t == 0);

	BigInt mod(t);
	BigInt r = mod%n;
	if (r == BigInt(0))
		r = n - BigInt(1);
	return r;
}
