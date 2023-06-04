#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    
    CascadeClassifier face_cascade;
    face_cascade.load("D:/opencv455/opencv/sources/data/haarcascades/haarcascade_frontalface_default.xml");

    
    VideoCapture cap(0);
    if (!cap.isOpened()) {
        cout << "无法打开摄像头" << endl;
        return -1;
    }

    
    namedWindow("人脸识别", 1);

    while (1) {
        // 读取摄像头帧
        Mat frame;
        cap.read(frame);

        // 转换为灰度图像
        Mat gray;
        cvtColor(frame, gray, COLOR_BGR2GRAY);

        // 检测人脸
        vector<Rect> faces;
        face_cascade.detectMultiScale(gray, faces, 1.1, 2, 0 | CASCADE_SCALE_IMAGE, Size(30, 30));

        // 在每个检测到的人脸周围绘制矩形框
        for (int i = 0; i < faces.size(); i++) {
            rectangle(frame, faces[i], Scalar(0, 255, 0), 2);

            // 在矩形框上方显示人脸识别结果
            putText(frame, "Person " + to_string(i + 1), Point(faces[i].x, faces[i].y - 5), FONT_HERSHEY_SIMPLEX, 0.8, Scalar(0, 255, 0), 2);
        }

        imshow("人脸识别", frame);

        // 按下 q 键退出
        if (waitKey(1) == 'q') break;
    }

    return 0;
}