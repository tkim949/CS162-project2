/****************************************************************************************************
 * * Program name: CS162 Project2
 * * Author: Taekyoung Kim
 * * Date: 01/21/2019
 * * Description: This is Animal.cpp file for CS162 Project2
 * * This project shows a zoo that has a few animals. We needs inheritance and class......
 ******************************************************************************************************/



#include "Animal.h"
#include <iostream>

Animal::Animal()=default;

Animal::Animal(int age, double cost, int numOfBabies, double baseFoodCost, double payoff){
    this -> age =age;
    this -> cost =cost;
    this -> numOfBabies = numOfBabies;
    this -> baseFoodCost = baseFoodCost;
    this -> payoff = payoff;
}
Animal::~Animal()=default;

int Animal::getAge() {
    return this -> age;
}

void Animal::setAge(int a){
    age = a;
}
double Animal::getCost(){
    return this ->cost;

}
void Animal::setCost(double co){
    cost = co;

}
int Animal::getNumOfBabies(){
    return this ->numOfBabies;

}
void Animal::setNumOfBabies(int babies){
    numOfBabies = babies;

}
double Animal::getBaseFoodCost(){
    return this -> baseFoodCost;

}
void Animal::setBaseFoodCost(double fCost){
    baseFoodCost =fCost;

}
double Animal::getPayoff(){
    return this -> payoff;

}
void Animal::setPayoff(double pay){
    payoff = pay;

}
