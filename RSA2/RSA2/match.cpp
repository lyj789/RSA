#include "match.h"


BigInt match::gcd(BigInt a, BigInt b)
{
	if (b == BigInt(0)) 
		return a;
	else 
		return gcd(b, a%b);
}

BigInt match::mod_fast(BigInt a, BigInt b, BigInt p)
{
	BigInt aa = a, t(1), k(2);
	while (b!=BigInt(0))
	{
		if ((b%k) != BigInt(0))
		{
			t = (t%p)*(aa%p) % p;
		}
		aa = (aa%p)*(aa%p) % p;
		b = b / k;
	}
	return t%p;
}

BigInt match::extgcd(BigInt a, BigInt b, BigInt & x, BigInt & y)
{
	//cout << "extgcd" << endl;
	BigInt d=a;
	//cout << a << "  "<<b<<endl;
	//cout << d << endl;

	if (b != BigInt(0)) {
		d = extgcd(b, a % b, y, x);
		y = y - (a / b) * x;
	}
	else {
		x = BigInt(1);
		y = BigInt(0);
	}
	//cout << x << endl;
	//cout << d<<endl;
	return d;
}

BigInt match::inverse(BigInt a,BigInt m)
{
	//cout << "inverse" << endl;
	BigInt x, y;
	BigInt temp=extgcd(a, m, x, y);
	if (temp == BigInt(1))
	{
		//cout << (x%m + m) % m << endl;
		return (x%m + m) % m;
	}
	else
		return -1;

}
