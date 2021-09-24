#include "buffer.h"
#include <cassert>
#include <fstream>

void Buffer::read()
{
    upc.open("us_postal_codes.csv");
    string temp, fileRec;
    for (int i = 0; i < 3; i++)
        getline(upc, temp);
    while (!upc.eof())
    {
        getline(upc, fileRec);
        if (fileRec != "")
            recordOrganize(unpack(fileRec));
    }
};

Record Buffer::unpack(string str)
{
    string tempString = "";
    char comma = ',';

    string state;
    double lat;
    double lon;
    int zipCode;
    string placeName;
    string county;


    int i = 0;
    while (str[i] != comma)
    {
        tempString += str[i];
        i++;
    }
    zipCode = stoi(tempString); //Extracted state name from string

    i++; tempString = "";
    while (str[i] != comma)
    {
        tempString += str[i];
        i++;
    }
    placeName = tempString; //Extracted city name from string

    i++; tempString = "";
    while (str[i] != comma)
    {
        tempString += str[i];
        i++;
    }
    state = tempString;     //Extracted state name from string

    i++; tempString = "";
    while (str[i] != comma)
    {
        tempString += str[i];
        i++;
    }
    county = tempString;    //Extracted county name from string

    i++; tempString = "";
    while (str[i] != comma)
    {
        tempString += str[i];
        i++;
    }
    lat = stod(tempString); //Extracted latitude from string

    i++; tempString = "";
    while (i <= str.size())
    {
        tempString += str[i];
        i++;
    }
    lon = stod(tempString); //Extracted longitude from string

    Record newRecord = Record(state, lat, lon, zipCode, placeName, county);    //Construct a new record 
    return newRecord;
};

void Buffer::createInnerVector(Record rec)     //Creates a new inner vector and adds the given record to it
{
    vector<Record> newVector;
    newVector.push_back(rec);
    outer.push_back(newVector);
};

void Buffer::addToVector(Record rec)           //Adds the given record to a prexisting inner vector
{
    for (int i = 0; i < outer.size(); i++)
    {
        if (rec.get_state() == outer[i][0].get_state())
        {
            outer[i].push_back(rec);
            break;
        }
    }
};

bool Buffer::checkExist(Record rec)        //Returns True, if there is a prexisting vector for the given record.
{
    bool flag = false;

    for (int i = 0; i < outer.size(); i++)
    {
        if (!outer.empty())
        {
            if (rec.get_state() == outer[i][0].get_state())
            {
                flag = true;
                break;
            }
        }
        
    }
    return flag;

};

void Buffer::recordOrganize(Record rec)
{
    if (checkExist(rec))
    {
        addToVector(rec);
    }
    else
    {
        createInnerVector(rec);
    }
}

void Buffer::vectorAlphabetize(vector<vector<Record>> &outer)
{
    vector<Record> temp;
    for (int i = 0; i < outer.size()-1; i++)
    {
        for (int j = i + 1; j < outer.size(); j++)
        {
            if (outer[i][0].get_state().compare(outer[j][0].get_state()) > 0)
            {
                temp = outer[i];
                outer[i] = outer[j];
                outer[j] = temp;
            }
        }
    }
};

void Buffer::generateTable(vector<vector <Record>> outer)
{
    cout << "State\tNorthern Most\tSouthern Most\tEastern Most\tWestern Most\n-----\t-------------\t-------------\t------------\t------------\n";
    for (int i = 0; i < outer.size(); i++)
    {
        for (int j = 0; j < outer[i].size(); j++)
        {
            if (northern.get_state() == "" || (northern.get_lat() < outer[i][j].get_lat()))
            {
                northern = outer[i][j];
            }
            if (southern.get_state() == "" || (southern.get_lat() > outer[i][j].get_lat()))
            {
                southern = outer[i][j];
            }
            if (eastern.get_state() == "" || (eastern.get_long() < outer[i][j].get_long()))
            {
                eastern = outer[i][j];
            }
            if (western.get_state() == "" || (western.get_long() > outer[i][j].get_long()))
            {
                western = outer[i][j];
            }
        }
        cout << outer[i][0].get_state() << "\t" << northern.get_zip() << "\t\t" << southern.get_zip() << "\t\t" << eastern.get_zip() << "\t\t" << western.get_zip() << endl;
        
        northern = Record();    //Reset holders for 
        southern = Record();
        eastern = Record();
        western = Record();
    }
    

};
