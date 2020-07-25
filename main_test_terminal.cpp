#include <iostream>
#include "include/Block.h"

using std::cout;
using std::endl;

int main()
{
    return 0;
}

bool block_test_1()
{
    MtmParkingLot::Block block(5);
    block.park(std::string("hi"), 2);
    block.park(std::string("hi"), 3);

    block.park(std::string("l"), 2);
    block.exit(std::string("l"));
    block.park(std::string("l"), 3);

    cout << block[2] << "\n" << block[3] << endl;
    block.exit(std::string("l"));

    cout << block[2] << "\n";
    try
    {
        cout << block[3] << endl;
    }
    catch (std::out_of_range& e)
    {
        cout << e.what();
    }

    if (block[2] != std::string("hi"))
    {
        return false;
    }
    return true;
}