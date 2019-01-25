/****************************************************************************************************
 * * Program name: CS162 Project2
 * * Author: Taekyoung Kim
 * * Date: 01/21/2019
 * * Description: This is Zoo.cpp file for CS162 Project2
 * * This project shows a zoo that has a few animals. We needs inheritance and class......
 ******************************************************************************************************/


#ifndef PROJECT2_DARRAY_H
#define PROJECT2_DARRAY_H
#include "Turtle.h"
#include "Animal.h"
#include "Penguin.h"
#include "Tiger.h"


class DArray {

protected:
    int sizeOfTi;
    int sizeOfPe;
    int sizeOfTu;

    Tiger *arr;
    Penguin *arra;
    Turtle *array;

public:
    DArray();
    ~DArray();
    int getSizeOfTi();
    void setSizeOfTi(int ti);
    int getSizeOfPe();
    void setSizeOfPe(int pe);
    int getSizeOfTu();
    void setSizeOfTu(int tu);
    void arrayTiger(Tiger *arr, int sizeOfTi);
    void arrayPen(Penguin *arra, int sizeOfPe);
    void arrayTur(Turtle *array, int sizeOfTu);


};


#endif //PROJECT2_DARRAY_H
