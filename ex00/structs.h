typedef struct s_input
{
	int	*up;
	int	*down;
	int	*left;
	int	*right;
}				t_input;

typedef struct s_matrix
{
	int	rows;
	int	cols;
	int	**values;
}				t_matrix;

typedef struct s_pos
{
	int	row;
	int	col;
}				t_pos;
