//
// Created by zfy on 2019/12/17.
//

#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/filters/voxel_grid.h>


int main(int argc, char** argv)
{
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered (new pcl::PointCloud<pcl::PointXYZ>);

    pcl::PCDReader reader;
    reader.read("/home/zfy/PointCloudDataset/table_scene_mug_stereo_textured.pcd", *cloud);

    std::cerr << "Point cloud before filtering: " << cloud->height * cloud->width << "data points" << std::endl;

    pcl::VoxelGrid<pcl::PointXYZ> sor;
    sor.setInputCloud(cloud);
    sor.setLeafSize(0.01f, 0.01f, 0.01f);
    sor.filter(*cloud_filtered);

    std::cerr << "Point cloud after filtering: " << cloud_filtered->height * cloud_filtered->width << "data points" << std::endl;

    pcl::PCDWriter writer;
    writer.write("table_scene_mug_stereo_textured_downsampled.pcd", *cloud_filtered, false);

    return 0;
}