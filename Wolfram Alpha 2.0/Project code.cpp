#include <iostream>
#include <graphics.h>
#include <string>
#include <cmath>
#include<iomanip>
#include<vector>
#include<windows.h>
#include<mmsystem.h>
//Group Members
//Roll No.24100043-Muhammad Hamza Khawaja
//Roll No. 24100039-Irtaza Tanveer Ahmad





using namespace std;
// putpixel puts dot at x and y position
// setstyle decides the style and size of text
// outtextxy puts string output on x and y coordinate
// each time display opened its get closed by minimize button so that new display can be made
/** starting display*/

void display_frontscreen()
{
    int gd = DETECT, gm;
    int n=0;  // number of times screen blinks in intro
    int x, y;

    initgraph(&gd, &gm, "");   // initialize graphic window
    PlaySound(TEXT("blinding Lights.wav"),NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);

    while (n!=8)
    {    //blinking stars printed with title
        for(int i=0; i<=500; i++)
        {
            x=rand()%getmaxx();  // at random position of x and y
            y=rand()%getmaxy();
            putpixel(x,y,15);
            settextstyle(10,0,4);
            outtextxy(getmaxx()/2-150,getmaxy()/2,"Wolfram Alpha 2.0");
      }
      n++; // runs 8 times
      delay(600); // switches after delay
      cleardevice(); //clear screen to show blinking effect


    }

    closegraph();



}
/** Main menu */

void main_display()
{

     int gd = DETECT, gm;
    int n=0;  // number of times screen blinks in intro
    int x, y;

    initgraph(&gd, &gm, "");

    // making display
    string display[]={"1: Arthmetics","2: Solution Of Equations ","3: Trignometric Graphs","4: Integrals","5: Matrix ","6: PnC"}; // options printed
    int display_options=0;
    settextstyle(10,0,1);
    outtextxy(getmaxx()/2-100,0,"Wolfram Alpha 2.0"); //prints heading and quit at bottom
    outtextxy(getmaxx()/2-80,getmaxy()-50,"q: Quit");
    for(int x=getmaxx()/2-300; x<=getmaxx()/2; x+=300) // gets x and y coordinates where options printed, prints vertically
    {

       for(int y=getmaxy()/2-100;y<=getmaxy()/2+100; y+=100) // helps in printing at fixed x and y changes
       {
           string a=display[display_options]; // a stores  option(whole word) as string
           char*ptr=&a[0]; // gets char pointer of first letter of option
           settextstyle(10,0,1);
           setcolor(display_options+2);
           // used ptr as outtext function only takes char ptr of string going to be printed
           outtextxy(x,y,ptr); //prints the pointed string
           display_options++; //moves to new option
       }

    }
    // minimize button
    cout<<endl<<endl<<"Enter any key to minimize the graphic window: ";
    string minimize;
    cin>>minimize;
    if(minimize=="m")
        closegraph();
    else
        closegraph();


}
void if_integer_input_fails(double&num) // checks integer failture, type of input is double
{
    if(cin.fail())
    {
        cin.clear();
        string dummy;
        getline(cin,dummy);
        cout<<endl<<"Invalid Number"<<endl<<endl;
        cout<<"Enter Number Only: ";
        cin>>num;
        if_integer_input_fails(num); // makes a recursion till integer input

    }
}
void if_integer_input_fails(int&num) // checks integer failture, type of input is int
{
    if(cin.fail())
    {
        cin.clear();
        string dummy;
        getline(cin,dummy);
        cout<<endl<<"Invalid Number"<<endl<<endl;
        cout<<"Enter Number Only: ";
        cin>>num;
        if_integer_input_fails(num);

    }
}
/** ARTHEMTICS OPERATION */
void check_op1(bool&check_op1_bool, string op)  // checks for only quiting function, used in arthmetics function, used to exit outer while loop
{
    if ((op=="quit") || (op=="Quit" )|| (op=="quit") || (op=="q") || (op=="Q"))
    {
        check_op1_bool=false;
    }
    else
    {
        check_op1_bool=true;
    }
}
void check_op2(bool &check_op2_bool, string op) // checks for ac and quit, used in arthmetics function, usedto exit inner while loop
{
    if ((op=="AC") || (op=="ac") || (op=="Quit") || (op=="quit") || (op=="QUIT") || (op=="q") || (op=="Q"))
    {
       check_op2_bool=false;
    }
    else
    {
        check_op2_bool=true;
    }
}
void check_op3(string &op)    // checks for invalid operator, used in arthmetics function
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
void arthmetics_display() // display for this operation
{
    string a =" -----------------------";
    cout<<a<<endl;
    cout<<"|  1  |  2  |  3  |  +  |"<<endl;
    cout<<a<<endl;
    cout<<"|  4  |  5  |  6  |  -  |"<<endl;
    cout<<a<<endl;
    cout<<"|  7  |  8  |  9  |  x  |"<<endl;
    cout<<a<<endl;
    cout<<"|  0  |  AC | quit|  /  |"<<endl;
    cout<<a<<endl<<endl<<endl;
}
void arthmetics()       // main working station
{
    // entering ac clears the result
    // entering q or quit exit to main menu
    arthmetics_display();
    double num1,result;
    string op;                 //op stands for operation
    bool check_op1_bool=true;  // check for only quit and exit outer while loop so exit to main menu
    bool check_op2_bool=true;  // check for ac and quit and exit only inner while loop
    cout<<"Enter Number: ";
    cin>>result;                // result is the number on display
    if_integer_input_fails(result);  // integer validation
    cout<<"Enter operation or q to quit: ";
    cin>>op;
    check_op1(check_op1_bool, op);
    check_op2(check_op2_bool, op);
    while(check_op1_bool){       // outer loop exited when only when quit true
        while(check_op2_bool)   // inner loop exit when quit or ac entered and after exit check whether ac to clear screen or quit was entered

        {
            cout<<"Enter number: ";  // 2nd number
            cin>>num1;
            if_integer_input_fails(num1);
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
            cout<<"Enter Operation or q to quit: ";  // consecutive operations
            cin>>op;
            check_op1(check_op1_bool,op);    // checks for quit, exit outer while loop
            check_op2(check_op2_bool,op);    //checks for quit and ac, exit inner while loop
/** if ac entered here inner loop exits but outerloop is still running*/

        }
        if(op=="Quit" || op=="quit" || op=="QUIT" || op=="q" || op=="Q")  // possible styles for user entering quit
        {

            return;   // exits the outer loop and function
        }
        else if(op=="Ac" || op=="AC"||op=="ac")    // if ac entered make result zero
        {
            result=0;
            cout<<endl<<"Result: "<<result<<endl<<endl;
            cout<<"Enter number: ";
            cin>>result;      // this becomes number 1
            if_integer_input_fails(num1);
            cout<<"Enter operation or q to quit: ";
            cin>>op;

            check_op1(check_op1_bool,op); // checks for exiting outer loop
            check_op2(check_op2_bool,op);  // checks for exiting inner loop
        }
       else
       {
        continue; //continue the inner loop
       }

    }
}
/** SOLUTIONS OF EQUATIONS*/


void print_table_of_eq()  // display
{
    cout<<endl<<"Enter 1 for solving: Ax + By= C"<<endl;
    cout<<"                     Dx + Ey= F"<<endl<<endl;
    cout<<"Enter 2 for solving: Ax^2 + Bx +C = 0"<<endl<<endl;
    cout<<"Enter q to quit"<<endl<<endl;
    cout<<"Enter option: ";
}
void solutions_of_eq()  // working station
{

    string option; //takestring option so if enter q exit to main function
    do
    {

        print_table_of_eq(); // print display
        cin>>option;
        cout<<endl;
        if(option=="1")   // simultaneous eqs
        {
            cout<<"Solving Simultaneous Equations"<<endl;
            double a, b, c, d, e, f, x, y;
            cout<<"A= ";cin>>a;cout<<"B= ";cin>>b;cout<<"C= ";cin>>c;cout<<"D= ";cin>>d;cout<<"E= ";cin>>e;cout<<"F= ";cin>>f;
            y=(a*f-c*d)/(a*e-b*d); // formulas to calculate
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
        else if(option=="2")   // quadratic equations
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
            else if(a==0)  // a=0 makes a linear equation so also gives root for it
            {
                root1=-c/b;
                root2=root1;
            }
            else
            {
                root1=((-b+sqrt((b*b)-4*a*c))/(2*a));  // formulas
                root2=((-b-sqrt((b*b)-4*a*c))/(2*a));
            }
            if((b*b-4*a*c)>=0)                   // only nprint real roots  and not the math error one
            {
                cout<<endl<<"x1= "<<root1<<endl;
                cout<<"x2= "<<root2<<endl<<endl<<endl<<endl;
            }
        }
        else if (option=="q")
        {
            cout<<":)";
        }
        else
        {
            cout<<"Invalid Option"<<endl<<endl; // option other than q,1,2 says invalid option
        }
    }
    while(option!="q");    // helps to exit to main menu

}

/** TRIGNOMETRIC GRAPHS*/


void display_trignometric_graphs()  //prints display
{
    cout<<endl;
    cout<<"              1: Sin Graph              "<<endl<<endl;
    cout<<"2: Cos Graph                 3:Tan Graph"<<endl<<endl;
    cout<<"              q: Quit                    "<<endl<<endl<<endl<<endl;
    cout<<"-----------------------------------------"<<endl;
    cout<<"    Press Any Key To Close The Graph     "<<endl;
    cout<<"-----------------------------------------"<<endl<<endl<<endl;
}
/* Three parts to sin and cos graph 1: maxamplitude, 2: minimum amplitude, 3: zero amplitude
labeling of x and y axis done for these regions and move about these region*/
void sin_graph() {
    int gd = DETECT, gm;
    double x, y,trig_equation;    // x: xcoordinate, y: y coordinate for putpixel, trig_eq gives amplitude which is used to get y
    int angle=0;   // angle changes to find putpixel y coordinate
    int xaxis_angle_label=0; //labeling of xaxis, they are angles
    int amp=0;
    int shift=0;
    int yaxis_amp_label=0;    // labeling of y axis with amplitudes
    int factor=0;             // factor helps in converting real values to graphic screen values. Helps to ratio the graph accurately
    int phase=0;
    cout<<endl<<"General Form: Asin(Bx)+C"<<endl;
    cout<<"Enter A (amplitude): ";
    cin>>amp;
    if_integer_input_fails(amp);
    cout<<"Enter B (phase): ";
    cin>>phase;
    if_integer_input_fails(shift);
    cout<<"Enter C (shift): ";
    cin>>shift;
    if_integer_input_fails(shift);
    double decimal_error_correction=0;
    if(abs(amp)<=2 && shift<=2)  // helps to deal with a range of amp and shift, changes factor accordingly
    {
         factor=50;
    }
    else if(abs(amp)<=4 && shift<=4)
    {
         factor=25;

    }
    else if(abs(amp)<=6 && shift<=6)
    {
        factor=10;
    }
    else
    {
        factor=5;
    }


initgraph(&gd, &gm, "");
line(getmaxx()/2,getmaxy(),getmaxx()/2,0); // yaxis printed
line(0, getmaxy() / 2, getmaxx(), getmaxy() / 2); //xaxis printed
 /* generate a sine wave */
 for(x = getmaxx()/2; x < getmaxx(); x+=3) {      // changes in xcoordinates of pixels and get corresponding y
      if(xaxis_angle_label>=405){break;}          // limits the range to 360 degrees
     /* calculate y value given x */
     trig_equation = factor*(amp*sin(phase*angle*3.141/180)+shift);  //give amp
     y = getmaxy()/2 - trig_equation;  // place it with respect to center of axis
     if(trig_equation>=((amp*factor-0.1+factor*shift)) && trig_equation<=(amp*factor+factor*shift+0.1))  // range where max amplitude of sine wave lie
     {


         //labeling angles on xaxis
        string int_xlabel_to_string = to_string(xaxis_angle_label);
        char*ptr1=&int_xlabel_to_string[0];   // get char ptr as outtext take char pointer
        settextstyle(0, 0, 1);
        outtextxy(x-5, getmaxy()/2,ptr1);
        xaxis_angle_label=xaxis_angle_label+90/phase;  // changes the angle value for new label on xaxis

        // labeling yaxis
        if((amp*sin(angle*3.142/180)+shift)<0)   // decimal error correction as values are not exact
        {
            decimal_error_correction=-0.5;
        }
        else
        {
            decimal_error_correction=0.5;
        }
        yaxis_amp_label=(amp*sin(phase*angle*3.142/180)+shift)+decimal_error_correction; // gets me the label of max amplitude and prints it
        string int_ylabel_to_string=to_string(yaxis_amp_label);
        char*ptr2=&int_ylabel_to_string[0];
        settextstyle(0, 0, 1);
        outtextxy(getmaxx()/2,y,ptr2);
    }
    else if (trig_equation>=-0.2+factor*shift && trig_equation<=0.2+factor*shift) // range where sin wave is at zero amplitude
    {
        string int_xlabel_to_string = to_string(xaxis_angle_label); // labeling xaxis
        char*ptr=&int_xlabel_to_string[0];
        outtextxy(x-5, getmaxy()/2,ptr);
        settextstyle(0, 0, 1);
        xaxis_angle_label=xaxis_angle_label+90/phase;
    }
    else if(trig_equation>=-(amp*factor)-0.1+factor*shift && trig_equation<=-(amp*factor)+0.1+factor*shift) // minimum amplitude of sin wave
    {
        string int_xlabel_to_string = to_string(xaxis_angle_label); // label xaxis where minimum amplitude
        char*ptr1=&int_xlabel_to_string[0];
        outtextxy(x-5, getmaxy()/2,ptr1);
        settextstyle(0, 0, 1);
        xaxis_angle_label=xaxis_angle_label+90/phase;

        //labeling yaxis amplitudes
        if ((amp*sin(phase*angle*3.142/180)+shift)<0)  // decimal correction
        {
            decimal_error_correction=-0.5;
        }
        else
        {
            decimal_error_correction=0.5;
        }
        yaxis_amp_label=(amp*sin(phase*angle*3.142/180)+shift)+decimal_error_correction; // yaxis labels at minimum amplitude
        string int_ylabel_to_string=to_string(yaxis_amp_label);
        char*ptr2=&int_ylabel_to_string[0];
        settextstyle(0, 0, 1);
        outtextxy(getmaxx()/2,y,ptr2);
    }


     //put dots on that position
  putpixel(x, y, 15);

 angle+=5; // changes in angle to get y values
 }


    cout<<endl<<endl<<"Enter any key to minimize the graphic window: ";  // minimize key
    string minimize;
    cin>>minimize;
    if(minimize=="m")
        closegraph();
    else
        closegraph();

}

// SAME EXPLAINATION AS OF SIN WAVE
void cos_graph() {
    int gd = DETECT, gm;
    double x, y,trig_equation;
    int angle=0;
    int xaxis_angle_label=0;
    int amp=0;
    int shift=0;
    int yaxis_amp_label=0;
    int factor=0;
    int phase=0;
    cout<<endl<<"General Form: Acos(Bx)+C"<<endl;
    cout<<"Enter A (amplitude): ";
    cin>>amp;
    if_integer_input_fails(amp);
    cout<<"Enter B (phase): ";
    cin>>phase;
    if_integer_input_fails(shift);
    cout<<"Enter C (shift): ";
    cin>>shift;
    if_integer_input_fails(shift);
    double decimal_error_correction=0;
    if(abs(amp)<=2 && shift<=2)
    {
         factor=50;
    }
    else if(abs(amp)<=4 && shift<=4)
    {
         factor=25;

    }
    else if(abs(amp)<=6 && shift<=6)
    {
        factor=10;
    }
    else
    {
        factor=5;
    }


initgraph(&gd, &gm, "");
line(getmaxx()/2,getmaxy(),getmaxx()/2,0);
line(0, getmaxy() / 2, getmaxx(), getmaxy() / 2);

 for(x = getmaxx()/2; x < getmaxx(); x+=3) {

     if (xaxis_angle_label>=405){break;}
     trig_equation = factor*(amp*cos(phase*angle*3.141/180)+shift);
     y = getmaxy()/2 - trig_equation;
     if(trig_equation>=((amp*factor-0.1+factor*shift)) && trig_equation<=(amp*factor+factor*shift+0.1))
     {



        string int_xlabel_to_string = to_string(xaxis_angle_label);
        char*ptr1=&int_xlabel_to_string[0];
        settextstyle(0, 0, 1);
        outtextxy(x-5, getmaxy()/2,ptr1);
        xaxis_angle_label=xaxis_angle_label+90/phase;

        if((amp*cos(phase*angle*3.142/180)+shift)<0)
        {
            decimal_error_correction=-0.5;
        }
        else
        {
            decimal_error_correction=0.5;
        }
        yaxis_amp_label=(amp*cos(phase*angle*3.142/180)+shift)+decimal_error_correction;
        string int_ylabel_to_string=to_string(yaxis_amp_label);
        char*ptr2=&int_ylabel_to_string[0];
        settextstyle(0, 0, 1);
        outtextxy(getmaxx()/2,y,ptr2);
    }
    else if (trig_equation>=-0.2+factor*shift && trig_equation<=0.2+factor*shift)
    {
        string int_xlabel_to_string = to_string(xaxis_angle_label);
        char*ptr=&int_xlabel_to_string[0];
        outtextxy(x-5, getmaxy()/2,ptr);
        settextstyle(0, 0, 1);
        xaxis_angle_label=xaxis_angle_label+90/phase;
    }
    else if(trig_equation>=-(amp*factor)-0.1+factor*shift && trig_equation<=-(amp*factor)+0.1+factor*shift)
    {
        string int_xlabel_to_string = to_string(xaxis_angle_label);
        char*ptr1=&int_xlabel_to_string[0];
        outtextxy(x-5, getmaxy()/2,ptr1);
        settextstyle(0, 0, 1);
        xaxis_angle_label=xaxis_angle_label+90/phase;

        if ((amp*cos(phase*angle*3.142/180)+shift)<0)
        {
            decimal_error_correction=-0.5;
        }
        else
        {
            decimal_error_correction=0.5;
        }
        yaxis_amp_label=(amp*cos(phase*angle*3.142/180)+shift)+decimal_error_correction;
        string int_ylabel_to_string=to_string(yaxis_amp_label);
        char*ptr2=&int_ylabel_to_string[0];
        settextstyle(0, 0, 1);
        outtextxy(getmaxx()/2,y,ptr2);
    }



  putpixel(x, y, 15);

 angle+=5;
 }



 cout<<endl<<endl<<"Enter any key to minimize the graphic window: ";
    string minimize;
    cin>>minimize;
    if(minimize=="m")
        closegraph();
    else
        closegraph();

}
/* alot of code is carried the only difference is xaxis is only labelled at infinity and and where tan is zero
The code not used from sine and cos is marked purple, */
void tan_graph() {
    int gd = DETECT, gm;
    double x, y,trig_equation;
    int angle=0;
    int xaxis_angle_label=0;
    int amp=0;
    int shift=0;
    int yaxis_amp_label=0;
    int factor=0;
    int phase=0;
    cout<<endl<<"General Form: Atan(Bx)+C"<<endl;
    cout<<"Enter A (amplitude): ";
    cin>>amp;
    if_integer_input_fails(amp);
    cout<<"Enter B (phase): ";
    cin>>phase;
    if_integer_input_fails(shift);
    cout<<"Enter C (shift): ";
    cin>>shift;
    if_integer_input_fails(shift);
    double decimal_error_correction=0;
    if(abs(amp)<=2 && shift<=2)
    {
         factor=50;
    }
    else if(abs(amp)<=4 && shift<=4)
    {
         factor=25;

    }
    else if(abs(amp)<=6 && shift<=6)
    {
        factor=10;
    }
    else
    {
        factor=5;
    }

initgraph(&gd, &gm, "");
line(getmaxx()/2,getmaxy(),getmaxx()/2,0);
line(0, getmaxy() / 2, getmaxx(), getmaxy() / 2);

 for(x = getmaxx()/2; x < getmaxx(); x+=3) {
      if(xaxis_angle_label>=405){break;}

     trig_equation = factor*(amp*tan(phase*angle*3.141/180)+shift);
     y = getmaxy()/2 - trig_equation;
     if(trig_equation>=((amp*factor-0.1+factor*shift)) && trig_equation<=(amp*factor+factor*shift+0.1))  // range where tan is amp+shift
     {



        /**string int_xlabel_to_string = to_string(xaxis_angle_label);     // this code was in sine cos marking xaxis
        char*ptr1=&int_xlabel_to_string[0];                                // when sin and cos were equal to amp+shift
        settextstyle(0, 0, 1);                                             // here we only label when infinity or zero so dont use this code
        outtextxy(x-5, getmaxy()/2,ptr1);
        xaxis_angle_label=xaxis_angle_label+45/phase;*/

        if((amp*tan(phase*angle*3.142/180)+shift)<0)
        {
            decimal_error_correction=-0.5;
        }
        else
        {
            decimal_error_correction=0.5;
        }
        yaxis_amp_label=(amp*tan(phase*angle*3.142/180)+shift)+decimal_error_correction; // yamp labeled where tan is = amp+shift
        string int_ylabel_to_string=to_string(yaxis_amp_label);
        char*ptr2=&int_ylabel_to_string[0];
        settextstyle(0, 0, 1);
        outtextxy(getmaxx()/2,y,ptr2);
    }
    else if (abs(trig_equation)>=9999) // range where tan goes infinity
    {
        // xaxis labeling only done where tan goes infinity and zero
        string int_xlabel_to_string = to_string(xaxis_angle_label);
        char*ptr=&int_xlabel_to_string[0];
        outtextxy(x-5, getmaxy()/2,ptr);
        settextstyle(0, 0, 1);
        xaxis_angle_label=xaxis_angle_label+90/phase;
    }
     else if (trig_equation>=-0.2+factor*shift && trig_equation<=0.2+factor*shift) //range where tan goes zero
    {   //tan xaxis only labeled where zero or infinity
        string int_xlabel_to_string = to_string(xaxis_angle_label);
        char*ptr=&int_xlabel_to_string[0];
        outtextxy(x-5, getmaxy()/2,ptr);
        settextstyle(0, 0, 1);
        xaxis_angle_label=xaxis_angle_label+90/phase;
    }
    else if(trig_equation>=-(amp*factor)-0.1+factor*shift && trig_equation<=-(amp*factor)+0.1+factor*shift) // range where tan is -amp+shift
    {
        /**string int_xlabel_to_string = to_string(xaxis_angle_label);    // same thing only used in sin cos
        char*ptr1=&int_xlabel_to_string[0];                               // in tan we only label at zero or infinity
        outtextxy(x-5, getmaxy()/2,ptr1);
        settextstyle(0, 0, 1);
        xaxis_angle_label=xaxis_angle_label+45/phase;*/

        if ((amp*tan(phase*angle*3.142/180)+shift)<0)
        {
            decimal_error_correction=-0.5;
        }
        else
        {
            decimal_error_correction=0.5;
        }
        yaxis_amp_label=(amp*tan(phase*angle*3.142/180)+shift)+decimal_error_correction;  //yaxis labeling at these point
        string int_ylabel_to_string=to_string(yaxis_amp_label);
        char*ptr2=&int_ylabel_to_string[0];
        settextstyle(0, 0, 1);
        outtextxy(getmaxx()/2,y,ptr2);
    }


     // put pixels at x and y position
  putpixel(x, y, 15);

 angle+=5;
 }


 cout<<endl<<endl<<"Enter any key to minimize the graphic window: ";
    string minimize;
    cin>>minimize;
    if(minimize=="m")
        closegraph();
    else
        closegraph();

}

void trignometric_graphs()
{
    display_trignometric_graphs();
    string option;
    cout<<"Enter option or \"q\" to quit: ";
    cin>>option;
    while(option!="q")
    {   if(option=="1")
        {
            sin_graph();
        }
        if (option=="2")
        {
            cos_graph();
        }
        if(option=="3")
        {
            tan_graph();
        }
        display_trignometric_graphs();
        cout<<endl<<"Enter option or \"q\" to quit: ";
        cin>>option;

    }


}

/**MATRIX OPERATIONS*/

//function generates the matrix by taking input from user
vector<vector<double>> generate_matrix(int rows, int columns) {
    vector<vector<double>> matrix; //matrix vector declared
    double value;
    cout << "Enter matrix elements" << endl;
    for(int i=0; i<rows; i++) {
        vector<double> temp; //temp vector stores elements for each row
        for(int j=0; j<columns; j++) {
            cout << "matrix element ["<<i<<"]["<<j<<"]: ";
            cin >> value; //input is taken here
            temp.push_back(value); //input is added to the temp vector
        }
        matrix.push_back(temp); //temp vector is added to the matrix vector
    }
    return matrix;
}

//simply displays the matrix by iterating through the rows and columns
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
    vector<vector<double>> matrixAB; //multiplication matrix declared here
    for(int i=0; i<rowsA; i++) {
        vector<double> temp; //temp vector declared here
        for(int j=0; j< columnsB; j++) {
            double total = 0;
            for(int k=0; k<columnsB; k++) {
                total += matrixA[i][k] * matrixB[k][j]; //the result of the multiplication is stored in total
            }
            temp.push_back(total); //values of total are added to temp
        }
        matrixAB.push_back(temp); //temp is added back to the multiplication matrix
    }
    return matrixAB;
}

//function which performs matrix addition
vector<vector<double>> matrix_addition(vector<vector<double>> matrixA, vector<vector<double>>matrixB, int rowsA, int columnsA) {
    vector<vector<double>> sum_matrix; //sum matrix declared here
    for(int i=0; i<rowsA; i++) {
        vector<double> temp; //temp vector declared here
        for(int j=0; j<columnsA; j++) {
            double sum = matrixA[i][j] + matrixB[i][j]; //value of sum is evaluated for each index and added to temp
            temp.push_back(sum);
        }
        sum_matrix.push_back(temp); //temp is added to the sum matrix
    }
    return sum_matrix;
}

//function which performs matrix subtraction
vector<vector<double>> matrix_subtraction(vector<vector<double>> matrixA, vector<vector<double>>matrixB, int rowsA, int columnsA) {
    vector<vector<double>> difference_matrix; //difference matrix declared here
    for(int i=0; i<rowsA; i++) {
        vector<double> temp; //temp vector declared
        for(int j=0; j<columnsA; j++) {
            double difference = matrixA[i][j] - matrixB[i][j]; //value of difference is evaluated for each index and added to temp
            temp.push_back(difference); //temp is added back to the difference matrix
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
    for (int i=0; i<n-1; i++) {    //loop generates sub-matrices and determines their determinants
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
            for (int j=i;j<n; j++)
                matrix[r][j] -= multiple * matrix[i][j];
        }
      determinant *= pivot;
   }
   determinant *= matrix[n-1][n-1]; //allows for program to calculate the determinant for any n by n matrix
   return determinant;
}

void matrix_operation() {
string input; //input from the user is stored
do{

    cout << "What operation do you want to perform?" << endl;
    cout << "Enter 1 to multiply two matrices" << endl;
    cout << "Enter 2 to add two matrices" << endl;
    cout << "Enter 3 to subtract two matrices" << endl;
    cout << "Enter 4 to calculate the determinant of a matrix" << endl;
    cout << "Enter q to quit" << endl;
    cout << "Enter your option: ";
    cin >> input;

    if(input == "1") {
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

    else if(input == "2") {
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

    else if(input == "3") {
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

    else if(input == "4") {
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
    else if(input=="q")
    {
        cout<<endl<<":)"<<endl;
    }
    else
    {
        cout<<endl<<endl<<"Invalid Input"<<endl<<endl;
    }

}
while(input!="q");
}
/** PnC operations*/

// evaluates factorial of number which user input
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
  permutation = factorial(n)/factorial(d); //computes number of possible permutations
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
  combination = factorial(n)/(factorial(d)*factorial(r)); //computes the number of possible combination
  cout << "The number of possible combinations are " << combination << endl;
}

int PnC_operation() {
  string input;
do{
  cout << "What operation do you want to perform?" << endl;
  cout << "Enter 1 to compute the factorial of a number" << endl;
  cout << "Enter 2 to compute the number of possible permutations" << endl;
  cout << "Enter 3 to compute the number of possible combinations" << endl;
  cout << "Enter q to quit" << endl;
  cout << "Enter your option: ";
  cin >> input;

  if(input == "1") {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;
    cout << n << " factorial is " << factorial(n) << endl;
  }
  else if(input == "2")
    permutations();
  else if(input == "3")
    combinations();
  else if(input=="q")
  {
      cout<<endl<<":)"<<endl;
  }
  else
  {
      cout<<endl<<"Invalid input"<<endl<<endl;
  }

}
while(input!="q");
}


/** Integration operation*/

//generates numerical values for the function user choose
double numerical_value(double x, int input) {
  double function; //numerical function values are returned into this variable
  if(input == 1)
    function = x*x;
  else if(input == 2)
    function = x*x*x;
  else if(input == 3)
    function = sin(x);
  else if(input == 4)
    function = cos(x);
  else if(input == 5)
    function = sqrt(x);
  else if(input == 6)
    function = exp(x);
  else if(input == 7)
    function = log(x);
  return function;
}


//Integration Function
void integral(double x,int input) {
  double reimann_sum = 0; //numerical integral value
  double upper_limit; //upper limit of integration
  double lower_limit; //lower limit of integration
  cout << "Enter lower limit: ";
  cin >> lower_limit;
  cout << "Enter upper limit: ";
  cin >> upper_limit;
  int n = 100000; //number of rectangles - the more the more accurate the value of the integral
  double dx = (upper_limit-lower_limit)/n; //dx is the width of one small rectangle
  for (int i=0; i<=n; i++) { //loop performs the integration
    double xi = lower_limit + (i * dx);
    double function_value = numerical_value(xi, input);
    double area = function_value * dx;
    reimann_sum += area;
  }
  cout << "The integral is: " << fixed << setprecision(5) << reimann_sum << endl;
}

int Integration_operation() {
  double x;
  int input;
  cout<<endl<<endl;
  cout << "Enter 1 to integrate x^2" << endl;
  cout << "Enter 2 to integrate x^3" << endl;
  cout << "Enter 3 to integrate sin(x)" << endl;
  cout << "Enter 4 to integrate cos(x)" << endl;
  cout << "Enter 5 to integrate sqrt(x)" << endl;
  cout << "Enter 6 to integrate e^x" << endl;
  cout << "Enter 7 to integrate ln(x)" << endl;
  cout << "Enter q to quit" << endl;
  cout << "Enter the function you want to integrate from the options above: ";
  while(cin >> input)
  {
     if(input<=7)
    {
        integral(x,input);
    }
    else
    {
        cout<<endl<<endl<<"Invalid Input"<<endl;
    }
    cout<<endl<<endl;
    cout << "Enter 1 to integrate x^2" << endl;
    cout << "Enter 2 to integrate x^3" << endl;
    cout << "Enter 3 to integrate sin(x)" << endl;
    cout << "Enter 4 to integrate cos(x)" << endl;
    cout << "Enter 5 to integrate sqrt(x)" << endl;
    cout << "Enter 6 to integrate e^x" << endl;
    cout << "Enter 7 to integrate ln(x)" << endl;
    cout << "Enter q to quit" << endl;
    cout << "Enter the function you want to integrate from the options above: ";

  }
  if(cin.fail())
  {
      cin.clear();
      string dummy;
      getline(cin,dummy);
  }
}
/** main station*/
int main()
{
    display_frontscreen();
    int option;
    main_display();
    cout<<"Enter Option Number or any letter to exit: ";
    while(cin>>option) //runs till letter entered
    {
        cout<<endl;
        if(option==1){
            arthmetics();}
        else if(option==2){
            solutions_of_eq();}
        else if(option==3){
            trignometric_graphs();}
        else if (option==4)
        {
            Integration_operation();
        }
        else if(option==5)
        {
            matrix_operation();
        }
        else if(option==6)
        {
            PnC_operation();
        }
        else{
            cout<<"Invalid Option"<<endl<<endl;}
        main_display();
        cout<<"Enter Option Number or any letter to exit: ";

    }
    return 0;

}
