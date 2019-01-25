/****************************************************************************************************
 * * Program name: CS162 Project2
 * * Author: Taekyoung Kim
 * * Date: 01/21/2019
 * * Description: This is Animal.h file for CS162 Project2
 * * This project shows a zoo that has a few animals. We needs inheritance and class......
 ******************************************************************************************************/

#include "Animal.h"
#ifndef PROJECT2_TURTLE_H
#define PROJECT2_TURTLE_H


#include "Animal.h"

class Turtle:
        public Animal
{
private:

public:
    Turtle();
    ~Turtle() override;
    Turtle(int age, double cost, int numOfBabies, double baseFoodCost, double payoff);
};


#endif //PROJECT2_TURTLE_H
