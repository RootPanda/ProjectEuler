#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <queue>

using namespace std;

int main() 
{
	int days_in_month[] = {	31, 28, 31, 30, 31, 30, 
				31, 31, 30, 31, 30, 31};

	int days_in_month_leap[] = {	31, 29, 31, 30, 31, 30, 
					31, 31, 30, 31, 30, 31};
	int runningTotalDays = 1;
	queue<int> first_days_of_month;
	for (int y = 1900; y <= 2000; y++)
	{
		int * d_in_m = 0;
		if (y % 4 == 0 && y != 1900)
		{
			d_in_m = days_in_month_leap;
		}
		else
		{
			d_in_m = days_in_month;
		}
		for (int m = 0; m < 12; m++)
		{
			runningTotalDays += ((int *)d_in_m)[m];
			if (y > 1900)
			{
				first_days_of_month.push(runningTotalDays);
			}
			//cout << y << " " << m << " " << runningTotalDays << endl;
		}
	}
	int totalSundays = 0;
	while (!first_days_of_month.empty())
	{
		if (first_days_of_month.front() % 7 == 0)
		{
			totalSundays++;
		}
		first_days_of_month.pop();
	}
	cout << "Answer: " << totalSundays << endl;
}
