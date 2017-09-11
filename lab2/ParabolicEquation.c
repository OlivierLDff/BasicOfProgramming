#include <stdio.h>
#include <math.h>

typedef struct ParabolicEquation ParabolicEquation;

struct ParabolicEquation
{
	double a;
	double b;
	double c;
};

void PrintParabolicEquationSolution(ParabolicEquation * e)
{
	printf("Equation is %lf*x^2 + %lf*x + %lf\n", e->a, e->b, e->c);
	double delta = 0;
	if(e->a)
	{
		delta = pow(e->b, 2) - 4*e->a*e->c;
		if(delta > 0)
		{
			printf("Solution is x1 = %lf x2 = %lf\n", (-e->b-sqrt(delta))/(2*e->a), (-e->b+sqrt(delta))/(2*e->a));
		}
		else if(delta < 0)
		{
			printf("There is no real solutions for x\n");
		}
		else
			printf("Solution is x = %lf\n", -e->b/(2*e->a));
	}
	else if(e->b)
		printf("Solution is x = %lf\n", -e->c/e->b);
	else
		printf("x E R\n");
}
 
int main() 
{
	ParabolicEquation e1 = {0, 0, 0};
	ParabolicEquation e2 = {2, -1, -6};
	ParabolicEquation e3 = {1, 12, 35};
	ParabolicEquation e4 = {1, -2, 1};
	ParabolicEquation e5 = {1, 2, 10};
	

	printf("Parabolic Equation is ax^2+bx+c=0\n");
	printf("a = ");
	scanf("%lf", &e1.a);
	printf("b = ");
	scanf("%lf", &e1.b);
	printf("c = ");
	scanf("%lf", &e1.c);

	PrintParabolicEquationSolution(&e1);
	PrintParabolicEquationSolution(&e2);
	PrintParabolicEquationSolution(&e3);
	PrintParabolicEquationSolution(&e4);
	PrintParabolicEquationSolution(&e5);
	

#if WIN32
	system("pause");
#endif
}