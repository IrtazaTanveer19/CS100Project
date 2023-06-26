#include <iostream>
#include <cmath> 
#include <string>
using namespace std;

//Evaluates the factorial of a number which the user inputs
int factorial(int n) { 
  int factorial = 1;
  if(n==1 || n==0)
    return 1;
  else {
    for(int i=1; i<=n; ++i)
        factorial *= i;
  }
  return factorial;
}

//Evaluates the number of possible permutations 
void permutations() {
  int n; 
  int r; 
  int permutation;
  cout << "Permuations are in the form nPr" << endl; 
  cout << "Enter the value of n: "; 
  cin >> n; 
  cout << "Enter the value of r: "; 
  cin >> r; 
  int d = n - r; 
  permutation = factorial(n)/factorial(d); //computes the number of possible permutations
  cout << "The number of possible permutations are " << permutation << endl; 
}

//Evaluates the number of possible combinations
void combinations() {
  int n; 
  int r; 
  int combination;
  cout << "Combinations are in the form nCr" << endl; 
  cout << "Enter the value of n: "; 
  cin >> n; 
  cout << "Enter the value of r: "; 
  cin >> r; 
  int d = n - r; 
  combination = factorial(n)/(factorial(d)*factorial(r)); //computes the number of possible combinations
  cout << "The number of possible combinations are " << combination << endl; 
}

int main() {
  int input;
  cout << "What operation do you want to perform?" << endl; 
  cout << "Enter 1 to compute the factorial of a number" << endl; 
  cout << "Enter 2 to compute the number of possible permutations" << endl; 
  cout << "Enter 3 to compute the number of possible combinations" << endl; 
  cout << "Enter q to quit" << endl;
  cout << "Enter your option: ";
  cin >> input;

  if(input == 1) {
    int n;
    cout << "Enter a positive integer: "; 
    cin >> n;
    cout << n << " factorial is " << factorial(n) << endl; 
  }
  else if(input == 2) 
    permutations();
  else if(input == 3) 
    combinations();
  return 0;
}