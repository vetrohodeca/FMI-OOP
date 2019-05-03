#include<iostream>
#include<cstring>
#include<fstream>
#include "Flight.h"
#include "FlightList.h"
#define MAXSIZE 256
using namespace std;

int main(){
    string input;
    char plane[MAXSIZE], type[MAXSIZE];
    size_t id,numberFlights;
    FlightList data;
    data.read();
    while(input!="exit"){
        cin>>input;
        if(input == "create"){
            cin>>id>>plane>>type>>numberFlights;
            Flight temp(id, plane,type, numberFlights);
            data.add(temp);
            data.write();
        }
        if(input == "search"){
            cin>>id;
            data.search(id);
        }
    }
    return 0;
}
