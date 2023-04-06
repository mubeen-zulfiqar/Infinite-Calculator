#pragma once
#include<iostream>
#include<string>
using namespace std;
class HugeInteger
{
private:
	char* data;
	int size;
public:
	HugeInteger();
	HugeInteger(int size);
	HugeInteger(const HugeInteger& hugeinteger);
	friend istream& operator>>(istream& in, HugeInteger& hugeinteger);
	friend ostream& operator<<(ostream& out, HugeInteger& hugeinteger);
	bool operator ==(HugeInteger& hugeinteger);
	bool operator !=(HugeInteger& hugeinteger);
	bool operator <(HugeInteger& hugeinteger);
	bool operator >(HugeInteger& hugeinteger);
	bool operator <=(HugeInteger& hugeinteger);
	bool operator >=(HugeInteger& hugeinteger);
	void complement(int noOfDigits);
	HugeInteger& operator =(const HugeInteger& hugeinteger);
	HugeInteger operator +(HugeInteger& hugeinteger);
	HugeInteger operator -(HugeInteger& hugeinteger);
	HugeInteger operator *(HugeInteger& hugeinteger);
	inline void operator ++(int );
	void operator --(int);
	HugeInteger operator /(HugeInteger& hugeinteger);
	void squareRoot();
	~HugeInteger();
};