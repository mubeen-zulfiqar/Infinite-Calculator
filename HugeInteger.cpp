#include"HugeInteger.h"
using namespace std;
HugeInteger::HugeInteger()
{
	size=0;
	data = nullptr;
}
HugeInteger::HugeInteger(int size)
{
	this->size = size;
	this->data = new char[size+1];
	*(this->data + size) = '\0';
}
HugeInteger::HugeInteger(const HugeInteger& hugeinteger)
{
	this->size = hugeinteger.size;
	this->data = new char[size];
	for (int i = 0; i < size; i++)
	{
		*(data + i) = *(hugeinteger.data + i);
	}
}
istream& operator>>(istream& in, HugeInteger& hugeinteger)
{
	if (hugeinteger.data != nullptr)
	{
		delete[]hugeinteger.data;
		hugeinteger.data = nullptr;
	}
	cout << "Enter your Integer :\n";
	string temp;
	while (in.peek() == '0')
	{
		in.ignore(1);
	}
	getline(in, temp, '\n');
	//cout <<"length : " <<temp.length();
	hugeinteger.size=(temp.length()+1);
	//cout << "size : " << hugeinteger.size<<'\n';
	hugeinteger.data = new char[hugeinteger.size];
	for (int i = 0; i < hugeinteger.size; i++)
	{
		*(hugeinteger.data + i) = temp[i];
	}
	if (hugeinteger.size == 1)
	{
		//cout << "***";
		delete[] hugeinteger.data;
		hugeinteger.data = new char[2];
		*(hugeinteger.data + 0) = int('0');
		*(hugeinteger.data + 1) = '\0';
		hugeinteger.size ++;
	}
	//cout << "data : " << hugeinteger.data;
	return in;
}
ostream& operator<<(ostream& out, HugeInteger& hugeinteger)
{
	if (((*hugeinteger.data + 0) == int ('0') && *(hugeinteger.data + 1) == int( '0')) || (*hugeinteger.data + 0) == '\0')
		out << 0<<'\n';
	else {
		out << hugeinteger.data;
		out << '\n';
	}
	return out;
}
bool HugeInteger::operator ==(HugeInteger& hugeinteger)
{
	bool verify = true;

	for (int i = 0;*(data+i)!='\0'|| *(hugeinteger.data+i)!='\0' ;i++)
	{
		if (*(data + i) != *(hugeinteger.data + i))
		{
			verify = false;
			return verify;
		}
	}

	return verify;
}
bool HugeInteger::operator!=(HugeInteger& hugeinteger)
{
	bool verify = false;

	for (int i = 0; *(data + i) != '\0' || *(hugeinteger.data + i) != '\0'; i++)
	{
		if (*(data + i) != *(hugeinteger.data + i))
		{
			verify = true;
			return verify;
		}
	}

	return verify;
}
bool HugeInteger::operator <(HugeInteger& hugeinteger)
{
	if (*this != hugeinteger)
	{
		bool verify = true;
		if (size < hugeinteger.size)
		{
			return verify;
		}
		else if (size > hugeinteger.size)
		{
			verify = false;
			return verify;
		}
		else {
			for (int i = 0; i < size - 1; i++)
			{
				if (*(data + i) > * (hugeinteger.data + i))
				{
					verify = false;
					return verify;
				}
				else if (*(data + i) < *(hugeinteger.data + i))
				{
					verify = true;
					return verify;
				}

			}
		}
	}
	else return false;
}
bool HugeInteger::operator >(HugeInteger& hugeinteger)
{
	if (*this != hugeinteger)
	{
		bool verify = true;
		if (size > hugeinteger.size)
		{
			return verify;
		}
		else if (size < hugeinteger.size)
		{
			verify = false;
			return verify;
		}
		else {
			for (int i = 0; i < size - 1; i++)
			{
			
				if (*(data + i) < * (hugeinteger.data + i))
				{
					verify = false;
					return verify;
				}
				else if (*(data + i) > *(hugeinteger.data + i))
				{
					verify = true;
					return verify;
				}

			}
		}
	}
	else return false;
}
bool HugeInteger::operator<=(HugeInteger& hugeinteger)
{
	if (*this == hugeinteger)
		return true;
	else if (*this < hugeinteger)
		return true;
	else
	return false;
}
bool HugeInteger::operator >=(HugeInteger& hugeinteger)
{
	if (*this == hugeinteger)
		return true;
	else if (*this > hugeinteger)
		return true;
	else
		return false;
}
void HugeInteger::complement(int noOfDigits)
{

	for (int i = 0; i < size - 1; i++)
	{
		*(data + i) = int('9') - (*(data + i)) + int('0');
	}
	*(data + size - 2) = *(data + size - 2) + 1;

	char* temp = new char[size];
	for (int j = 0; j < size; j++)
	{
		*(temp + j) = *(data + j);
	}
	delete[] data;
	data = new char[noOfDigits];
	for (int k = 0; k < noOfDigits - size; k++)
	{
		*(data + k) = int('9');
	}
	for (int x = noOfDigits - size, y = 0; x < noOfDigits; x++, y++)
	{
		*(data + x) = *(temp + y);
	}
	delete[] temp;
	size = noOfDigits;
}
HugeInteger& HugeInteger::operator =(const HugeInteger& hugeinteger)
{
//	cout << "Operator = Called\n";
	this->size = hugeinteger.size;
	if (data != nullptr)
	{
		delete[] data;
		data = nullptr;
	}
	this->data = new char[size];
	for (int i = 0; i < size; i++)
	{
		*(data + i) = *(hugeinteger.data + i);
	}
	return *this;
}
HugeInteger HugeInteger:: operator +(HugeInteger& hugeinteger)
{
	HugeInteger temp;
	if ( *(data) == int('0') && *(hugeinteger.data) == int('0'))
	{
		//cout << size;
		//cout << data;
		return *this;
	
	}
	temp.size = size ;
	if (temp.size < hugeinteger.size)
		temp.size = hugeinteger.size;
	temp.size ++;
	temp.data = new char[temp.size];
	*(temp.data + temp.size-1) = '\0';
	int carry = 0;
	for (int i = temp.size - 2, j = size - 2, k = hugeinteger.size - 2; i > 0; i--, j--, k--)
	{
		if  (((*(data + j) + *(hugeinteger.data + k)) % int('0') + int('0') + carry <=  int('9') && (k>=0 && j>=0 ))||
				((*(hugeinteger.data + k)) % int('0') + int('0') + carry <= int('9') && j<0)||
				((*(data + j) ) % int('0') + int('0') + carry <= int('9') && k<0))
			{
				if (k < 0)
				{
					*(temp.data + i) = (*(data + j) +carry);
				}
				else if (j < 0)
				{
					*(temp.data + i) = (*(hugeinteger.data + k) +carry);
				}
				else
				{
					*(temp.data + i) = (((*(data + j) + *(hugeinteger.data + k)) % int('0') + int('0')) + carry);
				}
				carry = 0;
			}
		else
			{
			if (k >= 0 && j >= 0)
			{
				*(temp.data + i) = ((*(data + j) % int('0') + *(hugeinteger.data + k) % int('0')) + carry) % 10 + int('0');
				carry = (((*(data + j) % int('0') + *(hugeinteger.data + k) % int('0') + carry)) / 10);
			}
			else if (k < 0)
			{
				*(temp.data + i) = (*(data + j) % int('0') + carry) % 10 + int('0');
				carry = (*(data + j) % int('0') + carry) / 10;
			}
			else if (j < 0)
			{
				*(temp.data + i) = ((*(hugeinteger.data + k)% int('0') + carry) %10 + int('0'));
				carry = (*(hugeinteger.data + k) % int('0') + carry) / 10;
			}

			}
		}
		
		*(temp.data + 0) = carry + int('0');
	
		if (*(temp.data + 0) == int{ '0' })
		{
			for (int x = 0; x < temp.size-1; x++)
			{
				*(temp.data + x) = *(temp.data + x + 1);
			}
			temp.size--;
		}
		//cout << "data is : "<<temp.data;
	return temp;
}
HugeInteger HugeInteger:: operator -(HugeInteger& hugeinteger)
{
	if (*(data + 0) == int('0') && *(hugeinteger.data + 0) == int('0'))
	{
		return *this;
	}
	else if (*(data + 0) == int( '0' ))
	{
		HugeInteger h = hugeinteger;
		delete[] h.data;
		h.size++;
		h.data = new char[h.size];
		for (int p = 0; p < hugeinteger.size; p++)
		{
			*(h.data + p+1) = *(hugeinteger.data + p);
		}
		*(h.data) = int('-');
		return h;
	
	}
	else if (*(hugeinteger.data + 0) == int{ '0' })
		return *this;

	HugeInteger temp;
	HugeInteger hi1 = *this;
	HugeInteger hi2 = hugeinteger;
	bool check,equal =false;
	if ((*this) == hugeinteger)
	{
		equal = true;
	}
	if (*this > hugeinteger)
	{
		check = true;
		hugeinteger.complement(size);
	}
	else 
	{
		check = false;
		(*this).complement(hugeinteger.size);

	}

	temp = ((*this) + hugeinteger);
	if (check || equal )
	{
		for (int x = 0; x < temp.size - 1; x++)
		{
			*(temp.data + x) = *(temp.data + x + 1);
		}
		temp.size--;
	}
	else
	{
		*(temp.data + 0) = int('-');
	}
	while (*temp.data == '0')
	{
		for(int m = 0; m < temp.size - 1; m++)
		{
			*(temp.data + m) = *(temp.data + m + 1);
		}
		temp.size--;
	}

	 *this =hi1 ;
	 hugeinteger=hi2 ;
	return temp;
	
}
HugeInteger HugeInteger:: operator *(HugeInteger& hugeinteger)
{
	HugeInteger temp;
	temp.size = size + hugeinteger.size -1;
	temp.data = new char[temp.size];
	*(temp.data) = int('0');
	*(temp.data + temp.size -1) = '\0';
	int sum=0,carry=0;
	int place = temp.size - 2;
	for (int i = size - 2, j = hugeinteger.size - 2; i >= 0 && j>=0; i--)
	{

		sum = (((*(data + i)) % int('0')) * (*(hugeinteger.data + j) % int('0')) + carry);
		carry = 0;
		for (int k = i + 1, l = j - 1; l>=0 && k<=size -2  ;k++,l--)
		{
				sum = sum + ((*(data + k) % int('0')) * (*(hugeinteger.data + l) % int('0')) );
		}
		
		if (sum  <= 9)
		*(temp.data + place) = sum  + int ('0') ;
		else 
		{
			*(temp.data + place) = (sum % 10)+ int('0');
			carry = (sum / 10);;
		}
		*(temp.data + 0) = (carry) + int('0'); 
		place--;
		sum = 0;
		if(i==0)
		{
			i++;
			j--;
		}
	}
	if (*(temp.data) == int('0'))
	{	
		for (int x = 0; x < temp.size - 1; x++)
		{
			*(temp.data + x) = *(temp.data + x + 1);
		}
		temp.size--;
	}
	return temp;
}
inline void HugeInteger::operator ++(int)
{
	HugeInteger one;
	one.data = new char[2];
	*(one.data + 0) = int('1');
	*(one.data + 1) = '\0';
	one.size = 2;
	(*this) = *(this) + one;
}
void HugeInteger::operator --(int)
{
	HugeInteger one;
	one.data = new char[2];
	*(one.data + 0) = int('1');
	*(one.data + 1) = '\0';
	one.size = 2;
	(*this) = *(this) - one;
}
HugeInteger HugeInteger::operator /(HugeInteger& hugeinteger)
{
	HugeInteger counter;
	counter.data = new char[2];
	*(counter.data + 0) = int('1');
	*(counter.data + 1) = '\0';
	counter.size = 2;

	HugeInteger multiplier = hugeinteger;
	if (((*multiplier.data) % int('0')) == 0 || ((*data) % int('0')) == 0 || multiplier.size>size)
	{
		(*counter.data) = int('0');
	}
	else if (this->size == hugeinteger.size)
	{
		(*counter.data) = ((((*data) % int('0')) / ((*multiplier.data) % int('0'))) + int('0'));
	}
	else {
		HugeInteger sizedifference;
		sizedifference.size = this->size - hugeinteger.size + 1;
		sizedifference.data = new char[sizedifference.size];
		//cout << "\nsize : " << sizedifference.size;
		*(sizedifference.data + 0) = int('1');
		*(sizedifference.data + sizedifference.size - 1) = '\0';
		for (int s = 1; s < sizedifference.size - 1; s++)
		{
			*(sizedifference.data + s) = int('0');
		}
	
		for (int p = 1; sizedifference.size >= 2; p++)
		{
			while (((counter + sizedifference) * multiplier) <= *this)
			{
				counter = counter + sizedifference;
				//cout << "counter by size difference " << counter << '\n';
			}
			//cout << "loop break \n";
			delete[] sizedifference.data;
			sizedifference.data = nullptr;
			sizedifference.size = this->size - hugeinteger.size + 1 - p;
			sizedifference.data = new char[sizedifference.size];
			//cout << "size : " << sizedifference.size;
			*(sizedifference.data + 0) = int('1');
			*(sizedifference.data + sizedifference.size - 1) = '\0';
			for (int s = 1; s < sizedifference.size - 1; s++)
			{
				*(sizedifference.data + s) = int('0');
			}
			//cout << "updated data of sizedifference : " << sizedifference << '\n';



		}
		//cout << "outer loop break \n";
	}
	return counter;
}
void HugeInteger::squareRoot()
{
	HugeInteger counter;
	counter.data = new char[2];
	counter.size = 2;
	*(counter.data + 0) = '0';
	*(counter.data + 1) = '\0';

	HugeInteger adder;
	adder.size = ((size - 1) / 2) + 1;
	adder.data = new char[size];
	*(adder.data + 0) = int('1');
	*(adder.data + adder.size-1) = '\0';
	for (int i = 1; i < adder.size - 1; i++)
	{
		*(adder.data + i) = int('0');
	}
	
	for (int p=1;adder.size>=2;p++)
	{
		HugeInteger check = (counter + adder);
		while (check * check < *this)
		{
			check = (counter + adder);
			counter = counter + adder;
			//counter = counter + adder;
			//cout << "Alhamdulillah\n";
		}
		counter = counter - adder;
		//cout << "loop bleak\n";
		//cout << "counter : " << counter << '\n';
		delete[]adder.data;
		adder.data = nullptr;
		adder.size = (((size - 1) / 2) + 1 -p);
		//cout << "Updated adder.size : " << adder.size << '\n';
		adder.data = new char[size];
		*(adder.data + 0) = int('1');
		*(adder.data + adder.size - 1) = '\0';
		for (int k = 1; k < adder.size - 1;k++)
		{
			*(adder.data + k) = int('0');
		}
	}

	while ((counter * counter) < *this)
	{
		counter++;
	}
	*this = counter;
}
HugeInteger::~HugeInteger()
{
	delete[] data;
	data = nullptr;
}

