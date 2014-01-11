#include "Coin.h"

Coin::Coin()
{
	Address = "";
	Value = 0;
}

void Coin::LoadImage(string Address)
{
	this->Address = Address;
}

void Coin::SetValue(int Value)
{
	this->Value = Value;
}

string Coin::GetImage()
{
	return Address;
}

int Coin::GetValue()
{
	return Value;
}