#include "network_analysis.h"
#include <iostream>
#include <math.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#define M_PI 2 * acos(0.0)
using namespace cv;
using namespace std;
#define MAX_NODE_NUMBER 100
#define STATE_GRAPH_RADIUS 300
void calculateArrow(Point p_start, Point p_end, Point &p_new_start, Point &p_new_end, double radius)
{
    double xdiff = (p_end.x - p_start.x);
    double ydiff = (p_end.y - p_start.y);

    if (p_end.x == p_start.x)
    {
        if (p_end.y > p_start.y)
        {
            p_new_end.y = p_end.y - (int)ceil(radius);
            p_new_start.y = p_start.y + (int)ceil(radius);
        }
        else
        {
            p_new_end.y = p_end.y + (int)ceil(radius);
            p_new_start.y = p_start.y - (int)ceil(radius);
        }

        p_new_start.x = p_start.x;
        p_new_end.x = p_end.x;
    }
    else if (p_end.y == p_start.y)
    {
        if (p_end.x > p_start.x)
        {
            p_new_end.x = p_end.x - (int)ceil(radius);
            p_new_start.x = p_start.x + (int)ceil(radius);
        }
        else
        {
            p_new_end.x = p_end.x + (int)ceil(radius);
            p_new_start.x = p_start.x - (int)ceil(radius);
        }
        p_new_start.y = p_start.y;
        p_new_end.y = p_end.y;
    }
    else if (p_end.y > p_start.y && p_end.x > p_start.x)
    {
        double slope = atan2(ydiff, xdiff);
        p_new_end.y = p_end.y - (int)ceil(radius * sin(slope));
        p_new_start.y = p_start.y + (int)ceil(radius * sin(slope));
        p_new_end.x = p_end.x - (int)ceil(radius * cos(slope));
        p_new_start.x = p_start.x + (int)ceil(radius * cos(slope));
    }
    else if (p_end.y < p_start.y && p_end.x < p_start.x)
    {
        double slope = atan2(ydiff, xdiff) + M_PI;
        p_new_end.y = p_end.y + (int)ceil(radius * sin(slope));
        p_new_start.y = p_start.y - (int)ceil(radius * sin(slope));
        p_new_end.x = p_end.x + (int)ceil(radius * cos(slope));
        p_new_start.x = p_start.x - (int)ceil(radius * cos(slope));
    }
    else if (p_end.y > p_start.y && p_end.x < p_start.x)
    {
        double slope = atan2(ydiff, xdiff) + M_PI;
        p_new_end.y = p_end.y + (int)ceil(radius * sin(slope));
        p_new_start.y = p_start.y - (int)ceil(radius * sin(slope));
        p_new_end.x = p_end.x + (int)ceil(radius * cos(slope));
        p_new_start.x = p_start.x - (int)ceil(radius * cos(slope));
    }
    else if (p_end.y < p_start.y && p_end.x > p_start.x)
    {
        double slope = atan2(ydiff, xdiff);
        p_new_end.y = p_end.y - (int)ceil(radius * sin(slope));
        p_new_start.y = p_start.y + (int)ceil(radius * sin(slope));
        p_new_end.x = p_end.x - (int)ceil(radius * cos(slope));
        p_new_start.x = p_start.x + (int)ceil(radius * cos(slope));
    }
    else
    {
        return;
    }
}
void drawArrow(Mat image, Point p_start, Point p_end, int thickness, double radius)
{
    Point p_new_start;
    Point p_new_end;
    calculateArrow(p_start, p_end, p_new_start, p_new_end, radius);
    double angle = atan2(p_end.y - p_start.y, p_end.x - p_start.x) + M_PI;
    Point p_side1(p_new_end.x + (int)ceil(20 * cos(angle - (M_PI / 6))), p_new_end.y + (int)ceil(20 * sin(angle - (M_PI / 6))));
    Point p_side2(p_new_end.x + (int)ceil(20 * cos(angle + (M_PI / 6))), p_new_end.y + (int)ceil(20 * sin(angle + (M_PI / 6))));
    line(image, p_new_start, p_new_end, Scalar(0, 0, 255), thickness, LINE_8);
    line(image, p_new_end, p_side1, Scalar(0, 0, 255), thickness, LINE_8);
    line(image, p_new_end, p_side2, Scalar(0, 0, 255), thickness, LINE_8);
}
void drawNodes(Mat image, int number_of_nodes, Point points[], double radius)
{
    double temp = 0;
    Point temp_point;
    for (int i = 0; i < number_of_nodes; i++)
    {
        temp = STATE_GRAPH_RADIUS * cos(2 * i * M_PI / (double)number_of_nodes);
        points[i].x = (int)ceil((400.0 + 800 * pow(2, -number_of_nodes)) + temp);
        temp = STATE_GRAPH_RADIUS * sin(2 * i * M_PI / (double)number_of_nodes);
        points[i].y = (int)ceil(400.0 + temp);
        temp_point.x = points[i].x - 5 - 20 * ((double)number_of_nodes) * pow(2, -(double)number_of_nodes / 2.0);
        temp_point.y = points[i].y + 5 + 5 * ((double)number_of_nodes) * pow(2, -(double)number_of_nodes / 2.0) + 10 * ((double)number_of_nodes) * pow(2, -number_of_nodes);
        circle(image, points[i], (int)ceil(radius), Scalar(76, 153, 0), FILLED, LINE_8);
        putText(image, to_string(i + 1), temp_point, FONT_HERSHEY_DUPLEX, (10.0 / (double)(number_of_nodes)), Scalar(255, 0, 0), (10.0 / (double)(number_of_nodes)), LINE_AA);
    }
}

void connectUsers(Mat image, int mat[][100], int number_of_nodes, Point points[], int line_thickness, double radius)
{
    for (int i = 0; i < number_of_nodes; i++)
    {

        for (int j = 0; j < number_of_nodes; j++)
        {
            if (j == i)
            {
                continue;
            }
            if (mat[i][j] == 1)
            {
                drawArrow(image, points[i], points[j], line_thickness, radius);
            }
        }
    }
}

GraphAnalysis::GraphAnalysis(int arr[100][100], int number_of_nodes, string output_file_name)
{
    Mat image(800, 1800, CV_8UC3, Scalar(0, 0, 0));

    if (!image.data)
    {
        cout << "Could not open or find"
             << " the image";

        return;
    }

    int line_thickness = 1;
    if (number_of_nodes >= 9)
    {
        line_thickness = 1;
    }
    else
    {
        line_thickness = 2;
    }

    double radius = (double)(11000.0 / (32 * number_of_nodes));
    Point points[MAX_NODE_NUMBER];
    drawNodes(image, number_of_nodes, points, radius);
    connectUsers(image, arr, number_of_nodes, points, line_thickness, radius);
    //imshow("Output", image);
    imwrite(output_file_name, image);
   // waitKey(0);

    return;
}
