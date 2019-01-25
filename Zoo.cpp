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
    //animal.setBaseFoodCost(10.00);
   // double baseCost = animal.getBaseFoodCost();
    Tiger tiger;
    Penguin penguin;
    Turtle turtle;
    double baseCost = 10.00;
    tiger.setCost(10000.00);
    double tigCost = tiger.getCost();
    penguin.setCost(1000.00);
    double penCost = penguin.getCost();
    turtle.setCost(100.00);
    double turCost = turtle.getCost();

    tiger.setBaseFoodCost(baseCost*5);
    penguin.setBaseFoodCost(baseCost);
    turtle.setBaseFoodCost(baseCost*0.5);

    tiger.setPayoff(tigCost*0.2);
    penguin.setPayoff(penCost*0.1);
    turtle.setPayoff(turCost*0.05);

    int roomForTi = 10;
    //Tiger * arrayOfTi = new Tiger();
    Tiger * arrayOfTi = new Tiger[roomForTi];

    for(int i=0; i<roomForTi; i++){
        arrayOfTi[i] = Tiger(0, 0.00, 0, 0.00, 0.00);
    }

    int roomForPe =10;
    Penguin * arrayOfPe = new Penguin[roomForPe];

    for(int i=0; i<roomForPe; i++){

        arrayOfPe[i] = Penguin(0, 0.00, 0, 0.00, 0.00);
    }

    int roomForTu =10;
    Turtle * arrayOfTur = new Turtle[roomForTu];

    for(int i=0; i<roomForTu; i++){

        arrayOfTur[i] = Turtle(0, 0.00, 0, 0.00, 0.00);
    }

    double fBuyTi;
    //int numOfTi = 0 ;
    double fBuyP;
    //int numOfPe = 0;
    double fBuyTu;
    //int numOfTu = 0;
    int playAgain;


    //std::cin.clear();
    //std::cin.ignore(INT_MAX, '\n');
    std::cout<<std::endl;
    std::cout<<"Now, did you decide how many each animals buy"<<std::endl;
    std::cout<<"How many tigers do you want? input just 1 or 2: ";
    std::cin >> fBuyTi;
    setNumOfTig(inputVal(fBuyTi));

    if(!(getNumOfTig()==1 || getNumOfTig() ==2)) {

        do{
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            std::cout<<"Wrong input. You can buy only 1 or 2 Tigers, Please try again: ";
            std::cin >> fBuyTi;
            setNumOfTig(inputVal(fBuyTi));
        }while(!(getNumOfTig() ==1 || getNumOfTig()==2));
    }

    for(int i =0; i <getNumOfTig(); i++) {

       arrayOfTi[i] = Tiger(0, tigCost, 0, tiger.getBaseFoodCost(), tiger.getPayoff());
    }
    account -= (getNumOfTig()*tigCost);

    std::cin.clear();
    std::cin.ignore(INT_MAX, '\n');
    std::cout<<"How many Penguins are you willing to buy? choose 1 or 2: ";
    std::cin >> fBuyP;
    setNumOfPeng(inputVal(fBuyP));

    if(!(getNumOfPeng() ==1 || getNumOfPeng() ==2)) {

        do{
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            std::cout<<"Wrong input. You can buy only 1 or 2 Penguins, Please try again: ";
            std::cin >> fBuyP;
            setNumOfPeng(inputVal(fBuyP));
        }while(!(getNumOfPeng() ==1 || getNumOfPeng() ==2));
    }

    for(int i =0; i <getNumOfPeng(); i++) {

        arrayOfPe[i] = Penguin(0, penCost, 0, penguin.getBaseFoodCost(), penguin.getPayoff());
    }

    account -= (getNumOfPeng() * penCost);

    std::cin.clear();
    std::cin.ignore(INT_MAX, '\n');
    std::cout<<"How many Turtles do you want to buy? Choose 1 or 2: ";
    std::cin>>fBuyTu;
    setNumOfTurt(inputVal(fBuyTu));

    if(!(getNumOfTurt() ==1 || getNumOfTurt() ==2)) {

        do{
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            std::cout<<"Wrong input. You can buy only 1 or 2 Turtles, Please try again: ";
            std::cin>>fBuyTu;
            setNumOfTurt(inputVal(fBuyTu));

        }while(!(getNumOfTurt() ==1 || getNumOfTurt() ==2));
    }

    for(int i =0; i <getNumOfTurt(); i++) {

        arrayOfTur[i] = Turtle(0, turCost, 0, turtle.getBaseFoodCost(), turtle.getPayoff());
    }
    account -= (getNumOfTurt() * turCost);

    std::cout<<"After the purchase, your account balance is "<<account<<std::endl;

    do{
        setDay(getDay()+1);
        std::cout<<"The day: "<<day<<std::endl;

        for (int i=0; i<getNumOfTig() ; i++){

            arrayOfTi[i].setAge(arrayOfTi[i].getAge()+1);
        }

        for (int i=0; i<getNumOfPeng() ; i++){

            arrayOfPe[i].setAge(arrayOfPe[i].getAge()+1);
        }

        for (int i=0; i<getNumOfTurt(); i++){

            arrayOfTur[i].setAge(arrayOfTur[i].getAge()+1);
        }

        std::cout<<"The Tiger is: "<<std::endl;
        for(int i=0; i<roomForTi; i++){
            std::cout<<"number "<<i+1<<" : "<<arrayOfTi[i].getAge()<<", "<<arrayOfTi[i].getCost()<<std::endl;
        }

        std::cout<<"The Penguin is: "<<std::endl;
        for(int i=0; i<roomForPe; i++){
            std::cout<<"number "<<i+1<<" : "<<arrayOfPe[i].getAge()<<", "<<arrayOfPe[i].getCost()<<std::endl;
        }
        std::cout<<"The Turtle is: "<<std::endl;
        for(int i=0; i<roomForTu; i++){
            std::cout<<"number "<<i+1<<" : "<<arrayOfTur[i].getAge()<<" , "<<arrayOfTur[i].getCost()<<std::endl;
        }

        double costPerDay;
        //Feed the animals and deduct the cost from the account.
        costPerDay = (getNumOfTig()*baseCost*5)+(getNumOfPeng()*baseCost)+(getNumOfTurt()*baseCost*0.5);
        std::cout<<"Today's feeding cost is "<<costPerDay<<std::endl;

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

           int numOfAni = getNumOfTig()+getNumOfPeng()+getNumOfTurt();
           int whoSick;

           int * allAnimal= new int [numOfAni];

           for(int i=0; i< getNumOfTig() ; i++){

               allAnimal[i]= i;
           }
           for(int i= getNumOfTig(); i<getNumOfTig()+getNumOfPeng(); i++){

               allAnimal[i] = i;
           }
           for(int i=getNumOfTig()+getNumOfPeng(); i<numOfAni ; i++){

               allAnimal[i] = i;
           }

            std::uniform_int_distribution <int> dist2(0,numOfAni-1);
            whoSick = dist2(mt);

            // A Tiger gets sick and remove
            if(whoSick < getNumOfTig()) {

                std::cout<<"Your Tiger number "<<whoSick+1<< " got sick and died. So sorry!"<<std::endl;
                setNumOfTig(getNumOfTig()-1);

                for(int j=whoSick; j<roomForTi; j++) {

                    Tiger temp = arrayOfTi[j];
                    arrayOfTi[j] = arrayOfTi [j+1];
                    arrayOfTi[j+1] = temp;
                }
                arrayOfTi[roomForTi-1] = Tiger(0, 0.00, 0, 0.00, 0.00);
            }
            //A Penguin get sick and remove
            else if(whoSick>= getNumOfTig() && whoSick < getNumOfTig()+getNumOfPeng()) {

                setNumOfPeng(getNumOfPeng()-1);
                //arrayOfPe[whoSick-numOfTi];
                int sickP= whoSick -getNumOfTig();

                std::cout<<"Your Penguin number "<<sickP<<" got sick and died. So sorry"<<std::endl;

                for(int j= sickP; j<roomForPe; j++) {

                    Penguin temp = arrayOfPe[j];
                    arrayOfPe[j] = arrayOfPe [j+1];
                    arrayOfPe[j+1] = temp;
                }
                arrayOfPe[roomForPe-1] = Penguin(0, 0.00, 0, 0.00, 0.00);

            }
            //A turtle get sick and remove
            else // whoSick >= numOfTi+numOfPe && whoSick < numOfAni
            {
                setNumOfTurt(getNumOfTurt()-1);
               //arrayOfTur[whoSick -(numOfTi + numOfPe)];
                int sickTu = whoSick -(getNumOfTig() + getNumOfPeng());
                std::cout<<"Your Turtle number "<<sickTu<<" got sick and died. So sorry"<<std::endl;

                for(int j=sickTu; j<roomForTu; j++) {

                    Turtle temp = arrayOfTur[j];
                    arrayOfTur[j] = arrayOfTur [j+1];
                    arrayOfTur[j+1] = temp;
                }
                arrayOfTur[roomForTu-1] = Turtle(0, 0.00, 0, 0.00, 0.00);
            }

            delete [] allAnimal;
        }

        // A boom in zoo attendance occurs
        else if(event == 2){
            //another random need to set the bonus

             std::uniform_int_distribution <int> dist3(250, 500);
             bonus= dist3(mt);
             std::cout<<"Your today bonus is "<<bonus*getNumOfTig()<<std::endl;
             bonus = (bonus*getNumOfTig()); //bonus * number of tiger
        }

        //This event gives babies to the animal, event ==3
        else{

            int draw;

            int numAdTi = 0;
            for (int i = 0; i < getNumOfTig(); i++) {
                if (arrayOfTi[i].getAge() >= 3) {
                    numAdTi += 1;
                }
            }
            std::cout <<"Number of Adult Tigers: " << numAdTi << std::endl;

            int *adultTiger = new int[numAdTi];
            int j = 0;
            for (int i = 0; i < getNumOfPeng(); i++) {
                if (arrayOfTi[i].getAge() >= 3) {
                    adultTiger[j] = i;
                    j++;
                }
                std::cout<<"Age of Penguins: "<<i<<" : "<<arrayOfPe[i].getAge()<<std::endl;
            }
            int numAdPen = 0;
            for (int i = 0; i < getNumOfPeng(); i++) {
                if (arrayOfPe[i].getAge() >= 3) {
                    numAdPen += 1;
                }
            }
            std::cout <<"Number of Adult penguins: " << numAdPen << std::endl;


            int *adultPenguin = new int[numAdPen];
            int k = 0;
            for (int i = 0; i < getNumOfPeng(); i++) {
                if (arrayOfPe[i].getAge() >= 3) {
                    adultPenguin[k] = i;
                    k++;
                }
            }


            int numAdTur = 0;
            for (int i = 0; i < getNumOfTurt(); i++) {
                if (arrayOfTur[i].getAge() >= 3) {
                    numAdTur += 1;
                }
                std::cout<<"Age of Turtles: "<<i<<" : "<<arrayOfTur[i].getAge()<<std::endl;
            }
            std::cout << "Number of Adult Turtle: " << numAdTur << std::endl;

            int *adultTurtle = new int[numAdTur];

            int l = 0;
            for (int i = 0; i < getNumOfTurt(); i++) {
                if (arrayOfTur[i].getAge() >= 3) {
                    adultTurtle[l] = i;
                    l++;
                }
            }


            //to just show an check
            for (int m = 0; m < numAdPen; m++) {

                std::cout << "Adult Penguin: " << adultPenguin[m] << std::endl;
            }

            int numAdAnimal = numAdTi + numAdPen + numAdTur;

            std::uniform_int_distribution<int> dist5(0, numAdAnimal - 1);
            draw = dist5(mt);

            //A Tiger has a baby.
            if (numAdAnimal <= 0) {
                std::cout << "Sorry. You don't have any adult animals. Maybe next time!" << std::endl;
            }

            else {
                if (draw < numAdTi) {
                    int chosenTi;
                    chosenTi = adultTiger[draw];
                    std::cout << "Your tiger number: "<<chosenTi+1<< "has a baby. Congratulations!" << std::endl;

                    delete[] adultTiger;

                    //Updates the baby record of the tiger who has a baby.
                    arrayOfTi[chosenTi].setNumOfBabies(arrayOfTi[chosenTi].getNumOfBabies() + 1);
                    setNumOfTig(getNumOfTig()+1);

                    if (getNumOfTig() >= roomForTi) {

                        DArray arr;
                        arr.setSizeOfTi(roomForTi);
                        arr.arrayTiger(arrayOfTi, roomForTi);
                        roomForTi = arr.getSizeOfTi();

                        std::cout<<"Room For Tiger inside "<<roomForPe<<std::endl;


                    }
                    //Add the new baby to the array of Tiger.
                    arrayOfTi[getNumOfTig() - 1] = Tiger(0, tigCost, 0, tiger.getBaseFoodCost(), tiger.getPayoff());

                }

                    //A penguin has 5 babies.

                else if (draw >= numAdTi && draw < numAdTi + numAdPen) {
                    int chosenPen;
                    chosenPen = adultPenguin[draw - numAdTi];
                    std::cout << "Your penguin number "<<chosenPen+1<<"  has 5 babies. Congratulations!" << std::endl;
                    delete[] adultPenguin;


                    //Updates the baby record of the Penguin who has babies.
                    arrayOfPe[chosenPen].setNumOfBabies(arrayOfPe[chosenPen].getNumOfBabies() + 5);
                    setNumOfPeng(getNumOfPeng()+5);
                    if (getNumOfPeng() >= roomForPe) {

                        //resize(arrayOfPe, roomForPe);
                        DArray arra;
                        arra.setSizeOfPe(roomForPe);
                        arra.arrayPen(arrayOfPe, roomForPe);
                        roomForPe = arra.getSizeOfPe();

                        std::cout<<"Room For penguin inside "<<roomForPe<<std::endl;

                    }

                    //Adds the penguin babies to the array of Penguin.
                    for (int i = 0; i < 5; i++) {
                        arrayOfPe[getNumOfPeng() - 5 + i] = Penguin(0, penCost, 0, penguin.getBaseFoodCost(),
                                                             penguin.getPayoff());
                    }

                }
                    //A turtle has 10 babies.

                else // whoSick >= numOfTi+numOfPe && whoSick < numOfAni
                {
                    int chosenTurtle;
                    chosenTurtle = adultTurtle[draw - numAdTi - numAdPen];
                    std::cout << "Your Turtle number "<<chosenTurtle +1<<" has 10 babies.Congratulations!" << std::endl;
                    delete[] adultTurtle;
                    //Updates the record of the Turtle who has babies.
                    arrayOfTur[chosenTurtle].setNumOfBabies(arrayOfTur[chosenTurtle].getNumOfBabies() + 10);
                    setNumOfTurt(getNumOfTurt()+10);

                    if (getNumOfTurt() >= roomForTu) {

                       DArray array;
                       array.setSizeOfTu(roomForTu);
                       array.arrayTur(arrayOfTur, roomForTu);
                       roomForTu = array.getSizeOfTu();

                    }
                    //Adds the babies to the array of Turtle.
                    for (int i = 0; i < 10; i++) {
                        arrayOfTur[getNumOfTurt() - 10 + i] = Turtle(0, turCost, 0, turtle.getBaseFoodCost(),
                                                              turtle.getPayoff());
                    }
                }

                //delete [] allAnimal;
            }
        }

        double todayAIncome =getNumOfTig()*tiger.getPayoff()+getNumOfPeng()*penguin.getPayoff()+getNumOfTurt()*turtle.getPayoff();
        account= account + bonus + todayAIncome - costPerDay;

        std::cout<<"Now it's the time to check your balance."<<std::endl;
        std::cout<<"Today's Tiger payoff "<<getNumOfTig() * tiger.getPayoff()<<std::endl;
        std::cout<<"The Penguin's payoff "<<getNumOfPeng() * penguin.getPayoff()<<std::endl;
        std::cout<<"The Turtle's payoff "<<getNumOfTurt() * turtle.getPayoff()<<std::endl;
        std::cout<<"So, Your total admission fee income is "<<todayAIncome<<std::endl;
        std::cout<<"And, today's your bonus income is "<<bonus<<std::endl;
        std::cout<<"Now your balance is "<<account<<std::endl;


        double buyNewOne;
        int buyNew;

        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        std::cout<<"Pretty busy day, right? Now you can buy an adult animal."<<std::endl;
        std::cout<<"Currently, you have "<<getNumOfTig()<<" Tigers, "<<getNumOfPeng()<<" Penguins, "<<getNumOfTurt()<<" Turtles"<<std::endl;
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
                if(getNumOfTig() >= roomForTi) {

                    DArray arr;
                    arr.setSizeOfTi(roomForTi);
                    arr.arrayTiger(arrayOfTi, roomForTi);
                    roomForTi = arr.getSizeOfTi();

                }
                //Adds a new tiger to the array.
                arrayOfTi[getNumOfTig()] = Tiger(3, tigCost, 0, tiger.getBaseFoodCost(), tiger.getPayoff());
                setNumOfTig(getNumOfTig()+1);
                account -= tigCost;
                std::cout<<"After you buy the tiger, your balance is "<<account<<std::endl;
            }

            else if (buyOneMore == 2) {

                std::cout << "So, you decided to buy a Penguin. Fantastic Choice!" << std::endl;
                if(getNumOfPeng() >= roomForPe) {
                    //resize(arrayOfPe, roomForPe);
                    DArray arra;
                    arra.setSizeOfPe(roomForPe);
                    arra.arrayPen(arrayOfPe, roomForPe);
                    roomForPe = arra.getSizeOfPe();

                }
                arrayOfPe[getNumOfPeng()] = Penguin(3, penCost, 0, penguin.getBaseFoodCost(), penguin.getPayoff());
                setNumOfPeng(getNumOfPeng()+1);
                account -= penCost;
                std::cout<<"After you buy the penguin, your balance is "<<account<<std::endl;

            }

            else // (buyOneMore == 3)
            {
                std::cout <<"So, you decided to buy a Turtle. Beautiful Choice!"<< std::endl;
                if(getNumOfTurt() >= roomForTu) {
                    //resize(arrayOfTur, roomForTu);
                    DArray array;
                    array.setSizeOfTu(roomForTu);
                    array.arrayTur(arrayOfTur, roomForTu);
                    roomForTu = array.getSizeOfTu();

                }
                arrayOfTur[getNumOfTurt()] = Turtle(3, turCost, 0, turtle.getBaseFoodCost(), turtle.getPayoff());
                setNumOfTurt(getNumOfTurt()+1);
                account -= turCost;
                std::cout<<"After you buy the turtle, your balance is "<<account<<std::endl;
            }

            std::cout<<"After the purchase now you have "<<getNumOfTig()<<" Tigers, "<<getNumOfPeng()<<" Penguins, "<<getNumOfTurt()<<" Turtles"<<std::endl;
        }

        else //(buyNew ==2)
        {
           std::cout<<"so you don't want to buy more. That's fine."<<std::endl;
        }


        std::cout<<"The Tiger is: "<<std::endl;
        for(int i=0; i<roomForTi; i++){
            std::cout<<"number "<<i+1<<" : "<<arrayOfTi[i].getAge()<<", "<<arrayOfTi[i].getCost()<<std::endl;
        }

        std::cout<<"The Penguin is: "<<std::endl;
        for(int i=0; i<roomForPe; i++){
            std::cout<<"number "<<i+1<<" : "<<arrayOfPe[i].getAge()<<", "<<arrayOfPe[i].getCost()<<std::endl;
        }
        std::cout<<"The Turtle is: "<<std::endl;
        for(int i=0; i<roomForTu; i++){
            std::cout<<"number "<<i+1<<" : "<<arrayOfTur[i].getAge()<<" , "<<arrayOfTur[i].getCost()<<std::endl;
        }

        std::cout<<"The room for tiger: "<<roomForTi<<std::endl;
        std::cout<<"The room for Penguin "<< roomForPe<<std::endl;
        std::cout<<"the room for turtle "<<roomForTu<<std::endl;


        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        std::cout<<"If you want to play again, input 1. Otherwise, click any keys! ";
        std::cin>>playAgain;
        std::cout<<std::endl;

    }while(playAgain == 1 && account > 0);

    if (account < 0){
        std::cout<<"I'm sorry, but your account is empty. Play next time. Good buy!"<<std::endl;
    }
    delete [] arrayOfTi;
    delete [] arrayOfPe;
    delete [] arrayOfTur;

    if(playAgain !=1) {

        std::cout <<"You want to stop. Good bye! See you again!" << std::endl;
    }
}