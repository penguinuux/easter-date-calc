/*
 * This file is part of Easter Date Calculator.
 * 
 * Portions of this code are based on examples from "The GNU C Reference Manual"
 * and the GNU manual for `getopt`, both licensed under the GNU General Public License (GPL).
 *
 * Easter Date Calculartor is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 * 
 * Written by "penguinuux".
 * © 2025 Pablo Adriano M. Costa, "penguinuux", licensed under the GNU GPL v3.
 */

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void
show_version (void)
{
	printf ("v1.0.0\n");
}

void show_help(void)
{
  printf("\nNAME\n");
  printf("       easterdt - calculates and displays the date of Easter for the given year.\n\n");

  printf("SYNOPSIS\n");
  printf("       easterdt [OPTION]... [YEAR]...\n\n");

  printf("DESCRIPTION\n");
  printf("       easterdt calculates and displays the date of Easter for the given year.\n");

  printf("OPTIONS\n");
  printf("  -h\n");
  printf("       Show this help message and exit.\n");
  printf("  -v\n");
  printf("       Show the version of the program and exit.\n");
  printf("  -y <year>\n");
  printf("       Specify the year for which to calculate the date of Easter.\n\n");

  printf("EXAMPLES\n");
  printf("  easterdt -y 2033\n");
  printf("       Calculate and display the date of Easter in the year 2033.\n\n");
  printf("  easterdt -v\n");
  printf("       Display the version of the program.\n\n");
  printf("  easterdt -h\n");
  printf("       Show this help message.\n\n");

  printf("AUTHOR\n");
  printf("       Written by Pablo Adriano M. Costa, \"penguinuux\".\n\n");

  printf("COPYRIGHT\n");
  printf("       Copyright © 2025 Pablo Adriano M. Costa, \"penguinuux\" <https://github.com/penguinuux/>.\n");
  printf("       License GPLv3+: GNU GPL version 3 or later <https://gnu.org/licenses/gpl.html>.\n");
  printf("       This is free software: you are free to change and redistribute it. There is NO WARRANTY, to the extent permitted by law.\n");
}

unsigned int
char_year_to_int (const char *year_str)
{
	unsigned int year = 0;
	unsigned short int len = strlen(year_str);

	for (unsigned short int i = 0; i < len; i++)
	{
	  year = year * 10 + (year_str[i] - '0');
	}

	return year;
}

void
define_easter (unsigned int y)
{
	int n = 0;
	int g = (y % 19) + 1;
	int c = (y / 100) + 1;
	int x = ((3 * c) / 4) - 12;
	int z = (((8 * c) + 5) / 25) - 5;
	int d = ((5 * y) / 4) - x - 10;
	int e = ((11 * g) + 20 + z - x) % 30;

	if (((e == 25) && (g > 11)) || (e == 24))
	   e++;

	n = 44 - e;

	if (n < 21)
	  n += 30;

	n = n + 7 - ((d + n) % 7);

	if (n > 31)
	   printf ("Easter: %d April %d\n", n - 31, y);
	else
	   printf ("Easter: %d March %d\n", n, y);
}

int
main (int argc, char **argv)
{
	char *cvalue = NULL;
	int index;
	int c;
	unsigned int y;

	opterr = 0;

	while ((c = getopt (argc, argv, "vhy:")) != -1)
	  switch (c)
	    {
	    case 'v':
	      show_version();
	      break;
	    case 'h':
	      show_help();
	      break;
	    case 'y':
	      y = char_year_to_int(optarg);
	      define_easter(y);
	      break;
	    case '?':
	      if (optopt == 'y')
					fprintf (stderr, "Option -%c requires an argument.\n", optopt);
	      else if (isprint (optopt))
					fprintf (stderr,
									"Unknown option character `\\x%x'.\n",
									optopt);
	      return 1;
	    default:
	      abort ();
	    }

	for (index = optind; index < argc; index++)
	  printf ("Non-option argument %s\n", argv[index]);
	return 0;
}
