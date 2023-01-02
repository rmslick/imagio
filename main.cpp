#include "pgmlib.h"

int main()
{ 
    auto m = imutil::loadPGMImage("coins.ascii.pgm");
    for(int i = 10; i <=14; i++)
    {
        for(int j = 10; j <=20; j++)
        {
            m._im[i][j][0] = 0;
        }
    }
    imutil::savePGMImage("coins2.ascii.pgm",m);
    std::cout << m.rows << " " << m.cols << std::endl;
};