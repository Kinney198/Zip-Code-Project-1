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
 Buffer()
 {
 }
 void read();
 
 Record unpack(string str);
 
 void createInnerVector(Record rec);
 
 void addToVector(Record rec);
 
 bool checkExist(Record rec);
 
 void vectorAlphabetize(vector<vector<Record>> &outer);
 
 void generateTable(vector<vector<Record>> outer);

 void recordOrganize(Record rec);
 
private:
 Record northern = Record();
 Record southern = Record();
 Record eastern = Record();
 Record western = Record();
 ifstream upc;
};

#endif