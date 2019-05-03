#include <iostream>

using namespace std;

class clock
{
	private:
		int hour;
		int min;
		int sec;
	public:
		clock(int new_hour = 0, int new_min = 0, int new_sec = 0)
		{
			if (new_hour < 24 && new_hour >= 0)
			{
				hour = new_hour;
			}
			if (new_min < 60 && new_min >= 0)
			{
				min = new_min;
			}
			if (new_sec < 60 && new_sec >= 0)
			{
				sec = new_sec;
			}
		}
		void setHour(int hour)
		{
			if (hour < 0 || hour>24)
			{
				this->hour = 0;
			}
			else
				this->hour = hour;
		}
		void setMin(int min)
		{
			if (min < 0 || min>60)
			{
				this->min = 0;
			}
			else
				this->min = min;
		}
		void setSec(int sec)
		{
			this->sec = sec;
		}
		int getHour() const
		{
			return hour;
		}
		int getMin() const
		{
			return min;
		}
		int getSec() const
		{
			return sec;
		}
		void printHour()
		{
			if (getHour() < 10)
			{
				cout << "0";
			}
			cout << getHour() << ":";
			if (getMin() < 10)
			{
				cout << "0";
			}
			cout << getMin() << ":";
			if (getSec() < 10)
			{
				cout << "0";
			}
			cout << getSec();
		}
		void nextTick()
		{
			sec++;
			if (getSec() == 60)
			{
				setSec(0);
				setMin(getMin() + 1);
			}
			if (getMin() == 60)
			{
				setMin(0);
				setHour(getHour() + 1);
			}
			if (getHour() == 24)
			{
				setHour(0);
			}
		}
		/*void syncTime()
		{
			setHour();
		}*/
};
int main()
{
	clock chasovnik;
	chasovnik = clock(22, 22, 22);
	chasovnik.nextTick();
	chasovnik.printHour();
	cout << endl;
	system("pause");
	return 0;
}
