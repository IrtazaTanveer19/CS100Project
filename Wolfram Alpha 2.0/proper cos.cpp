#include<string>
#include<sstream>
#include<iostream>
#include<graphics.h>
#include<cmath>
using namespace std;
int main() {
    int gd = DETECT, gm;
    double x, y,s;
    int angle=0;
    int xaxis_angle_label=0;
    int amp=3;
    int shift=0;
    int yaxis_amp_label=0;
    int factor=0;
    int phase=2;
    double decimal_error_correction=0;
    if(abs(amp)<=2 && shift<=2)  // zero amp
    {
         factor=50;
    }
    else
    {
         factor=25;

    }


initgraph(&gd, &gm, "");
line(getmaxx()/2,getmaxy(),getmaxx()/2,0);
line(0, getmaxy() / 2, getmaxx(), getmaxy() / 2);
 /* generate a sine wave */
 for(x = getmaxx()/2; x < getmaxx(); x+=3) {

     if (xaxis_angle_label>=405){break;}
     s = factor*(amp*cos(phase*angle*3.141/180)+shift);
     y = getmaxy()/2 - s;
     if(s>=((amp*factor-0.1+factor*shift)) && s<=(amp*factor+factor*shift+0.1))  // int or double
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
    else if (s>=-0.2+factor*shift && s<=0.2+factor*shift)
    {
        string int_xlabel_to_string = to_string(xaxis_angle_label);
        char*ptr=&int_xlabel_to_string[0];
        outtextxy(x-5, getmaxy()/2,ptr);
        settextstyle(0, 0, 1);
        xaxis_angle_label=xaxis_angle_label+90/phase;
    }
    else if(s>=-(amp*factor)-0.1+factor*shift && s<=-(amp*factor)+0.1+factor*shift)
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
        yaxis_amp_label=(amp*cos(phase*angle*3.142/180)+shift)+decimal_error_correction;  // -0.5 remove decimal error
        string int_ylabel_to_string=to_string(yaxis_amp_label);
        char*ptr2=&int_ylabel_to_string[0];
        settextstyle(0, 0, 1);
        outtextxy(getmaxx()/2,y,ptr2);
    }


     /* color a pixel at the given position */
  putpixel(x, y, 15);

 angle+=5;
 }



 getch();

 /* deallocate memory allocated for graphics screen */
 closegraph();
}



