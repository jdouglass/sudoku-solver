#include <iostream>
#include <fstream>  // for file input and output
#include <iomanip>  // std::setw
#include <cmath>
#include "Grid.h"

// width of a number
const int Grid::OUT_WIDTH = 2;
// output that the position is empty
const char Grid::OUT_BLANK = ' ';
// should be as long as WIDTH + 1
const std::string Grid::OUT_ROOF = "---"; 
// output a wall around the number
const char Grid::OUT_WALL = '|';
// corner of a number
const char Grid::OUT_CORNER = '+';

// at first, the dimensions are 0
Grid::Grid() : numSolns(0), numAssigns(0), n(0) {}

bool Grid::isEmpty() const {
    return n == 0;
}

int Grid::numberOfSolutions() const {
    return numSolns;
}

long Grid::workAssigns() const {
    return numAssigns;
}

int Grid::dimension() const {
    return n;
}

std::istream& operator >> (std::istream& in, Grid& G) { 
    // deallocates memory if there was an existing array in it
    if (!G.isEmpty()) {
        for (int i = 0; i < G.n; i++) {
            delete [] G.arr[i];
        }
        delete [] G.arr;
    }

    int row, col, i, j, x;
    in >> row >> col;
    if (row == col) {
        G.n = row;
        G.arr = new int*[G.n];
        for (int i = 0; i < G.n; i++) {
            G.arr[i] = new int [G.n];
            for (int j = 0; j < G.n; j++) {
                G.arr[i][j] = 0;
            }
        }
        while (in) {
            in >> i >> j >> x;
            G.arr[i-1][j-1] = x;
        }
    }
    return in;
}

// pretty printing
void Grid::printHorizontalLine(int n, std::ostream& out) {
   out << OUT_CORNER;
   for (int i = 0; i < n; i++)  {
      out << OUT_ROOF << OUT_CORNER;
   }
   out << std::endl;
}

// pretty printing
void Grid::printGrid(std::ostream& out) const {
   // print a top line
   printHorizontalLine(n, out);
   for (int i = 0; i < n; i++) {
      out << OUT_WALL;
      for (int j = 0; j < n; j++) {
         if (arr[i][j] == 0) {
            out << std::setw(Grid::OUT_WIDTH) << Grid::OUT_BLANK;
         }
         else {
            out << std::setw(Grid::OUT_WIDTH) << arr[i][j];
         }
         out << OUT_BLANK << OUT_WALL;
      } // for j
      out << std::endl;
      printHorizontalLine(n, out);
   } // for i
   out << std::endl;
}

std::ostream& operator << (std::ostream& out, const Grid& g) {
    g.printGrid(out);
    return out;
}

// checks to see the value can be placed in the cell
bool Grid::isLegal(int row, int col, int val) {
    // check the entire row
    for (int i = 0; i < n; i++) {
        if (arr[row][i] == val) {
            return false;
        }
    }

    // check the entire column
    for (int i = 0; i < n; i++) {
        if (arr[i][col] == val) {
            return false;
        }
    }

    // check the sub grid
    int root = sqrt(n);
    
    // creates the starting position for the sub grid row and sub grid column
    int gridRow = (row/root)*root;
    int gridCol = (col/root)*root;

    // loops through the sub grid to check if it is legal
    for (int i = gridRow; i < gridRow + root; i++) {
        for (int j = gridCol; j < gridCol + root; j++) {
            if (arr[i][j] == val) {
                return false;
            }
        }
    }
    return true;
}

// solves the sudoku puzzle
void Grid::solveGrid(std::ostream& out, int row, int col) {
    int nextRow = 0;

    // if col is at the end, go to the next row
    // else keep working within the current row
    if (col == n-1) {
        nextRow = row + 1;
    } else {
        nextRow = row;
    }

    // assign the next column
    int nextCol = (col + 1) % n;

    // if row == n, then we have solved the sudoku puzzle
    if (row == n) {
        numSolns++;
        out << *this;
        return;
    }

    // checks if the cell in the grid is not empty
    if (arr[row][col] != 0) {
        return solveGrid(out, nextRow, nextCol);
    }

    // loops from 1 to n to find a legal value for the cell
    for (int num = 1; num <= n; num++) {

        // checks if you can legally place the value
        if (isLegal(row, col, num)) {
            arr[row][col] = num;
            numAssigns++;
            solveGrid(out, nextRow, nextCol);
        }

        // resets to 0 if isLegal returns false
        arr[row][col] = 0;
    }
    arr[row][col] = 0;
}


void Grid::solve(std::ostream& out) {
    int row = 0;
    int col = 0;

    // calls the sudoku helper function
    solveGrid(out, row, col);
}

// copy constructor
Grid::Grid(const Grid& other) : numSolns(other.numSolns), numAssigns(other.numAssigns), n(other.n) {
    arr = new int*[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[n];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = other.arr[i][j];
        }
    }
}

// assignment operator
Grid& Grid::operator = (const Grid& rtSide) {
    if (this == &rtSide) {
        return *this;
    }
    numSolns = rtSide.numSolns;
    numAssigns = rtSide.numAssigns;
    n = rtSide.n;
    arr = new int*[n];
    for (int i = 0; i < n; i++)
        arr[i] = new int [n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = rtSide.arr[i][j];
        }
    }
    return *this;
}

// destructor
Grid::~Grid() {
    for (int i = 0; i < n; i++) {
        delete [] arr[i];
    }
    delete [] arr;
}
