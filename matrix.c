#include<stdio.h>
#include "head.h"

/*! \brief Brief description.
 *         Brief description continued.
 *

 *  Detailed description starts here.
 It starts here ity is a reverse spiral matrix whixh it really prints \fast!!!
 */
 
 

void main()
{
int n;
/**
 * let us check out what is happening
 */
printf("Enter the value of for a nxn matrix");
scanf("%d",&n);

int A[n][n];

printf("\nenter the elements in a matrix");
int i=0,j=0;
/*! \brief Brief description.
 *         Brief description continued.
 *
 *  Detailed description starts here.
 It starts here ity is a reverse spiral matrix whixh it really prints \fast!!!
 */
for(i=0;i<n;i++)
{
	for(j=0;j<n;j++)
{
 scanf("%d",&A[i][j]);
 
 /**
<A short one line description>

<Longer description>
<May span multiple lines or paragraphs as needed>

@param  Description of method's or function's input parameter
@param  ...
@return Description of the return value
*/
}
}

PrintSpiral(n,A);

}



