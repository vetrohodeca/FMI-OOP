//za koleda priemam samo 25.12
#include<iostream>
int daysOfMonths[12];
using namespace std;
class Date {
private:
	short day;
	short month;
	short year;
public:
	Date differenceBetweenTwoDates(Date d1, Date d2);

	Date()
	{
		this->day = 1;
		this->month = 1;
		this->year = 2000;
	}

	Date(int day, int month, int year)
	{
		setDay(day);
		setMonth(month);
		setYear(year);
	}

	int getDay() const
	{
		return day;
	}

	int getMonth() const
	{
		return month;
	}

	int getYear() const
	{
		return year;
	}

	void printDate()
	{
		if (getDay() < 10)
		{
			cout << "0" << getDay();
		}
		else
		{
			cout << getDay();
		}
		cout << ".";
		if (getMonth() < 10)
		{
			cout << "0" << getMonth();
		}
		else
		{
			cout << getMonth();
		}
		cout << ".";
		cout << getYear();
		cout << endl;
	}

	// 1- is for leap, 0 is not leap
	bool checkLeapYear(Date d)
	{
		int  year = d.getYear();

		if (year % 4 == 0)
		{
			if (year % 100 == 0)
			{
				if (year % 400 == 0)
					return 1;
				else
					return 0;
			}
			else
				return 1;
		}
		else
			return 0;

	}

	void setMonth(int month)
	{
		if (month < 0 || month>12)
		{
			month = 1;
		}
		this->month = month;
	}

	void setYear(int year)
	{
		this->year = year;
	}

	// TODO: play with the conditions trying to make it look nicer
	void setDay(int day)
	{
		if (month == 1 && month == 3 && month == 5 && month == 7 && month == 8 && month == 10 && month == 12 && (day < 0 || day>31))
		{
			day = 1;
		}
		if (month == 4 && month == 6 && month == 9 && month == 11 && (day < 0 || day>30))
		{
			day = 1;
		}
		if (month == 2 && year % 4 == 0 && year % 400 == 0 && year % 100 != 100 && day > 29)
		{
			day = 1;
		}
		if (month == 2 && year % 4 != 0 && year % 400 != 0 && year % 100 == 100 && month > 28)
		{
			day = 1;
		}
		this->day = day;
	}

	void monthTable(int months[12], Date d)
	{
		daysOfMonths[0] = 31;
		bool leap = d.checkLeapYear(d);
		if (leap == 1)
		{
			daysOfMonths[1] = 29;
		}
		else
		{
			daysOfMonths[1] = 28;
		}
		daysOfMonths[2] = 31;
		daysOfMonths[3] = 30;
		daysOfMonths[4] = 31;
		daysOfMonths[5] = 30;
		daysOfMonths[6] = 31;
		daysOfMonths[7] = 31;
		daysOfMonths[8] = 30;
		daysOfMonths[9] = 31;
		daysOfMonths[10] = 30;
		daysOfMonths[11] = 31;
	}

	int getCurrentDayAsNumber(Date d)
	{
		monthTable(daysOfMonths, d);
		int daysOfYear = 0;
		int month = d.getMonth();
		int day = d.getDay();
		daysOfYear += day;
		for (int i = 0; i < month - 1; i++)
		{
			daysOfYear += daysOfMonths[i];
		}
		return daysOfYear;
	}

	int timeToChristmas(Date d)
	{
		int nextYear;
		nextYear = d.year + 1;
		Date d1 = Date(1, 1, nextYear);
		int currentDays = d.getCurrentDayAsNumber(d);
		bool leap = d.checkLeapYear(d);
		bool leap2 = d1.checkLeapYear(d1);
		if (leap == 1)// ako tazi godina e visokosna
		{
			if (d.getCurrentDayAsNumber(d) > 360)// ako sme minali koleda
			{
				return 359 + 366 - d.getCurrentDayAsNumber(d);
			}
			else
			{
				return 360 - d.getCurrentDayAsNumber(d);
			}
		}
		else // ako tazi godina ne e visokosna
		{
			if (d.getCurrentDayAsNumber(d) > 359)// ako sme minali koleda
			{
				if (leap2 == 0)// ako sledvashtata godina e visokosna
				{
					return 359 + 365 - d.getCurrentDayAsNumber(d);
				}
				else  return 359 + 366 - d.getCurrentDayAsNumber(d);;//ako sledvashtata godina e normalna
			}
			else  // ako ne sme minali koleda
			{
				return 359 - d.getCurrentDayAsNumber(d);
			}
		}
	}
	bool cmpDate(Date d1, Date d2)
	{
		if (d1.year > d2.year)
		{
			return false;
		}
		else if (d1.year < d2.year)
		{
			return true;
		}
		else
		{
			if (d1.getCurrentDayAsNumber(d1) < d2.getCurrentDayAsNumber(d2))
			{
				return true;
			}
			else return false;
		}
	}
	int DaysInMonth(Date d)
	{
		int days[] = { -1, 31,28,31,30,31,30,31,31,30,31,30,31 };

		if (checkLeapYear(d) == 1)
		{
			days[2] = 29;
		}

		return days[month];
	}
	void NextDay(Date d)
	{
		day++;
		if (day > DaysInMonth(d))
		{
			day = 1;
			month++;
		}
		if (month > 12)
		{
			month = 1;
			year++;
		}
	}
	void PrevDay(Date d)
	{
		day--;
		if (day < 1)
		{
			month--;
			if (month < 1)
			{
				month = 12;
				year--;
			}
			day = DaysInMonth(d);
		}
	}
	void addDates(Date d, int N)
	{
		for (int i = 0; i < N; i++)
		{
			NextDay(d);
		}

	}
	void removeDates(Date d, int N)
	{
		for (int i = 0; i < N; i++)
		{
			PrevDay(d);
		}
	}
};
Date dateDifferebce(Date d1, Date d2)
{
	bool larger;// if larger ==1, the first date is larger, if larger==0, the first day is smaller
	Date result;
	result = Date(0, 0, 0);
	if (d1.getYear() > d2.getYear())// 1 godina e po- golqma
	{
		larger = 1;
	}
	else if (d1.getYear() == d2.getYear())// 1 goddina =
	{
		if (d1.getMonth() == d2.getMonth())// meseca =
		{
			if (d1.getDay() > d2.getDay()) //1 day>
			{
				larger = 1;
			}
			else larger = 0;// 1 day<
		}
		else if (d1.getMonth() < d2.getMonth())
		{
			larger = 0;
		}
		else larger = 1;
		//!= meseci
	}
	else larger = 0;//  1 godina <
	if (larger == 0)// ako 2 godina e >
	{
		Date tempDate(d1.getDay(), d1.getMonth(), d1.getYear());
		bool flag = (tempDate.getYear() == d2.getYear());
		bool flag1 = (tempDate.getMonth() == d2.getMonth());
		bool flag2 = (tempDate.getDay() == d2.getDay());
		while (flag1 != true || flag2 != true || flag != true)
		{
			flag = (tempDate.getYear() == d2.getYear());
			flag1 = (tempDate.getMonth() == d2.getMonth());
			flag2 = (tempDate.getDay() == d2.getDay());
			tempDate.NextDay(tempDate);
			result.NextDay(result);
		}
	}
	else// ako 1 godina e >
	{
		Date tempDate(d2.getDay(), d2.getMonth(), d2.getYear());
		bool flag = (tempDate.getYear() == d1.getYear());
		bool flag1 = (tempDate.getMonth() == d1.getMonth());
		bool flag2 = (tempDate.getDay() == d1.getDay());
		while (flag1 != true || flag2 != true || flag != true)
		{
			flag = (tempDate.getYear() == d1.getYear());
			flag1 = (tempDate.getMonth() == d1.getMonth());
			flag2 = (tempDate.getDay() == d1.getDay());
			tempDate.NextDay(tempDate);
			result.NextDay(result);
		}
	}
	return result;
}
int main()
{

	Date data;
	data = Date(23,10, 2020);
	Date data2;
	data2 = Date(24, 10, 2020);
	data.printDate();
	data2.printDate();
	cout << data.checkLeapYear(data)<<endl;
	cout << data.getCurrentDayAsNumber(data) << endl;
	cout << data.timeToChristmas(data) << endl;
	cout << data.cmpDate(data, data2) << endl;
	dateDifferebce(data, data2).printDate();
	/*data.NextDay(data);
	data.printDate();
	data.removeDates(data, 52);
	data.printDate();
	data.addDates(data, 33);
	data.printDate();*/
	system("pause");
	return 0;
}