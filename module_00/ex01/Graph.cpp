#include "Graph.hpp"


// ! maybe it should be a single dimenssion array and they store the point
// ! when it come to printing search for if the current position is sat
Graph::Graph(Vector2 s) : size(s)
{
    // for (int y = 0; y < (int)size.get_y(); y++)
    // {
    //     std::vector<Vector2>    row;
    //     for (int x = 0; x < (int)size.get_x(); x++)
    //         row.push_back(Vector2());
    //     this->graph.push_back(row);
    // }
}

Graph::Graph(const Graph& g)
{
    this->size = g.size;
    this->points = g.points;
}

Graph& Graph::operator=(const Graph& rhs)
{
    if (this == &rhs)
        return (*this);
    this->size = rhs.size;
    this->points = rhs.points;
    return (*this);
}

Graph::~Graph()
{

}

void    Graph::add_point(const Vector2& v)
{
    if (v.get_x() > size.get_x() || 
        v.get_y() > size.get_y())
        throw MyRuntimeError("x, y out of the graph size");
	// if (point_occupied(v))
	// 	return ;
    points.push_back(v);
}

void	Graph::add_line(const Vector2& start, const Vector2& end)
{
	// ! some checks goes here....
	lines.push_back(std::pair<Vector2, Vector2>(start, end));
}

void    Graph::read_input_points(const std::string& file_path)
{
	// std::ifstream	file_points;

	// file_point.open(file_path);
	// if (!file_points.is_open())
	// 	throw MyRuntimeError("bad file path");
	(void)file_path;
}


bool    Graph::point_occupied(const Vector2& p) const
{
	for (std::vector<Vector2>::const_iterator cit = points.begin(); cit != points.end(); ++cit)
		if (cit->get_x() == p.get_x() && cit->get_y() == p.get_y())
			return (true);
    return (false);
}

bool    Graph::point_occupied(double x, double y) const
{
	for (std::vector<Vector2>::const_iterator cit = points.begin(); cit != points.end(); ++cit)
	{
		// if (std::abs((double)cit->get_x() - x) <= 0.1 && std::abs((double)cit->get_y() - y) <= 0.1)
		if (std::pow(x - (double)cit->get_x(), 2) + std::pow(y - (double)cit->get_y(), 2) - 0.04 <= 0.1)
			return (true);
	}
    return (false);
}

bool	Graph::cross_line(int col, int row) const
{
	for (std::vector<std::pair<Vector2, Vector2> >::const_iterator it = lines.begin(); it != lines.end(); ++it)
	{
		Vector2 start = it->first;
		Vector2 end = it->second;
		// if (start.get_x() < col && col < end.get_x())
			// std::cout << "row: " << row << "\nstart: " << start.get_x() << "," << start.get_y() << " end: " << end.get_x() << "," << end.get_y() << "\n";
		// i can check just for the min of them and put it in the start Vector2/
		// because i'm expected the min to be in the start
		if (((int)start.get_x() <= col && col <= (int)end.get_x() &&
			(int)start.get_y() <= row && row <= (int)end.get_y()) ||
			((int)start.get_x() >= col && col >= (int)end.get_x() &&
			(int)start.get_y() >= row && row >= (int)end.get_y())) {
			return (true);
		}
	}
	return (false);
}

int	Graph::digit_count(int nbr) const
{
	if (nbr == 0)
		return (1);
	return (static_cast<int>(std::log10(nbr)) + 1);
}


void	Graph::save_as_png(std::string output_file)
{
	uint32_t		white_color = ~0x0, color;
	int				width = 500, height = 500;
	UncomPngWriter	png_writer(height, width, output_file);

	for (int y = 0; y < height; ++y)
	{
		for (int x = 0; x < width; ++x)
		{
			color = white_color;
			if ((x >= width / 2 - 1 && x <= width / 2 + 1) || (y >= height / 2 - 1 && y <= height / 2 + 1))
				color = 0x0;
			
			if ((x >= width / 2 - 4 && x <= width / 2 + 4) && y % (width / (2 * (int)size.get_y())) == 0)
				color = 0x0;
			
			if ((y >= height / 2 - 4 && y <= height / 2 + 4) && x % (height / (2 * (int)size.get_x())) == 0)
				color = 0x0;

			png_writer.put_pixel(x, y, color);
		}
	}

	for (int y = 0; y < height; ++y)
	{
		for (int x = 0; x < width; ++x)
		{
			double d_x = (x * (2*size.get_x())) / width - size.get_x();
			double d_y = size.get_x() - (y * (2*size.get_x())) / height;

			if (point_occupied(d_x, d_y))
				png_writer.put_pixel(x, y, 0x0000ff);
		}
	}

	png_writer.save_image();
}







std::ostream&   operator<<(std::ostream& os, const Graph& g)
{
	int	highest_digit = g.digit_count(g.size.get_y());

	std::cout << highest_digit << "\n";
	for (int row = static_cast<int>(g.size.get_y()); row >= 0; row--)
	{
		std::string	spaces(highest_digit - g.digit_count(row) + 1, ' ');
		os << ">& " << row << spaces;
		for (int col = 0; col <= static_cast<int>(g.size.get_x()); col++)
		{
			std::string space = (col == static_cast<int>(g.size.get_x())) ? "" : " ";
			if (g.point_occupied(Vector2(col, row)))
				os << "X" << space;
			else if (g.cross_line(col, row))
				os << "X" << space;
			else
				os << ". ";
		}
		os << "\n";
	}
	os << ">& " << std::string(highest_digit + 1, ' ');
	for (int i = 0; i <= static_cast<int>(g.size.get_x()); i++)
		os << i << ((i != static_cast<int>(g.size.get_x())) ? " " : "");
	return (os);
}