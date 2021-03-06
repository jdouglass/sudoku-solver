#ifndef GRID_H
#define GRID_H


#include <iostream>

class Grid {
   public:
      // create an empty grid
      Grid();

      // return true if there are no numbers (that have been read)
      // false otherwise
      bool isEmpty() const;

      bool cellIsEmpty(const Grid& g, int row, int col);

      // solve the grid after reading with the operator >> from a stream
      // output ALL the solutions using the operator << and the stream out
      void solve(std::ostream& out);

      // after calling solve, numberOfSolutions returns how many solutions
      // were computed (and printed) during the last call to solve
      int numberOfSolutions() const;

      // return the number of work assignments
      long workAssigns() const;

      // return the side of the grid 
      // possible spot values are 1, 2, ..., dimension
      // the dimension is set on input
       int dimension() const;

      // on INput, a 0 is a blank spot
      static const int IN_BLANK = 0;

      // read the number of rows and number of columns
      //   if rows is not equal to columns, do nothing
      //   the rows becomes the dimension of the grid
      // read all the positions in the format
      //    i  j  x
      // where the value x is 1, 2, ..., 4  (dimension)
      // is x is IN_BLANK, then make the spot (i,j) to empty
      // assume that all the other spots not given are empty
      // set the dimension of g inside of the operator >> 
      friend std::istream& operator >> (std::istream& in, Grid&);

      // a pretty printed grid
      friend std::ostream& operator << (std::ostream& out, const Grid&);
      
      // copy constructor
      Grid(const Grid&);  
   
      // overloaded assignment operator
      Grid& operator = (const Grid&);
   
      // destructor
      ~Grid();

      // checks if the element in the cell is legal for the row, col, and grid
      bool isLegal(int row, int col, int val);

      // recursive helper funtion to solve the suokdu puzzle
      void solveGrid(std::ostream& out, int row, int col);

      bool isFilled();
   
   private:
      int numSolns; // number of possible solutions for the sudoku puzzle
      long numAssigns; // number of legal assignments made when trying to solve the puzzle
      int n; // sudoku puzzle dimension
      int** arr;
      
      // for pretty printing
      // width of a cell for up to 2 digits
      static const int OUT_WIDTH;
      // roof of a cell
      static const std::string OUT_ROOF; 
      // vertical wall around a cell
      static const char OUT_WALL;
      // show that the grid is empty
      static const char OUT_BLANK;
      // corner of a cell
      static const char OUT_CORNER;

      static void printHorizontalLine(int n, std::ostream& out);

      // pretty print the nxn grid G to standard output
      // if any value is zero, print a BLANK
      void printGrid(std::ostream& out) const;

};
#endif
