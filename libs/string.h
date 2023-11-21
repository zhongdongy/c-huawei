/**
 * \brief Sort characters in a string ascendingly.
 *
 * \param ar Char pointer or char array
 * \param a Length of string (including trailing '\0')
 */
void str_sort_asc(char *, int);

/**
 * \brief Sort characters in a string descendingly.
 *
 * \param ar Char pointer or char array
 * \param a Length of string (including trailing '\0')
 */
void str_sort_desc(char *, int);

/**
 * \brief Read string contents from standard input stream
 * 
 * 1. read string limited by 2nd arg and truncate when '\n' met or reach limit;
 * 2. returns NULL when input stream empty or error occurs;
 * 3. returns the same char * pointer as 1st arg if contents read successfully.
 * 
 * Note: '\n' will not be included in the result string.
 * \param str Char * pointer to string storage
 * \param n Number of characters to read
*/
char *s_gets(char *, int);