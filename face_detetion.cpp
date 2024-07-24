#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

//adding a new feature to adding a sticker as soon as a face is detected
//below id the function for overly a sticker.s
void overlaySticker(Mat &background, Mat &sticker, Rect face) {
    // Resize the sticker to fit the detected face
    Mat resizedSticker;
    resize(sticker, resizedSticker, Size(face.width, face.height));

    // Determine the region of interest (ROI) on the background where the sticker will be placed
    Mat roi = background(Rect(face.x, face.y, resizedSticker.cols, resizedSticker.rows));

    // Create a mask of the sticker and its inverse mask
    Mat stickerGray, mask, maskInv;
    cvtColor(resizedSticker, stickerGray, COLOR_BGR2GRAY);
    threshold(stickerGray, mask, 10, 255, THRESH_BINARY);
    bitwise_not(mask, maskInv);

    // Black-out the area of the sticker in the ROI
    Mat backgroundROI;
    roi.copyTo(backgroundROI);
    backgroundROI.setTo(Scalar::all(0), mask);

    // Take only the region of the sticker from the sticker image
    Mat stickerRegion;
    resizedSticker.copyTo(stickerRegion, mask);

    // Put the sticker in the ROI and modify the background image
    add(backgroundROI, stickerRegion, roi);
}

int main() {
    // Load the Haar cascade classifier for face detection
    CascadeClassifier faceCascade;
    if (!faceCascade.load("path/to/haarcascade_frontalface_default.xml")) {
        cerr << "Error: Couldn't load Haar cascade classifier." << endl;
        return -1;
    }

    // Load the sticker image
    Mat sticker = imread("path/to/sticker.png", IMREAD_UNCHANGED);
    if (sticker.empty()) {
        cerr << "Error: Couldn't load sticker image." << endl;
        return -1;
    }

    // Open the webcam or load a video file
    VideoCapture cap(0); // 0 for default webcam, change to video file path if needed
    if (!cap.isOpened()) {
        cerr << "Error: Couldn't open camera or video file." << endl;
        return -1;
    }

    Mat frame;
    while (cap.read(frame)) {
        // Convert the frame to grayscale
        Mat grayFrame;
        cvtColor(frame, grayFrame, COLOR_BGR2GRAY);

        // Detect faces
        vector<Rect> faces;
        faceCascade.detectMultiScale(grayFrame, faces, 1.1, 4, 0, Size(30, 30));

        // Overlay sticker on each detected face
        for (const auto &face : faces) {
            overlaySticker(frame, sticker, face);
        }

        // Display the frame with detected faces and stickers
        imshow("Face Detection with Sticker", frame);

        // Exit on ESC key press
        if (waitKey(1) == 27) {
            break;
        }
    }

    cap.release();
    destroyAllWindows();

    return 0;
}
