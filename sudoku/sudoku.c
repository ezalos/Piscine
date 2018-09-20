/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 14:32:09 by ldevelle          #+#    #+#             */
/*   Updated: 2018/09/16 01:11:40 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void ft_print_grid(char array[9][9][10], int grid)
{
	int i;
	int j;

	i = 0;
	j = 0;

	while (j <= 8)
	{
		i = 0;
		while (i <= 8)
		{
			printf("%c ", array[j][i][grid]);
			if (i == 2 || i == 5)
				printf("| ");
			i++;
		}
		printf("\n");
		if (j == 2 || j == 5)
			printf("- - -   - - -   - - - \n" );
		j++;
	}
}

void ft_print_all_grid(char array[9][9][10], int grid)
{

	grid = 0;

	while (grid <= 9)
	{
		ft_print_grid(array, grid);
		printf("\n//////////////////////\n");
		grid++;
	}
}

int ft_check_columns(char array[9][9][10], int i, int grid)
{
	int n;

	n = 0;
	while (array[n][i][0] != grid + 48 && n < 9)
		n++;
	//	printf("Check columns = %d", n);
	if (n == 9)
		return (1);
	else
		return (0);
}

int ft_check_line(char array[9][9][10], int j, int grid)
{
	int n;

	n = 0;
	while (array[j][n][0] != grid + 48 && n < 9)
		n++;
	//	printf("Check lines = %d", n);
	if (n == 9)
		return (1);
	else
		return (0);
}

void ft_remplissage_ghost(char array[9][9][10], int sqr[3][3], int y, int x, int grid)
{
	int i;
	int j;

	if (sqr[y][x] == 0)   // PARTIE DE REMPLISSAGE **********
	{
		j = y * 3;
		while (j <= (y * 3) + 2 && j >= y * 3)  // deplacement dans case line
		{
			i = x * 3;
			while (i <= (x * 3) + 2 && i >= x * 3)  // deplacement dans case colonnes
			{
				if (ft_check_line(array, j, grid) == 1 && ft_check_columns(array, i, grid) == 1 && array[j][i][0] == 48)
					array[j][i][grid] = '*';
				i++;
			}
			j++;
		}
	}
}

void ft_remplissage_base(char array[9][9][10], int sqr[3][3], int y, int x, int grid)
{
	int i;
	int j;


	j = y * 3;
	while (j <= (y * 3) + 2 && j >= y * 3)  // deplacement dans case line
	{
		i = x * 3;
		while (i <= (x * 3) + 2 && i >= x * 3)  // deplacement dans case colonnes
		{
			if (array[j][i][grid] == '*')
			{
				//				printf("y %d x : %d j : %d i : %d grid : %d\n", y, x, j, i, grid);
			if (ft_check_line(array, j, grid) == 1 && ft_check_columns(array, i, grid) == 1 && array[j][i][0] == 48)
			{
				array[j][i][grid] = grid + 48;
				array[j][i][0] = grid + 48;
			}
			}
			i++;
		}
		j++;
	}
}

void ft_check_square(char array[9][9][10], int grid)
{
	int j;
	int i;
	int x;
	int y;
	int o;
	int sqr[3][3] = {0,0,0,0,0,0,0,0,0};

	j = 0;
	i = 0;
	x = 0;
	y = 0;
	o = 0;
	while (y <= 2)  // bloc de case lignes
	{
		x = 0; 
		while ( x <= 2)  // bloc de case colonnes
		{
			j = y * 3;
			while (j <= (y * 3) + 2 && j >= y * 3)  // deplacement dans case line
			{
				i = x * 3;
				while (i <= (x * 3) + 2 && i >= x * 3)  // deplacement dans case colonnes
				{
					if (array[j][i][grid] == grid + 48)
						sqr[y][x]++;		//Determine quelle case possede deja le nombre grid
					i++;
				}
				j++;
			}
			ft_remplissage_ghost(array, sqr, y, x, grid);
			x++;
		}
		y++;
	}
}

void ft_check_star(char array[9][9][10], int grid)
{
	int j;
	int i;
	int x;
	int y;
	int sqr[3][3] = {0,0,0,0,0,0,0,0,0};

	j = 0;
	i = 0;
	x = 0;
	y = 0;
	while (y <= 2)  // bloc de case lignes
	{
		x = 0; 
		while ( x <= 2)  // bloc de case colonnes
		{
			j = y * 3;
			while (j <= (y * 3) + 2 && j >= y * 3)  // deplacement dans case line
			{
				i = x * 3;
				while (i <= (x * 3) + 2 && i >= x * 3)  // deplacement dans case colonnes
				{
					if (array[j][i][grid] == '*')
						sqr[y][x]++;		//Determine quelle case possede deja le nombre grid
					i++;
				}
				j++;
			}
			//			printf("Y a t'il un sqr[y][x] = %d ? %d \n", grid, sqr[y][x]);
			if (sqr[y][x] == 1)
				ft_remplissage_base(array, sqr, y, x, grid);
			x++;
		}
		y++;
	}
}

void ft_check_star_all_grids(char array[9][9][10], int j, int i)
{
	int grid;

	grid = 1;
	while (grid <= 9)
	{
		if (array[j][i][grid] == '*')
		{
			//			array[j][i][grid] = grid + 48;
			array[j][i][0] = grid + 48;		//Determine quelle case possede deja le nombre grid
		}
		grid++;
	}
}

void ft_write_ghost_array(char array[9][9][10])
{
	int i;
	int j;
	int grid;

	i = 0;
	j = 0;
	grid = 1;
	while ( grid <= 9)
	{
		j = 0;
		while (j <= 8)
		{
			i = 0;
			while (i <= 8)
			{
				if (array[j][i][0] == grid + 48)
					array[j][i][grid] = grid + 48;
				else 
					array[j][i][grid] = ' ';
				i++;
			}
			j++;
		}
		//		ft_check_square(array, grid);
		grid++;
	}
}

void ft_check_all_grids(char array[9][9][10])
{
	int i;
	int j;
	int o;
	int grid;

	i = 0;
	j = 0;
	o = 0;
	grid = 1;
	while (j <= 8)
	{
		i = 0;
		while (i <= 8)
		{
			while (grid <= 9)
			{
				if (array[j][i][grid] == '*')
					o++;
				grid++;
			}
			if (o == 1)
				ft_check_star_all_grids(array, j, i);
			o = 0;
			grid = 1;
			i++;
		}
		j++;
	}
}

void first_writing_base(char array[9][9][10], char **argv)
{
	int i;
	int j;
	int grid;

	i = 0;
	j = 0;
	grid = 0;
	while (j <= 8)
	{
		i = 0;
		while (i <= 8)
		{
			if (*(argv[j + 1]+i) == 46)
				*(argv[j + 1]+i) = 48;
			array[j][i][grid] = *((argv[j + 1])+i);
			i++;
		}
		j++;
	}
}
/*
   void ft_simplification_star1(char array[9][9][10])
   {
   int i;
   int j;
   int o;
   int grid;

   i = 0;
   j = 0;
   o = 0;
   grid = 1;
   while (j <= 8)
   {
   i = 0;
   while (i <= 8)
   {
   while (grid <= 9)
   {
   if (array[j][i][grid] == '*')
   o++;
   grid++;
   }
   if (o <= 3)
   ft_check_star_all_grids(array, j, i);
   o = 0;
   grid = 1;
   i++;
   }
   j++;
   }
   }*/

void ft_simplification_star3h(char array[9][9][10], int aire, int droite, int grid)
{
	int i;

	i = 0;
	while (i <= 8)
	{
		if ( i / 3 != aire)
			array[droite][i][grid] = ' ';
		i++;
	}
	printf("\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
	ft_print_grid(array, grid);
	printf("\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
}

void ft_simplification_star3v(char array[9][9][10], int aire, int droite, int grid)
{
	int i;

	i = 0;
	while (i <= 8)
	{
		if ( i / 3 != aire)
			array[i][droite][grid] = ' ';
		i++;
	}
	printf("\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
	ft_print_grid(array, grid);
	printf("\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
}

void ft_simplification_star2(char array[9][9][10], int sqr[3][3], int y, int x, int grid)
{
	int i;
	int j;
	int str[3][2];
	int n;

	n = 0;
	j = y * 3;
	while (j <= (y * 3) + 2 && j >= y * 3)  // deplacement dans case line
	{
		i = x * 3;
		while (i <= (x * 3) + 2 && i >= x * 3)  // deplacement dans case colonnes
		{
			if (array[j][i][grid] == '*')
			{
				str[n][0]=j;
				str[n][1]=i;
				n++;
			}
			i++;
		}
		j++;
	}
	if (str[1][0] == str[2][0] == str[0][0] && n == 3)
			{
				ft_simplification_star3h(array, x, str[0][0], grid);
			}
			else if (str[1][0] == str[0][0] && n == 2)
			{
				ft_simplification_star3h(array, x, str[0][0], grid);
			}
//			else if (n == 1)

			if (str[1][1] == str[2][1] == str[0][1] && n ==3) 
			{
				ft_simplification_star3v(array, y, str[0][1], grid);
			}
			else if (str[1][1] == str[0][1] && n == 2) 
			{
				ft_simplification_star3v(array, y, str[0][1], grid);
			}
}


void ft_simplification_star(char array[9][9][10], int grid)
{
	int j;
	int i;
	int x;
	int y;
	int sqr[3][3] = {0,0,0,0,0,0,0,0,0};

	j = 0;
	i = 0;
	x = 0;
	y = 0;
	while (y <= 2)  // bloc de case lignes
	{
		x = 0; 
		while ( x <= 2)  // bloc de case colonnes
		{
			j = y * 3;
			while (j <= (y * 3) + 2 && j >= y * 3)  // deplacement dans case line
			{
				i = x * 3;
				while (i <= (x * 3) + 2 && i >= x * 3)  // deplacement dans case colonnes
				{
					if (array[j][i][grid] == '*')
						sqr[y][x]++;		//Determine quelle case possede deja le nombre grid
					i++;
				}
				j++;
			}
			if (sqr[y][x] <= 3 && sqr[y][x] > 0)
				ft_simplification_star2(array, sqr, y, x, grid);
			x++;
		}
		y++;
	}
}

int compteur(char array[9][9][10])
{
	int o;
	int i;
	int j;

	o = 0;
	i = 0;
	j = 0;
	while (j <= 8)

	{
		i = 0;
		while (i <= 8)
		{
			if (array[j][i][0] != '0')
				o++;
			i++;
		}
		j++;
	}
	return (o);
}

void ft_brain(char array[9][9][10], int grid)
{
	int b;
	while (compteur(array) != b)
	{
	b = compteur(array);
		grid = 1;
		printf("\n\n1");

		ft_write_ghost_array(array);  //met les numeros dans les ghosts
		while (grid <= 9)
		{
			printf("2");
			ft_check_square(array, grid);  // met les etoiles dansns les ghosts
			printf("3");
		grid++;
		}
		grid = 1;
		while (grid <= 9)
		{
			ft_simplification_star(array, grid);  //simplifie les etoiles alignees
			printf("4");
			grid++;
		}
		printf("5");

		grid = 1;
		while (grid <= 9)
		{
			printf("6");

			ft_check_star(array, grid);   //resoud les etoiles seule dans carres
			printf("7");

//			ft_check_all_grids(array);  //resoud les etoiles seules sur position
			grid++;
		}
		printf("8\n\n");
printf("NOMBRE DE NOMBRE TROUVES : %d\n", b);
		ft_print_all_grid(array, grid);
	}
}

int  main(int argc, char **argv)
{
	char array[9][9][10];
	int i;
	int j;
	int grid;

	//ON CHECK L'INPUT

	first_writing_base(array, argv);

	ft_brain(array, grid);

	ft_print_all_grid(array, grid);
}

/*
   recopier le nombre dans le ghost
   regarder les carres sans le nombre
   si colonnes ET lignes des cases exemptes du nombre ecrire le nombre
   */
