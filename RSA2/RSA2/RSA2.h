#pragma once
#include"BigInt2.h"
class RSA2
{
public:
	BigInt e, N;
private:
	BigInt p, q;
	BigInt d;
	BigInt phi;

public:
	RSA2();
	~RSA2();
	void init(unsigned int n);//��ʼ��������P,Q����������
public:
	BigInt encrypt(const BigInt& m);//��Կ����
	BigInt decode(const BigInt& c);//˽Կ����
private:
	BigInt random_odd(unsigned int n);//���ɳ���Ϊn������
	bool isPrime(const BigInt& n, unsigned int k);//Miller-Rabin���Լ���
	BigInt createPrime(unsigned int n, unsigned int k);//���ɳ���Ϊn������
	BigInt random_a(const BigInt& n);//�������Լ����е�a�����

};

