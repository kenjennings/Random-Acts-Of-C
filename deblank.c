
/* DEBLANK:
 * Remove leading, and trailing blanks. 
 * This assumes a natural C string ending in 
 * the appropriate terminator.
 * Updates are done in-place to the string 
 * passed as argument, so no memory allocation.
 */
int deblank( char * s )
{
	char * fb  = NULL; /* First blanks */
	char * lnb = NULL; /* last non-blanks */
	char * lt  = NULL; /* walk the string */

	if ( NULL == s )  /* Bad Pointer */
		return -1; /* Exit with error */

	if ( !*s )   /* Empty String */
		return 0;  /* Not an error, just nothing to do here. */

	fb = s;

	while ( *fb && isspace(*fb) ) /* Skip over leading spaces */
		fb++;

	lt = lnb = fb; /* Then this is not a space (or it is the EOT) */

	while ( *lt ) /* Loop over the remainder of the string */
	{
		if ( !isspace( *lt ) ) /* Always remember the last */
			lnb = lt;       /* non-space character */
		lt++;
	}

/* (Length could be determined at this point by   lnb - fb ) */

	if ( (lt - lnb ) > 1 ) /* spaces follow the last char? */
	{
		lnb++;
		*lnb = '\0'; /* Terminate string at last char after non-blank */
	}

	/* Now that the trailing blanks have been clipped, see if the leading
	 * part of the string needs to be shifted down to eat the white space.
	 */
	if ( fb > s )
	{
		while ( *fb ) /* Basically, this is strcpy() */
		{
			*s = *fb; /* Yes, post increment could be done in the same statement. */
			s++;     /* Separated post increment to assist understanding */
			fb++;    /* by the originally intended  audience. */
		}

		*s = *fb; /* And make sure the EOT gets copied */
	}

	return 0;
}

