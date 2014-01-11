#ifndef _COIN_H_
#define _COIN_H_
#include <string.h>
#include <iostream>
using namespace std;

class Coin
{
public:
	Coin();

	void LoadImage(string);
	string GetImage();

	void SetValue(int);
	int GetValue();

private:
	string Address;
	int Value;

};

#endif