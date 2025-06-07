#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>
#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <random>

class rnd
{
	
	public:
		rnd(int, int, bool);
		bool roll();
		int result(int);
		int cost();
		void reset();
		void incPrior();
};
