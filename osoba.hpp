/* 
 * File:   osoba.hpp
 * Author: ucitel
 *
 * Created on 29. listopadu 2016, 11:26
 */

#ifndef OSOBA_HPP
#define	OSOBA_HPP
#include <string>
class osoba {
public:
    osoba();
    osoba(std::string);
    std::string getRC()const;
    bool setRC(std::string);
    std::string datum()const;
    int vek()const;  
private:
     std::string RC;
     bool kontrolaRC(std::string)const;
     int rok()const;
    int mesic()const;
    int den()const;
};

#endif	/* OSOBA_HPP */

