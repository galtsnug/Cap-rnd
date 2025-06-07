#include "rnd.h"

using namespace std;

int main()
{
	while (true)
	{
		int prior;
		int costOffset;
		int numRolls;
		char kg;
		bool keepGoing;

		cout << "Prior: ";
		cin >> prior;
		cout << endl <<
			"Cost Offset: ";
		cin >> costOffset;
		cout << endl <<
			"Number of Rolls: ";
		cin >> numRolls;
		while (true)
		{
			cout << endl <<
				"Keep Going if failed? (y/n only): ";
			cin >> kg;
			if (kg == 'y' || kg == 'Y')
			{
				keepGoing = true;
				break;
			}
			else if (kg == 'n' || kg == 'N')
			{
				keepGoing = false;
				break;
			}
			else
			{
				cout << endl << "Invalid input";
			}
		}

		cout << endl;

		rnd a = rnd(prior, costOffset, keepGoing);

		for (int i = 0; i < numRolls; i++)
		{
			while (true)
			{
				bool result = a.roll();
				if (result)
				{
					cout << endl;
					i -= a.cost();
					break;
				}
			}
			a.reset();
			a.incPrior();
		}
		cout << "All completed, wish to do more rolls? (-1 to end, anything else to continue):";
		int b;
		cin >> b;
		cout << endl << endl;

		if (b == -1)
			break;
		b = 0;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		sleep(1);
	}
	return 0;
}


