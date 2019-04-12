#pragma once
#include"BigInt2.h"
class match
{
public:

	BigInt gcd(BigInt a, BigInt b);//欧几里德求GCD
	BigInt mod_fast(BigInt a, BigInt b, BigInt p);//快速幂模
    BigInt extgcd(BigInt a, BigInt b, BigInt &x, BigInt &y);//扩展欧几里德实现乘法逆
	BigInt inverse(BigInt a, BigInt m);//求a模m的逆元


};
