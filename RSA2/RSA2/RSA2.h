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
	void init(unsigned int n);//初始化，产生P,Q两个大素数
public:
	BigInt encrypt(const BigInt& m);//公钥加密
	BigInt decode(const BigInt& c);//私钥解密
private:
	BigInt random_odd(unsigned int n);//生成长度为n的奇数
	bool isPrime(const BigInt& n, unsigned int k);//Miller-Rabin素性检验
	BigInt createPrime(unsigned int n, unsigned int k);//生成长度为n的素数
	BigInt random_a(const BigInt& n);//产生素性检验中的a随机数

};

