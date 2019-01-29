/****************************************************************************************************
 * * Program name: CS162 Project2
 * * Author: Taekyoung Kim
 * * Date: 01/21/2019
 * * Description: This is Zoo.cpp file for CS162 Project2
 * * This project shows a zoo that has a few animals. We needs inheritance and class......
 ******************************************************************************************************/


#include "DArray.h"
#include "Zoo.h"
#include "Animal.h"
#include "Penguin.h"
#include "Turtle.h"
#include "Tiger.h"
#include <iostream>
#include <random>
#include <climits>
//#include <iterator>


DArray::DArray() =default;
DArray::~DArray()=default;

int DArray::getRoomOfTi(){
    return roomOfTi;

}
void DArray::setRoomOfTi(int ti){
    roomOfTi = ti;

}
int DArray::getRoomOfPe(){
    return roomOfPe;
}
void DArray::setRoomOfPe(int pe){
    roomOfPe = pe;

}
int DArray::getRoomOfTu(){
    return roomOfTu;

}
void DArray::setRoomOfTu(int tu){
    roomOfTu = tu;

}

void DArray::arrayTiger(Tiger *arr, int roomOfTi) {

    Tiger *temp_ti = new Tiger[roomOfTi * 2];

    for (int i = 0; i < roomOfTi; i++) {
        temp_ti[i] = arr[i];
    }
    //delete[] arr;

    for (int i = 0; i < roomOfTi * 2; i++) {
        arr[i] = temp_ti[i];
    }
   delete [] temp_ti;

    setRoomOfTi(roomOfTi * 2);
}

void DArray::arrayPen(Penguin *arra, int roomOfPe){

    int newSize = roomOfPe*2;
    Penguin *temp_pe = new Penguin[newSize];

    //std::copy(arra, arra + std::min(roomOfPe, roomOfPe*2), temp_pe);
    //std::copy(std::begin(arra), std::end(arra), std::begin(temp_pe));


    for (int i = 0; i < roomOfPe; i++) {
        temp_pe[i] = arra[i];
    }

    //delete [] arra;

    for (int i =0; i<roomOfPe*2; i++){
        arra[i] = temp_pe[i];
    }

    delete [] temp_pe;
    setRoomOfPe(roomOfPe*2);
}

void DArray::arrayTur(Turtle *array, int roomOfTu){

    Turtle *temp_tu = new Turtle[roomOfTu * 2];

    for (int i = 0; i < roomOfTu; i++) {
        temp_tu[i] = array[i];
    }

    //delete [] array;

    for (int i =0; i<roomOfTu*2; i++){
        array[i] = temp_tu[i];
    }

    delete [] temp_tu;

    setRoomOfTu(roomOfTu*2);
}

void DArray::pickRemove(int &ti, int &pe, int &tu, Tiger *arr, Penguin *arra, Turtle *array) {

    int numOfAni = ti + pe + tu;

    std::cout <<"You have  "<< ti << " tiger/s "<<pe<< " penguin/s  "<<tu<< " Turtle/s"<< std::endl;

    int whoSick;

    //int *allAnimal = new int[numOfAni];
    int allAnimal[numOfAni];

    for (int i = 0; i < ti; i++) {

        allAnimal[i] = i;
    }
    for (int i = ti; i < ti + pe; i++) {

        allAnimal[i] = i;
    }
    for (int i = ti + pe; i < numOfAni; i++) {

        allAnimal[i] = i;
    }

    if (numOfAni <= 0) {
        std::cout<<"I don't know if this is good, but you don't have any animals. So no animal dies today."<<std::endl;
    }

    else { //numOfAnimal>0

        std::random_device ran;
        std::mt19937 mt(ran());
        std::uniform_int_distribution<int> dist2(1, numOfAni);
        whoSick = dist2(mt) - 1;

        std::cout << "Who sick? number is: " << whoSick + 1 << std::endl;

        // A Tiger gets sick and remove
        if (whoSick < ti) {

            std::cout << "Your Tiger number " << whoSick + 1 << " got sick and died. So sorry!" << std::endl;
            ti -= 1;

            Tiger temp;

            for (int j = whoSick; j < roomOfTi; j++) {

                arr[j] = arr[j + 1];
            }

            arr[roomOfTi - 1] = Tiger(0, 0.00, 0, 0.00, 0.00);

        }
            //A Penguin get sick and remove
        else if (whoSick >= ti && whoSick < ti + pe) {

            pe -= 1;
            int sickP = whoSick - ti;

            std::cout << "Your Penguin number " << sickP + 1 << " got sick and died. So sorry" << std::endl;

            for (int j = sickP; j < roomOfPe; j++) {

                arra[j] = arra[j + 1];
            }
            arra[roomOfPe - 1] = Penguin(0, 0.00, 0, 0.00, 0.00);

        }

            //A turtle get sick and remove
        else // whoSick >= numOfTi+numOfPe && whoSick < numOfAni
        {
            tu -= 1;

            int sickTu = whoSick - (ti + pe);
            std::cout << "Your Turtle number " << sickTu + 1 << " got sick and died. So sorry" << std::endl;


            for (int j = sickTu; j < roomOfTu; j++) {

                array[j] = array[j + 1];
            }
            array[roomOfTu - 1] = Turtle(0, 0.00, 0, 0.00, 0.00);

        }

    }

}

void DArray::whoHasBaby(int &numTi, int &numPen, int &numTurt, Tiger *arr, Penguin *arra, Turtle *array){

    Zoo zoo;
    int draw;

    int numAdTi = 0;
    for (int i = 0; i < numTi; i++) {

        if (arr[i].getAge() >= 3) {
            numAdTi += 1;
        }
    }
    std::cout <<"Number of Adult Tigers: " << numAdTi << std::endl;

   // int *adultTiger = new int[numAdTi];
      int adultTiger [numAdTi];

    int j = 0;
    for (int i = 0; i < numTi; i++) {
        if (arr[i].getAge() >= 3) {
            adultTiger[j] = i;
            j++;
        }
    }

    int numAdPen = 0;
    for (int i = 0; i < numPen; i++) {
        if (arra[i].getAge() >= 3) {
            numAdPen += 1;
        }
    }
    std::cout <<"Number of Adult penguins: " << numAdPen << std::endl;

    //int *adultPenguin = new int[numAdPen];
      int adultPenguin[numAdPen];

    int k = 0;
    for (int i = 0; i < numPen; i++) {
        if (arra[i].getAge() >= 3) {
            adultPenguin[k] = i;
            k++;
        }
    }

    int numAdTur = 0;
    for (int i = 0; i < numTurt; i++) {
        if (array[i].getAge() >= 3) {
            numAdTur += 1;
        }

    }
    std::cout << "Number of Adult Turtle: " << numAdTur << std::endl;

    //int *adultTurtle = new int[numAdTur];
    int adultTurtle[numAdTur];

    int l = 0;
    for (int i = 0; i < numTurt; i++) {
        if (array[i].getAge() >= 3) {
            adultTurtle[l] = i;
            l++;
        }
    }

    int numAdAnimal = numAdTi + numAdPen + numAdTur;

    std::random_device ran1;
    std::mt19937 mt1(ran1());
    std::uniform_int_distribution<int> dist(1, numAdAnimal);
    draw = dist(mt1)-1;


    if (numAdAnimal <= 0) {
        std::cout << "Sorry. You don't have any adult animals. Maybe next time!" << std::endl;

    }

    else {
        //A Tiger has a baby.
        if (draw < numAdTi) {

            int chosenTi;
            chosenTi = adultTiger[draw];
            std::cout << "Your tiger number: "<<chosenTi+1<< " has a baby. Great, isn't it!" << std::endl;

            //Updates the baby record of the tiger who has a baby.
            std::cout<<"Add baby to the tiger: previous baby num: "<<arr[chosenTi].getNumOfBabies()<<std::endl;

            arr[chosenTi].setNumOfBabies(arr[chosenTi].getNumOfBabies() + 1);
            numTi +=1;

            std::cout<<"Add baby to the tiger: new baby num: "<<arr[chosenTi].getNumOfBabies()<<std::endl;

            if (numTi >= roomOfTi-1) {

                this->DArray::arrayTiger(arr, roomOfTi);

                std::cout<<"Room For Tiger after resizing "<< roomOfTi<<std::endl;

            }
            //Add the new baby to the array of Tiger.

            arr[numTi - 1] = Tiger(0, 10000.00, 0, zoo.baseCost*5, 10000.00*0.2);

        }

            //A penguin has 5 babies.
        else if (draw >= numAdTi && draw < numAdTi + numAdPen) {

            int chosenPen;
            chosenPen = adultPenguin[draw - numAdTi];
            std::cout << "Your penguin number "<<chosenPen+1<<"  has 5 babies. Fantastic!" << std::endl;

            //Updates the baby record of the Penguin who has babies.
            std::cout<<"Add baby to the Penguin: previous baby num: "<<arra[chosenPen].getNumOfBabies()<<std::endl;

            arra[chosenPen].setNumOfBabies(arra[chosenPen].getNumOfBabies() + 5);

            std::cout<<"Add baby to the Penguin: new baby num: "<<arra[chosenPen].getNumOfBabies()<<std::endl;

            numPen +=5;

            if (numPen >= roomOfPe-1) {

                arrayPen(arra, roomOfPe);
                //zoo.resizePen(arra, roomOfPe);
                std::cout<<"Room For penguin after resizing "<<roomOfPe<<std::endl;

            }

            //Penguin peng;
            //Adds the penguin babies to the array of Penguin.
            for (int i = 0; i < 5; i++) {
                arra[numPen - 5 + i] = Penguin(0, 1000.00, 0, zoo.baseCost, 1000.00*0.1);
            }

        }
            //A turtle has 10 babies.

        else
        {
            int chosenTurtle;
            chosenTurtle = adultTurtle[draw - numAdTi - numAdPen];
            std::cout << "Your Turtle number "<<chosenTurtle +1<<" has 10 babies.God blessed you!" << std::endl;

            std::cout<<"Add baby to the turtle: previous baby num: "<<array[chosenTurtle].getNumOfBabies()<<std::endl;

            //Updates the record of the Turtle who has babies.
            array[chosenTurtle].setNumOfBabies(array[chosenTurtle].getNumOfBabies() + 10);
            numTurt +=10;

            std::cout<<"Add baby to the turtle: New baby num: "<<array[chosenTurtle].getNumOfBabies()<<std::endl;

            if (numTurt >= roomOfTu-1) {

                arrayTur(array, roomOfTu);
                std::cout<<"Room For Turtle after resizing "<<roomOfTu<<std::endl;

            }
            //Adds the babies to the array of Turtle.
            for (int i = 0; i < 10; i++) {
                array[numTurt - 10 + i] = Turtle(0, 100.00, 0, zoo.baseCost, 100.00*0.05);
            }

        }

    }

}
