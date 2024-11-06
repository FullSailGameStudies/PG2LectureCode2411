// Day05.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <iomanip>

enum class Weapon
{
    Sword, Axe, Spear, Mace
};


int LinearSearch(const std::vector<int>& searchItems, int searchNumber)
{
    int index = -1;//-1 indicates not found
    for (int i = 0; i < searchItems.size(); i++)
    {
        if (searchNumber == searchItems[i])
        {
            index = i;
            break;
        }
    }
    return index;
}

void ShowGradesIterator(const std::map<std::string, double>& course)
{
    std::cout << "\nIterator loop\nPG2 2411 Grades\n";
    for (auto i = course.begin(); i != course.end(); i++)
    {
        std::cout << std::setw(7) << std::right << i->second << " ";
        std::cout << std::left << i->first << "\n";
    }
}
void ShowGradesRangeBased(const std::map<std::string, double>& course)
{

    std::cout << "\nRange-based loop\nPG2 2411 Grades\n";
    for (auto& [name,grade] : course)
    {
        std::cout << std::setw(7) << std::right << grade << " ";
        std::cout << std::left << name << "\n";
    }
}

void PrintPrice(std::map<std::string, float>& menu, const std::string& itemToFind)
{
    auto foundIterator = menu.find(itemToFind);
    if (foundIterator == menu.end())
        std::cout << itemToFind << " is not on the menu.\n";
    else
    {
        float oldPrice = foundIterator->second;
        foundIterator->second *= 1.05F;//5% increase
        std::cout << itemToFind << " used to costs " << oldPrice << ".\n";
        std::cout << "Now it costs " << foundIterator->second << "!! Thanks Putin!\n";
    }

}
int main()
{
    srand(time(NULL));
    /*
        ╔═════════╗
        ║Searching║
        ╚═════════╝

        There are 2 ways to search a vector: linear search or binary search

        CHALLENGE:

            write a method to linear search the numbers list.
                The method should take 2 parameters: vector of ints to search, int to search for.
                The method should return -1 if NOT found or the index if found.

            The algorithm:
                1) start at the beginning of the vector
                2) compare each item in the vector to the search item
                3) if found, return the index
                4) if reach the end of the vector, return -1 which means not found

    */
    std::vector<int> numbers = { 0,1,2,3,4,5,6 };
    int searchNumber = 15;
    int foundIndex;
    foundIndex = LinearSearch(numbers, searchNumber);
    if (foundIndex == -1) std::cout << searchNumber << " was not found.\n";
    else std::cout << searchNumber << " was found at index " << foundIndex << "\n";

    searchNumber = 0;
    foundIndex = LinearSearch(numbers, searchNumber);
    if (foundIndex == -1) std::cout << searchNumber << " was not found.\n";
    else std::cout << searchNumber << " was found at index " << foundIndex << "\n";

    searchNumber = 6;
    foundIndex = LinearSearch(numbers, searchNumber);
    if (foundIndex == -1) std::cout << searchNumber << " was not found.\n";
    else std::cout << searchNumber << " was found at index " << foundIndex << "\n";



    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Creating a map  ]

        map<TKey, TValue>  - an associative collection.
            TKey is a placeholder for the type of the keys.
            TValue is a placeholder for the type of the values.

        When you want to create a map variable,
            1) replace TKey with whatever type of data you want to use for the keys
            2) replace TValue with the type you want to use for the values


        [  Adding items to a map  ]

        There are 2 ways to add items to a map:
        1) using the insert method.
        2) using [key] = value
    */

    std::map<std::string,float> menu;
    menu["Spaghetti"] = 9.99F;
    menu["Cheese Pizza"] = 12.99f;
    menu["Lobster Risotto"] = 18.99f;
    menu["Lobster Risotto"] = 28.99f;//overwrites
    menu["Chicken Parmesan"] = 24.99f;

    //insert needs a std::pair object
    //  std::pair<tFirst, tSecond>
    //  use pair.first and pair.second to access the items
    std::pair< std::string, float> pair =
        std::make_pair("Garlic Bread", 8.99F);
    menu.insert(pair);
    pair = std::make_pair("Garlic Bread", 10.99F);
    std::pair<std::map<std::string, float>::iterator,bool> result =
        menu.insert(pair);//??will NOT overwrite
    if (result.second)//== true. meaning, was inserted
        std::cout << pair.first << " was inserted.\n";
    else
        std::cout << pair.first << " was already on the menu.\n";


    std::string itemToFind = "Dino Nuggies";
    PrintPrice(menu, itemToFind);

    itemToFind = "Garlic Bread";
    PrintPrice(menu, itemToFind);




    std::map<Weapon, int> dorasBackpack;//will store the counts of each kind of weapon

    //returns an iterator and a bool. 
    //if the key is already in the map, it will NOT insert it -- the bool will be false.
    auto inserted = dorasBackpack.insert(std::make_pair(Weapon::Sword, 5));
    if (inserted.second == false) //meaning not inserted
        std::cout << "The key was already in the map. It was not inserted.\n";
    else
        std::cout << "The key was inserted in the map.\n";

    dorasBackpack[Weapon::Axe] = 3;
    dorasBackpack[Weapon::Axe] = 7;//simply overwrites the value if the key is already in the map


    /*
        CHALLENGE:

            Create a map that stores names (string) and grades. 
            Call the variable grades.
            Add students and grades to your map.

    */




    std::vector<std::string> students = {"Ethan",
    "Maura", "Jacob", "Yoga", "Michael", "Erick",
    "JJ", "Donald", "Jeffrey", "Stefano", "Zacary", "Zane", "Christa"};

    std::map<std::string, double> grades;
    for (auto& name : students)
    {
        //grades[name] = rand() % 10001 / 100.0;
        auto studentpair = std::make_pair(name, rand() % 10001 / 100.0);
        auto inserted = grades.insert(studentpair);
        if (!inserted.second)
            std::cout << name << " was already in the course. Not inserted.\n";
    }
    ShowGradesIterator(grades);
    ShowGradesRangeBased(grades);


    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Looping over a map  ]

        You should use a ranged-based for loop when needing to loop over the entire map.

    */
    for (auto const& [key, val] : dorasBackpack) //requires C++ 20
    {
        switch (key)
        {
        case Weapon::Sword:
            std::cout << "Sword: ";
            break;
        case Weapon::Axe:
            std::cout << "Axe: ";
            break;
        case Weapon::Spear:
            std::cout << "Spear: ";
            break;
        case Weapon::Mace:
            std::cout << "Mace: ";
            break;
        default:
            break;
        }
        std::cout << val << "\n";
    }


    /*
        CHALLENGE:

            Loop over your grades map and print each student name and grade.

    */



    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Checking for a key in a map  ]

        use the find method to check if the key is in the map

        will return map.end() if NOT found.

    */
    std::map<Weapon, int>::iterator foundIter = dorasBackpack.find(Weapon::Mace);
    if (foundIter == dorasBackpack.end()) //meaning it was NOT found
    {
        std::cout << "Dora did not find any maces.\n";
    }
    else
    {
        //can safely grab the value for the key
        std::cout << "Dora found " << foundIter->second << " Maces\n";
    }



    /*
        CHALLENGE:

            look for a specific student in the map.
            If the student is found, print out the student's grade
            else print out a message that the student was not found


            Pick any student and curve the grade (add 5) that is stored in the grades map

        EXTRA CHALLENGE: 
            put it in a loop so you can update multiple students
    */
    do
    {
        ShowGradesRangeBased(grades);
        std::string studentToFind;
        std::cout << "\nName of student: ";
        std::getline(std::cin, studentToFind);
        if (studentToFind.empty()) break;

        auto studentIter = grades.find(studentToFind);
        if (studentIter == grades.end())
            std::cout << studentToFind << " is not in the course.\n";
        else
        {
            studentIter->second = std::min(100.0, studentIter->second + 5.0);
        }
    } while (true);




    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Updating a value for a key in a map  ]

        To update an exisiting value in the map, use the [ ]


    */
    dorasBackpack[Weapon::Axe] = 1;//updates the count for the axe



}