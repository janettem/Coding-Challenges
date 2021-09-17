#include "point_within_triangle.h"

int is_point_inside_triangle(Point corner1, Point corner2, Point corner3, Point point)
{
    double area = get_area_of_triangle(corner1, corner2, corner3);
    double area1 = get_area_of_triangle(point, corner1, corner2);
    double area2 = get_area_of_triangle(point, corner2, corner3);
    double area3 = get_area_of_triangle(point, corner3, corner1);
    if (area1 + area2 + area3 == area)
        return TRUE;
    return FALSE;
}

double get_area_of_triangle(Point corner1, Point corner2, Point corner3)
{
    double a = get_length_of_side(corner1, corner2);
    double b = get_length_of_side(corner2, corner3);
    double c = get_length_of_side(corner3, corner1);
    double p = get_perimeter_of_triangle(a, b, c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

double get_perimeter_of_triangle(double side1, double side2, double side3)
{
    return side1 + side2 + side3;
}

double get_length_of_side(Point point1, Point point2)
{
    return sqrt(pow(point2.x - point1.x, 2) + pow(point2.y - point1.y, 2) * 1.0);
}

Point get_point(int x, int y)
{
    Point point;
    point.x = x;
    point.y = y;
    return point;
}
