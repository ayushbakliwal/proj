#include "func.h"
/**
<A short one line description>

<Longer description>
<May span multiple lines or paragraphs as needed>

@param  Description of method's or function's input parameter
@param  ...
@return Description of the return value

this is the main function
let us see what effect dopes iot have

*/
int main()
{
	char a[] = "gt*";
	char b[] = "gtfg";
	printf("answer is : %d",match(a,b));
	return 0;
}



//int match(char a[],char b[])

/*{
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
}*/

