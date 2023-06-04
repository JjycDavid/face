#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    
    CascadeClassifier face_cascade;
    face_cascade.load("D:/opencv455/opencv/sources/data/haarcascades/haarcascade_frontalface_default.xml");

    
    VideoCapture cap(0);
    if (!cap.isOpened()) {
        cout << "�޷�������ͷ" << endl;
        return -1;
    }

    
    namedWindow("����ʶ��", 1);

    while (1) {
        // ��ȡ����ͷ֡
        Mat frame;
        cap.read(frame);

        // ת��Ϊ�Ҷ�ͼ��
        Mat gray;
        cvtColor(frame, gray, COLOR_BGR2GRAY);

        // �������
        vector<Rect> faces;
        face_cascade.detectMultiScale(gray, faces, 1.1, 2, 0 | CASCADE_SCALE_IMAGE, Size(30, 30));

        // ��ÿ����⵽��������Χ���ƾ��ο�
        for (int i = 0; i < faces.size(); i++) {
            rectangle(frame, faces[i], Scalar(0, 255, 0), 2);

            // �ھ��ο��Ϸ���ʾ����ʶ����
            putText(frame, "Person " + to_string(i + 1), Point(faces[i].x, faces[i].y - 5), FONT_HERSHEY_SIMPLEX, 0.8, Scalar(0, 255, 0), 2);
        }

        imshow("����ʶ��", frame);

        // ���� q ���˳�
        if (waitKey(1) == 'q') break;
    }

    return 0;
}