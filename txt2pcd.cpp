//
// Created by zfy on 2019/12/17.
//

#include <iostream>
#include <pcl/io/pcd_io.h>
#include <vector>
#include <string>
#include <pcl/point_types.h>


using namespace std;

int main(int argc, char** argv)
{
    typedef struct TXT_Point_XYZIC
    {
        double x;
        double y;
        double z;
        int label;
        int confidence;
    }TXT_Points;

    int num_txt;
    FILE *fp_txt;
    TXT_Point_XYZIC txt_points;
    vector<TXT_Point_XYZIC> vTXTPoints;
    fp_txt = fopen("test.txt", "r");

    if(fp_txt)
    {
        int i = 0;
        while(fscanf(fp_txt, "%lf %lf %lf %d %d", &txt_points.x, &txt_points.y, &txt_points.z, &txt_points.label, &txt_points.confidence) != EOF)
        {
            vTXTPoints.push_back(txt_points);
            i++;
            cout << "Reading number" << i << "point" << txt_points.x << " " << txt_points.y << " " << txt_points.z <<endl;
            sleep(0.01);
        }
    }
    else
    {
        cout << "error reading txt file" << endl;
    }

    num_txt = vTXTPoints.size();

    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);
    cloud->width = num_txt;
    cloud->height = 1;
    cloud->is_dense = false;
    cloud->points.resize(cloud->width * cloud->height);
    for(size_t i=0; i<cloud->points.size(); ++i)
    {
        cloud->points[i].x = vTXTPoints[i].x;
        cloud->points[i].y = vTXTPoints[i].y;
        cloud->points[i].z = vTXTPoints[i].z;
    }

    pcl::io::savePCDFileASCII("test.pcd", *cloud);
    cerr << "Writing " << cloud->points.size() << "data points " << endl;

    return 0;
}