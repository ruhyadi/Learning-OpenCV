#include "opencv2/opencv.hpp"

int main (int argc, char** argv) {
    // make windows
    cv::namedWindow("Before", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("After", cv::WINDOW_AUTOSIZE);

    cv::Mat image, out;

    // load image
    image = cv::imread(argv[1], -1);

    // transformation
    cv::pyrDown(image, out);

    //display
    cv::imshow("Before", image);
    cv::imshow("After", out);

    cv::waitKey(0);
    return(0);
}