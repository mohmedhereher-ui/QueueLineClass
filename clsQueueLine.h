#pragma once
#pragma warning(disable : 4996)
#include<iostream>
#include<cstdio>
#include<string>
#include<iomanip>
#include<queue>
#include "clsTime.h"
using namespace std;
class clsQueueLine
{
protected:
	class ticket {
	public:
		short order;
		string TicketNumber;
		short RemainingTime;
		string Date;
	};
	string _Prefix;
	short _ServeTime;
	queue<ticket>_Tickets;
	int _Total;
	int _Sarved;
	void _PrintCard(ticket ticket) {
		cout << setw(36) << left << "" << "--------------------------\n";
		cout << setw(43) << left << "" << " --Ticket--\n";
		cout << setw(36) << left << "" << "--------------------------\n";
		cout << setw(47) << left << "" << ticket.TicketNumber << endl<< endl;
		cout << setw(38) << left << "" << ticket.Date << endl;
		cout << setw(38) << left << "" << " Wating clients = "<<ticket.order-1<< endl;
		cout << setw(38) << left << "" << "    Serve time in"<< endl;
		cout << setw(44) << left << "" <<ticket.RemainingTime<<"minute"<< endl;
		cout << setw(36) << left << "" << "--------------------------\n\n\n";
	}
public:
	clsQueueLine(string prefix,short ServeTime) {
		_Prefix = prefix;
		_ServeTime = ServeTime;
		_Total = 0;
		_Sarved = 0;
	}
	void PrintInfo() {
		cout << setw(36) << left << "" << "--------------------------\n";
		cout << setw(43) << left << "" << "Queue Info\n";
		cout << setw(36) << left << "" << "--------------------------\n";
		cout << setw(39) << left << "" << "Prefix : "<< _Prefix<<endl;
		cout << setw(39) << left << "" << "Total tickets : "<< _Total <<endl;
		cout << setw(39) << left << "" << "Served cleint : "<< _Sarved <<endl;
		cout << setw(39) << left << "" << "Waiting cleint : "<<_Total- _Sarved <<endl;
		cout << setw(36) << left << "" << "--------------------------\n\n\n";
	}
	void IssueTicket() {
		_Total+=1;
		ticket Tecket;
		Tecket.TicketNumber = (_Prefix +to_string(_Total));
		Tecket.Date = clsTime::GetTimeAsLine();
		Tecket.RemainingTime = _Total * _ServeTime;
		Tecket.order = _Total;
		_Tickets.push(Tecket);
	}
	void PrintAllTickets() {
		if (_Total != 0) {
			queue<ticket>T = _Tickets;
			while (!T.empty()) {
				_PrintCard(T.front());
				T.pop();
			}
		}
	}
	void PrintTicketsLine() {
		cout <<setw(20)<<left<<""<< "Tickets : ";
		if (_Total != 0) {
			queue<ticket>T = _Tickets;
			while (!T.empty()) {
				cout<<T.front().TicketNumber<<"<--";
				T.pop();
			}
			cout << endl;
		}
	}
	bool ServeNextCleint() {
		if (_Tickets.empty())
			return false;
		else
		{
			_Tickets.pop();
			_Sarved++;
			return true;
		}
	}
};

