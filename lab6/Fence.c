/*Define a Point type to represent a 2D point by 
 *its coordinates (x, y). Write a function (dist()), 
 *which returns the distance of two points received as parameters. 
 *(Use the Pythagorean theorem.) Define two points in main, 
 *calculate their distance and print the result to the screen.

When it works, create further functions to:

examine two points and tell if they are at the same position,
read in the coordinates of a point from the user and return the point.
Now solve the following task using the functions.*/

#include <math.h>
#include <stdio.h>

typedef struct Point
{
	double x;
	double y;
}Point_t;

double dist(Point_t * p1, Point_t * p2)
{
	if(p1 && p2)
		return sqrt(pow(p1->x - p2->x, 2) + pow(p1->y - p2->y, 2));
	return 0;
}

int main()
{
	Point_t p1 = { 0.f, 0.f };
	Point_t p2 = { 0.f, 0.f };
	Point_t p3 = { 0.f, 0.f };

	double d = 0.f;

//	printf("Distance between p1 and p2 = %f\n", dist(&p1, &p2));
	printf("first point x y : \n");
	scanf("%lf %lf", &p1.x, &p1.y);

	printf("second point x y : \n");
	scanf("%lf %lf", &p2.x, &p2.y);

	d = dist(&p1, &p2);

	while(!(p2.x == p1.x && p2.y == p1.y))
	{
		printf("point x y : \n");
		scanf("%lf %lf", &p3.x, &p3.y);
		if(!(p3.x == p1.x && p3.y == p1.y))
			d += dist(&p2, &p3);
		p2 = p3;
	}

	printf("distance = %lf\n", d);
	
	
#ifdef WIN32
	system("pause");
#endif

	return 0;
}
