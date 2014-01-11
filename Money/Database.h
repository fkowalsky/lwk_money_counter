#ifndef _DATABASE_H_
#define _DATABASE_H_
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include "Coin.h"
using namespace std;

class Database
{
public:
	Database();

	bool Initialize();
	vector<Coin*> GetMoney();

private:
	vector<Coin*> coins;

};

#endif