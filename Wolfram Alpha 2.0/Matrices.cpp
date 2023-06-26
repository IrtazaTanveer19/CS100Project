#include <iostream>  
#include <string> 
#include <iomanip> 
#include <vector> 
#include <cmath> 
using namespace std;

//function generates the matrix by taking in user input
vector<vector<double>> generate_matrix(int rows, int columns) {
    vector<vector<double>> matrix; 
    double value;
    cout << "Enter matrix elements" << endl;
    for(int i=0; i<rows; i++) {
        vector<double> temp; //temp vector stores elements for each row
        for(int j=0; j<columns; j++) {
            cout << "matrix element ["<<i<<"]["<<j<<"]: ";
            cin >> value; 
            temp.push_back(value); //input is added to the temp vector
        }
        matrix.push_back(temp); //temp vector is added to the matrix vector
    }
    return matrix;
}

//displays the matrix by iterating through the rows and columns 
void display_matrix(vector<vector<double>> matrix, int rows, int columns) {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<columns; j++) {
            cout << setw(3) << matrix[i][j] << " "; 
        }
        cout << endl; 
    } 
}

//function performs matrix multiplication
vector<vector<double>> matrix_multiplication(vector<vector<double>> matrixA, vector<vector<double>>matrixB, int rowsA, int columnsB) {
    vector<vector<double>> matrixAB; 
    for(int i=0; i<rowsA; i++) {
        vector<double> temp; 
        for(int j=0; j< columnsB; j++) {
            double total = 0; 
            for(int k=0; k<columnsB; k++) {
                total += matrixA[i][k] * matrixB[k][j]; //the result of the multiplication is stored in total
            }
            temp.push_back(total); 
        }
        matrixAB.push_back(temp); 
    }
    return matrixAB;
}

//function which performs matrix addition
vector<vector<double>> matrix_addition(vector<vector<double>> matrixA, vector<vector<double>>matrixB, int rowsA, int columnsA) {
    vector<vector<double>> sum_matrix; 
    for(int i=0; i<rowsA; i++) {
        vector<double> temp; 
        for(int j=0; j<columnsA; j++) {
            double sum = matrixA[i][j] + matrixB[i][j]; //value of sum is evaluated for each index and added to temp
            temp.push_back(sum);  
        }
        sum_matrix.push_back(temp); 
    }
    return sum_matrix; 
}

//function which performs matrix subtraction
vector<vector<double>> matrix_subtraction(vector<vector<double>> matrixA, vector<vector<double>>matrixB, int rowsA, int columnsA) {
    vector<vector<double>> difference_matrix; 
    for(int i=0; i<rowsA; i++) {
        vector<double> temp; 
        for(int j=0; j<columnsA; j++) {
            double difference = matrixA[i][j] - matrixB[i][j]; //value of difference is evaluated for each index and added to temp
            temp.push_back(difference); 
        }
        difference_matrix.push_back(temp);
    }
    return difference_matrix;
}

//function which evaluates the determinant of any square matrix
double matrix_determinant(vector<vector<double>> matrix) {
    const double EPSILON = 1.0E-30;
    int n = matrix.size(); 
    double determinant = 1; 
    for (int i=0; i<n-1; i++) { 
        int r = i;
        double max = abs(matrix[i][i]); 
        for (int k=i+1; k<n; k++) {
            double val = abs(matrix[k][i]);
            if (val > max) {
                r = k;
                max = val;
            }
        }
        if (r!=i) {
            for (int j=i; j<n; j++) 
                swap(matrix[i][j], matrix[r][j]);
            determinant = -determinant;
        }
        double pivot = matrix[i][i];
        if (abs(pivot) < EPSILON ) 
            return 0;       
        for (int r=i+1; r<n; r++) {
            double multiple = matrix[r][i] / pivot;
            for (int j=i; j<n; j++) 
                matrix[r][j] -= multiple * matrix[i][j];
        }
      determinant *= pivot;
   }
   determinant *= matrix[n-1][n-1]; //allows for program to calculate the determinant for any n by n matrix
   return determinant;
}

int main() {
    int input; //input from the user is stored
    cout << "What operation do you want to perform?" << endl;
    cout << "Enter 1 to multiply two matrices" << endl; 
    cout << "Enter 2 to add two matrices" << endl; 
    cout << "Enter 3 to subtract two matrices" << endl;
    cout << "Enter 4 to calculate the determinant of a matrix" << endl; 
    cout << "Enter q to quit" << endl; 
    cout << "Enter your option: "; 
    cin >> input; 

    if(input == 1) {
        //Matrix A generated
        int rowsA; 
        int columnsA;
        cout << "Enter the number of rows for Matrix A: ";  
        cin >> rowsA; 
        cout << "Enter the number of columns for Matrix A: "; 
        cin >> columnsA; 
        vector<vector<double>> matrixA = generate_matrix(rowsA, columnsA);
        cout << "Matrix A:" << endl;
        display_matrix(matrixA, rowsA, columnsA);

        //Matirx B generated
        int rowsB; 
        int columnsB;
        cout << "Enter the number of rows Matrix B: ";  
        cin >> rowsB; 
        cout << "Enter the number of columns for Matrix B: "; 
        cin >> columnsB; 
        vector<vector<double>> matrixB = generate_matrix(rowsB, columnsB);
        cout << "Matrix B:" << endl;
        display_matrix(matrixB, rowsB, columnsB);
        
        //program checks if multiplication is possible depending on the dimensions of Matrices A & B
        if(columnsA != rowsB) 
            cout << "A and B will not multiply" << endl; 
        else{
            vector<vector<double>> matrixAB;
            matrixAB = matrix_multiplication(matrixA, matrixB, rowsA, rowsB); 
            cout << "A x B:" << endl;
            display_matrix(matrixAB, rowsA, columnsB); 
        }
    }

    else if(input == 2) {
        //Matrix A generated
        int rowsA; 
        int columnsA;
        cout << "Enter the number of rows for Matrix A: ";  
        cin >> rowsA; 
        cout << "Enter the number of columns for Matrix A: "; 
        cin >> columnsA; 
        vector<vector<double>> matrixA = generate_matrix(rowsA, columnsA);
        cout << "Matrix A:" << endl;
        display_matrix(matrixA, rowsA, columnsA);

        //Matrix B generated
        int rowsB; 
        int columnsB;
        cout << "Enter the number of rows Matrix B: ";  
        cin >> rowsB; 
        cout << "Enter the number of columns for Matrix B: "; 
        cin >> columnsB; 
        vector<vector<double>> matrixB = generate_matrix(rowsB, columnsB);
        cout << "Matrix B:" << endl;
        display_matrix(matrixB, rowsB, columnsB);

        if((columnsA != rowsB) && (rowsA != rowsB)) //program checks if addition can be performed
            cout << "Addition cannot be performed" << endl;
        else {
            vector<vector<double>> sum_matrix; 
            sum_matrix = matrix_addition(matrixA, matrixB, rowsA, columnsA); 
            cout << "A + B:" << endl;
            display_matrix(sum_matrix, rowsA, columnsA);
        } 
    }

    else if(input == 3) {
        //Matrix A generated
        int rowsA; 
        int columnsA;
        cout << "Enter the number of rows for Matrix A: ";  
        cin >> rowsA; 
        cout << "Enter the number of columns for Matrix A: "; 
        cin >> columnsA; 
        vector<vector<double>> matrixA = generate_matrix(rowsA, columnsA);
        cout << "Matrix A:" << endl;
        display_matrix(matrixA, rowsA, columnsA);

        //Matrix B generated
        int rowsB; 
        int columnsB;
        cout << "Enter the number of rows Matrix B: ";  
        cin >> rowsB; 
        cout << "Enter the number of columns for Matrix B: "; 
        cin >> columnsB; 
        vector<vector<double>> matrixB = generate_matrix(rowsB, columnsB);
        cout << "Matrix B:" << endl;
        display_matrix(matrixB, rowsB, columnsB);

        if((columnsA != rowsB) && (rowsA != rowsB)) //program checks if subtraction can be performed
            cout << "Subtraction cannot be performed" << endl;
        else {
            vector<vector<double>> difference_matrix; 
            difference_matrix = matrix_subtraction(matrixA, matrixB, rowsA, columnsA); 
            cout << "A - B:" << endl;
            display_matrix(difference_matrix, rowsA, columnsA);
        }
    }

    else if(input == 4) {
        //user inputs the number of rows and columns for the matrix
        int rows; 
        cout << "Enter the number of rows of the matrix: "; 
        cin >> rows; 
        int columns; 
        cout << "Enter the number of columns of the matrix: "; 
        cin >> columns; 
        if(rows != columns) //checks if the matrix is a square matrix
            cout << "Determinant does not exist" << endl; 
        else {
            vector<vector<double>> matrix; 
            int n = matrix.size();
            matrix = generate_matrix(rows, columns); 
            cout << "Matrix is:" << endl;
            display_matrix(matrix, rows, columns); 
            double determinant = matrix_determinant(matrix); 
            cout << "Determinant is: " << determinant << endl; 
        }
    }
    return 0;
}