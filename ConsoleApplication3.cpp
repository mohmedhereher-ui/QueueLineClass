#include <iostream>
#include"clsQueueLine.h"
using namespace std;
int main()
{
    clsQueueLine q("A", 2);   // Prefix = "A", ServeTime = 2 minutes

    q.IssueTicket();       // order = 1-0 = 1, RemainingTime = 2
    q.IssueTicket();       // order = 2-0 = 2, RemainingTime = 4
    q.ServeNextCleint();   // _Sarved = 1
    q.IssueTicket();       // order = 3-1 = 2, RemainingTime = 4  ✅

    q.PrintAllTickets();
    q.PrintInfo();

    system("pause>0");
    return 0;
}