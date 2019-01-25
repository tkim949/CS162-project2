/****************************************************************************************************
 * * Program name: CS162 Project2
 * * Author: Taekyoung Kim
 * * Date: 01/21/2019
 * * Description: This is Zoo.cpp file for CS162 Project2
 * * This project shows a zoo that has a few animals. We needs inheritance and class......
 ******************************************************************************************************/


#include "DArray.h"
#include "Zoo.h"


DArray::DArray() =default;
DArray::~DArray()=default;

int DArray::getSizeOfTi(){
    return sizeOfTi;

}
void DArray::setSizeOfTi(int ti){
    sizeOfTi = ti;

}
int DArray::getSizeOfPe(){
    return sizeOfPe;
}
void DArray::setSizeOfPe(int pe){
    sizeOfPe = pe;

}
int DArray::getSizeOfTu(){
    return sizeOfTu;

}
void DArray::setSizeOfTu(int tu){
    sizeOfTu = tu;

}
void DArray::arrayTiger(Tiger *arr, int sizeOfTi){

    Tiger *temp_ti = new Tiger[sizeOfTi * 2];

    for (int i = 0; i < sizeOfTi * 2; i++) {
        temp_ti[i] = Tiger(0, 0.00, 0, 0.00, 0.00);
    }

    for (int i = 0; i < sizeOfTi; i++) {
        temp_ti[i] = arr[i];
    }
    setSizeOfTi(sizeOfTi*2);
   // delete[] arr;
   // for (int i = 0; i < sizeOfTi * 2; i++) {
    //    arr[i] = Tiger(0, 0.00, 0, 0.00, 0.00);
   // }

    arr = temp_ti;

}
void DArray::arrayPen(Penguin *arra, int sizeOfPe){

    Penguin *temp_pe = new Penguin[sizeOfPe * 2];

    for (int i = 0; i < sizeOfPe * 2; i++) {
        temp_pe[i] = Penguin(0, 0.00, 0, 0.00, 0.00);
    }

    for (int i = 0; i < sizeOfPe; i++) {
        temp_pe[i] = arra[i];
    }
    setSizeOfPe(sizeOfPe*2);

    for (int i = sizeOfPe; i < sizeOfPe * 2; i++) {
        arra[i] = Penguin(0, 0.00, 0, 0.00, 0.00);
    }

    arra = temp_pe;

}
void DArray::arrayTur(Turtle *array, int sizeOfTu){

    Turtle *temp_tu = new Turtle[sizeOfTu * 2];

    for (int i = 0; i < sizeOfTu * 2; i++) {
        temp_tu[i] = Turtle(0, 0.00, 0, 0.00, 0.00);
    }

    for (int i = 0; i < sizeOfTu; i++) {
        temp_tu[i] = array[i];
    }

    setSizeOfTu(sizeOfTu*2);
   // delete[] array;

    for (int i = sizeOfTu; i < sizeOfTu * 2; i++) {
       array[i] = Turtle(0, 0.00, 0, 0.00, 0.00);
    }

    array = temp_tu;

}