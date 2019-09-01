//
//#include <opencv2/core/core.hpp>
//#include <opencv2/highgui/highgui.hpp>
//#include "opencv2/imgproc/imgproc.hpp"
//#include "opencv2/imgcodecs.hpp"
//#include <iostream>
//
//using namespace std;
//using namespace cv;
//
//Mat src, erosion_dst, dilation_dst, resultImg;
//
//int dilation_size = 2;
//int erosion_size = 1;
//
//vector<Rect> detectLetters(cv::Mat img);
//void Erosion( int, void* );
//void Dilation( int, void* );
//
//int main()
//{
//
//	src = imread( "/home/lokesh/Desktop/3.jpg", 1);
//	if(src.empty())
//	{
//		cout << "No source iamge" << endl;
//	}
//	src.copyTo(resultImg);
//
//
//	Mat img;
//	Size size( (src.cols*1), (src.rows*1) );//the dst image size,e.g.100x100
//	resize(src, src, size);
//	//  img.copyTo(src);
//	imshow( "Display Image", src);
//
////	Dilation (0,0);
////	Erosion (0,0);
////
////	vector<Rect> textBoxes=detectLetters(erosion_dst);
////	cout << "rectangles: " << textBoxes.size();
////
////	for(int i=0; i< textBoxes.size(); i++)
////		rectangle(erosion_dst, textBoxes[i], Scalar(0,255,0),3,8,0);
////
////	imwrite( "/home/lokesh/Desktop/result.jpg", erosion_dst);
////    imshow("Result", erosion_dst);
//	waitKey(0);
//	return 0;
//}
//
//vector<Rect> detectLetters(Mat img)
//{
//	vector<cv::Rect> boundRect;
//	Mat img_gray, img_sobel, img_threshold, element;
//
//	cvtColor(img, img_gray, COLOR_BGR2GRAY);
//	//    imshow("Gray", img_gray); waitKey(0);
//	Sobel(img_gray, img_sobel, CV_8U, 1, 0, 3, 1, 0, cv::BORDER_DEFAULT);
//
////	imshow ("Sobel", img_sobel); waitKey(0);
//	threshold(img_sobel, img_threshold, 0, 255, THRESH_BINARY+THRESH_OTSU);
//
//	element = getStructuringElement(cv::MORPH_RECT, cv::Size(37, 3) );
//	morphologyEx(img_threshold, img_threshold, MORPH_CLOSE, element); //Does the trick
//
//	vector< std::vector< cv::Point> > contours;
//
//	findContours(img_threshold, contours, 0, 1);
//	vector<std::vector<cv::Point> > contours_poly( contours.size() );
//
//	for( unsigned int i = 0; i < contours.size(); i++ )
//		if (contours[i].size()>100)
//		{
//			cv::approxPolyDP( cv::Mat(contours[i]), contours_poly[i], 3, true );
//			cv::Rect appRect( boundingRect( cv::Mat(contours_poly[i]) ));
//
//			if (appRect.width > appRect.height)
//				boundRect.push_back(appRect);
//		}
//	return boundRect;
//}
//
//void Erosion( int, void* )
//{
//	Mat element = getStructuringElement( MORPH_RECT,
//			Size( 2*erosion_size + 1, 2*erosion_size+1 ),
//			Point( erosion_size, erosion_size ) );
//
//	erode( dilation_dst, erosion_dst, element );
//	imshow( "Erosion Demo", erosion_dst );
//	imwrite("/home/lokesh/Desktop/errodedImg.jpg", erosion_dst);
//	//	waitKey(0);
//}
//
//void Dilation( int, void* )
//{
//	Mat element = getStructuringElement( MORPH_RECT,
//			Size( 2*dilation_size + 1, 2*dilation_size+1 ),
//			Point( dilation_size, dilation_size ) );
//	dilate( src, dilation_dst, element );
//	imshow( "Dilation Demo", dilation_dst );
//	imwrite("/home/lokesh/Desktop/dilatedImg.jpg", dilation_dst);
//	//	waitKey(0);
//}
