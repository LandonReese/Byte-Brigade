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

const int matrixRow = 1; // dx
const int matrixCol = 1; // dy
int k;                   // times wind was blown over the crystal, aka total lines to analyze

int windX;       // horizontal direction of wind
int windY;       // vertical direction of wind
int numOfPoints; // amount of crystal pairs

//START OF MAIN FUNCTION
int main(){
    // File input/Output
    ifstream newFile;
    newFile.open("sample-1.txt"); // INSERT NAME OF TEST-FILE HERE

    if(!newFile){
        cout << "Error, the selected file has not been found." << endl;
    } else { // The file has been found, storing data into variables
        string g = "";
        while(newFile){
            cin >> g;
            cout << g << " " << endl;
        }
        
        // newFile >> matrixRow;
        // newFile << matrixCol;
        // newFile >> k;

        // bool minMatrix[matrixRow][matrixCol];
        // bool maxMatrix[matrixRow][matrixCol];

        // //call function to set all x and y to FALSE for initial declaration

        // newFile >> windX;
        // newFile >> windY;
        // newFile >> numOfPoints;
        // for (int h = 0; h < numOfPoints; h++) // loops through the file k time, taking in data one line at a time
        // {
        //     // inner for loop for how many k iterations
        //     newFile >> pointX;
        //     newFile >> pointY;
        //     point p = new point(pointX, pointY);
        //     boundaries.push_back(p);
        // }
    }

    for(point d: boundaries){
        //minMatrix[d.x][d.y] = '#';
    }

    // Assign all numbers to variables

    // Create Min Matrix
}

// Print function for our min/max matrices
void print(bool** m, int row, int col){
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

void setMatrix(bool** matrix, int row, int col){
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            matrix[i][j] = false;
        }
    }
}