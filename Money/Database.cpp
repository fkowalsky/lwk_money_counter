#include "Database.h"

Database::Database()
{
	coins = vector<Coin*>();
}

bool Database::Initialize()
{
	// 1 grosz.
	Coin* m_Coin = new Coin();
	m_Coin->LoadImage("money/1.png");
	m_Coin->SetValue(1);
	coins.push_back(m_Coin);

	// 2 grosze.
	m_Coin = new Coin();
	m_Coin->LoadImage("money/2.png");
	m_Coin->SetValue(2);
	coins.push_back(m_Coin);

	// 5 groszy.
	m_Coin = new Coin();
	m_Coin->LoadImage("money/5.png");
	m_Coin->SetValue(5);
	coins.push_back(m_Coin);

	// 10 groszy.
	m_Coin = new Coin();
	m_Coin->LoadImage("money/10.png");
	m_Coin->SetValue(10);
	coins.push_back(m_Coin);

	// 20 groszy.
	m_Coin = new Coin();
	m_Coin->LoadImage("money/20.png");
	m_Coin->SetValue(20);
	coins.push_back(m_Coin);

	// 50 groszy.
	m_Coin = new Coin();
	m_Coin->LoadImage("money/50.png");
	m_Coin->SetValue(50);
	coins.push_back(m_Coin);

	// 1 zloty.
	m_Coin = new Coin();
	m_Coin->LoadImage("money/100.png");
	m_Coin->SetValue(100);
	coins.push_back(m_Coin);

	// 2 zlote.
	m_Coin = new Coin();
	m_Coin->LoadImage("money/200.png");
	m_Coin->SetValue(200);
	coins.push_back(m_Coin);

	// 5 zloty.
	m_Coin = new Coin();
	m_Coin->LoadImage("money/500.png");
	m_Coin->SetValue(500);
	coins.push_back(m_Coin);

	return true;
}

vector<Coin*> Database::GetMoney()
{
	return coins;
}