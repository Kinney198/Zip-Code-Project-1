#include <iostream>
#include <fstream>
#include <string>
#include "buffer.h"
#include "record.h"
using namespace std;

int main()
{
    Buffer buffer;
    buffer.read();
    buffer.vectorAlphabetize(buffer.outer);
    buffer.generateTable(buffer.outer);
}
