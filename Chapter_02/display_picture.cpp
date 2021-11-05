// #include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

int main(int argc, char** argv) {
    // read image from argument
    cv::Mat img = cv::imread(argv[1], -1);
    if (img.empty()) return -1;

    // make windows and show image
    cv::namedWindow("Display Image", cv::WINDOW_AUTOSIZE);
    cv::imshow("Display Image", img);

    // wait to destroy window(s)
    cv::waitKey(0);
    cv::destroyWindow("Display Image");
    return 0;
}