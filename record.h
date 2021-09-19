#ifndef RECORD_H
#define RECORD_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Record
{
 public:
 /**<
 // default constructor
 */
 Record()
 {
     state = "";
     lat = NULL;
     lon = NULL;
     zipCode = NULL;
     placeName = "";
     county = "";
 }
 /**<
 // contructor with parameters
 */
 Record(string st, double la, double lo, int zip, string place, string count)
 {
     state = st;
     lat = la;
     lon = lo;
     zipCode = zip;
     placeName = place;
     county = count;
 }
 /**<
 //returns state abreviation
 */
 string get_state();
 /**<
 returns zip code lattitude
 */
 double get_lat();
 /**< returns zip code longitude */
 double get_long();

 int get_zip();
 private:
 string state;
 double lat;
 double lon;
 int zipCode;
 string placeName;
 string county;
};

#endif