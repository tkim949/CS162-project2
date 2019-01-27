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
#include <iostream>
#include <random>
#include "Tiger.h"
#include "Penguin.h"
#include "Turtle.h"
#include "DArray.h"

Zoo::Zoo()=default;
Zoo::~Zoo()=default;

int Zoo::getDay(){
    return this -> day;
}
void Zoo::setDay(int d){
    day = d;
}
int Zoo::getNumOfTig(){
    return numOfTig;
}
void Zoo::setNumOfTig(int tig){
    numOfTig =tig;

}
int Zoo::getNumOfPeng(){
    return numOfPeng;

}
void Zoo::setNumOfPeng(int pen){
    numOfPeng = pen;

}
int Zoo::getNumOfTurt(){
    return numOfTurt;

}
void Zoo::setNumOfTurt(int turt){
    numOfTurt =turt;
}

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
    //Tiger * arrayOfTi = new Tiger();
    Tiger * arrayOfTi = new Tiger[room.getRoomOfTi()];

    for(int i=0; i<room.getRoomOfTi(); i++){
        arrayOfTi[i] = Tiger(0, 0.00, 0, 0.00, 0.00);
    }

    room.setRoomOfPe(10);
    Penguin * arrayOfPe = new Penguin[room.getRoomOfPe()];

    for(int i=0; i<room.getRoomOfPe(); i++){

        arrayOfPe[i] = Penguin(0, 0.00, 0, 0.00, 0.00);
    }

    room.setRoomOfTu(10);
    Turtle * arrayOfTur = new Turtle[room.getRoomOfTu()];

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
    setNumOfTig(inputVal(fBuyTi));

    if(!(numOfTig==1 || numOfTig ==2)) {

        do{
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            std::cout<<"Wrong input. You can buy only 1 or 2 Tigers, Please try again: ";
            std::cin >> fBuyTi;
            setNumOfTig(inputVal(fBuyTi));
        }while(!(numOfTig ==1 || numOfTig==2));
    }

    for(int i =0; i <numOfTig; i++) {

       arrayOfTi[i] = Tiger(0, tiger.getCost(), 0, tiger.getBaseFoodCost(), tiger.getPayoff());
    }
    account -= (numOfTig*tiger.getCost());

    std::cin.clear();
    std::cin.ignore(INT_MAX, '\n');
    std::cout<<"How many Penguins are you willing to buy? choose 1 or 2: ";
    std::cin >> fBuyP;
    setNumOfPeng(inputVal(fBuyP));

    if(!(numOfPeng ==1 || numOfPeng ==2)) {

        do{
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            std::cout<<"Wrong input. You can buy only 1 or 2 Penguins, Please try again: ";
            std::cin >> fBuyP;
            setNumOfPeng(inputVal(fBuyP));
        }while(!(numOfPeng ==1 || numOfPeng ==2));
    }

    for(int i =0; i <numOfPeng; i++) {

        arrayOfPe[i] = Penguin(0, penguin.getCost(), 0, penguin.getBaseFoodCost(), penguin.getPayoff());
    }

    account -= (numOfPeng * penguin.getCost());

    std::cin.clear();
    std::cin.ignore(INT_MAX, '\n');
    std::cout<<"How many Turtles do you want to buy? Choose 1 or 2: ";
    std::cin>>fBuyTu;
    setNumOfTurt(inputVal(fBuyTu));

    if(!(numOfTurt ==1 || numOfTurt ==2)) {

        do{
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            std::cout<<"Wrong input. You can buy only 1 or 2 Turtles, Please try again: ";
            std::cin>>fBuyTu;
            setNumOfTurt(inputVal(fBuyTu));

        }while(!(numOfTurt ==1 || numOfTurt ==2));
    }

    for(int i =0; i <numOfTurt; i++) {

        arrayOfTur[i] = Turtle(0, turtle.getCost(), 0, turtle.getBaseFoodCost(), turtle.getPayoff());
    }
    account -= (numOfTurt* turtle.getCost());

    std::cout<<"After the purchase, your account balance is "<<account<<std::endl;
    std::cout<<std::endl;

    do{
        setDay(getDay()+1);
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
        //Feed the animals and deduct the cost from the account.
        costPerDay = (numOfTig*baseCost*5)+(numOfPeng*baseCost)+(numOfTurt*baseCost*0.5);
        std::cout<<"Today's feeding cost is "<<costPerDay<<std::endl;

        std::cout<<"The Turtle is (before the event!: "<<std::endl;
        for(int i=0; i<room.getRoomOfTu(); i++){
            std::cout<<"number "<<i+1<<" : "<<arrayOfTur[i].getAge()<<" , "<<arrayOfTur[i].getCost()<<" "<<arrayOfTur[i].getNumOfBabies()<<std::endl;
        }

        //Random Event!
        int event;
        double bonus =0.00;

        std::random_device ran;
        std::mt19937 mt(ran());
        std::uniform_int_distribution <int> dist(1, 3);
        event = dist(mt);

        std::cout<<"Today's event is: "<<event<<std::endl;

        //Sickness occurs and one animal that is chosen will die.
        if (event == 1) {

            room.pickRemove(numOfTig, numOfPeng, numOfTurt, arrayOfTi, arrayOfPe, arrayOfTur);

            std::cout<<"after the funct 'who sick'. The num of Tiger: "<<numOfTig<<std::endl;
            std::cout<<"after the funct 'who sick'. The num of Penguin: "<<numOfPeng<<std::endl;
            std::cout<<"after the funct 'who sick'. The num of Turtle: "<<numOfTurt<<std::endl;

        }
        // A boom in zoo attendance occurs
        else if(event == 2){
            //another random need to set the bonus

             std::uniform_int_distribution <int> dist3(250, 500);
             bonus= dist3(mt);
             std::cout<<"Your today bonus is "<<bonus*numOfTig<<std::endl;
             bonus = (bonus*getNumOfTig()); //bonus * number of tiger
        }

        //This event gives babies to the animal, "event ==3"
        else{

            room.whoHasBaby(numOfTig, numOfPeng, numOfTurt, arrayOfTi, arrayOfPe, arrayOfTur);

            std::cout<<"after the funct 'who has babay'. The num of Tiger: "<<numOfTig<<std::endl;
            std::cout<<"after the funct 'who has babay'. The num of Penguin: "<<numOfPeng<<std::endl;
            std::cout<<"after the funct 'who has baaby.' The num of Turtle: "<<numOfTurt<<std::endl;

        }

        std::cout<<"The Turtle is (just after the event!: "<<std::endl;
        for(int i=0; i<room.getRoomOfTu(); i++){
            std::cout<<"number "<<i+1<<" : "<<arrayOfTur[i].getAge()<<" , "<<arrayOfTur[i].getCost()<<" "<<arrayOfTur[i].getNumOfBabies()<<std::endl;
        }

        double todayAIncome =numOfTig*tiger.getPayoff()+numOfPeng*penguin.getPayoff()+numOfTurt*turtle.getPayoff();
        double profit = todayAIncome + bonus - costPerDay;
        account= account + profit;

        std::cout<<"Now it's the time to check your balance."<<std::endl;
        std::cout<<"Today's Tiger payoff "<<numOfTig * tiger.getPayoff()<<std::endl;
       // std::cout<<"The Penguin's payoff "<<numOfPeng * penguin.getPayoff()<<std::endl;
        std::cout<<"The Turtle's payoff "<<numOfTurt * turtle.getPayoff()<<std::endl;
        std::cout<<"So, Your income from admission fee is "<<todayAIncome<<std::endl;
        std::cout<<"And, today's your bonus income is "<<bonus<<std::endl;
        std::cout<<"Today's your profit(Admission income + bonus - daily cost)= "<<profit<<std::endl;
        std::cout<<"Now your balance is "<<account<<std::endl;



        double buyNewOne;
        int buyNew;

        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        std::cout<<"Pretty busy day, right? Now you can buy an adult animal."<<std::endl;
        std::cout<<"Currently, you have "<<numOfTig<<" Tigers, "<<numOfPeng<<" Penguins, "<<numOfTurt<<" Turtles"<<std::endl;
        std::cout<<"If you want to buy, input 1, otherwise (it you don't want to buy), click 2: ";
        std::cin>>buyNewOne;
        buyNew =inputVal(buyNewOne);

        if(!(buyNew ==1 || buyNew ==2)) {

            do{
                std::cin.clear();
                std::cin.ignore(INT_MAX, '\n');
                std::cout<<"Wrong input. You can only input 1 or 2, Please try again: ";
                std::cin>>buyNewOne;
                buyNew =inputVal(buyNewOne);
            }while(!(buyNew ==1 || buyNew ==2));
        }

        if(buyNew==1) {

            double buyChoice;
            int buyOneMore;
            std::cout
                    << "So, you want to buy. Good! which animal will you buy; input 1 for Tiger, 2 for Penguin, and 3 for Turtle: ";
            std::cin >> buyChoice;
            buyOneMore = inputVal(buyChoice);

            if(!(buyOneMore ==1 || buyOneMore ==2 || buyOneMore ==3)) {

                do{
                    std::cin.clear();
                    std::cin.ignore(INT_MAX, '\n');
                    std::cout<<"Wrong input. You should input 1,2,or 3. Please try again: ";
                    std::cin >> buyChoice;
                    buyOneMore = inputVal(buyChoice);

                }while(!(buyOneMore ==1 || buyOneMore ==2 || buyOneMore ==3));
            }

            if (buyOneMore == 1) {

                std::cout << "So, you decided to buy a Tiger. Best Choice!" << std::endl;
                if(numOfTig >= room.getRoomOfTi()) {

                    room.arrayTiger(arrayOfTi, room.getRoomOfTi());

                }
                //Adds a new tiger to the array.
                arrayOfTi[numOfTig] = Tiger(3, tiger.getCost(), 0, tiger.getBaseFoodCost(), tiger.getPayoff());
                setNumOfTig(numOfTig+1);
                account -= tiger.getCost();
                std::cout<<"After you buy the tiger, your balance is "<<account<<std::endl;
            }

            else if (buyOneMore == 2) {

                std::cout << "So, you decided to buy a Penguin. Fantastic Choice!" << std::endl;
                if(numOfPeng >= room.getRoomOfPe()) {

                    room.arrayPen(arrayOfPe, room.getRoomOfPe());

                }
                arrayOfPe[numOfPeng] = Penguin(3, penguin.getCost(), 0, penguin.getBaseFoodCost(), penguin.getPayoff());
                setNumOfPeng(numOfPeng+1);
                account -= penguin.getCost();
                std::cout<<"After you buy the penguin, your balance is "<<account<<std::endl;

            }

            else // (buyOneMore == 3)
            {
                std::cout <<"So, you decided to buy a Turtle. Beautiful Choice!"<< std::endl;
                if(numOfTurt >= room.getRoomOfTu()) {

                    room.arrayTur(arrayOfTur, room.getRoomOfTu());

                }
                arrayOfTur[numOfTurt] = Turtle(3, turtle.getCost(), 0, turtle.getBaseFoodCost(), turtle.getPayoff());
                setNumOfTurt(numOfTurt+1);
                account -= turtle.getCost();
                std::cout<<"After you buy the turtle, your balance is "<<account<<std::endl;
            }
        }

        else //(buyNew ==2)
        {
           std::cout<<"so you don't want to buy more. That's fine."<<std::endl;
        }

        std::cout<<"Now you have "<<numOfTig<<" Tigers, "<<numOfPeng<<" Penguins, "<<numOfTurt<<" Turtles"<<std::endl;

        std::cout<<"The Tiger is: "<<std::endl;
        for(int i=0; i<room.getRoomOfTi(); i++){
            std::cout<<"number "<<i+1<<" : "<<arrayOfTi[i].getAge()<<", "<<arrayOfTi[i].getCost()<<" " <<arrayOfTi[i].getNumOfBabies()<<std::endl;
        }

        std::cout<<"The Penguin is: "<<std::endl;
        for(int i=0; i<room.getRoomOfPe(); i++){
            std::cout<<"number "<<i+1<<" : "<<arrayOfPe[i].getAge()<<", "<<arrayOfPe[i].getCost()<<" "<<arrayOfPe[i].getNumOfBabies()<<std::endl;
        }
        std::cout<<"The Turtle is: "<<std::endl;
        for(int i=0; i<room.getRoomOfTu(); i++){
            std::cout<<"number "<<i+1<<" : "<<arrayOfTur[i].getAge()<<" , "<<arrayOfTur[i].getCost()<<" "<<arrayOfTur[i].getNumOfBabies()<<std::endl;
        }

        std::cout<<"The room for tiger: "<<room.getRoomOfTi()<<std::endl;
        std::cout<<"The room for Penguin "<<room.getRoomOfPe()<<std::endl;
        std::cout<<"the room for turtle "<<room.getRoomOfTu()<<std::endl;


        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        std::cout<<"If you want to play again, input 1. Otherwise, click any keys! ";
        std::cin>>playAgain;
        std::cout<<std::endl;

    }while(playAgain == 1 && account > 0);

    if (account < 0){
        std::cout<<"I'm sorry, but your account is empty. Play next time. Good buy!"<<std::endl;
    }

    //if(playAgain !=1) {

    std::cout <<"You want to stop. Good bye! See you again!" << std::endl;
    //}


    delete [] arrayOfTi;
    delete [] arrayOfPe;
    delete [] arrayOfTur;

}