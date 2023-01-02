#ifndef PGMLIB_H
#define PGMLIB_H
#include <iostream>
#include <memory>
#include <vector>
#include "pgma_io.h"
namespace imutil
{
    using Point1D = std::array<int,1>;
    using Point2D = std::array<int,2>;
    using Point3D = std::array<int,3>;
    template<typename T>
    class Image
    {
        public:
            int *g;
            std::vector<std::vector<T>> _im;
            int rows;
            int cols;
            Image();
            ~Image();
            int& operator()(int row, int col)
            {
                return g[row*this->cols + col];
            }   
    };

    Image<Point1D> loadPGMImage(std::string fPath);
    void savePGMImage(std::string fPath, imutil::Image<imutil::Point1D> im);
};
template<typename T>
imutil::Image<T>::Image()
{
    
}
template<typename T>
imutil::Image<T>::~Image()
{
    //delete this->g;
}
imutil::Image<imutil::Point1D> imutil::loadPGMImage(std::string fPath)
{
    imutil::Image<imutil::Point1D> im;
    im.rows;
    im.cols;

    int max;
    pgma_read(fPath, im.cols, im.rows,max, &im.g);
    for(int i = 0; i < im.rows; i++)
    {
        std::vector<imutil::Point1D> row;
        for(int j = 0; j < im.cols; j++)
        {
            //std::cout << i*im.cols+j << std::endl;
            imutil::Point1D p = { im.g[i*im.cols+j] } ;
            row.push_back( p );
        }
        im._im.push_back(  row );
    }
    return im;
};
void imutil::savePGMImage(std::string fPath, imutil::Image<imutil::Point1D> im)
{
    int g[im.rows*im.cols];
    for(int i = 0; i < im.rows; i++)
    {
        std::vector<imutil::Point1D> row;
        for(int j = 0; j < im.cols; j++)
        {
            //std::cout << i*im.cols+j << std::endl;
            g[i*im.cols+j] = im._im[i][j][0];
        }
    }
    pgma_write(fPath, im.cols, im.rows, g);
};


#endif