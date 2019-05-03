#pragma once

class FlightList{
private:
    Flight* list;
    size_t capacity;
    size_t length;
    resize();
public:
    FlightList();
    void add(const Flight& newFlight);
    void search(size_t id);
    void write();
    void read();
    ~FlightList();
};

#include "FlightList.cpp"
