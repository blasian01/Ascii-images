#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

int main()
{
    // Open the camera
    VideoCapture cap(0);
    if (!cap.isOpened())
    {
        cerr << "Failed to open the camera." << endl;
        return -1;
    }

    // Take a picture with the camera
    Mat frame;
    cap >> frame;

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
