#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "Grid.h"


// prints a message showing the user how to use the arguments
// and what args are required or optional
void showUsage(char* argv[]) {
    std::cerr << "usage:\t" << argv[0] << " -input inFile [-output outFile]" << std::endl
              << "\t" << argv[0] << " -help" << std::endl;  
}

// finds all integers from the input file and prints them to the other output file
void inputAndOutput(std::string inputFile, std::string outputFile) {
    Grid grid;
    std::ifstream inFile(inputFile);
    std::ofstream outFile(outputFile);

    // checks if the files cannot be opened
    if (!inFile.is_open() || !outFile.is_open()) {
        std::cerr << "error: cannot open files" << std::endl;
        return;
    } else {
        inFile >> grid;

        outFile << "the input grid\n" << grid;

        grid.solve(outFile);

        outFile << "for a " << grid.dimension();
        outFile << " by " << grid.dimension() << " grid\n";
        outFile << "number of solutions = ";
        outFile << grid.numberOfSolutions() << "\n";
        outFile << "work assignments = " << grid.workAssigns();
        outFile << "\n";
        inFile.close();
        outFile.close();
    }

}


// finds all integers from file and prints to std out
void inputOnly(std::string inputFile, std::ostream& out) {
    Grid grid;
    std::ifstream inFile(inputFile);

    // checks if file cannot be opened
    if (!inFile.is_open()) {
        std::cerr << "error: cannot open file" << std::endl;
    } else {
        inFile >> grid;

        std::cout << "the input grid\n" << grid;

        grid.solve(out);

        std::cout << "for a " << grid.dimension();
        std::cout << " by " << grid.dimension() << " grid\n";
        std::cout << "number of solutions = ";
        std::cout << grid.numberOfSolutions() << std::endl;
        std::cout << "work assignments = " << grid.workAssigns();
        std::cout << std::endl;
        inFile.close();
    }
}


int main(int argc, char* argv[]) {

    // check if incorrect number of args was given
    if (argc <= 2 || argc == 4) {
        showUsage(argv);
        return 1;
    }

    // loop through all args to see if -help was inputted
    for (int i = 1; i < argc; i++) {
        if (std::string(argv[i]) == "-help") {
            showUsage(argv);
            return 1;
        }
    }

    // check if only -input was given or if both -input and -output were given
    if (argc == 3 && std::string(argv[1]) == "-input") {
        inputOnly(argv[2], std::cout);
    } else if ((argc == 5) && (std::string(argv[1]) == "-input") && (std::string(argv[3]) == "-output")) {
        inputAndOutput(argv[2], argv[4]);
    } else if ((argc == 5) && (std::string(argv[1]) == "-output") && (std::string(argv[3]) == "-input")) {
        inputAndOutput(argv[4], argv[2]);
    }
    return 0;
}
