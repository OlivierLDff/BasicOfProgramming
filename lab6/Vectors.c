#include <stdio.h>
#include <math.h>

typedef struct Vector
{
	double x;
	double y;
}Vector_t;

double v_length(Vector_t * v) { return v ? sqrt(v->x*v->x + v->y*v->y) : 0.f; }

Vector_t v_sum(Vector_t v1, Vector_t v2)
{
	Vector_t sum = { v1.x + v2.x, v1.y + v2.y };
	return sum;
}

int main()
{
	Vector_t v1 = { 1.f, 2.f };
	Vector_t v2 = { -0.5f, 3.f };
	Vector_t vsum = v_sum(v1, v2);

	printf("sum is x=%lf y=%lf\n", vsum.x, vsum.y);

#ifdef WIN32
	system("pause");
#endif
}