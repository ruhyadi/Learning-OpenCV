#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <string>

int main (int argc, char** argv) {

    //make windows
    cv::namedWindow("Camera left", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("Camera right", cv::WINDOW_AUTOSIZE);

    // capture video
    cv::VideoCapture cam0("nvarguscamerasrc sensor-id=0 ! video/x-raw(memory:NVMM), width=640, height=480, format=(string)NV12, framerate=(fraction)20/1 ! nvvidconv flip-method=2 ! video/x-raw, width=640, height=480, format=(string)BGRx ! videoconvert ! video/x-raw, format=(string)BGR ! appsink", cv::CAP_GSTREAMER);
    cv::VideoCapture cam1("nvarguscamerasrc sensor-id=1 ! video/x-raw(memory:NVMM), width=640, height=480, format=(string)NV12, framerate=(fraction)20/1 ! nvvidconv flip-method=2 ! video/x-raw, width=640, height=480, format=(string)BGRx ! videoconvert ! video/x-raw, format=(string)BGR ! appsink", cv::CAP_GSTREAMER);

    //make frame for video
    cv::Mat frame0, frame1;

    //loop thru video frames
    for(;;) {
        cam0 >> frame0;
        cam1 >> frame1;
        if (frame0.empty()) break;

        cv::imshow("Camera left", frame0);
        cv::imshow("Camera right", frame1);

        // waitkey to break
        if (cv::waitKey(33) >= 0) break;
    }

    return 0;
}