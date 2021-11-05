#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <string>

int main (int argc, char** argv) {

    //make windows
    cv::namedWindow("Video", cv::WINDOW_AUTOSIZE);

    // capture video
    cv::VideoCapture cap;
    cap.open(std::string(argv[1]));

    //make frame for video
    cv::Mat frame;

    //loop thru video frames
    for(;;) {
        cap >> frame;
        if (frame.empty()) break;
        cv::imshow("Video", frame);

        // waitkey to break
        if (cv::waitKey(33) >= 0) break;
    }

    return 0;
}