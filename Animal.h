/****************************************************************************************************
 * * Program name: CS162 Project2
 * * Author: Taekyoung Kim
 * * Date: 01/21/2019
 * * Description: This is Animal.h file for CS162 Project2
 * * This project shows a zoo that has a few animals. We needs inheritance and class......
 ******************************************************************************************************/



#ifndef ANIMAL_H
#define ANIMAL_H


class Animal {

private:

protected:
    int age;
    double cost ;
    int numOfBabies;
    double baseFoodCost;
    double payoff;

public:
    Animal();

    Animal(int age, double cost, int numOfBabies, double baseFoodCost, double payoff);
    virtual ~Animal();

    int getAge();

    void setAge(int a);

    double getCost();

    void setCost(double co);

    int getNumOfBabies();

    void setNumOfBabies(int Babies);

    double getBaseFoodCost();

    void setBaseFoodCost(double fCost);

    double getPayoff();

    void setPayoff(double pay);



};


#endif //PROJECT2_ANIMAL_H
