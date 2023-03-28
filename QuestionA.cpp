// file read in/read out
// process numbers into variables
// process numbers, and XY pairs for array coordinates
// be able to interpret the files into visual text maps
// bool arrays that output '.' if false, and '#' if true
// No molecule exists at the (x - x(wind), y - y(wind))
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// Defined Variables
struct point
{
    int x;
    int y;
    point(int a, int b)
    {
        x = a;
        y = b;
    }
};

int pointX;     // x value for point
int pointY;     // y value for point
vector<point> boundaries; // list of all points that are boundaries

// There isn't a single person in the world that knows why these values need to be defined.
// Several hours have been wasted because of these next two line,
// PROCEED WITH EXTREME CAUTION!
const int ROWS = 1;
const int COLS = 1;

int matrixRow = -1; // dx
int matrixCol = -1; // dy
int k;              // times wind was blown over the crystal, aka total lines to analyze

int windX;       // horizontal direction of wind
int windY;       // vertical direction of wind
int numOfPoints; // amount of crystal pairs

// Passing a 2D Array through a function
/*
int **array;
array = new int *[matrixRow];
for(int i = 0; i <matrixRow; i++)
    array[i] = new int[matrixCol];
void passFunc(int **a)
{
    // ...
}
passFunc(array);
*/

// Sets all values in matrix to zero
void setMatrix(bool matrix[ROWS][COLS], int row, int col){
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            matrix[i][j] = false;
        }
    }
}

/* from ChatGPT
void setMatrix(bool matrix[][matrixCol], int row, int col){
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            matrix[i][j] = false;
        }
    }
}
*/

// Print function for min/max matrices
void print(bool m[ROWS][COLS], int row, int col){
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (m[i][j])
                cout << "#";
            else
                cout << ".";
        }
        cout << endl;
    }
}
/*

void print(bool m[][matrixCol], int row, int col){
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (m[i][j])
                cout << "#";
            else
                cout << ".";
        }
        cout << endl;
    }
}

*/

//Prototype functions
//void print(bool m[ROWS][COLS], int, int);
//void setMatrix(bool m[ROWS][COLS], int, int);

//START OF MAIN FUNCTION
int main(){
    cout << "1. Starting main. " << endl;

    // File input/Output
    ifstream newFile;
    newFile.open("sample-1.txt"); // INSERT NAME OF TEST-FILE HERE

    cout << "2. File has been created. " << endl;

    if(!newFile){
        cout << "Error, the selected file has not been found." << endl;
    } else { // The file has been found, storing data into variables
        
        cout << "3. The file has been found. " << endl;
        newFile >> matrixRow;
        newFile >> matrixCol;
        newFile >> k;

        cout << "The variables row, col, k, have been instantiated" << endl;
        //Debugging variable check
        cout << "matrixRow: " << matrixRow << endl;
        cout << "matrixCol: " << matrixCol << endl;
        cout << "k: " << k << endl;

        //Define and instantiate each matrix as false
        // const int mRow = matrixRow;
        // const int mCol = matrixCol;
        bool minMatrix[matrixRow][matrixCol];
        bool maxMatrix[matrixRow][matrixCol];
        setMatrix(minMatrix, matrixRow, matrixCol);
            //thinks of it's parameters like this:
            //setMatrix(bool *(matrix)[1], rows, cols)
        

        //call function to set all x and y to FALSE for initial declaration

        newFile >> windX;
        newFile >> windY;
        newFile >> numOfPoints;
        for (int h = 0; h < numOfPoints; h++) // loops through the file k time, taking in data one line at a time
        {
            // inner for loop for how many k iterations
            newFile >> pointX;
            newFile >> pointY;
            minMatrix[pointX][pointY] = true;
            // point p = point(pointX, pointY);
            //p.x = pointX;
            //p.y = pointY;
            // boundaries.push_back(p);
        }
        // setMatrix(minMatrix, matrixRow, matrixCol);
        // print(minMatrix, matrixRow, matrixCol);
    }

    // for(point d: boundaries){
    //     int count = 1;
    //     cout << count << ": " << d.x <<", " << d.y << endl;
    //     count++;
    //     //minMatrix[d.x][d.y] = '#';
    // }

    // Assign all numbers to variables

    // Create Min Matrix
    
}
//END OF MAIN FUNCTION

// // Print function foCOLSur min/max matrices
// void print(bool m[ROWS][COLS], int row, int col){
//     for (int i = 0; i < row; i++)
//     {
//         for (int j = 0; j < col; j++)
//         {
//             if (m[i][j])
//                 cout << "#";
//             else
//                 cout << ".";
//         }
//         cout << endl;
//     }
// }

// void setMatrix2(bool(*matrix)[matrixCol])
// {
    
    
// }

// void setMatrix(bool matrix[ROWS][COLS], int row, int col){
//     for (int i = 0; i < row; i++)
//     {
//         for (int j = 0; j < col; j++)
//         {
//             matrix[i][j] = false;
//         }
//     }
// }