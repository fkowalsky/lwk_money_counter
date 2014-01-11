#include "ShowEffect.h"
#include "CameraEffect.h"
#include "FiltrCanny.h"
#include "FiltrLaplace.h"
#include "FiltrSobel.h"
#include "FiltrHough.h"
#include "Database.h"
using namespace std;

int main(int argc, char** argv)
{
	bool result;
	
	// Create and Initialize the Database object.
	Database* m_Database = new Database();
	result = m_Database->Initialize();
	if(!result)
		return -1;

	vector<Coin*> m_Money = m_Database->GetMoney();

	// Create and Initialize ShowImage object.
	ShowEffect* m_Show = new ShowEffect();
	result = m_Show->Initialize(0, 0);
	if(!result)
		return -1;

	// Create and Initialize the Canny object.
	FiltrCanny* m_Canny = new FiltrCanny();
	m_Canny->SetEdgeTresh(1);
	m_Canny->SetLowThreshold(5);
	m_Canny->SetMaxLowTreshold(100);
	m_Canny->SetRatio(3);
	m_Canny->SetKernelSize(3);
	m_Canny->Initialize();

	// Render all moneys in new window.
	for(int i=0; i<m_Money.size(); i++)
	{
		// Convert int to string.
		string text;
		ostringstream ss;
		ss << m_Money[i]->GetValue();
		text = "Money " + ss.str();

		// Convert string to char*.
		char* char_type = new char[text.length()];
		strcpy(char_type, text.c_str());

		// Set parameters to ShowEffect object.
		m_Show->SetTitle(char_type);
		m_Show->SetText("");

		// Render the FiltrCanny object.
		m_Canny->Render(imread(m_Money[i]->GetImage(),1));
		
		// Render the ShowEffect object.
		m_Show->SetImage(m_Canny->GetMatrix());
		m_Show->Render();
	}

	// Create and Initialize the Hough object.
	FiltrHough* m_Hough = new FiltrHough();
	m_Hough->Initialize();
	
	// Render the Hough object.
	result = m_Hough->Render(imread(argv[1], 1));
	if(!result)
	{
		cout << "Could not rendered the Hough object!" << endl;
	}

	// Set parameters to the ShowEffect object.
	m_Show->SetTitle("Hough");
	m_Show->SetText("Filtr: Hough");
	m_Show->SetImage(m_Hough->GetMatrix());
		
	// Render the ShowEffect object.
	result = m_Show->Render();
	if(!result)
	{
		cout << "Could not render the ShowImage object!" << endl;
	}

	// Get all moneys.
	Vector<Mat> Matrixes = m_Hough->GetMatrixes();

	// Render all moneys in new window.
	for(int i=0; i<Matrixes.size(); i++)
	{
		// Convert int to string.
		string text;
		ostringstream ss;
		ss << i;
		text = ss.str();

		// Convert string to char*.
		char* char_type = new char[text.length()];
		strcpy(char_type, text.c_str());

		// Set parameters to ShowEffect object.
		m_Show->SetTitle(char_type);
		m_Show->SetText("");

		// Render the FiltrCanny object.
		m_Canny->Render(Matrixes[i]);
		
		// Render the ShowEffect object.
		m_Show->SetImage(m_Canny->GetMatrix());
		m_Show->Render();
	}

	// Destroy the ShowEffect object.
	if(m_Show)
	{
		m_Show->Shutdown();
		delete m_Show;
		m_Show = 0;
	}

	// Destroy the FiltrCanny object.
	if(m_Canny)
	{
		m_Canny->Shutdown();
		delete m_Canny;
		m_Canny = 0;
	}

	// Destroy the FiltrHough object.
	if(m_Hough)
	{
		m_Hough->Shutdown();
		delete m_Hough;
		m_Hough = 0;
	}

	waitKey(0);
	return 0;
}