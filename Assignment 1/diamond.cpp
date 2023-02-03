/* Kian Wheeler
 *  COP3330 section 10
 * Assignment 1
 * The project utilizes an object for a main file, files include a header fill and cpp file
 * this project will take inputs from the main file and create, mutate, and access
 * different members and member data of the object
 * 1/31/2023
 */

#include <iostream>
#include "diamond.h"
#include "cmath"
#include "iomanip"


using namespace std;
//constructor
Diamond::Diamond(int size, char border, char fill)
{
  //side size
 sidelength = size;
 if(sidelength > 39){   //makes sure that the sides are within accepted values
     sidelength = 39;   //if not defaults to either 39 or 1
 }
 if (sidelength < 1){
     sidelength = 1;
 }

  borderchar = border;
  fillchar = fill;


}

//accessors

//draw function which prints diamond
void Diamond::Draw() const {
    //top half of diamond
    for (int i = 1; i <= sidelength; i++){ //given size iterates from 1 to size
        if (sidelength == 1){ //if sidelength is only 1 auto prints just the border
            cout<<borderchar;
        }else {
            for (int z = 1; z <= sidelength - i; z++){ //iterates to sidelength to determine how many spaces
                cout<<" ";
            }


            for (int x = 1; x <= i; x++) {
                if (x == 1)
                {
                cout<<borderchar<<" ";    //for each i iteration using elif commands
                }else if(x == i){         // determines whether to print border or fill character  
                    cout<<borderchar<<" ";
                }else {
                    cout<< fillchar<<" ";
                }

            }
        }
    cout<< endl;   //starts a new line for each iteration until the top half of diamond is made
    }
    // bottom half of diamond
    //utilizes same code as the top of diamond except iterates downwards and no autocheck for length 1
    if (sidelength > 1){
        for (int i = sidelength - 1; i >= 0; i--){
            if (sidelength == 1){
                cout<<borderchar;
            }else {
                for (int z = 1; z <= sidelength - i; z++){ 
                    cout<<" ";
                }


                for (int x = 1; x <= i; x++) {
                    if (x == 1)
                    {
                        cout<<borderchar<<" ";
                    }else if(x == i){
                        cout<<borderchar<<" ";
                    }else {
                        cout<< fillchar<<" ";
                    }

                }
            }
            cout<< endl;
        }





    }
}

int Diamond::GetSize() const
{
    return sidelength; //accessor that returns sidelength

}

int Diamond::Perimeter() const  //accessor that returns perimiter
{
  int rows = sidelength + (sidelength -1); //gets total number of rows
  int y = 2*(rows - 2);   //knowing that each row except for first and last has 2
  int perimeter = y + 2;  // subtracts 2 and multiples 2 then finally addes the two extra
    return perimeter + 4;
}
// accessor returns area
double Diamond::Area() const
{
    double a = sidelength/2;   //use pythag theorem a^2+b^2=c^2 reranging, then finding height
    double cc = pow(sidelength,2);
    double aa = pow(a,2);        //calculations
    double hypotenuse = sqrt(cc-aa);
    double Area = hypotenuse*sidelength;  //finally height * diagonal for area
    return Area;


}
//provides a summary of each member data as directed
void Diamond::Summary() const
{
    cout<<"Size of diamond's side = "<<GetSize()<<" units."<<endl;
    cout<<"Perimeter of diamond = "<<Perimeter()<<" units."<<endl;
    cout<<"Area of diamond = "<<fixed<<setprecision(2)<<Area()<<" units."<<endl;
    cout<<"Diamond looks like:"<<endl;
    Draw();
}

//mutators
//adds one to sidelenght
void Diamond::Grow()
{
    if (sidelength < 39) {   //checks that sidelenght wont leave upperbound defaults to 39 if nec.
        sidelength += 1;
    }else {
        sidelength = 39;
    }
}
//subtracts one from sidelength
void Diamond::Shrink()
{
    if (sidelength > 1) {
        sidelength -= 1;  //checks that sidelength wont leave lowerbound defaults to 1 if nec.
    } else {
        sidelength = 1;
    }
}
//changes the borderchar
void Diamond::SetBorder(char NewBorder)
{
    int ascii = int(NewBorder); //converts to ascii number
    if (NewBorder >= 33 & NewBorder <= 126) //checks that number is within range
    {
        borderchar = NewBorder;
    }else borderchar = '#'; //if not in range goes to defualt character

}
//changes the fill char
void Diamond::SetFill(char NewFill)
{
    int ascii = int(NewFill); //converts to ascii number
    if (NewFill >= 33 & NewFill <= 126) //checks that number is within range
    {
        fillchar = NewFill;
    }else fillchar = '*'; // if not in range goes to default fill char


}

