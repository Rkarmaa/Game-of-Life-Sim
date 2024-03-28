// ====================================================
// Ramatu Kamara
// gol.cpp
// March 1, 2024
// This program is met to look through a set number of 
// coordinates that indicate where there is a hole in 
// the ozone. Based on the rules, defined The holes will
// persist, disappear, or create
// new holes.
// ====================================================


#include <iostream>
using namespace std;

#define S 15
void readPoints (char g[S][S],int x[], int y[], int n);
void printGrid (char g[S][S]);
void checkHole (char g[S][S]);
void changeHole (char g[S][S], int row, int col);

// ====================================================
// main
// ====================================================
int main ( void )


{
    // sets the elements automatically to 0
    char grid [S][S] = { };
    // number of points
    int n;
    cin >> n;
    int x[n], y[n];

    readPoints(grid, x, y, n);
    for(int months = 0; months < 24; months++)
        checkHole(grid);

    return 0;
}


// ====================================================
// checkHole
// This function checks an element's neighbors to 
// to see if they qaulify to be changed or stay the
// same. 
// PARAMETERS:
// grid[S][S] - Predefined array that is being checked
// RETURN:
// None
// ====================================================
void checkHole (char grid[S][S])
{
    char newgrid[S][S];
    int count0 = 0; // count neighbor 0
    // all the difference neighbor points
    int rw[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int cl[8] = {0, 1, 1, 1, 0, -1, -1, -1};

    for (int r = 0; r < S; r++)
    {
        for (int c = 0; c < S; c++)
        {
            count0 = 0;
            for (int i = 0; i < 8; i++)
            {   // steps through each row by column to 
                // find neighbors of current element
                int clP = cl[i];
                int rwP = rw[i];
                //will count the neighbors that are '0'
                if ((r + rwP < S) && (r + rwP >= 0) 
                && (c + clP >= 0) && (c + clP < S) 
                && (grid[r + rwP][c+ clP] == '0'))
                    count0++;
            }
            // if element is 'X' and number of neighbor '0'
            // is 3 then change
            if (grid[r][c] == 'X')
            {
                if (count0 == 3)
                    newgrid[r][c] = '0';
                else
                    newgrid[r][c] = 'X';
            }
            // if element is '0' and number of neighbor '0' 
            // is 2 or 3 then don't change
            else
            {
                if (count0 != 2 && count0 != 3)
                    newgrid[r][c] = 'X';
                else
                    newgrid[r][c] = '0';
            }
        }
    }
    // copies contents of new grid to original grid
    for (int i = 0; i < S; i++)
        for (int j = 0; j < S; j++)
            grid[i][j] = newgrid[i][j];

    printGrid(grid);
}


// ====================================================
// readPoints
// Reads through the starting points and inputs them
// in grid
// PARAMETERS:
// grid[S][S] - array that points are inputted in
// x[] - row value (0-14)
// y[] - column value (0-14)
// n[] - number of coordinates
// RETURN:
// None
// =====================================================
void readPoints (char grid[S][S], int x[], int y[], int n)
{
    // it is assumed that the points are within bounds
    for ( int i = 0; i < S; i++ )
        for ( int j = 0; j < S; j++ )
            grid[i][j] = 'X';


    for (int i = 0; i < n; i++)
    {   // changes the points to start at '0'
        cin >> x[i] >> y[i];
        grid[x[i]][y[i]] = '0';
    }
    printGrid(grid);
}


// =====================================================
// printGrid
// Prints modified grid
// PARAMETERS:
// grid[S][S] - grid that is being printed to screen
// RETURN:
// None
// =====================================================
void printGrid (char grid[S][S])
{
    for ( int i = 0; i < S; i++ )
    {
        for ( int j = 0; j < S; j++ )
            cout << grid[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}