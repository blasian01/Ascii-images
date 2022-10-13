#include <iostream> 
#include <math.h>
#include <string>
using namespace std;

//main function
int main() 
{
    //intalizing variables
    const string density = "Ñ@#W$9876543210?!abc;:+=-,._ "; //acii to represent the pixel density
    ifstream image(".jpg"); 
    int height, width
    int r, g, b, grey;

    string filePath;
    string exportPath;


    // asking user to type in the file path to the photo they want to convert to ascii
    do
    {
        cout << "Please enter a file path to a photo: ";
        cin >> filePath;
    }
    while(filePath == true);  // if the path does not lead to a photo then ask the user to try again


    //ask user for a directory that they would like theyre photo to be exported to
    do
    {
        cout << "Please enter a file path to export to: ";
        cin >> exportPath;
    }
    while(exportPath == true);  // if the path does not lead to a photo then ask the user to try again


    //reading the pixels from the image that is selected
    for(int i = 0; i < positionX; i++)
    {
        for(int k = 0; k < positionY; k++)
        {

        }
    }

    //converting pixel value from rgb to grey scale for brightness 


    // replacing pixels with ascii 
    
    
    //rendering new image


    //pasting new image to a selcted directory

    cout << "Success" << endl;

    return 0;
}