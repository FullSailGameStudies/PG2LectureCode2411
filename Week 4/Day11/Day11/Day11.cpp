﻿// Day11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Car.h"
#include <vector>
#include <fstream>

int main()
{
    std::cout << "Gone in 60 Seconds!\n";//https://carbuzz.com/features/beyond-eleanor-gone-in-60-seconds-car-names#:~:text=The%20Complete%20List%20Of%20Gone%20In%2060%20Seconds,8%201961%20Porsche%20Speedster%20-%20%22Natalie%22%20More%20items

    Car myRide(1967, "Ford", "Shelby Mustang GT500");
    std::string path = "garage.csv";
    std::ofstream outFile(path);
    char delimiter = '$';

    std::vector<Car> garage;
    garage.push_back(Car(1967, "Ford", "Shelby Mustang GT500"));
    garage.push_back(Car(1956, "Ford", "T Bird"));
    garage.push_back(Car(1961, "Porsche", "Speedster"));
    garage.push_back(Car(1965, "Pontiac", "GTO"));
    garage.push_back(Car(1969, "Plymouth", "Hemi Cuda"));

    if (outFile.is_open())
    {
        //write out the object
        for (auto& car : garage)
        {
            car.Serialize(outFile, delimiter);
            outFile << "\n";
        }
        //myRide.Serialize(outFile, delimiter);
    }
    else {
        std::cout << path << " could not be opened.\n";
    }
    outFile.close();


    /*
        ╔═════════════╗
        ║ Serializing ║
        ╚═════════════╝

        Saving the state (data) of objects

        Lecture Code: serialize the vector of Cars to a file.
            Data Format:
                separates cars. EX: car1|car2|car3
                separates data inside a car. EX: 1967;Ford;Shelby Mustang GT500

    */



    /*
        ╔═══════════════╗
        ║ Deserializing ║
        ╚═══════════════╝

        Recreating the objects from the saved state (data) of objects

        Lecture Code:
            Open the file
            Read in each line
            split each line to get each car
            split each car to get the car details

    */
    std::ifstream inFile(path);
    std::vector<Car> newGarage;
    if (inFile.is_open())
    {
        while (!inFile.eof())
        {
            std::string line;
            std::getline(inFile, line);

            if (!line.empty())
            {
                Car nextCar(line, delimiter);
                newGarage.push_back(nextCar);
            }

        }
    }
    else
    {
        std::cout << path << " could not be opened.\n";
    }
    inFile.close();

    std::cout << "\n\nMy Garage\n";
    for (auto& car : newGarage)
    {
        car.Serialize(std::cout, ' ');
        std::cout << "\n";
        //std::cout << car.ModelYear() << " " << car.Make() << " " << car.Model() << "\n";
    }
}