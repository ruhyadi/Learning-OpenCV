#include "opencv2/opencv.hpp"
#include <iostream>

int main (int argc, char** argv) {
    //make windows
    cv::namedWindow("camera", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("log-polar", cv::WINDOW_AUTOSIZE);

    cv::Mat camera, log_polar;

    //capture video
    cv::VideoCapture cap("nvarguscamerasrc sensor-id=0 ! video/x-raw(memory:NVMM), width=640, height=480, format=(string)NV12, framerate=(fraction)20/1 ! nvvidconv flip-method=2 ! video/x-raw, width=640, height=480, format=(string)BGRx ! videoconvert ! video/x-raw, format=(string)BGR ! appsink", cv::CAP_GSTREAMER);
    
    //get video parameter
    double fps = cap.get(cv::CAP_PROP_FPS);
    cv::Size size(
        (int) cap.get(cv::CAP_PROP_FRAME_WIDTH),
        (int) cap.get(cv::CAP_PROP_FRAME_HEIGHT)
    );

    cv::VideoWriter writer;
    writer.open(argv[1], cv::VideoWriter::fourcc('M','J','P','G'), fps, size);

    //loop thru video
    for(;;) {
        cap >> camera;
        if (camera.empty()) break;

        //log polar transforms
        cv::logPolar(
            camera,
            log_polar,
            cv::Point2f(
                camera.cols/2,
                camera.rows/2
            ),
            40,
            cv::WARP_FILL_OUTLIERS
        );

        //display
        cv::imshow("camera", camera);
        cv::imshow("log-polar", log_polar);

        //write
        writer << log_polar;

        //waitkey
        char c = cv::waitKey(10);
        if (c==27) break;
    }
    
    cap.release();
}