#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int input;

//generates numerical values for the function the user chooses
double numerical_value(double x, int* input) {
  double function; //numerical function values are returned into this variable
  if(*input == 1)
    function = x*x;
  else if(*input == 2)
    function = x*x*x; 
  else if(*input == 3)
    function = sin(x); 
  else if(*input == 4)
    function = cos(x); 
  else if(*input == 5) 
    function = sqrt(x); 
  else if(*input == 6) 
    function = exp(x); 
  else if(*input == 7)
    function = log(x); 
  return function; 
}


//Integration Function
void integral(double x) {
  double reimann_sum = 0;
  double upper_limit; 
  double lower_limit; 
  cout << "Enter lower limit" << endl; 
  cin >> lower_limit;
  cout << "Enter upper limit" << endl;
  cin >> upper_limit; 
  int n = 100000; //number of rectangles - the more the more accurate the value of the integral
  double dx = (upper_limit-lower_limit)/n; //dx is the width of one small rectangle
  for (int i=0; i<=n; i++) { //loop performs the integration 
    double xi = lower_limit + (i * dx);
    double function_value = numerical_value(xi, &input); 
    double area = function_value * dx; 
    reimann_sum += area; 
  }
  cout << "The integral is: " << fixed << setprecision(5) << reimann_sum << endl;
}

int main() {
  double x;
  cout << "Enter 1 to integrate x^2" << endl; 
  cout << "Enter 2 to integrate x^3" << endl; 
  cout << "Enter 3 to integrate sin(x)" << endl;
  cout << "Enter 4 to integrate cos(x)" << endl;
  cout << "Enter 5 to integrate sqrt(x)" << endl;
  cout << "Enter 6 to integrate e^x" << endl; 
  cout << "Enter 7 to integrate ln(x)" << endl; 
  cout << "Enter q to quit" << endl; 
  cout << "Enter the function you want to integrate from the options above: " << endl;
  cin >> input;
  integral(x);
  return 0;
}