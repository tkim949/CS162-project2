/****************************************************************************************************
 * * Program name: CS162 Project2
 * * Author: Taekyoung Kim
 * * Date: 01/21/2019
 * * Description: This is Animal.h file for CS162 Project2
 * * This project shows a zoo that has a few animals. We needs inheritance and class......
 ******************************************************************************************************/


#include "Turtle.h"

Turtle::Turtle()=default;
Turtle::~Turtle()=default;

Turtle::Turtle(int age, double cost, int numOfBabies, double baseFoodCost, double payoff)
        :Animal(age, cost, numOfBabies, baseFoodCost, payoff)
{

}