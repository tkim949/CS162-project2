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


Zoo::Zoo()=default;
Zoo::~Zoo()=default;

int Zoo::getDay(){
    return this -> day;
}
void Zoo::setDay(int d){
    day = d;
}

void Zoo::play() {

    std::cout << "Welcome to the Zoo! Now you run this Fantastic Zoo." << std::endl;
    std::cout << "First, you need to buy animals. You can buy three animals: Tiger, Penguin, and Turtle." << std::endl;
    std::cout << "You can only buy 1 or 2 per animals this first day with the basic given money, $100,000" << std::endl;
    std::cout << "You need to pay $10,000 for tiger, $1,000 for Penguin, and $100 for Turtle." << std::endl;
    std::cout << "You need to feed those animals everyday. The basic food cost is $10 per day." << std::endl;
    std::cout << "The tiger needs 5 times more than the basic food cost, and the turtle only needs half of that cost."
              << std::endl;
    std::cout << "Yes, it's too much cost, But don't worry. Those animals make money for you everyday" << std::endl;
    std::cout << "Tiger makes 20% of its cost, Penguin makes 10% of its cost, and turtle makes 5% of its cost"
              << std::endl;
    std::cout << std::endl;

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

    tiger.setBaseFoodCost(baseCost * 5);
    penguin.setBaseFoodCost(baseCost);
    turtle.setBaseFoodCost(baseCost * 0.5);

    tiger.setPayoff(tigCost * 0.2);
    penguin.setPayoff(penCost * 0.1);
    turtle.setPayoff(turCost * 0.05);

    int roomForTi = 10;
    //Tiger * arrayOfTi = new Tiger();
    Tiger *arrayOfTi = new Tiger[roomForTi];

    for (int i = 0; i < roomForTi; i++) {
        arrayOfTi[i] = Tiger(0, 0.00, 0, 0.00, 0.00);
    }

    int roomForPe = 10;
    Penguin *arrayOfPe = new Penguin[roomForPe];

    for (int i = 0; i < roomForPe; i++) {

        arrayOfPe[i] = Penguin(0, 0.00, 0, 0.00, 0.00);
    }

    int roomForTu = 10;
    Turtle *arrayOfTur = new Turtle[roomForTu];

    for (int i = 0; i < roomForTu; i++) {

        arrayOfTur[i] = Turtle(0, 0.00, 0, 0.00, 0.00);
    }

    double fBuyTi;
    int numOfTi = 0;
    double fBuyP;
    int numOfPe = 0;
    double fBuyTu;
    int numOfTu = 0;
    int playAgain;


    //std::cin.clear();
    //std::cin.ignore(INT_MAX, '\n');
    std::cout << std::endl;
    std::cout << "Now, did you decide how many each animals buy" << std::endl;
    std::cout << "How many tigers do you want? input just 1 or 2: ";
    std::cin >> fBuyTi;
    numOfTi = inputVal(fBuyTi);

    if (!(numOfTi == 1 || numOfTi == 2)) {

        do {
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            std::cout << "Wrong input. You can buy only 1 or 2 Tigers, Please try again: ";
            std::cin >> fBuyTi;
            numOfTi = inputVal(fBuyTi);
        } while (!(numOfTi == 1 || numOfTi == 2));
    }

    for (int i = 0; i < numOfTi; i++) {

        arrayOfTi[i] = Tiger(0, tigCost, 0, tiger.getBaseFoodCost(), tiger.getPayoff());
    }
    account -= (numOfTi * tigCost);

    std::cin.clear();
    std::cin.ignore(INT_MAX, '\n');
    std::cout << "How many Penguins are you willing to buy? choose 1 or 2: ";
    std::cin >> fBuyP;
    numOfPe = inputVal(fBuyP);

    if (!(numOfPe == 1 || numOfPe == 2)) {

        do {
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            std::cout << "Wrong input. You can buy only 1 or 2 Penguins, Please try again: ";
            std::cin >> fBuyP;
            numOfPe = inputVal(fBuyP);
        } while (!(numOfPe == 1 || numOfPe == 2));
    }

    for (int i = 0; i < numOfPe; i++) {

        arrayOfPe[i] = Penguin(0, penCost, 0, penguin.getBaseFoodCost(), penguin.getPayoff());
    }

    account -= (numOfPe * penCost);

    std::cin.clear();
    std::cin.ignore(INT_MAX, '\n');
    std::cout << "How many Turtles do you want to buy? Choose 1 or 2: ";
    std::cin >> fBuyTu;
    numOfTu = inputVal(fBuyTu);

    if (!(numOfTu == 1 || numOfTu == 2)) {

        do {
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            std::cout << "Wrong input. You can buy only 1 or 2 Turtles, Please try again: ";
            std::cin >> fBuyTu;
            numOfTu = inputVal(fBuyTu);
        } while (!(numOfTu == 1 || numOfTu == 2));
    }

    for (int i = 0; i < numOfTu; i++) {

        arrayOfTur[i] = Turtle(0, turCost, 0, turtle.getBaseFoodCost(), turtle.getPayoff());
    }
    account -= (numOfTu * turCost);

    std::cout << "After the purchase, your account balance is " << account << std::endl;

    do {
        setDay(getDay() + 1);
        std::cout << "The day: " << day << std::endl;

        for (int i = 0; i < numOfTi; i++) {

            arrayOfTi[i].setAge(arrayOfTi[i].getAge() + 1);
        }

        for (int i = 0; i < numOfPe; i++) {

            arrayOfPe[i].setAge(arrayOfPe[i].getAge() + 1);
        }

        for (int i = 0; i < numOfTu; i++) {

            arrayOfTur[i].setAge(arrayOfTur[i].getAge() + 1);
        }

        double costPerDay;
        //Feed the animals and deduct the cost from the account.
        costPerDay = (numOfTi * baseCost * 5) + (numOfPe * baseCost) + (numOfTu * baseCost * 0.5);
        std::cout << "Today's feeding cost is " << costPerDay << std::endl;

        //Random Event!
        int event;
        double bonus = 0.00;

        std::random_device ran;
        std::mt19937 mt(ran());
        std::uniform_int_distribution<int> dist(1, 3);
        event = dist(mt);

        std::cout << "Today's event is: " << event << std::endl;

        //Sickness occurs and one animal that is chosen will die.
        if (event == 1) {
            //another random needed to pick one animal.
            int numOfAni = numOfTi + numOfPe + numOfTu;
            int whoSick;

            int *allAnimal = new int[numOfAni];

            for (int i = 0; i < numOfTi; i++) {

                allAnimal[i] = i;
            }
            for (int i = numOfTi; i < numOfTi + numOfPe; i++) {

                allAnimal[i] = i;
            }
            for (int i = numOfTi + numOfPe; i < numOfAni; i++) {

                allAnimal[i] = i;
            }

            std::uniform_int_distribution<int> dist2(0, numOfAni - 1);
            whoSick = dist2(mt);

            // A Tiger gets sick and remove
            if (whoSick < numOfTi) {

                std::cout << "Your Tiger number " << whoSick + 1 << " got sick and died. So sorry!" << std::endl;
                numOfTi -= 1;

                for (int j = whoSick; j < roomForTi; j++) {

                    Tiger temp = arrayOfTi[j];
                    arrayOfTi[j] = arrayOfTi[j + 1];
                    arrayOfTi[j + 1] = temp;
                }
                arrayOfTi[roomForTi - 1] = Tiger(0, 0.00, 0, 0.00, 0.00);
            }
                //A Penguin get sick and remove
            else if (whoSick >= numOfTi && whoSick < numOfTi + numOfPe) {

                numOfPe -= 1;
                //arrayOfPe[whoSick-numOfTi];
                int sickP = whoSick - numOfTi;

                std::cout << "Your Penguin number " << sickP << " got sick and died. So sorry" << std::endl;

                for (int j = sickP; j < roomForPe; j++) {

                    Penguin temp = arrayOfPe[j];
                    arrayOfPe[j] = arrayOfPe[j + 1];
                    arrayOfPe[j + 1] = temp;
                }
                arrayOfPe[roomForPe - 1] = Penguin(0, 0.00, 0, 0.00, 0.00);

            }
                //A turtle get sick and remove
            else // whoSick >= numOfTi+numOfPe && whoSick < numOfAni
            {
                numOfTu -= 1;
                //arrayOfTur[whoSick -(numOfTi + numOfPe)];
                int sickTu = whoSick - (numOfTi + numOfPe);
                std::cout << "Your Turtle number " << sickTu << " got sick and died. So sorry" << std::endl;

                for (int j = sickTu; j < roomForTu; j++) {

                    Turtle temp = arrayOfTur[j];
                    arrayOfTur[j] = arrayOfTur[j + 1];
                    arrayOfTur[j + 1] = temp;
                }
                arrayOfTur[roomForTu - 1] = Turtle(0, 0.00, 0, 0.00, 0.00);
            }

            delete[] allAnimal;
        }

            // A boom in zoo attendance occurs
        else if (event == 2) {
            //another random need to set the bonus

            std::uniform_int_distribution<int> dist3(250, 500);
            bonus = dist3(mt);
            std::cout << "Your today bonus is " << bonus * numOfTi << std::endl;
            bonus = (bonus * numOfTi); //bonus * number of tiger
        }

            //This event gives babies to the animal
        else //event ==3
        {
            int pickType;

            std::uniform_int_distribution<int> dist5(1, 3);
            pickType = dist5(mt);

            std::cout<<"Now Today's event is baby and the animal number is: "<<pickType<<std::endl;

            bool adult = false;
            //This time tiger is the one who will have a baby.
            if (pickType == 1) {

                std::cout<<"Your tiger is gonna have a baby!"<<std::endl;
                int pickTiger=0;
                int numOfATig = 0;
                int chosenTig=0;

                for (int i = 0; i < numOfTi; i++) {
                    if (arrayOfTi[i].getAge() >= 3) {
                        adult = true;
                        numOfATig += 1;
                    }
                }
                int adultTig[numOfATig];

                for (int i = 0; i < numOfTi; i++) {
                    if (arrayOfTi[i].getAge() >= 3) {
                        adultTig[i];
                    }
                }

                if (adult) {
                    std::cout<<"You have adult Penguin"<<std::endl;
                    std::uniform_int_distribution<int> dist6(0, numOfATig - 1);
                    pickTiger = dist6(mt);
                    chosenTig = adultTig[pickTiger];
                    //Updates the baby record to the tiger who has a baby
                    arrayOfTi[chosenTig].setNumOfBabies(arrayOfTi[chosenTig].getNumOfBabies() + 1);
                    numOfTi += 1;
                    //Resize the array in case the number of tiger is going to be bigger that the size.
                    if (numOfTi >= roomForTi) {
                        Tiger *temp_ti = new Tiger[roomForTi * 2];

                        for (int i = 0; i < roomForTi * 2; i++) {
                            temp_ti[i] = Tiger(0, 0.00, 0, 0.00, 0.00);
                        }

                        for (int i = 0; i < roomForTi; i++) {
                            temp_ti[i] = arrayOfTi[i];
                        }
                        roomForTi *= 2;
                        delete[] arrayOfTi;
                        arrayOfTi = temp_ti;
                    }
                    //Add the baby at the end of the array.
                    arrayOfTi[numOfTi - 1] = Tiger(0, tigCost, 0, tiger.getBaseFoodCost(), tiger.getPayoff());
                } else //There is no adult
                {
                    std::cout<<"I'm sorry you don't have adult Tiger. Let's check the Penguin!"<<std::endl;
                    pickType = 2;
                }
            }
                //When penguin will have 5 babies.
            else if (pickType == 2) {

                std::cout<<"Your Penguin is gonna have a baby!"<<std::endl;
                int pickPenguin=0;
                int numOfAPen = 0;
                int chosenPen=0;

                for (int i = 0; i < numOfPe; i++) {
                    if (arrayOfPe[i].getAge() >= 3) {
                        adult = true;
                        numOfAPen += 1;
                    }
                }
                int adultPen[numOfAPen];

                for (int i = 0; i < numOfTi; i++) {
                    if (arrayOfPe[i].getAge() >= 3) {
                        adultPen[i];
                    }
                }

                if (adult) {
                    std::cout<<"You have adult Penguin"<<std::endl;
                    std::uniform_int_distribution<int> dist7(0, numOfAPen - 1);
                    pickPenguin = dist7(mt);
                    chosenPen = adultPen[pickPenguin];

                    //Updates the baby record to the penguin who has 5 babies
                    arrayOfPe[chosenPen].setNumOfBabies(arrayOfPe[chosenPen].getNumOfBabies() + 1);
                    numOfPe += 5;
                    //Resize the array in case the number of tiger is going to be bigger that the size.

                    if (numOfPe >= roomForPe) {
                        Penguin *temp_pe = new Penguin[roomForPe * 2];

                        for (int i = 0; i < roomForPe * 2; i++) {
                            temp_pe[i] = Penguin(0, 0.00, 0, 0.00, 0.00);
                        }

                        for (int i = 0; i < roomForPe; i++) {
                            temp_pe[i] = arrayOfPe[i];
                        }
                        roomForPe *= 2;
                        delete[] arrayOfPe;
                        arrayOfPe = temp_pe;
                    }
                    //Adds the penguin babies to the end of the array of Penguin.
                    for (int i = 0; i < 5; i++) {
                        arrayOfPe[numOfPe - 5 + i] = Penguin(0, penCost, 0, penguin.getBaseFoodCost(),
                                                             penguin.getPayoff());
                    }
                } else //There is no adult
                {
                    std::cout<<"I'm sorry you don't have adult Penguin. Let's check the Turtle!"<<std::endl;
                    pickType = 3;
                }
            }
            else //pickType ==3
            {
                std::cout<<"Your Turtle is gonna have babies!"<<std::endl;
                int pickTurtle=0;
                int numOfATur = 0;
                int chosenTur=0;

                for (int i = 0; i < numOfTu; i++) {
                    if (arrayOfTur[i].getAge() >= 3) {
                        adult = true;
                        numOfATur += 1;
                    }
                }
                int adultTur[numOfATur];

                for (int i = 0; i < numOfTu; i++) {
                    if (arrayOfTur[i].getAge() >= 3) {
                        adultTur[i];
                    }
                }

                if (adult) {
                    std::cout<<"You have adult turtle"<<std::endl;
                    std::uniform_int_distribution<int> dist8(0, numOfATur - 1);
                    pickTurtle = dist8(mt);
                    chosenTur = adultTur[pickTurtle];

                    //Updates the baby record to the Turtle who has 10 babies
                    arrayOfTur[chosenTur].setNumOfBabies(arrayOfPe[chosenTur].getNumOfBabies() + 1);
                    numOfPe += 10;
                    if (numOfTu >= roomForTu) {
                        Turtle *temp_tu = new Turtle[roomForTu * 2];

                        for (int i = 0; i < roomForTu * 2; i++) {
                            temp_tu[i] = Turtle(0, 0.00, 0, 0.00, 0.00);
                        }

                        for (int i = 0; i < roomForTu; i++) {
                            temp_tu[i] = arrayOfTur[i];
                        }
                        roomForTu *= 2;
                        delete[] arrayOfTur;
                        arrayOfTur = temp_tu;
                    }
                    //Adds the babies to the array of Turtle.
                    for (int i = 0; i < 10; i++) {
                        arrayOfTur[numOfTu - 10 + i] = Turtle(0, turCost, 0, turtle.getBaseFoodCost(),
                                                              turtle.getPayoff());
                    }
                } else {
                    std::cout << "I'm sorry, but there is no adult animal here. Maybe next time!" << std::endl;
                }
            }
        }
            double todayAIncome =
                    numOfTi * tiger.getPayoff() + numOfPe * penguin.getPayoff() + numOfTu * turtle.getPayoff();
            account = account + bonus + todayAIncome - costPerDay;

            std::cout << "Now it's the time to check your balance." << std::endl;
            std::cout << "Today's Tiger payoff " << numOfTi * tiger.getPayoff() << std::endl;
            std::cout << "The Penguin's payoff " << numOfPe * penguin.getPayoff() << std::endl;
            std::cout << "The Turtle's payoff " << numOfTu * turtle.getPayoff() << std::endl;
            std::cout << "So, Your total admission fee income is " << todayAIncome << std::endl;
            std::cout << "And, today's your bonus income is " << bonus << std::endl;
            std::cout << "Now your balance is " << account << std::endl;


            double buyNewOne;
            int buyNew;

            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            std::cout << "Pretty busy day, right? Now you can buy an adult animal." << std::endl;
            std::cout << "Currently, you have " << numOfTi << " Tigers, " << numOfPe << " Penguins, " << numOfTu
                      << " Turtles" << std::endl;
            std::cout << "If you want to buy, input 1, otherwise (it you don't want to buy), click 2: ";
            std::cin >> buyNewOne;
            buyNew = inputVal(buyNewOne);

            if (!(buyNew == 1 || buyNew == 2)) {

                do {
                    std::cin.clear();
                    std::cin.ignore(INT_MAX, '\n');
                    std::cout << "Wrong input. You can only input 1 or 2, Please try again: ";
                    std::cin >> buyNewOne;
                    buyNew = inputVal(buyNewOne);
                } while (!(buyNew == 1 || buyNew == 2));
            }

            if (buyNew == 1) {

                double buyChoice;
                int buyOneMore;
                std::cout
                        << "So, you want to buy. Good! which animal will you buy; input 1 for Tiger, 2 for Penguin, and 3 for Turtle: ";
                std::cin >> buyChoice;
                buyOneMore = inputVal(buyChoice);

                if (!(buyOneMore == 1 || buyOneMore == 2 || buyOneMore == 3)) {

                    do {
                        std::cin.clear();
                        std::cin.ignore(INT_MAX, '\n');
                        std::cout << "Wrong input. You should input 1,2,or 3. Please try again: ";
                        std::cin >> buyChoice;
                        buyOneMore = inputVal(buyChoice);

                    } while (!(buyOneMore == 1 || buyOneMore == 2 || buyOneMore == 3));
                }

                if (buyOneMore == 1) {

                    std::cout << "So, you decided to buy a Tiger. Best Choice!" << std::endl;

                    numOfTi += 1;
                    if (numOfTi >= roomForTi) {
                        Tiger *temp_ti = new Tiger[roomForTi * 2];

                        for (int i = 0; i < roomForTi * 2; i++) {
                            temp_ti[i] = Tiger(0, 0.00, 0, 0.00, 0.00);
                        }

                        for (int i = 0; i < roomForTi; i++) {
                            temp_ti[i] = arrayOfTi[i];
                        }
                        delete[] arrayOfTi;
                        //arrayOfTi[0] = Tiger(0, 0.00, 0, 0.00, 0.00);
                        arrayOfTi = temp_ti;
                        //temp_ti[0] = Tiger(0, 0.00, 0, 0.00, 0.00);
                        roomForTi *= 2;
                    }
                    arrayOfTi[numOfTi - 1] = Tiger(3, tigCost, 0, tiger.getBaseFoodCost(), tiger.getPayoff());
                    account -= tigCost;
                    std::cout << "After you buy the tiger, your balance is " << account << std::endl;
                } else if (buyOneMore == 2) {

                    std::cout << "So, you decided to buy a Penguin. Fantastic Choice!" << std::endl;
                    numOfPe += 1;
                    if (numOfPe >= roomForPe) {
                        Penguin *temp_pe = new Penguin[roomForPe * 2];

                        for (int i = 0; i < roomForPe * 2; i++) {
                            temp_pe[i] = Penguin(0, 0.00, 0, 0.00, 0.00);
                        }

                        for (int i = 0; i < roomForPe; i++) {
                            temp_pe[i] = arrayOfPe[i];
                        }
                        roomForPe *= 2;
                        delete[] arrayOfPe;
                        arrayOfPe = temp_pe;

                    }
                    arrayOfPe[numOfPe - 1] = Penguin(3, penCost, 0, penguin.getBaseFoodCost(), penguin.getPayoff());
                    account -= penCost;
                    std::cout << "After you buy the penguin, your balance is " << account << std::endl;

                } else // (buyOneMore == 3)
                {
                    std::cout << "So, you decided to buy a Turtle. Beautiful Choice!" << std::endl;

                    numOfTu += 1;
                    if (numOfTu >= roomForTu) {
                        Turtle *temp_tu = new Turtle[roomForTu * 2];

                        for (int i = 0; i < roomForTu * 2; i++) {
                            temp_tu[i] = Turtle(0, 0.00, 0, 0.00, 0.00);
                        }

                        for (int i = 0; i < roomForTu; i++) {
                            temp_tu[i] = arrayOfTur[i];
                        }
                        roomForTu *= 2;
                        delete[] arrayOfTur;
                        arrayOfTur = temp_tu;
                    }

                    arrayOfTur[numOfTu - 1] = Turtle(3, turCost, 0, turtle.getBaseFoodCost(), turtle.getPayoff());
                    account -= turCost;
                    std::cout << "After you buy the turtle, your balance is " << account << std::endl;
                }

                std::cout << "After the purchase now you have " << numOfTi << " Tigers, " << numOfPe << " Penguins, "
                          << numOfTu << " Turtles" << std::endl;
            }

            else if (buyNew == 2) {
                std::cout << "so you don't want to buy more. That's fine." << std::endl;
            }

            std::cout << "The Tiger is: " << std::endl;
            for (int i = 0; i < roomForTi; i++) {
                std::cout << "number " << i + 1 << " : " << arrayOfTi[i].getAge() << ", " << arrayOfTi[i].getCost()
                          << std::endl;
            }

            std::cout << "The Penguin is: " << std::endl;
            for (int i = 0; i < roomForPe; i++) {
                std::cout << "number " << i + 1 << " : " << arrayOfPe[i].getAge() << ", " << arrayOfPe[i].getCost()
                          << std::endl;
            }
            std::cout << "The Turtle is: " << std::endl;
            for (int i = 0; i < roomForTu; i++) {
                std::cout << "number " << i + 1 << " : " << arrayOfTur[i].getAge() << " , " << arrayOfTur[i].getCost()
                          << std::endl;
            }

            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            std::cout << "If you want to play again, input 1. Otherwise, click any keys! ";
            std::cin >> playAgain;
            std::cout << std::endl;

        }while (playAgain == 1 && account > 0);

        if (account < 0) {
            std::cout << "I'm sorry, but your account is empty. Play next time. Good buy!" << std::endl;
        }
        delete[] arrayOfTi;
        delete[] arrayOfPe;
        delete[] arrayOfTur;

        if (playAgain != 1) {

            std::cout << "You want to stop. Good bye! See you again!" << std::endl;
        }

}

