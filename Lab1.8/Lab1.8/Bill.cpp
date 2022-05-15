#include "Bill.h"

void Bill::Time::SetHour(unsigned int value)
{
	if (value > 23 || value < 0)
		value = 0;
	this->hour = value;
}

void Bill::Time::SetMinute(unsigned int value)
{
	if (value > 59 || value < 0)
		value = 0;
	this->minute = value;
}

void Bill::Time::SetSecond(unsigned int value)
{
	if (value > 59 || value < 0)
		value = 0;
	this->second = value;
}



void Bill::Time::Init_time(unsigned int hour, unsigned int minute, unsigned int second)
{
	SetHour(hour);
	SetMinute(minute);
	SetSecond(second);
}

void Bill::Time::Read()
{
	unsigned int h, m, s;
	do {
		cout << " Enter hour: "; cin >> h;
	} while (h > 23 || h < 0);

	do {
		cout << " Enter minute: "; cin >> m;
	} while (m > 59 || m < 0);

	do {
		cout << " Enter second: "; cin >> s;
	} while (s > 59 || s < 0);

	Init_time(h, m, s);
}

void Bill::Time::Display() {
	cout << endl << toString() << endl;
}

string Bill::Time::toString() const {
	stringstream sout;
	sout << " " << hour << ":" << minute << ":" << second;
	return sout.str();
}

Bill::Time SubstractSeconds(Bill::Time a, unsigned int b)
{
	unsigned int substr = b;

	a.hour -= trunc(substr / 3600.);
	a.minute -= trunc(substr % 3600 / 60.);
	a.second -= substr % 60;

	if (a.second >= 60 || a.second < 0)
	{
		a.minute += a.second / 60;
		a.second %= 60;
		if (a.second < 0)
		{
			a.minute--;
			a.second = 60 + a.second;
		}
	}

	if (a.minute >= 60 || a.minute < 0)
	{
		a.hour += a.minute / 60;
		a.minute = a.minute % 60;
		if (a.minute < 0)
		{
			a.hour--;
			a.minute = 60 + a.minute;
		}
	}

	if (a.hour >= 24 || a.hour < 0)
		a.hour = (a.hour < 0 ? 24 : 0) + a.hour % 24;

	return a;
}

Bill::Time Difference(Bill::Time a, unsigned int b)
{
	unsigned int seconds = b;

	unsigned int hm = trunc(seconds / 3600.);
	a.hour += trunc(seconds / 3600.);
	a.minute += trunc(seconds % 3600 / 60.);
	a.second += seconds % 60;

	if (a.second >= 60 || a.second < 0)
	{
		a.minute += a.second / 60;
		a.second %= 60;
		if (a.second < 0)
		{
			a.minute--;
			a.second = 60 + a.second;
		}
	}

	if (a.minute >= 60 || a.minute < 0)
	{
		a.hour += a.minute / 60;
		a.minute = a.minute % 60;
		if (a.minute < 0)
		{
			a.hour--;
			a.minute = 60 + a.minute;
		}
	}

	if (a.hour >= 24 || a.hour < 0)
		a.hour = (a.hour < 0 ? 24 : 0) + a.hour % 24;

	return a;
}

unsigned int ToSeconds(Bill::Time b)
{
	unsigned int t;
	t = b.hour * 3600 + b.minute * 60 + b.second;
	return t;
}

unsigned int ToMinutes(Bill::Time b)
{
	unsigned int t;
	if (b.second < 1)
	{
		t = b.hour * 60 + b.minute;
	}
	if (b.second > 0)
	{
		t = b.hour * 60 + b.minute + 1;
	}
	return t;
}

unsigned int Difference(Bill::Time T1, Bill::Time T2)
{
	return ToSeconds(T2) - ToSeconds(T1);
}

bool IsEqual(Bill::Time t1, Bill::Time t2)
{
	return t1.hour == t2.hour && t1.minute == t2.minute && t1.second == t2.second;
}

bool IsNotEqual(Bill::Time t1, Bill::Time t2)
{
	return !IsEqual(t1, t2);
}

bool IsEarlierThan(Bill::Time t1, Bill::Time t2)
{
	return t1.hour < t2.hour || t1.hour == t2.hour && t1.minute < t2.minute || t1.hour == t2.hour && t1.minute == t2.minute && t1.second < t2.second;
}

bool IsEarlierThanOrEq(Bill::Time t1, Bill::Time t2)
{
	return IsEarlierThan(t1, t2) || IsEqual(t1, t2);
}

bool IsLaterThan(Bill::Time t1, Bill::Time t2)
{
	return t1.hour > t2.hour || t1.hour == t2.hour && t1.minute > t2.minute || t1.hour == t2.hour && t1.minute == t2.minute && t1.second > t2.second;
}

bool IsLaterThanOrEq(Bill::Time t1, Bill::Time t2)
{
	return IsLaterThan(t1, t2) || IsEqual(t1, t2);
}

//Bill

void Bill::SetTaryf(double v)
{
	this->taryf = v;
}

void Bill::SetZnyzhka(double v)
{
	if (v > 100 || v < 0)
	{
		v = 0;
	}
	this->znyzhka = v;
}

void Bill::SetSumforpay(double v)
{
	this->sumforpay = v;
}

void Bill::Init(string surname, string cellnumb, double taryf, double znyzhka)
{
	SetSurname(surname);
	SetCellnumb(cellnumb);
	SetTaryf(taryf);
	SetZnyzhka(znyzhka);
}

void Bill::Read()
{
	string surname;
	cout << " Enter surname: "; cin >> surname;
	string cellnumb;
	cout << " Enter phone number: "; cin >> cellnumb;

	double taryf, znyzhka;
	cout << " Enter taryf per minute: "; cin >> taryf;
	do {
		cout << " Enter discount, %: "; cin >> znyzhka;
	} while (znyzhka > 100 || znyzhka < 0);



	Init(surname, cellnumb, taryf, znyzhka);
}

string Bill::toString() const
{
	stringstream sout;
	sout << endl << " Surname: " << surname << endl;
	sout << " Phone number: " << cellnumb << endl;
	sout << " Taryf per minute: " << taryf << "UAH" << endl;
	sout << " Discount: " << znyzhka << "%" << endl;

	return sout.str();
}

void Bill::Display()
{
	cout << toString() << endl;
}


double Bill::Sum_For_Pay(Time T1, Time T2)
{
	unsigned int t(Difference(T1, T2) / 60.);
	return t * taryf - (t * taryf) * (znyzhka / 100);
}