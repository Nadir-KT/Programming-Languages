#include <stdio.h>

main()
{
float length, breadth, radius, aor, por, aoc, coc;

printf ("\nEnter the Length and Breadth of the Rectangle: ");
scanf("%f %f", &length, &breadth);

printf("\nEnter the Radius of the Circle: ");
scanf("%f", &radius);

aor = length*breadth;
por= 2*(length+breadth);


aoc = 3.14*radius*radius;

coc = 2*radius*3.14;

printf("\nThe area of the rectangle is: %f", aor);

printf("\nThe perimeter of the rectangle is: %f ", por);


printf("\n\nThe area of the Circle with radius %f is: %f ", radius, aoc);

printf("\nThe circumference of the same circle is: %f", coc);
getch();
}
