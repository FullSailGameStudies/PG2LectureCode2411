// Day02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include "FullSailCourse.h"
#include "Console.h"

bool postFix(std::string& hero)
{
    srand((unsigned int)time(NULL));
    int postFixNumber = rand() % 1000;
    hero = hero + "-" + std::to_string(postFixNumber);
    return postFixNumber % 2 == 0;
}

float average(const std::vector<int>& scores)
{
    //scores.push_back(5); //not allowed because it is marked as const
    float sum = 0;
    for (auto score : scores)
        sum += score;

    return sum / scores.size();
}

void print(const std::vector<int>& scores)
{
    std::cout << "----SCORES----\n";
    int index = 1;
    for (int score : scores)
        std::cout << index++ << ". " << score << "\n";
}

void printInfo(const std::vector<int>& scores)
{
    std::cout << "size: " << scores.size() << "\tcapacity: " << scores.capacity() << "\n";
}

void RandomNums(int& r1, int& r2)
{
    r1 = rand();
    r2 = rand() % 1001;//% divides and returns the remainder
}

int sum(int& n1, int& n2)
{
    return n1 + n2;
}

int main()
{
    //sum(5, 2);
    int n1 = 0, n2 = 0;
    int& num1 = n1;
    num1++;
    std::cout << n1 << "\t" << num1 << "\n";
    std::cout << &n1 << "\n" << &num1 << "\n";
    std::cin.get();
    RandomNums(n1, n2);
    std::cout << n1 << "\t" << n2 << "\n";
    std::cin.get();
    /*
        ╔══════════════════════════════╗
        ║Parameters: Pass by Reference.║
        ╚══════════════════════════════╝
        Sends the variable itself to the method. The method parameter gives the variable a NEW name (i.e. an alias)

        NOTE: if the method assigns a new value to the parameter, the variable used when calling the method will change too.
            This is because the parameter is actually just a new name for the other variable.
    */
    std::string spider = "Spiderman";
    bool isEven = postFix(spider);
    std::string evenResult = (isEven) ? "TRUE" : "FALSE";
    std::cout << spider << "\n" << "Is Even postfix? " << evenResult << "\n";


    /*
        CHALLENGE 1:

            add a method to FullSailCourse
            The method should fill a vector of floats with grades.
            1) pass it in by reference
            2) add 10 grades to the vector
            3) call the method in main
            4) print the vector in main

    */
    std::vector<float> grades;
    FullSailCourse pg2;
    pg2.FillGrades(grades);
    pg2.ShowGrades(grades);
    std::cin.get();
    //add a method to FullSailCourse to show the grades



    /*
        ╔══════════════════╗
        ║ const parameters ║
        ╚══════════════════╝
        const is short for constant. It prevents the variable from being changed in the method.

        This is the way you pass by reference and prevent the method from changing the variable.
    */
    std::vector<int> highScores;
    highScores.reserve(10);
    printInfo(highScores);
    for (int i = 0; i < 12; ++i)
    {
        highScores.push_back(rand() % 5000);
        printInfo(highScores);
    }
    //std::cout << highScores[highScores.capacity() - 1];//???

    print(highScores);
    //erase all highscores < 2500
    for (size_t i = 0; i < highScores.size(); i++)
    {
        if (highScores[i] < 2500)
        {
            highScores.erase(highScores.begin() + i);
            i--;
        }
    }
    //OR...
    for (size_t i = 0; i < highScores.size();)
    {
        if (highScores[i] < 2500)
        {
            highScores.erase(highScores.begin() + i);
        }
        else
            i++;
    }
    //OR...
    for (int i = highScores.size() - 1; i >= 0; i--)
    {
        if (highScores[i] < 2500)
        {
            highScores.erase(highScores.begin() + i);
        }
    }
    //OR...
    for(auto i=highScores.begin();i!=highScores.end();)
    {
        if (*i < 2500)
        {
            i = highScores.erase(i);
        }
        else
            i++;
    }

    print(highScores);

    float avg = average(highScores);

    /*
        CHALLENGE 2:

            Add a method to FullSailCourse to calculate the stats on a vector of grades
            1) create a method to calculate the min, max. 
                pass the grades vector as a const reference. Use ref parameters for min and max.
            2) call the method in main and print out the min, max.

    */
    float minGrade, maxGrade;
    pg2.Stats(grades, minGrade, maxGrade);
    std::cout << "Min: ";
    Console::Write(std::to_string(minGrade), ((minGrade < 59.5) ? ConsoleColor::Red : ConsoleColor::Green));
    std::cout << "\tMax: ";
    //ternary operator
    Console::WriteLine(std::to_string(maxGrade), ((maxGrade < 59.5) ? ConsoleColor::Red : ConsoleColor::Green));
    std::cin.get();





    /*
        ╔═══════════╗
        ║ vector<T> ║
        ╚═══════════╝

        [  Removing from a vector  ]

        clear() - removes all elements from the vector
        erase(position) - removes the element at the position
        erase(starting position, ending position) - removes a range of elements. the end position is not erased.

    */
    print(highScores);
    //

    /*
        INTERMEDIATE LEVEL...
        a way using std::remove_if and a lambda
    highScores.erase(
        std::remove_if(highScores.begin(),
            highScores.end(),
            [](int score) { return score < 2500; }),
        highScores.end());
    */


    print(highScores);



    /*
        CHALLENGE 3:

            Using the vector of grades you created.
            Remove all the failing grades (grades < 59.5).
            Print the grades.
    */





    /*
        ╔═══════════╗
        ║ vector<T> ║
        ╚═══════════╝

        
        size(): # of items that have been ADDED
        capacity(): length of the internal array
        reserve(n): presizes the internal array
    */
    std::vector<int> scores;
    scores.reserve(10); //makes the internal array to hold 10 items.

    printInfo(scores);
}