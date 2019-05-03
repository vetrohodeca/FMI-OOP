#pragma once

char* copyDyn(const char* c){
    char* temp = new char[strlen(c) + 1];
    strcpy(temp, c);
    return temp;
}

Flight::erase(){
    delete[] plane;
    delete[] type;
}

Flight::copy(const Flight& other){
    this->plane = new char[strlen(other.plane) + 1];
    this->type = new char[strlen(other.type) + 1];
    strcpy(this->plane, other.plane);
    strcpy(this->type, other.type);
    this->id = other.id;
    this->numberFlights = other.numberFlights;
}

Flight::Flight(){
    this->id = 0;
    this->plane = copyDyn("");
    this->type = copyDyn("");
    this->numberFlights = 0;
}

Flight::Flight(const size_t id, const char* plane, const char* type, const size_t numberFlights){
    this->id = id;
    this->plane = copyDyn(plane);
    this->type = copyDyn(type);
    this->numberFlights = numberFlights;
}

size_t Flight::getId(){
    return this->id;
}

char* Flight::getPlane()
{
    return this->plane;
}

char* Flight::getType(){
    return this->type;
}

size_t Flight::getNumberFlights(){
    return this->numberFlights;
}

Flight::Flight(const Flight& other) {
    copy(other);
}

Flight& Flight::operator=(const Flight& other){
    if(this!=&other){
        erase();
        copy(other);
    }
    return *this;
}

Flight::~Flight(){
    erase();
}
