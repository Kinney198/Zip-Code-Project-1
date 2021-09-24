#ifndef BUFFER_H
#define BUFFER_H

#include <iostream>
#include <string>
#include <fstream>
#include "record.h"
#include <vector>
using namespace std;

class Buffer
{
 public:
 vector<vector <Record>> outer;

 /**<
 // This is a default constructor.
 // @pre There is no buffer object.
 // @post A buffer object is created with all data members initialized to null.
 */
 Buffer()
 {
 }

 /**<
 // This function skips through the first three lines of the CSV file and then
 // starts reading in each line as a string. These strings get passed
 // one-by-one to the unpack function.
 // @pre The CSV file exists.
 // @post Each string is passed to the unpack function to be organized.
 */
 void read();
 
 /**<
 // This function takes the string it has been given and saves each piece of
 // data into the correct data member. It does this by reading the string and
 // skipping over comma delimiters that break up the data. This complete
 // record is returned.
 // @pre The read() function passes a string of data.
 // @post The data is saved into the correct data members and this record is
 // returned.
 // @param str The string of data to be turned into a record.
 // @return The completed record.
 */
 Record unpack(string str);
 
 /**<
 // This function takes the record from the unpack() function and turns it
 // into a vector with the state name as its main identifier for the outer
 // vector.
 // @pre A record has been saved to the correct data members.
 // @post The record is converted to the inner vector of a 2D vecotr.
 // @param rec The completed record from the unpack() function.
 */
 void createInnerVector(Record rec);
 
 /**<
 // This function takes the vector it is passed and adds it to an already
 // existing outer vector if they have the same state.
 // @pre A record has the same state as an already existing vector.
 // @post The record is added to a vector with the same state.
 // @param rec A record to be placed in the 2D vecotr.
 */
 void addToVector(Record rec);
 
 /**<
 // This function determines wether there is an outer vector member for a
 // state.
 // @pre There is a vector of records being added.
 // @post It is determined if this state already has a vector.
 // @param rec The record being added.
 // @return True or false depending on if the vector exists.
 */
 bool checkExist(Record rec);
 
 /**<
 // This function uses bubble sort to organize the outer vector's states by
 // alphabetical order.
 // @pre There is a 2d vecotr of record vectors.
 // @post This 2d vector is organized alphabetically by state.
 // @param &outer A vector of record vectors passed by reference.
 */
 void vectorAlphabetize(vector<vector<Record>> &outer);
 
 /**<
 // This function prints this top of the table and then searches through the
 // vector of record vectors for the northern-, southern-, eastern-, and
 // western-most zip codes in each state. Then, it prints these zip code by
 // state in the correct columns. After each row is printed, the extreme
 // values are set back to null.
 // @pre There is an organized vector of record vectors.
 // @post The extreme zip code in each state are printed to the terminal.
 // @param outer The vector of record vectors.
 */
 void generateTable(vector<vector<Record>> outer);

 /**<
 // This function determines if a record vector should be added to an
 // already existing vector or if a new one should be created. Then, it
 // calls the appropriate function.
 // @pre There is a record to be added to the 2D vector.
 // @post The appropriate function is called to add the record.
 // @param rec The record to be added.
 */
 void recordOrganize(Record rec);
 
private:
 Record northern = Record();
 Record southern = Record();
 Record eastern = Record();
 Record western = Record();
 ifstream upc;
};

#endif
