#include <stdio.h>


/**
* @file util.h
* @brief this header file will contain all required
* definitions and basic utilities functions.
*
* @author Ayush Bakliwal
*
* @date 27-05-2016


Problem 1: Spiral Matrix

With a given number N (input from the keyboard) generate and print a square matrix containing the numbers from 0 to N2-1, located as a spiral beginning from the center of the matrix and moving clockwise starting downwards (look at the examples).

Sample output for N=3 and N=4:

clip_image001

Start Thinking on the Problem

It’s obvious from the requirement that we are given an algorithmic problem. Contriving the appropriate algorithm for filling up the square matrix cells in the required way is the main part of the solution to the problem. We will demonstrate to the reader the typical reasoning needed for solving this particular problem.

Inventing an Idea for the Solution

The next step is to think up the idea for the algorithm, which we will implement. We must fill the matrix with the numbers from 0 to N2-1 and we may immediately notice that this could be made by a loop, which puts one of the numbers in the supposed cell of the matrix at each iteration. We first put 0 at its place, then put 1 at its place, then put 2, and so on until we finish with putting N2-1 at its place.

Let’s suppose we know the starting position – the one we have to put the first number on (the zero). That’s how the problem is reduced to finding a method for determining each of the next positions, which we must put a number at – this is our primary subtask.

We try to find an approach for determining the next to the current position: we search a strict regularity for changing the indices during the traversal of the cells. It looks like the directions of the numbers are changed from time to time, right? First the direction if down, then the direction is changed to left, later to up, then to right then again to down. Changing of the directions is always clockwise and the initial direction is always downwards.

If we define an integer variable direction that holds the current moving direction, it will take sequentially the values 0 (down), 1 (left), 2 (up), 3 (right) and then again 0, 1, 2, … Looking at the problem examples (for N=3 and N=4) we can conclude that the direction stays down for some time, then changes to left, stays some time, then changes to up, stays some time, etc. We can assume that with changing the moving direction we can increase the value of direction by one and take its remainder of division by 4. Thus the next direction after 3 (right) will be 0 (down).

The next step is to determine when the moving direction changes: what is the number of moves in each direction. This may take some time. We can take a sheet of paper and test few hypotheses we might have.

From the two examples we can see that the number of moves in the consequent directions does form special sequences: for N=3 à 1, 1, 2, 2, 2 and for N=4 à 1, 1, 2, 2, 3, 3, 3. This means that for N=3 we move 1 cell down, then 1 cell left, then 2 cells up, then 2 cells right and finally 2 down. For N=4, the process is the same. We found an interesting dependency which can evolve into an algorithm for filling the spiral matrix.

If we write down a bigger matrix of the same type on a sheet of paper, we will see that the sequence of the changes of direction follows the same pattern: the numbers increases by 1 at an interval of two and the last number does not increase.

Seems like we have an idea to solve the problem: start from the middle of the matrix and move 1 cell down, 1 cell left, 2 cells up, 2 cells right, 3 cells down, 3 cells left, etc. During the moving we can fill the numbers from 0 to N2-1 consequently at the cells we visit.

Checking the Idea

Let’s check the idea. First we need to find the starting cell and check we have a correct algorithm for it. If N is odd, the starting cell seems to be the absolute center cell of the matrix. We can check this for N=1, N=3 and N=5 on a sheet of paper and this confirms to be correct. If N is even number, it seems like the starting cell is located upper-right from the central point of the matrix. At the figure below the central point is shown for a matrix of size 4 x 4 and the starting point located at the upper-right direction:

clip_image003

Now let’s check the matrix filling algorithm. We take for example N=4. Let’s start from the starting cell. The first direction is down. We go down 1 cell, then left 1 cell, then up 2 cells, then right 2 cells, then down 3 cells, then left 3 cells and finally up 3 cells. For simplicity we can assume the last step is 4 cells up but we stop at the first moment when the entire matrix if filled. The figure below shows what we could draw on a sheet of paper to trace how the algorithm works. See the small sketch of our algorithm, done by hand during the idea checking process:

clip_image005

After sketching the algorithm paper for N = 1, 2 and 3 on a sheet of paper we see that it works correctly. Seems like the idea is correct and we can thinks about how to implement it.

Data Structures and Efficiency

Let’s start with choosing the data structure for implementing the matrix. It’s appropriate to have direct access to each element of the matrix so we will choose a two-dimensional array matrix of integer type. When starting the program we read from the standard input the dimensionality n of the matrix and initialize it as it follows:

int[,] matrix = new int[n,n];

In this case the choice of a data structure is unambiguous. We will keep the matrix in a two-dimensional array. We have no other data. We will not have problems with the performance because the program will make as much steps as the elements in the matrix are.

Implementation of the Idea: Step by Step

We may split the implementation into few steps. A loop runs from 0 to N2-1 and at each iteration it does the following steps:

-     Fill the current cell of the matrix with the next number (this is a single move in the current direction).

-     Check whether the current direction should be changed and if yes, change it and calculate the number of moves in the new direction.

-     Move the current position to the next cell in the current direction (e.g. one position down / left / up / right).

Implementing the First Few Steps

We can represent the current position with integer variables positionX and positionY – the two coordinates for the position. At each iteration we will move to the next cell in the current direction and positionX and positionX will change accordingly.

For modeling the behavior of filling the spiral matrix we will use the variables stepsCount (total number of moves in the current direction), stepPosition (the move number in the current direction) and stepChange (flag showing if we have to change the value of stepCount – increments after every 2 direction changes).

Let’s see how we can implement this idea as a code:

for (int i = 0; i < count; i++)



Performing a Partial Check after the First Few Steps

This is the moment to point out the unlikelihood of creating the body of such a loop from the first time, without making any mistakes. We already know the rule for writing the code step by step and testing after each piece of code is written but for the body of this loop the rule is hard to be applied – we have no independent subproblems, which can be tested separately of each other. To test the above code we need first to finish it: to assign initial values for all the variables used.

Assigning the Initial Values

After we have a well thought-out idea for the algorithm (even if we are not completely sure that the written code will work correctly), it remains to set initial values of the already defined variables and to print the matrix, obtained after the implementation of the loop.

It is clear that the number of loop iterations is exactly N2 and that’s why we replace the variable count with this value. From the two given examples and our own additional examples (written on a paper) we determine the initial position in the matrix depending on the parity (odd / even) of its size:

int positionX = n / 2; // The middle of the matrix

int positionY = n % 2 == 0 ? (n / 2) - 1 : (n / 2); // middle

To the rest of the variables we give the following initial values (we have already explained their semantics):

int direction = 0; // The initial direction is "down"

int stepsCount = 1; // Perform 1 step in the current direction

int stepPosition = 0; // 0 steps already performed

int stepChange = 0; // Steps count will change after 2 steps

Putting All Together

The last subproblem we have to solve for creating a working program is printing the matrix on the standard output. Let’s write it, then put all code together and start testing.

The fully implemented solution is shown below. It includes reading the input data (matrix size), filling the matrix in a spiral (calculating the matrix center and filling it cell by cell) and output the result:

MatrixSpiral.cs

using System;

 


Testing the Solution

After we have implemented the solution it is appropriate to test it with enough values of N to ensure it works properly. We start with the sample values 3 and 4 and then we check for 5, 6, 7, 8, 9, … It works well.

It is important to check the border cases: 0 and 1. They work correctly as well. We do few more tests and we make sure all cases work correctly. We might notice that when N is large (e.g. 50) the output looks ugly, but this cannot be improved much. We can add more spaces between the numbers but the console is limited to 80 characters and the result is still ugly. We will not try to improve this further.

It is not necessary to test the program for speed (performance test, for example with N=1,000) because with a very big N the output will be extremely large and the task will be pointless.

We cannot find any non-working cases so we assume the algorithm and its implementation are both correct and the problem is successfully solved.

Now we are ready for the next problem from the exam.



*/


/**
* This method will be used to go around the spiral track
* @author Ayush Bakliwal
* @param m no of rows
* @param n no of coloumns
* @date 27-05-2016
*/
void spiralPrint(int m, int n, int a[n][n])
{
    int i, k = 0, l = 0,j;
    int t[100];
 
    /*  k - starting row index
        m - ending row index
        l - starting column index
        n - ending column index
        i - iterator
    */
    j=0;
    while (k < m && l < n)
    {
        /* Print the first row from the remaining rows */
        for (i = l; i < n; ++i)
        {
           t[j]=a[k][i];
           j++;
        }
        k++;
 
        /* Print the last column from the remaining columns */
        for (i = k; i < m; ++i)
        {
            t[j]=a[i][n-1];
            j++;
        }
        n--;
 
        /* Print the last row from the remaining rows */
        if ( k < m)
        {
            for (i = n-1; i >= l; --i)
            {
                t[j]=a[m-1][i];
                j++;
            }
            m--;
        }
 
        /* Print the first column from the remaining columns */
        if (l < n)
        {
            for (i = m-1; i >= k; --i)
            {
                t[j]= a[i][l];
                j++;
            }
            l++;    
        }        
    }
    
    for(i=j-1;i>=0;i--)
    {
    	printf("%d",t[i]);
    	
	}
}
 
/* Driver program to test above functions */
int main()
{

int n=1,q,c,d;

do
{
	printf("Enter the order of the matrix\n");
    
    if(n%2!=1)
   {
	 printf("please enter a valid input\n");
	 q=1;
	 
   }
   
}while(q);
	scanf("%d",&n);
int	a[n][n];
    printf("Enter the elements of  matrix\n");
 
   for (c = 0; c < n; c++)
      for (d = 0; d < n; d++)
      
         scanf("%d", &a[c][d]);
         printf("\n\nThe elements in the matrix are: \n\n") ;
for(c = 0 ; c < n ; c++)
{
  for(d = 0 ; d < n ; d++){
    printf("%d", a[c][d]) ;
    printf("\t");
  }
  printf("\n");
}
 
    spiralPrint(n, n, a);
    return 0;
}
