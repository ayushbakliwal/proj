#include "func.h"



/**








<A short one line description>

<Longer description>
<May span multiple lines or paragraphs as needed>

@param  Description of method's or function's input parameter
@param  ...
@return Description of the return value



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








\n\n\n\n\n\n\

When specifying file names (or paths) in CP/M, DOS, Microsoft Windows, and Unix-like operating systems, the asterisk pattern character (*, also called "star") matches zero or more characters.

In Unix-like and DOS operating systems, the question mark ? matches exactly one character; in DOS, if the question mark is placed at the end of the word, it will also match missing (zero) trailing characters. For example, in DOS, the pattern 123??? will match 1234 or 12345, but not 1234567.

In Unix shells and Windows PowerShell, ranges of characters enclosed in square brackets ([ and ]) match a single character within the range; for example, [A-Za-z] matches any single uppercase or lowercase letter. Unix shells allow negation of the specified character set by using a leading ! (e.g., foo.[!ch], which will match names like foo.o). In shells that interpret ! as a history substitution, a leading ^ can be used instead of ! to negate the character set.

The operation of matching of wildcard patterns to multiple file or path names is referred to as globbing.
Databases

In SQL, wildcard characters can be used in LIKE expressions; the percent sign % matches zero or more characters, and underscore _ a single character. Transact-SQL also supports square brackets ([ and ]) to list sets and ranges of characters to match, a leading caret ^ matches only a character not specified within the brackets. In Microsoft Access, wildcard characters can be used in LIKE expressions; the asterisk sign * matches zero or more characters, the question mark ? matches a single character, the number sign # matches a single digit (0-9), and square brackets can be used to enclose sets or ranges of characters to match.
Regular expressions

In regular expressions, the period (., also called "dot") is the wildcard pattern character that matches a single character. Combined with the asterisk operator .* it will match any number of characters.

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

/**
 *
 * It compares the string sequentially
 multiline components are here 
 *
 * 
 *
 */
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
