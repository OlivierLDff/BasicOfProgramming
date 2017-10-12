#include <stdio.h>

typedef struct Date {
	int year, month, day;
} Date;

typedef struct Competitor {
	char name[31];
	Date birth;
	int rank;
} Competitor;

void Date_print(Date d);

void Competitor_print(Competitor c);

int main() {
	Competitor competitors[5] = 
	{
		{ "Am Erika",{ 1984, 5, 6 }, 1 },
		{ "Break Elek",{ 1982, 9, 30 }, 3 },
		{ "Dil Emma",{ 1988, 8, 25 }, 2 },
		{ "Kasza Blanka",{ 1979, 6, 10 }, 5 },
		{ "Reset Elek",{ 1992, 4, 5 }, 4 },
	};

	/* name of competitor 0 - printf %s */
	printf("rank of competitor 0 %s : %d\n", competitors[0].name, competitors[0].rank);
	/* rank of competitor 2 */
	printf("rank of competitor 2 %s : %d\n", competitors[2].name, competitors[2].rank);
	/* birth date of competitor 4, use the given function */
	printf("birth of %s : ", competitors[4].name);
	Date_print(competitors[4].birth);
	/* the first letter of the name of competitor 1 (a string is an array of characters) */
	printf("the first letter of the name of competitor 1 : %c \n", competitors[1].name[0]);
	/* is competitor 1 among the best three? yes/no, may use ?: operator */
	printf("is competitor 1 among the best three? %s \n", competitors[1].rank<=3 ? "yes" : "no");
	/* is competitor 4 faster than competitor 3? */
	printf("is competitor 4 faster than competitor 3? %s \n", competitors[3].rank >= competitors[4].rank ? "yes" : "no");
	/* was competitor 1 born in the same year as competitor 2? */
	printf("was competitor 1 born in the same year as competitor 2?  %s \n", competitors[1].birth.year == competitors[2].birth.year ? "yes" : "no");
	/* complete the Competitor_print() function,
	* then print all data of competitor 1 */
	Competitor_print(competitors[0]);
	/* at last print all data of all competitors. */
	size_t i = 0;
	for(;i<5;++i)
		Competitor_print(competitors[i]);
#ifdef WIN32
	system("pause");
#endif
	return 0;
}

void Date_print(Date d) 
{
	printf("%d.%d.%d.\n", d.year, d.month, d.day);
}

void Competitor_print(Competitor c) 
{
	printf("%s : rank %d, date : ", c.name, c.rank);
	Date_print(c.birth);
}