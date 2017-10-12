/**
Data of circles must be stored in a geometry related program: origin
(x, y coordinates) and the radius. These are real values.

Define a type to store the data of a circle.
Write a function that receives two circle parameters and 
checks if they overlap. (They overlap if the distance of their origins 
[use Pythagorean theorem] is less than the sum of their radiuses.)
Write a function that reads the origin and the radius of a circle 
and returns the circle.
Write a program that reads two circles then prints if they overlap or not.
 */

#include <stdbool.h>
#include <math.h>
#include <stdio.h>

typedef struct Circle
{
	double x;
	double y;
	double r;
}Circle_t;

bool c_overlap(Circle_t * c1, Circle_t * c2)
{
	return c1 && c2 && sqrt(pow(c1->x - c2->x, 2) + pow(c1->y - c2->y, 2)) < (c1->r + c2->r);
}

Circle_t createCircle(double x, double y, double r)
{
	Circle_t res = { x, y, r };
	return res;
}

int main()
{
	Circle_t c1 = createCircle(5.f, 20.f, 5.f);
	Circle_t c2 = createCircle(3.f, 22.f, 6.f);

	printf("Circle overlaps? %s\n", c_overlap(&c1, &c2) ? "yes" : "no");

#ifdef WIN32
	system("pause");
#endif
}
