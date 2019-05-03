#pragma once

class Flight{
private:
    size_t id;
    char* plane;
    char* type;
    size_t numberFlights;

    erase();
    copy(const Flight& other);

public:
    Flight();
    Flight(const size_t id, const char* plane, const char* type, const size_t numberFlights);
    Flight(const Flight& other);
    Flight& operator=(const Flight& other);
    size_t getId();
    char* getPlane();
    char* getType();
    size_t getNumberFlights();
    ~Flight();
};

char* copyDyn(const char* c);

#include "Flight.cpp"
