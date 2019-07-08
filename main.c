#include <stdio.h>

int main()
{
	int a[100][100], rmax[100], nc, nr, i, j, k, flag = 1, cmin, cminloc;
	printf("\nEnter the no. of rows: ");
	scanf("%i", &nr);
	printf("\nEnter the no. of columns: ");
	scanf("%i", &nc);
	printf("\nEnter the elements of the matrix: \n");
	for(i = 1; i <= nr; i++)
	{
		for(j = 1; j <= nc; j++)
		{
			printf("\nEnter the element of a[%i, %i]: ", i, j);
			scanf("%i", &a[i][j]);
		}
		printf("\n");
	}
	for(k = 1; k <= 2; k++)
	{
		for(i = 1; i <= nr; i++)
		{
			rmax[i] = flag*-99999;
			for(j = 1; j <= nc; j++)
				if(flag*(a[i][j]) > flag*(rmax[i]))
					rmax[i] = a[i][j];
		}
		for(j = 1; j <= nc; j++)
		{
			cmin = flag*99999;
			for(i = 1; i <= nr; i++)
				if(flag*(a[i][j]) <= flag*cmin)
				{
					cmin = a[i][j];	
					cminloc = i;
				}
			if(cmin == rmax[cminloc])
				printf("\nSaddle point %i at location a[%i, %i].", cmin, cminloc, j);
		}
		printf("\n\n\n");
		flag = -1;
	}	
	return 0;
}
