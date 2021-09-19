#ifndef RECORD_H
#define RECORD_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Record
{
 public:
 Record()
 {
     state = "";
     lat = NULL;
     lon = NULL;
     zipCode = NULL;
     placeName = "";
     county = "";
 }

 Record(string st, double la, double lo, int zip, string place, string count)
 {
     state = st;
     lat = la;
     lon = lo;
     zipCode = zip;
     placeName = place;
     county = count;
 }
 string get_state();
 double get_lat();
 double get_long();
 int get_zip();
 
 public:
 string state;
 double lat;
 double lon;
 int zipCode;
 string placeName;
 string county;
};

#endif