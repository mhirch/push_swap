// int calculate(int a, int b)
// {
//   int result;

//   // Determine the absolute values of a and b
//   int absA = ftabs(a);
//   int absB = ftabs(b);

//   // Find the maximum absolute value between a and b
//   int maxAbs = (absA > absB) ? absA : absB;

//   // Calculate the result based on the maximum absolute value
//     if (a < 0 && b < 0) 
//         result = maxAbs;
//     else if (a < 0 || b < 0) 
//         result = maxAbs + 1;
//     else 
//         result = maxAbs + 2;
  
//   return result;
// }
int ftabs(int x)
{
    if (x < 0) 
        return -x;
    else
        return x;
}
int calculate(int a, int b)
{
    int result;
	int abs_a;
	int abs_b;

	abs_a = ft_abs(a);
	abs_b = ft_abs(b);
    if (a == b)
        result = abs_a;
    else if ((a < 0 & b < 0) || (a > 0 & b > 0))
        result = (abs_a > abs_b) ? abs_a : abs_b;
	else if ((a < 0 && b >= 0))
		result = abs_a + abs_b;
	else if ((b < 0 && a >= 0))
		result = abs_a + abs_b;
	return result;
}
# include <stdio.h>
int main()
{
    printf("%d\n", calculate(0, -1));
}