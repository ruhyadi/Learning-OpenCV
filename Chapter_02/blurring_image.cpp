#include "opencv2/opencv.hpp"

int main (int argc, char** argv) {

    //make windows
    cv::namedWindow("Before", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("After", cv::WINDOW_AUTOSIZE);

    // load image
    cv::Mat image = cv::imread(argv[1], -1);

    // transformation images
    cv::Mat out;

    // bluring
    cv::GaussianBlur(image, out, cv::Size(5,5), 3,3);

    // displaying result
    cv::imshow("Before", image);
    cv::imshow("After", out);

    //waitkey
    cv::waitKey(0);

    return 0;

}