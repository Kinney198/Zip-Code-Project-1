#include "buffer.h"
#include <cassert>

 /**<  */
 Buffer::Buffer() {
 };
 /**<  */
 void Buffer::main()
 {
 };
 /**<  */
 string Buffer::read()
 {
 };
 /**<  */
 Record* Buffer::unpack(string str)
 {
 };
 /**<  */
 void Buffer::recordOrganize(Record rec) 
 {
 };
 /**<  */
 void Buffer::createInnerVector() 
 {
 };
 /**<  */
 void Buffer::addToVector() 
 {
 };
 /**<  */
 bool Buffer::checkExist(Record rec) 
 {
 };
 /**<  */
 void Buffer::vectorAlphabetize(vector<vector <Record>> outer)
 {
 };
 /**<  */
 void Buffer::generateTable(vector<vector <Record>> outer)
 {
     cout<<"State\tNorthern Most\tSouthern Most\tEastern Most\tWestern Most\n-----\t-------------\t-------------\t------------\t------------\n";
     for (int i=0; i<outer.size(); i++)
     {
         for (int j=0; j<outer[i].size(); j++)
            {
             if (northern.get_state() == "" || (northern.get_lat() < outer[i][j].get_lat()))
                {
                    northern = outer[i][j];
                }
             if (southern.get_state() == "" || (southern.get_lat() > outer[i][j].get_lat()))
                {
                    southern=outer[i][j];
                }
            if (eastern.get_state() == "" || (eastern.get_long() > outer[i][j].get_long()))
                {
                    eastern = outer[i][j];
                }
            if (western.get_state() == "" || (western.get_long < outer[i][j].get_long()))
                {
                    western = outer[i][j];
                }
        }
        cout<<outer[i][1].get_state()<<"\t"<<northern.get_zip<<"\t"<<southern.get_zip()<<"\t"<<eastern.get_zip()<<"\t"<<western.get_zip()<<endl;
     }     
 };