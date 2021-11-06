#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <fstream>

using namespace std;

int g_slide_position = 0;
int g_run = 1;
int g_dontset = 0;

cv::VideoCapture g_cap;

//trackbar callback
void onTrackbarSlide(int pos, void *) {
    g_cap.set(cv::CAP_PROP_POS_FRAMES, pos);

    if (!g_dontset)
        g_run = 1;
    g_dontset = 0;
}

int main(int argc, char** argv) {
    cv::namedWindow("Trackbar", cv::WINDOW_AUTOSIZE);
    g_cap.open(string(argv[1]));
    int frames = (int) g_cap.get(cv::CAP_PROP_FRAME_COUNT);
    int tmpw = (int) g_cap.get(cv::CAP_PROP_FRAME_WIDTH);
    int tmph = (int) g_cap.get(cv::CAP_PROP_FRAME_HEIGHT);

    cout << "Video has: " << frames << endl;
    cout << "Frame Dimentions: " << "(" << tmpw << ", " << tmph << ")" << endl;

    cv::createTrackbar("Position", "Trackbar", &g_slide_position, frames, onTrackbarSlide);

    cv::Mat frame;
    for (;;) {
        if (g_run != 0) {
            g_cap >> frame;
            if (frame.empty()) break;
            int current_pos = (int) g_cap.get(cv::CAP_PROP_POS_FRAMES);
            g_dontset = 1;

            // set trackbar and show video
            cv::setTrackbarPos("Position", "Trackbar", current_pos);
            cv::imshow("Trackbar", frame);

            g_run = -1;
        }
    
    char c = (char) cv::waitKey(10);
    if (c=='s') {
        g_run = 1;
        cout << "Single step, run = " << g_run << endl;
    } if (c=='r') {
        g_run = -1;
        cout << "Run mode, run = " << g_run << endl;
    } if (c=27) break;

    }
    return(0);

}
