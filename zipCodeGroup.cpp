#include <iostream>
#include <fstream>
#include <string>
#include "buffer.h"
#include "record.h"
using namespace std;

int main()
{
    cout << "Hello World" << endl;
    return 0;
}

void recordOrganize(Buffer buffer, Record rec)
{
    if (buffer.checkExist(rec))
    {
        buffer.addToVector(rec);
    }
    else
    {
        buffer.createInnerVector(rec);
    }
        

}