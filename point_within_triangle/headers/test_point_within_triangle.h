#ifndef TEST_POINT_INSIDE_TRIANGLE
#define TEST_POINT_INSIDE_TRIANGLE

#include <stdio.h>
#include "point_within_triangle.h"

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define DEFAULT "\033[0m"

int test_is_point_inside(Point corner1, Point corner2, Point corner3, Point point, int inside);
int test_get_area(Point corner1, Point corner2, Point corner3, double area);
int test_get_perimeter(double side1, double side2, double side3);
int test_get_length_of_side(Point point1, Point point2, double distance);
int are_decimals_equal(double decimal1, double decimal2);
int test_get_point(int x, int y);
void print_result(int passed);
void set_color(char *color);

#endif
