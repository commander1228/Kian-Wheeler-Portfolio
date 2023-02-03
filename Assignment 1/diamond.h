/* Kian Wheeler
 *  COP3330 section 10
 * Assignment 1
 * The project utilizes an object for a main file, files include a header fill and cpp file
 * this project will take inputs from the main file and create, mutate, and access
 * different members and member data of the object
 * 1/31/2023
 */

#ifndef DIAMOND_DIAMOND_H
#define DIAMOND_DIAMOND_H

//Diamond class
class Diamond {
public:
    //constructor, paramaters for border and char include default values
    Diamond(int size,char border = '#', char fill = '*' );

    //accessors
    int GetSize() const; //accessor for size
    int Perimeter()const; // accessor for perimetter
    double Area()const; //accessor for Area is double due to decimals
    void Draw()const; //Draw function which prints the diamond onto the screen
    void Summary()const; //summary function that displays the data of the other accessors
                        // as well as calling the draw function
    //mutators
    void Grow(); //mutator that increases sidelength by 1 if within accepted ranges
    void Shrink(); //mutator that decreases sidelength by 1 if within accepted ranges
    void SetBorder(char NewBorder); //changes the Border character to parameter if in given ranges
    void SetFill(char NewFill); //changes the fill character to paramter if in given ranges



private:
    //Member data for the class
    int sidelength;
    char borderchar;
    char fillchar;

};


#endif //DIAMOND_DIAMOND_H
