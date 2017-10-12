#include <stdio.h>
#include <math.h>

inline double cube(const double v){return v*v*v;}
inline double absolute(const double v){return v >= 0 ? v : -v;}

int main()
{
	double a = -1.f;
	for(; a < 1.1f; a+=0.1f)
		printf("a = %1.4f\t |a|=%1.4f\t a^3=%1.4f\t sin(a)=%1.4f\n", 
			a, absolute(a), cube(a),sin(a));

#ifdef WIN32
		system("pause");
#endif
	return 0;
}