/* 
 * File:   osoba.cpp
 * Author: ucitel
 * 
 * Created on 29. listopadu 2016, 11:26
 */

#include "osoba.hpp"
#include <ctime>
#include <sstream>
#define DEFAULT_RC ""
osoba::osoba() {
    this->RC=DEFAULT_RC;
}

bool osoba::kontrolaRC(std::string rc) const{
    std::string prvnich9 = rc.substr (0,9); 
    int zbytek=std::stoi(prvnich9)%11;
    std::string kontrolniCislice = rc.substr (9,1); 
    if(std::stoi(kontrolniCislice)==zbytek)
        return true;
    else if(zbytek == 10 && rc[9]=='0')
        return true;
    else
        return false;
}

osoba::osoba(std::string rc){
    if(kontrolaRC(rc))
        this->RC=rc;
    else
        this->RC=DEFAULT_RC;
}

std::string osoba::getRC() const{
    return this->RC;
}

bool osoba::setRC(std::string rc){
     if(kontrolaRC(rc)){
        this->RC=rc;
        return true;
     }
     else
         return false;
}

int osoba::rok() const {    
    std::string r = this->RC.substr (0,2); 
   
    return std::stoi(r) < 53 ? 2000 + std::stoi(r) : 1900 + std::stoi(r);
}

int osoba::mesic() const {
    std::string m = this->RC.substr (2,2);
    
    return std::stoi(m) > 50 ? std::stoi(m) - 50 : std::stoi(m);
    
}

int osoba::den() const {
    std::string d = this->RC.substr (4,2);

    return std::stoi(d);
}

int osoba::vek() const {
    time_t rawtime;
    struct tm * timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    
    int vek;
    if(this->RC.length() > 0){ 
        //Získání věku v letech.
        vek = (timeinfo->tm_year + 1900) - rok();

        if (mesic() > timeinfo->tm_mon + 1) {
            vek--;
        } else if (mesic() == timeinfo->tm_mon + 1 && den() < timeinfo->tm_mday)
            vek--;
    } else
        return -1;
    
    return vek;
}

std::string osoba::datum() const {
    if(this->RC.length() > 0){ 
        std::ostringstream datum;
        datum<<den()<<". "<<mesic()<<". "<<rok();
        return datum.str();
    } 
    else
      return "Neplatne datum!";
}