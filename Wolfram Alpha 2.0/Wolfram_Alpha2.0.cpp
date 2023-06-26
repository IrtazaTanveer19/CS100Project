#include <iostream>
#include <cmath>
using namespace std;

void check_op1(bool&check_op1_bool, string op)  // checks for quiting function
{
    if ((op=="quit") || (op=="Quit" )|| (op=="quit"))
    {
        check_op1_bool=false;
    }
    else
    {
        check_op1_bool=true;
    }
}
void check_op2(bool &check_op2_bool, string op) // checks for ac and quit
{
    if ((op=="AC") || (op=="ac") || (op=="Quit") || (op=="quit") || (op=="QUIT"))
    {
       check_op2_bool=false;
    }
    else
    {
        check_op2_bool=true;
    }
}
void check_op3(string &op)    // checks for invalid operator
{
    if(op=="+" || op=="x" ||op=="/" || op=="-" || op=="%")
    {
        return;
    }
    {
        cout<<endl<<"Invalid Operation"<<endl;
        cout<<"Enter operation from (+ , - , x , / , %): ";
        cin>>op;
    }
}
void arthemetics()
{
    double num1,result;
    string op;
    bool check_op1_bool=true;  // for only quit
    bool check_op2_bool=true;  // for ac and quit
    cout<<"Enter Number: ";
    cin>>result;
    cout<<"Enter operation or quit to exit: ";
    cin>>op;
    check_op1(check_op1_bool, op);
    check_op2(check_op2_bool, op);
    while(check_op1_bool){       // outer loop exited when only quit true
        while(check_op2_bool)   // inner loop exit when quit or ac entered

        {
            cout<<"Enter number: ";
            cin>>num1;
            check_op3(op);
            if(op=="+")
            {
                result=result+num1;

            }
            else if(op=="-")
            {
                result=result-num1;
            }
            else if(op=="x")
            {
                result=result*num1;
            }
            else if(op=="/")
            {
                result=result/num1;
            }
            else
            {
                result=int(result)%int(num1);
            }
            cout<<endl<<"Result: "<<result<<endl<<endl;
            cout<<"Enter Operation or quit to exit: ";
            cin>>op;
            check_op1(check_op1_bool,op);    // checks for quit
            check_op2(check_op2_bool,op);    //checks for quit and ac
/** if ac entered here inner loop exits but outerloop is still running*/

        }
        if(op=="Quit" || op=="quit" || op=="QUIT")
        {
            return;   // exits the outer loop and function
        }
        else if(op=="Ac" || op=="AC"||op=="ac")    // if ac entered make result zero
        {
            result=0;
            cout<<endl<<"Result: "<<result<<endl<<endl;
            cout<<"Enter number: ";
            cin>>num1;
            cout<<"Enter operation or quit to exit: ";
            cin>>op;

            check_op1(check_op1_bool,op); // checks for exiting outer loop
            check_op2(check_op2_bool,op);  // checks for exiting inner loop
        }
       else
       {
        continue;
       }

    }
}
void print_table_of_eq()
{
    cout<<"Enter 1 for solving: Ax + By= C"<<endl;
    cout<<"                     Dx + Ey= F"<<endl<<endl;
    cout<<"Enter 2 for solving: Ax^2 + Bx +C = 0"<<endl<<endl;
    cout<<"Enter 3 to exit to main menu"<<endl<<endl;
    cout<<"Enter option: ";
}
void solutions_of_eq()
{

    int option;
    do
    {

        print_table_of_eq();
        cin>>option;
        cout<<endl;
        if(option==1)
        {
            cout<<"Solving Simultaneous Equations"<<endl;
            double a, b, c, d, e, f, x, y;
            cout<<"A= ";cin>>a;cout<<"B= ";cin>>b;cout<<"C= ";cin>>c;cout<<"D= ";cin>>d;cout<<"E= ";cin>>e;cout<<"F= ";cin>>f;
            y=(a*f-c*d)/(a*e-b*d);
            x=(c-b*y)/a;
            if(b>=0)   //checks for sign of b if +ve prints a positive sign and vice versa
            {
                cout<<endl<<"Your equation: "<<a<<"x"<<"+"<<b<<"y= "<<c<<endl;
            }
            else
            {
                cout<<endl<<"Your equation: "<<a<<"x"<<b<<"y= "<<c<<endl;
            }
            if(e>=0)
            {
                cout<<"               "<<d<<"x"<<"+"<<e<<"y= "<<f<<endl<<endl;
            }
            else
            {
                cout<<"               "<<d<<"x"<<e<<"y= "<<f<<endl<<endl;
            }
            cout<<"Your Solutions: x= "<<x<<" and y= "<<y<<endl<<endl<<endl<<endl;
        }
        if(option==2)
        {
            cout<<"Solving Quadratic Equation"<<endl;
            cout<<"Enter A= ";
            double a,b, c, root1, root2;
            cin>>a;
            cout<<"Enter B= ";
            cin>>b;
            cout<<"Enter C= ";
            cin>>c;
            if(b>=0 && c>=0)   //below are checks to write appropriate sign of b and c
            {
                cout<<endl<<"Solutions for Quadratic Equation: "<<a<<"x^2"<<"+"<<b<<"x"<<"+"<<c<<" :"<<endl;
            }
            else if(b<0 && c>=0)
            {
                cout<<endl<<"Solutions for Quadratic Equation: "<<a<<"x^2"<<b<<"x"<<"+"<<c<<" :"<<endl;
            }
            else if(b>=0 && c<0)
            {
                cout<<endl<<"Solutions for Quadratic Equation: "<<a<<"x^2"<<"+"<<b<<"x"<<c<<" :"<<endl;
            }
            else
            {
                cout<<endl<<"Solutions for Quadratic Equation: "<<a<<"x^2"<<b<<"x"<<c<<" :"<<endl;
            }
            if((b*b-4*a*c)<0)   // checks for math error
            {
                cout<<endl<<"Math Error"<<endl<<endl;
            }
            else if(a==0)
            {
                root1=-c/b;
                root2=root1;
            }
            else
            {
                root1=((-b+sqrt((b*b)-4*a*c))/(2*a));
                root2=((-b-sqrt((b*b)-4*a*c))/(2*a));
            }
            if((b*b-4*a*c)>=0)                   // only nprint real roots
            {
                cout<<endl<<"x1= "<<root1<<endl;
                cout<<"x2= "<<root2<<endl<<endl<<endl<<endl;
            }
        }
    }
    while(option!=3);

}

int main()
{
    solutions_of_eq();
}
