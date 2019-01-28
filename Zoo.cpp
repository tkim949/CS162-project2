/****************************************************************************************************
 * * Program name: CS162 Project2
 * * Author: Taekyoung Kim
 * * Date: 01/21/2019
 * * Description: This is Zoo.cpp file for CS162 Project2
 * * This project shows a zoo that has a few animals. We needs inheritance and class......
 ******************************************************************************************************/

#include "Zoo.h"
#include "Animal.h"
#include "inputVal.h"
#include "Tiger.h"
#include "Penguin.h"
#include "Turtle.h"
#include "DArray.h"
#include <iostream>
#include <random>
#include <memory>
#include <fstream>
#include <string>
#include <iomanip>

Zoo::Zoo()=default;
/*******************************
 Zoo::~Zoo(){
    delete [] arrayOfTi;
    delete [] arrayOfPe;
    delete [] arrayOfTur;
}
************************************************/

Zoo::~Zoo()=default;
void Zoo::play(){

    std::cout<<"Welcome to the Zoo! Now you run this Fantastic Zoo."<<std::endl;
    std::cout<<"First, you need to buy animals. You can buy three animals: Tiger, Penguin, and Turtle."<<std::endl;
    std::cout<<"You can only buy 1 or 2 per animals this first day with the basic given money, $100,000"<<std::endl;
    std::cout<<"You need to pay $10,000 for tiger, $1,000 for Penguin, and $100 for Turtle."<<std::endl;
    std::cout<<"You need to feed those animals everyday. The basic food cost is $10 per day."<<std::endl;
    std::cout<<"The tiger needs 5 times more than the basic food cost, and the turtle only needs half of that cost."<<std::endl;
    std::cout<<"Yes, it's too much cost, But don't worry. Those animals make money for you everyday"<<std::endl;
    std::cout<<"Tiger makes 20% of its cost, Penguin makes 10% of its cost, and turtle makes 5% of its cost"<<std::endl;
    std::cout<<std::endl;

    double account = 100000.00;

    Animal animal;
    
    Tiger tiger;
    Penguin penguin;
    Turtle turtle;
    //double baseCost = 10.00;


    tiger.setCost(10000.00);
    penguin.setCost(1000.00);
    turtle.setCost(100.00);

    tiger.setBaseFoodCost(baseCost*5);
    penguin.setBaseFoodCost(baseCost);
    turtle.setBaseFoodCost(baseCost*0.5);

    tiger.setPayoff(tiger.getCost()*0.2);
    penguin.setPayoff(penguin.getCost()*0.1);
    turtle.setPayoff(turtle.getCost()*0.05);

    DArray room;

    room.setRoomOfTi(10);
    room.setRoomOfPe(10);
    room.setRoomOfTu(10);

    //Tiger * arrayOfTi = new Tiger[room.getRoomOfTi()];
    //Penguin * arrayOfPe = new Penguin[room.getRoomOfPe()];
    //Turtle * arrayOfTur = new Turtle[room.getRoomOfTu()];
    arrayOfTi = new Tiger[room.getRoomOfTi()];
    arrayOfPe = new Penguin[room.getRoomOfPe()];
    arrayOfTur = new Turtle[room.getRoomOfTu()];

    for(int i=0; i<room.getRoomOfTi(); i++){
        arrayOfTi[i] = Tiger(0, 0.00, 0, 0.00, 0.00);
    }

    for(int i=0; i<room.getRoomOfPe(); i++){

        arrayOfPe[i] = Penguin(0, 0.00, 0, 0.00, 0.00);
    }

    for(int i=0; i<room.getRoomOfTu(); i++){

        arrayOfTur[i] = Turtle(0, 0.00, 0, 0.00, 0.00);
    }

    double fBuyTi;
    double fBuyP;
    double fBuyTu;
    int playAgain;

    //std::cin.clear();
    //std::cin.ignore(INT_MAX, '\n');
    std::cout<<std::endl;
    std::cout<<"Now, did you decide how many each animals buy"<<std::endl;
    std::cout<<"How many tigers do you want? input just 1 or 2: ";
    std::cin >> fBuyTi;
    numOfTig = inputVal(fBuyTi);
    numOfTig =choiceBTwo(numOfTig);

    for(int i =0; i <numOfTig; i++) {

       arrayOfTi[i] = Tiger(0, 10000, 0, baseCost * 5, 10000 * 0.2);
    }
    account -= (numOfTig*tiger.getCost());

    std::cin.clear();
    std::cin.ignore(INT_MAX, '\n');
    std::cout<<"How many Penguins are you willing to buy? choose 1 or 2: ";
    std::cin >> fBuyP;
    numOfPeng = inputVal(fBuyP);
    numOfPeng =choiceBTwo(numOfPeng);


    for(int i =0; i <numOfPeng; i++) {

        arrayOfPe[i] = Penguin(0, 1000, 0, baseCost, 1000 * 0.1);
    }
    account -= (numOfPeng * penguin.getCost());

    std::cin.clear();
    std::cin.ignore(INT_MAX, '\n');
    std::cout<<"How many Turtles do you want to buy? Choose 1 or 2: ";
    std::cin>>fBuyTu;
    numOfTurt = inputVal(fBuyTu);
    numOfTurt =choiceBTwo(numOfTurt);


    for(int i =0; i <numOfTurt; i++) {

        arrayOfTur[i] = Turtle(0, 100,0,baseCost * 0.5, 100 * 0.05);
                //(0, turtle.getCost(), 0, turtle.getBaseFoodCost(), turtle.getPayoff());
    }
    account -= (numOfTurt* turtle.getCost());

    std::cout<<"After the purchase, your account balance is "<<account<<std::endl;
    std::cout<<std::endl;

    do{
        day +=1;
        std::cout<<"The day: "<<day<<std::endl;

        for (int i=0; i<numOfTig ; i++){

            arrayOfTi[i].setAge(arrayOfTi[i].getAge()+1);
        }

        for (int i=0; i<numOfPeng ; i++){

            arrayOfPe[i].setAge(arrayOfPe[i].getAge()+1);
        }

        for (int i=0; i<numOfTurt; i++){

            arrayOfTur[i].setAge(arrayOfTur[i].getAge()+1);
        }

        double costPerDay;
        double option;
        int feedOpt;

        //std::cin.clear();
        //std::cin.ignore(INT_MAX, '\n');
        std::cout<<"You have 3 options for feeding animals; Cheap, Generic, and Premium"<<std::endl;
        std::cout<<"If you choose the Cheap one, you can save the cost by half but sickness become twice."<<std::endl;
        std::cout<<"If you choose the premium, you need to pay twice, but sickness becomes half."<<std::endl;
        std::cout<<"Please input 1 for Cheap one, 2 for Generic, or 3 for Premium!";
        std::cin>>option;
        feedOpt = inputVal(option);
        feedOpt = choiceBThree(feedOpt);

        //Feed the animals and deduct the cost from the account.
        costPerDay = (numOfTig*baseCost*5)+(numOfPeng*baseCost)+(numOfTurt*baseCost*0.5);

        //Random Event!
        int event;
        double bonus =0.00;

        std::random_device ran;
        std::mt19937 mt(ran());

        if (feedOpt == 1) {

            std::cout<<"\nYou chose cheap feeding option!"<<std::endl;
            costPerDay =costPerDay/2;
            std::cout<<"Today's feeding cost is "<<costPerDay<<std::endl;

            int cheapOpt;

            int dice[]={1,2,3,1,1,1};
            std::uniform_int_distribution <int> dist7(0, 5);
            cheapOpt = dist7(mt);
            std::cout<<"feedOpt 1 random number: "<<std::endl;

            event = dice[cheapOpt];
        }

        else if (feedOpt == 3) {

            std::cout<<"\nYou chose premium feeding option!"<<std::endl;
            costPerDay =costPerDay*2;
            std::cout<<"Today's feeding cost is "<<costPerDay<<std::endl;

            int premOpt;

            int dice2[] ={1,2,3,2,3,2};
            std::uniform_int_distribution <int> dist8(0, 5);
            premOpt = dist8(mt);

            std::cout<<"feedOpt 3 random number: "<<premOpt<<std::endl;

            event = dice2[premOpt];
        }

        else{ // feedOpt == 2

            std::cout<<"\nYou chose generic feeding option!"<<std::endl;
            std::cout<<"Today's feeding cost is "<<costPerDay<<std::endl;

            std::uniform_int_distribution <int> dist(1, 3);
            event = dist(mt);

            std::cout<<"feedOpt 2 random number: "<<event<<std::endl;

        }

        std::cout<<std::endl;
        std::cout<<"Today's event is: "<<event<<std::endl;

        std::ofstream text;
        text.open("note.txt", std::ios::out);

        if(text.fail()) {
            std::cout<<"note.txt"<<" could not be found"<<std::endl;
            exit(1);
        }

        //Sickness occurs and one animal that is chosen will die.
        if (event == 1) {

            text<<"'I'm so sorry, but today one of your animals gets sick and die.'\n"<<std::endl;
            text.close();

            std::cout<<std::ifstream("note.txt").rdbuf();
            std::ofstream del("note.txt", std::ios::out | std::ios::trunc);
            del.close();

            room.pickRemove(numOfTig, numOfPeng, numOfTurt, arrayOfTi, arrayOfPe, arrayOfTur);

        }
        // A boom in zoo attendance occurs
        else if(event == 2){
            //another random need to set the bonus
            text<<"'Good news for you, you win the bonus. Let's check how much it is!'\n"<<std::endl;
            text.close();

            std::cout<<std::ifstream("note.txt").rdbuf();
            std::ofstream del("note.txt", std::ios::out | std::ios::trunc);
            del.close();

             std::uniform_int_distribution <int> dist3(250, 500);
             bonus= dist3(mt);
             std::cout<<"Your today bonus is "<<bonus*numOfTig<<std::endl;
             bonus = (bonus*numOfTig); //bonus * number of tiger
        }

        else{//This event gives babies to the animal, "event ==3"

            text<<"'Congratulations! One of your animal is going to be a mom or dad!'\n"<<std::endl;
            text.close();

            std::cout<<std::ifstream("note.txt").rdbuf();
            std::ofstream del("note.txt", std::ios::out | std::ios::trunc);
            del.close();

            room.whoHasBaby(numOfTig, numOfPeng, numOfTurt, arrayOfTi, arrayOfPe, arrayOfTur);
        }

        double todayAIncome =numOfTig*tiger.getPayoff()+numOfPeng*penguin.getPayoff()+numOfTurt*turtle.getPayoff();
        double profit = todayAIncome + bonus - costPerDay;
        account= account + profit;

        std::cout<<"\nNow it's the time to check your balance."<<std::endl;
      //std::cout<<"Today's Tiger payoff "<<numOfTig * tiger.getPayoff()<<std::endl;
      //std::cout<<"The Penguin's payoff "<<numOfPeng * penguin.getPayoff()<<std::endl;
      //std::cout<<"The Turtle's payoff "<<numOfTurt * turtle.getPayoff()<<std::endl;
        std::cout<<"So, Your today's income from admission fee is "<<todayAIncome<<std::endl;
        std::cout<<"And, today's your bonus income is "<<bonus<<std::endl;
        std::cout<<"Today's your profit(Admission income + bonus - daily cost)= "<<profit<<std::endl;
        std::cout<<"Now your balance is "<<account<<std::endl;

        double buyNewOne;
        int buyNew;

        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        std::cout<<"\nPretty busy day, right? Now you can buy an adult animal."<<std::endl;
        std::cout<<"Currently, you have "<<numOfTig<<" Tigers, "<<numOfPeng<<" Penguins, "<<numOfTurt<<" Turtles"<<std::endl;
        std::cout<<"If you want to buy, input 1, otherwise (it you don't want to buy), click 2: ";
        std::cin>>buyNewOne;
        buyNew =inputVal(buyNewOne);
        buyNew =choiceBTwo(buyNew);

        if(buyNew==1) {

            double buyChoice;
            int buyOneMore;
            std::cout
                    << "\nSo, you want to buy. Good! which animal will you buy; input 1 for Tiger, 2 for Penguin, and 3 for Turtle: ";
            std::cin >> buyChoice;
            buyOneMore = inputVal(buyChoice);
            buyOneMore =choiceBThree(buyOneMore);

            if (buyOneMore == 1) {

                std::cout << "So, you decided to buy a Tiger. Best Choice!" << std::endl;
                if(numOfTig >= room.getRoomOfTi()-1) {

                    room.arrayTiger(arrayOfTi, room.getRoomOfTi());

                }
                //Adds a new tiger to the array.
                arrayOfTi[numOfTig] = Tiger(3, 10000, 0, baseCost*5, 10000*0.2);
                        //(3, tiger.getCost(), 0, tiger.getBaseFoodCost(), tiger.getPayoff());
                numOfTig +=1;
                account -= tiger.getCost();
                std::cout<<"After you buy the tiger, your balance is "<<account<<std::endl;
            }

            else if (buyOneMore == 2) {

                std::cout << "So, you decided to buy a Penguin. Fantastic Choice!" << std::endl;
                if(numOfPeng >= room.getRoomOfPe()-1) {

                    room.arrayPen(arrayOfPe, room.getRoomOfPe());
                    //resizePen(arrayOfPe, room.getRoomOfPe());

                }
                arrayOfPe[numOfPeng] = Penguin(3, 1000, 0, baseCost, 1000*0.1);
                        //(3, penguin.getCost(), 0, penguin.getBaseFoodCost(), penguin.getPayoff());
                numOfPeng+=1;
                account -= penguin.getCost();
                std::cout<<"After you buy the penguin, your balance is "<<account<<std::endl;

            }

            else // (buyOneMore == 3)
            {
                std::cout <<"So, you decided to buy a Turtle. Beautiful Choice!"<< std::endl;
                if(numOfTurt >= room.getRoomOfTu()-1) {

                    room.arrayTur(arrayOfTur, room.getRoomOfTu());

                }
                arrayOfTur[numOfTurt] = Turtle(3, 100, 0, baseCost*0.5, 100*0.05);
                        //(3, turtle.getCost(), 0, turtle.getBaseFoodCost(), turtle.getPayoff());
                numOfTurt+=1;
                account -= turtle.getCost();
                std::cout<<"After you buy the turtle, your balance is "<<account<<std::endl;
            }
        }

        else //(buyNew ==2)
        {
           std::cout<<"\nso you don't want to buy more. That's fine."<<std::endl;
        }

        std::cout<<"Now you have "<<numOfTig<<" Tigers, "<<numOfPeng<<" Penguins, "<<numOfTurt<<" Turtles\n"<<std::endl;

        std::cout<<"The Tiger is: "<<std::endl;
        for(int i=0; i<room.getRoomOfTi(); i++){
            std::cout<<"Number " <<std::setw(2)<<i + 1 <<"  Age: "<<std::setw(2)<<arrayOfTi[i].getAge()<<"  Cost: "<<std::setw(5);
            std::cout<<arrayOfTi[i].getCost()<<std::setw(2)<<"  Babies: "<<arrayOfTi[i].getNumOfBabies()<<std::setw(8);
            std::cout<<"  Base_food_cost: "<<std::setw(5)<<arrayOfTi[i].getBaseFoodCost()<<"  payoff: ";
            std::cout<<std::setw(5)<<arrayOfTi[i].getPayoff()<<std::endl;
        }

        std::cout<<"The Penguin is: "<<std::endl;
        for(int i=0; i<room.getRoomOfPe(); i++) {
            std::cout<<"Number " <<std::setw(2)<<i + 1 <<"  Age: "<<std::setw(2)<<arrayOfPe[i].getAge()<<"  Cost: "<<std::setw(5);
            std::cout<<arrayOfPe[i].getCost()<<std::setw(2)<<"  Babies: "<<arrayOfPe[i].getNumOfBabies()<<std::setw(8);
            std::cout<<"  Base_food_cost: "<<std::setw(5)<<arrayOfPe[i].getBaseFoodCost()<<" p ayoff: ";
            std::cout<<std::setw(5)<<arrayOfPe[i].getPayoff()<<std::endl;
        }
        std::cout << "The Turtle is: " << std::endl;
        for (int i = 0; i < room.getRoomOfTu(); i++) {
            std::cout<<"Number " <<std::setw(2)<<i + 1 <<"  Age: "<<std::setw(2)<<arrayOfTur[i].getAge()<<"  Cost: "<<std::setw(5);
            std::cout<<arrayOfTur[i].getCost()<<std::setw(2)<<"  Babies: "<<arrayOfTur[i].getNumOfBabies()<<std::setw(8);
            std::cout<<"  Base_food_cost: "<<std::setw(5)<<arrayOfTur[i].getBaseFoodCost()<<"  payoff: ";
            std::cout<<std::setw(5)<<arrayOfTur[i].getPayoff()<<std::endl;
        }

        std::cout<<"The room for tiger: "<<room.getRoomOfTi()<<std::endl;
        std::cout<<"The room for Penguin "<<room.getRoomOfPe()<<std::endl;
        std::cout<<"the room for turtle "<<room.getRoomOfTu()<<std::endl;


        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        std::cout<<"\nIf you want to play again, input 1. Otherwise, click any keys! ";
        std::cin>>playAgain;
        std::cout<<std::endl;

    }while(playAgain == 1 && account > 0);

    if (account < 0){
        std::cout<<"\nI'm sorry, but your account is empty. Play next time. Good buy!"<<std::endl;
    }

    //if(playAgain !=1) {

    std::cout <<"\nYou want to stop. Good bye! See you again!" << std::endl;
    //}

    //deleteArrays();
     delete [] arrayOfTi;
     delete [] arrayOfPe;
     delete [] arrayOfTur;
}

int Zoo::choiceBTwo(int a){

    double getInput;

    if(a==1 || a==2) {

        return a;
    }
    else{
        do{
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            std::cout<<"Wrong input. You can buy only 1 or 2 Tigers, Please try again: ";
            std::cin >> getInput;
            a = inputVal(getInput);
        }while(!(a == 1 || a == 2));
    }

    return a;
}


int Zoo::choiceBThree(int b){
    double getInput;

    if(b==1 || b==2 || b==3) {

        return b;
    }
    else{
        do{
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            std::cout<<"Wrong input. You can buy only 1 or 2 Tigers, Please try again: ";
            std::cin >> getInput;
            b = inputVal(getInput);
        }while(!(b == 1 || b == 2 || b==3));
    }

    return b;

}

/*********************************************************
void Zoo::resizePen(Penguin *arrayOfPe, int roomOfPe) {

    DArray room;

        int newSize = roomOfPe*2;
        Penguin *temp_pe = new Penguin[newSize];

        for (int i = 0; i < roomOfPe; i++) {
            temp_pe[i] = arrayOfPe[i];
        }

        delete [] arrayOfPe;

        for (int i =0; i<roomOfPe*2; i++){
            arrayOfPe[i] = temp_pe[i];
        }

        delete [] temp_pe;
        room.setRoomOfPe(roomOfPe*2);

}
 **************************************************************/