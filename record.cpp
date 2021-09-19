#include "record.h"
#include <cassert>
using namespace std;

 /**<
 // default constructor
 */
 Record::Record(){}
 /**<
 // contructor with parameters
 */
 Record::Record(string st, double la, double lo, int zip, string place, string count) {}
 /**<
 //returns state abreviation
 */
 string Record::get_state()
 {
     return state;
 }
 /**<
 returns zip code lattitude
 */
 double Record::get_lat()
 {
     return lat;
 }
 /**< returns zip code longitude */
 double Record::get_long()
 {
     return lon;
 };

 int Record::get_zip() 
 {
     return zipCode;
 }