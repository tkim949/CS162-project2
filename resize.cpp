/****************************************************************************************************
 * * Program name: CS162 Project2
 * * Author: Taekyoung Kim
 * * Date: 01/21/2019
 * * Description: This is Animal.cpp file for CS162 Project2
 * * This project shows a zoo that has a few animals. We needs inheritance and class......
 ******************************************************************************************************/


#include "resize.h"

void resize(Animal *arr, int size){


    Animal *temp_tu = new Animal[size * 2];

    for (int i = 0; i < size * 2; i++) {
        temp_tu[i] = Animal(0, 0.00, 0, 0.00, 0.00);
    }

    for (int i = 0; i < size; i++) {
        temp_tu[i] = arr[i];
    }
    size *= 2;

    //for (int j=0; j<size; j++) {
    //    arr[j]= Animal (0, 0.00, 0, 0.00, 0.00);
    //}

    arr = temp_tu;

}
