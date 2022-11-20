// Copyright (c) 2022 Van Nguyen All rights reserved.
//
// Created by: Van Nguyen
// Created on: November 10, 2022
// This program asks the user how many numbers they plan on finding
// the greatest common factor of.
// This program will then ask the user if they want to run the program again


#include <iostream>
#include <list>
#include <algorithm>


// This function finds the greatest common factor from a list of numbers
int findGreatestFactor(std::list<int> numbers, int highestNum) {
    // Declared Common Factors list
    std::list<int> commonFactors;

    // Declared Variable
    bool inList;

    // Referenced: https://riptutorial.com/cplusplus/example/17316/auto--const--and-references
    // Learned how to iterate through lists with auto
    // Iterates through the list of numbers
    for (auto index : numbers) {
        // Finds every factor of the index
        for (int counter = 1; counter <= highestNum; counter++) {
            // Checks if index is evenly divisible by counter
            // (checks if counter is a factor of the index)
            if (index % counter == 0) {
                // Used: https://www.geeksforgeeks.org/list-cpp-stl/
                // To find how to use different list functions in C++
                // Adds the number to commonFactors list
                commonFactors.push_back(counter);
            }
        }
    }

    // Referenced: https://riptutorial.com/cplusplus/example/17316/auto--const--and-references
    // Learned how to iterate through lists with auto
    // Iterates through the list of numbers
    for (auto index : numbers) {
        // Iterates through every possible number that could be the factor
        for (int counter = 1; counter <= highestNum; counter++) {
            // Used code from (cpplint found that the link was too long):
            // https://stackoverflow.com/
            // questions/24139428/check-if-element-is-in-the-list-contains
            // Also consulted: https://cplusplus.com/reference/algorithm/find/
            // To learn about find()
            // Boolean value for if counter is inside of the commonFactors list
            inList = (std::find(commonFactors.begin(), commonFactors.end(),
                                    counter) != commonFactors.end());

            // IF there is a factor that an index does not have,
            // inside of commonFactors list
            if (index % counter != 0 && inList == true) {
                // Used: https://www.geeksforgeeks.org/list-cpp-stl/
                // To find how to use different list functions in C++
                // Removes all appearances of the incorrect factor
                commonFactors.remove(counter);
            }
        }
    }

    // Used: https://www.geeksforgeeks.org/list-cpp-stl/
    // To find how to use different list functions in C++
    // Sorts commonFactors list from lowest to highest
    commonFactors.sort();

    // Used: https://www.geeksforgeeks.org/list-cpp-stl/
    // To find how to use different list functions in C++
    // Stores highest common factor (Variable)
    int highestCommonFactor = commonFactors.back();

    // Returns the greatest common factor
    return highestCommonFactor;
}

int main() {
    // Initialize Variable
    std::string runAgain = "y";

    // Declared Variables
    int totalNumbers, userNumber, highestInput, counter;
    std::string totalNumbersString, userNumberString;
    float totalNumbersFloat, userNumberFloat;

    // Do-while loop to run the program once and then run the program again
    // (if the user wants to)
    do {
        // Initialize Variable
        counter = 0;

        // List meant to hold all the numbers the user wants to find the GCF of
        std::list<int> allNumbers;

        try {
            // Asks user for how many numbers they plan on finding GCF of,
            // (total numbers)
            std::cout << "How many numbers do you plan to find the "
                        << "greatest common factor of: ";
            std::cin >> totalNumbersString;

            // Converts totalNumbers to integer
            totalNumbers = stoi(totalNumbersString);

            // Converts totalNumbers to float
            totalNumbersFloat = stof(totalNumbersString);

            // Checks if totalNumbers is negative or contains decimals
            if (totalNumbers <= 0 || totalNumbers != totalNumbersFloat) {
                std::cout << "Please enter a positive integer for the"
                << " total numbers!\n" << std::endl;

                // Returns to beginning of loop
                continue;
            }

            // Asks the user for all the numbers they want to find the
            // shared GCF of and add it to the allNumbers list
            while (counter < totalNumbers) {
                try {
                    // Asks user for the number that want to include
                    // when finding the GCF
                    std::cout << "Enter a number: ";
                    std::cin >> userNumberString;

                    // Converts user number to integer
                    userNumber = stoi(userNumberString);

                    // Converts user number to float
                    userNumberFloat = stof(userNumberString);

                    // If the user number is not positive or contains decimals
                    if (userNumber <= 0 || userNumber != userNumberFloat) {
                        std::cout << "Please enter a positive integer!\n"
                        << std::endl;

                        // Returns to the innermost loop
                        continue;

                    // IF the number that the user entered is valid
                    } else {
                        // Adds user's number to the allNumbers list
                        allNumbers.push_back(userNumber);

                        // Increments counter
                        counter++;
                    }

                // In the event of an exception
                } catch (std::invalid_argument) {
                    std::cout << "You must always enter a positive number!\n"
                    << std::endl;
                }
            }

            // Used: https://www.geeksforgeeks.org/list-cpp-stl/
            // To find how to use different list functions in C++
            // Sorts allNumbers list from lowest to highest
            allNumbers.sort();

            // Used: https://www.geeksforgeeks.org/list-cpp-stl/
            // To find how to use different list functions in C++
            // Stores highest number in allNumbers list (for function call)
            highestInput = allNumbers.back();

            // Displays the greatest common factor of
            // the user's number(s) to the console
            std::cout << "The greatest common factor of your numbers is "
            << findGreatestFactor(allNumbers, highestInput) << std::endl;

            // Continues to ask user if they want to run the program again
            // (until valid input)
            do {
                std::cout << "Do you want to run the program again?";

                // Asks user if they want to run the program again
                std::cout << " (Enter 'y' to run again or "
                            << "'n' to end the program): ";
                std::cin >> runAgain;

                // Referenced https://cplusplus.com/reference/algorithm/transform/
                // Learned from transform() works in C++
                // Converts user input into lowercase
                std::transform(runAgain.begin(), runAgain.end(),
                                runAgain.begin(), ::tolower);

            // Ensures that the user inputs either 'n' or 'y'
            // (not case sensitive)
            } while (runAgain != "n" && runAgain != "y");

        // In the event of an exception
        } catch (std::invalid_argument) {
            std::cout << "You must always input a positive number!\n"
            << std::endl;
        }

    // Will re-run the program
    // unless the user indicates that the program should end
    } while (runAgain != "n");
}
