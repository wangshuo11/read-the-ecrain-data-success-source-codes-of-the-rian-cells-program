#include <iostream>
#include <string>
#include <fstream>
#include<opencv2/opencv.hpp>
using namespace std;
const int rows = 281;             //define the size of Mat variable
const int cols = 361;
using namespace cv;

int main()
{
	string s;
	ifstream fp("F:\\12050108.003");

	if (!fp)
	{
		cerr << "OPEN ERROR" << endl;
		return 1;
	}
	
	Mat I0(282, 361, CV_32F);            //   initialize the  size and datatype of Mat variable
	int len_rows = 0, len_cols = 0;
	int len_s, x=0, y=0;
	 
	float num;
	
	ofstream out("F:\\1.txt");      //saveroute
	while (getline(fp, s))          //get a line of datas then ergodic and chartofloat
	{
		char buffer[20];
		len_s = s.length();
		for (int i = 0; i < len_s; i++) {
			if (s[i] != ' ') {
				buffer[y++] = s[i];
				if (i == len_s - 1||s[i+1]==' ') {
					y = 0;
					num = atof(buffer);          //chartofloat
					out << num << " ";           // save the num in the saveroute
					I0.at<float>(len_rows, len_cols)=num; 
					len_cols++;
					memset(buffer, 0, 20);         //clear the buffer 
					if (len_cols == 361) {         //if the float nums count to 361 ,then len_cols=0 and len_rows++ 
						len_cols = 0;
						len_rows++;
					}
				}
			}
		}
		out << endl;
		x = 0;
	}
	fp.close(); 
	cout << "len_cols=" << len_cols<< endl;
	cout << "len_rows="<<len_rows << endl;
	/* imshow the data by image without filtering */
	namedWindow("myimage", WINDOW_AUTOSIZE);
	imshow("myimage", I0);
	waitKey(0);
	
	return 0;
}

