#include "test_point_within_triangle.h"

//     2  .    P2
//     1 / \
// -1  0  1  2  3
//   /-1 P1    \
//  ._-2________.

int main()
{
    Point corner1 = get_point(1, 2);
    Point corner2 = get_point(-1, -2);
    Point corner3 = get_point(3, -2);
    double side1 = get_length_of_side(corner1, corner2);
    double side2 = get_length_of_side(corner2, corner3);
    double side3 = get_length_of_side(corner3, corner1);
    Point point_inside = get_point(1, -1);
    Point point_outside = get_point(3, 2);

    print_result(test_get_point(1, 2));
    print_result(test_get_perimeter(side1, side2, side3));
    print_result(test_get_length_of_side(corner1, corner2, 4.472136));
    print_result(test_get_area(corner1, corner2, corner3, 8.000000100624));
    print_result(test_is_point_inside(corner1, corner2, corner3, point_inside, TRUE));
    print_result(test_is_point_inside(corner1, corner2, corner3, point_outside, FALSE));
    printf("\n");

    return 0;
}

int test_is_point_inside(Point corner1, Point corner2, Point corner3, Point point, int inside)
{
    int inside2 = is_point_inside(corner1, corner2, corner3, point);
    if (inside2 == inside)
        return TRUE;
    return FALSE;
}

int test_get_area(Point corner1, Point corner2, Point corner3, double area)
{
    double area2 = get_area(corner1, corner2, corner3);
    if (are_decimals_equal(area2, area))
        return TRUE;
    return FALSE;
}

int test_get_perimeter(double side1, double side2, double side3)
{
    double perimeter = get_perimeter(side1, side2, side3);
    if (perimeter == side1 + side2 + side3)
        return TRUE;
    return FALSE;
}

int test_get_length_of_side(Point point1, Point point2, double distance)
{
    double distance2 = get_length_of_side(point1, point2);
    if (are_decimals_equal(distance2, distance))
        return TRUE;
    return FALSE;
}

int are_decimals_equal(double decimal1, double decimal2)
{
    if (fabs(decimal1 - decimal2) < 0.00001)
        return TRUE;
    return FALSE;
}

int test_get_point(int x, int y)
{
    Point point = get_point(x, y);
    if (point.x == x && point.y == y)
        return TRUE;
    return FALSE;
}

void print_result(int passed)
{
    if (passed)
        set_color(GREEN);
    else
        set_color(RED);
    printf(".");
    set_color(DEFAULT);
}

void set_color(char *color)
{
    printf("%s", color);
}
