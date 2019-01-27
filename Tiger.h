/****************************************************************************************************
 * * Program name: CS162 Project2
 * * Author: Taekyoung Kim
 * * Date: 01/21/2019
 * * Description: This is Animal.h file for CS162 Project2
 * * This project shows a zoo that has a few animals. We needs inheritance and class......
 ******************************************************************************************************/

#include "Animal.h"
#ifndef PROJECT2_TIGER_H
#define PROJECT2_TIGER_H


class Tiger:
        public Animal
{
private:

public:
    explicit Tiger();
    ~Tiger() override;
    Tiger(int age, double cost, int numOfBabies, double baseFoodCost, double payoff);


};


#endif //PROJECT2_TIGER_H
