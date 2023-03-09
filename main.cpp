#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main()
{
    // Open the camera
    // This can be replaced with code to read an image file
    // For example, you could use the following line of code:
    // Mat frame = imread("image.jpg", IMREAD_COLOR);

    // Take a picture with the camera
    // This can be replaced with code to read an image file
    // For example, you could use the following line of code:
    // Mat frame = imread("image.jpg", IMREAD_COLOR);
    Mat frame;
    //Code to read an image file
    ifstream file("image.jpg", ios::binary | ios::ate);
    streamsize size = file.tellg();
    file.seekg(0, ios::beg);
    vector<char> buffer(size);
    if (file.read(buffer.data(), size))
    {
        Mat img = imdecode(Mat(buffer), IMREAD_COLOR);
    }
    else
    {
        cerr << "Failed to read image file." << endl;
        return -1;
    }

    // Convert the image to grayscale
    Mat gray;
    cvtColor(frame, gray, COLOR_BGR2GRAY);

    // Resize the image to reduce the number of pixels
    // This will make the ASCII art more detailed
    Size size(100, 100);
    resize(gray, gray, size);

    // Create a string that contains the characters to use for the ASCII art
    // These characters should be ordered from darkest to lightest
    string asciiChars = "`^\",:;Il!i~+_-?][}{1)(|\\/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao*#MW&8%B@$";

    // Loop through the pixels in the image and convert them to ASCII characters
    for (int y = 0; y < gray.rows; y++)
    {
        for (int x = 0; x < gray.cols; x++)
        {
            // Get the grayscale value of the pixel
            int value = gray.at<uchar>(y, x);

            // Map the grayscale value to a character from the asciiChars string
            int index = (int)((float)value / 255.0f * (asciiChars.size() - 1));
            char character = asciiChars[index];

            // Print the character to the screen
            cout << character;
        }

        // Add a newline character at the end of each row
        cout << endl;
    }

    return 0;
}
