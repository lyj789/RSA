#pragma once
#include"BigInt2.h"
class match
{
public:

	BigInt gcd(BigInt a, BigInt b);//ŷ�������GCD
	BigInt mod_fast(BigInt a, BigInt b, BigInt p);//������ģ
    BigInt extgcd(BigInt a, BigInt b, BigInt &x, BigInt &y);//��չŷ�����ʵ�ֳ˷���
	BigInt inverse(BigInt a, BigInt m);//��aģm����Ԫ


};
