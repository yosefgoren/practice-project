#include <iostream>
#include "include/Block.h"

using std::cout;
using std::endl;

int main()
{
    Block block(5);
    block[3] = "dfsfds";
    for(int i = 0; i < block.size(); ++i)
    {
        cout << block[i] << endl;
    }

    return 0;
}