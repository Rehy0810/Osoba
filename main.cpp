/* 
 * File:   main.cpp
 * Author: ucitel
 *
 * Created on 29. listopadu 2016, 11:26
 */

#include <cstdlib>
#include "osoba.hpp"
#include <iostream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    osoba o1;
    osoba o2("6462191472");
    std::string rc;
    int znova;
     cout<<"Objekt vytvoreny konstruktorem bez parametru: "<<endl;
     cout<<o1.getRC()<<endl;
     cout<<"Objekt vytvoreny konstruktorem s parametrem: "<<endl;
     cout<<o2.getRC()<<endl;     
     cout<<"Datum narozeni: "<<o1.datum()<<endl;
     cout<<"Datum narozeni: "<<o2.datum()<<endl;
     cout<<"Vek: "<<o1.vek()<<endl;
     cout<<"Vek: "<<o2.vek()<<endl;
    
    do{
        cout<<"Zadej rodne cislo:";
        cin>>rc;
        if(o1.setRC(rc)){
            cout<<"Rodne cislo je "<<o1.getRC()<<endl;
            cout<<"Datum narozeni: "<<o1.datum()<<endl;
            cout<<"Vek: "<<o1.vek()<<endl;
        }      
        else{
            cout<<"Chybne rodne cislo!"<<endl;
        }
        cout<<"Pro pokracovani stiskni 1."<<endl;
        cin>>znova;
        znova==1;
    }while(znova==1);
     
    return 0;
}

