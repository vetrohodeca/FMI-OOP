#pragma once
const int CAP = 8;
const int MAXSIZE=256;
FlightList::FlightList(){
    this->capacity = CAP;
    this->length = 0;
    this->list = new Flight[this->capacity];
}

FlightList::resize(){
    this->capacity*=2;
    Flight* save = this->list;
    this->list = new Flight[this->capacity];
    for(size_t i=0;i<this->length;i++){
        this->list[i] = save[i];
    }
    delete[] save;
}

void FlightList::add(const Flight& newFlight){
    if(this->length + 1 >= this->capacity){
        resize();
    }
    this->list[this->length] = newFlight;
    this->length++;
}

void FlightList::search(size_t id){
    bool flag = false;
    for(size_t i=0;i<this->length;i++){
        if(this->list[i].getId() == id){
            std::cout<<this->list[i].getId()<<" "<<this->list[i].getPlane()<<" "<<this->list[i].getType()<<" "<<this->list[i].getNumberFlights()<<std::endl;
            flag = true;
            break;
        }
    }
    if(flag == false){
        std::cout<<"Record not found!"<<std::endl;
    }
}

void FlightList::write(){
    std::ofstream out ("Planes.txt");
    out<<this->length<<std::endl;
    for(size_t i = 0;i<this->length;i++){
        out<<this->list[i].getId()<<std::endl;
        out<<this->list[i].getPlane()<<std::endl;
        out<<this->list[i].getType()<<std::endl;
        out<<this->list[i].getNumberFlights()<<std::endl;
    }
    std::cout<<"Record saved!"<<std::endl;
    out.close();
}

void FlightList::read(){
    std::ifstream in ("Planes.txt");
    char plane[MAXSIZE], type[MAXSIZE];
    size_t id,numberFlights;
    in>>this->length;
    for(size_t i=0;i<this->length;i++){
        in>>id>>plane>>type>>numberFlights;
        Flight temp(id, plane,type, numberFlights);
        this->add(temp);
    }
    in.close();
}

FlightList::~FlightList(){
    delete[] this->list;
}
