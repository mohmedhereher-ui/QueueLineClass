#pragma once
#pragma warning(disable : 4996)
#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
class clsTime {
public:
	short Day;
	short Month;
	short Year;
	short Hour;
	short Minute;
	short Second;
	static clsTime GetSystemDate()
	{
		clsTime Date;
		time_t t = time(0);
		tm* now = localtime(&t);
		Date.Year = now->tm_year + 1900;
		Date.Month = now->tm_mon + 1;
		Date.Day = now->tm_mday;
		Date.Hour = now->tm_hour;
		Date.Minute = now->tm_min;
		Date.Second = now->tm_sec;
		return Date;
	}

	static string GetTimeAsLine() {
		string date = "";
		clsTime cdate = GetSystemDate();
		date += (to_string(cdate.Day) + " / ");
		date += (to_string(cdate.Month) + " / ");
		date += (to_string(cdate.Year) + " - ");

		date += (to_string(cdate.Hour) + ":");
		date += (to_string(cdate.Minute) + ":");
		date += to_string(cdate.Second);
		return date;
	}
};

