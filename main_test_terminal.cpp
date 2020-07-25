#include <iostream>
#include "include/Block.h"

using std::cout;
using std::endl;

bool block_test_1();

int main()
{
    if(block_test_1())
    {
        cout << "OK" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}

bool block_test_1()
{
    MtmParkingLot::Block block(5);
    std::string hi("hi");
    std::string l("l");
    block.park(hi, 2);
    block.park(hi, 3);

    block.park(l, 2);
    block.exit(l);
    block.park(l, 3);

    cout << block[2] << "\n" << block[3] << endl;
    block.exit(l);

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