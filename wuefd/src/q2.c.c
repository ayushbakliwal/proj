#include <stdio.h>
#include <stdlib.h>




/**
* @file util.h
* @brief this header file will contain all required
* definitions and basic utilities functions.
*
* @author Ayush Bakliwa
*
* @date 27-05-2016
*/


/**
* This method will be used to match character one by one
* @author Ayush Bakliwal
* @param a[] first String with wild entries
* @param b[] second String
* @date 27-05-2016
*/


int match(char a[] , char b[])
{
    if(a==NULL||b==NULL)
    {
    return 0;
    }
if(a[0] == '\0' && b[0] == '\0')
{
return 1;    
}
else if(a[0] == b[0])
{
    return (match(&a[1],&b[1]));   // ??
}


else if(a[0] == '?')
{
    if(b[0] == '\0')
    {
        return 0;
    }
    else
    {
        return (match(&a[1],&b[1]));
    }
}
else if(a[0] == '*')
{
    if(b[0] == '\0')
    {
        return (match(&a[1],&b[0]));
    }
    else
    {
        return (match(&a[1],&b[0])||match(&a[0],&b[1]));  // ?
    }
    
}
return 0;
}



int main() {
    char a[1000], b[1000];
 
   printf("Input first string\n");
   gets(a);
 
   printf("Input second string\n");
   gets(b);
 
	printf("answer is : %d",match(a,b));
	return 0;
}
