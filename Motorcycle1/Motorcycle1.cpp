
#include <iostream>
#include "motorcycle.h"
using namespace std;

int main()
{
    motorcycle  m(1, 2, 3, 4);//1表示height，2表示setnum，3表示maxspeed，4表示weight 
    m.run();
    m.stop();
    return  0;
}
