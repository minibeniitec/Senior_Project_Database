#include <iostream>
#include <fstream>
#include <stdio.h> 
#include <stdlib.h> 
using namespace std;

int main()
{
    ofstream fout;
    fout.open("Insert_Fake_Data.psql", ios::app); // open file for appending
    assert(!fout.fail());
    srand(time(NULL));

    int size = 1,
        day = 0,
        serverid = 4,
        tableid = 1,
        inHour = -02,
        inMinute = 30,
        outHour = 00,
        outMinute = 00,
        experience = 1,
        visits = 1,
        time = 0, 
        wait = 0;


    for (int i = 0; i < 1592; i++)
    {
        size = (int)rand() % 6 + 1;      //Party Size
        if (i % 60 == 0) { day++; }     //Day   
        serverid = (int)rand() % 7 + 4;  //ServerID
        tableid = i % 4 + 1;             //TableID
        experience = (int)rand() % 5 + 1;//Experience
        visits = (int)rand() % 11 + 5;
        if (i % 4 == 0)
        {
            if(inMinute == 30) {
                inHour = (inHour + 1) % 24;
                inMinute = outMinute;
                outMinute = 30;
            }
            else {
                outHour = (outHour + 1) % 24;
                inMinute = outMinute;
                outMinute = 00;
            }
            inHour = (inHour + 1) % 24;
            outHour = (outHour + 1) % 24;            
        }
        if(outHour == 00) {
            inHour = 00;
            inMinute = 00;
            outHour = 01;
            outMinute = 30;
        }
        fout << "INSERT INTO Orders (PartyName, PartySize, Date, ServerID, TableID, CheckinTIme, CheckoutTime, Experience) VALUES (";
        fout << "'Guest', "                                                       //PartyName
             << size << ", "                                                      //PartySize
             << "'2020-04-" << day << "', "                                       //Date
             << serverid << ", "                                                  //ServerID
             << tableid << ", "                                                   //TableID
             << "'" << inHour << ":" << inMinute << ":00', "                      //CheckinTime
             << "'" << outHour << ":" << outMinute << ":00', "                  //CheckoutTime
             << experience << ");" << endl;                                       //Experience
        time = 00;
        wait = 90 / (visits + 1);
        for (int a = 0; a < visits; a++)
        {
            time += wait;
            fout << "INSERT INTO TABLEVISITS (OrderID, StartTime, Wait) VALUES (" << i << ", '";
            fout << inHour + (int)(time / 60) << ":" << (inMinute + time) % 60 << ":00', '00:" << wait << ":00');" << endl;
        }
    }
    fout.close();
    return 0;
}