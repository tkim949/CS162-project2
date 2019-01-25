/****************************************************************************************************
 * * Program name: CS162 Project2
 * * Author: Taekyoung Kim
 * * Date: 01/21/2019
 * * Description: This is Zoo.h file for CS162 Project2
 * * This project shows a zoo that has a few animals. We needs inheritance and class......
 ******************************************************************************************************/

#ifndef PROJECT2_ZOO_H
#define PROJECT2_ZOO_H


class Zoo {

private:

    int day = 0;


public:
    Zoo();
    ~Zoo();
    int getDay();
    void setDay(int d);
    void play();

};


#endif //PROJECT2_ZOO_H
