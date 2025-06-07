#include "rnd.h"

using namespace std;

int prior;
int successes;
int fails;
int faults;

int costOffset;
int totalCost;

bool keepGoing;

rnd::rnd(int p, int co, bool kg)
{
	prior = p;
	costOffset = co + 3;
	keepGoing = kg;
	successes = 0;
	fails = 0;
	faults = 0;
	totalCost = 0;

	srand(time(0));
}

void rnd::reset()
{
	successes = 0;
	fails = 0;
	faults = 0;
}


bool rnd::roll()
{
	cout << (result(rand() % 20 + 1 + prior)) << ", "; 
	if (successes >= 3 || fails >= 3)
		return true;

	return false;
}

int rnd::result(int r)
{
	if (r >= 23)
	{
		//R&D overall succeeds
		successes = 3;
		totalCost += (rand()%20+1);
		return r;
	}
	else if (r >= 18)
    	{
		// Success w/o fault
        	successes++;
        	totalCost += (rand()%20+1);
		return r;
    	}
    	else if (r >= 14)
    	{
		// Success w/ fault
        	successes++;
        	faults++;
		totalCost += (rand()%20+1);
		return r;
    	}
	else if (r >= 7)
    	{
		// Costing, but no progress
        	totalCost += (rand()%20+1);
		return r;
    	}
    	else if (r >= 1)
    	{
		// Failure
        	fails++;
        	totalCost += (rand()%20+1);
		return r;
    	}
	return r;
}

int rnd::cost()
{
	if (fails < 3)
	{
		cout << "Faults: " << faults << ", " << fails << " crit faults" << endl;
	}

	cout << "Total cost: ";
	
	string tc = to_string(totalCost);
	
	for (int i = 0; i < (costOffset); i++)
		tc += "0";
	
	int a;

	if ((tc.length() % 3) > 0)
		a = 0;
	else
		a = 1;


	for (int i = tc.length(); i > a; i-=3)
		tc.insert(i, ",");	

	
	cout << tc;

	if (successes >= 3)
	{
		if (faults >= 1 || fails >= 1)
		{
			cout << "success, redoing to remove fault." << endl << endl;
			return 1;
		}
		else
		{
			cout << " success." << endl << endl;
			return 0;
		}
	}
	else if (keepGoing)
	{
		cout << " failed." << endl << endl;
		return 1;
	}
	cout << " failed." << endl << endl;
	return 0;
}

void rnd::incPrior()
{
	if (prior < 7) prior++;
}
