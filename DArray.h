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

    int roomOfTi;
    int roomOfPe;
    int roomOfTu;

    Tiger *arr;
    Penguin *arra;
    Turtle *array;

public:
    DArray();
    ~DArray();
    int getRoomOfTi();
    void setRoomOfTi(int ti);
    int getRoomOfPe();
    void setRoomOfPe(int pe);
    int getRoomOfTu();
    void setRoomOfTu(int tu);
    void arrayTiger(Tiger *arr, int sizeOfTi);
    void arrayPen(Penguin *arra, int sizeOfPe);
    void arrayTur(Turtle *array, int sizeOfTu);
    void tigerSick(Tiger *arr, int sickNum);
    void penguinSick(Penguin *arra, int pickNum);
    void turtleSick(Turtle *array, int rollNum);
    //void pickRemove(int &ti, int &pe, int &tu, Tiger *arr, Penguin *arra, Turtle *array);
    void tigerHasBaby(Tiger *arr, int &numOfTiger, int goNum);
    void penguinHasBaby(Penguin *arra, int &numOfPenguin, int getNum);
    void turtleHasBaby(Turtle *array, int &numOfTurtle, int takeNum);
    //void whoHasBaby(int &rTiger, int &rPenguin, int &rTurtle, Tiger *arr, Penguin *arra, Turtle *array);

};


#endif //PROJECT2_DARRAY_H
