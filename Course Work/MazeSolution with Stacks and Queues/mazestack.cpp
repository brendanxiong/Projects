#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Coord
{
public:
	Coord(int rr, int cc) : m_r(rr), m_c(cc) {}
	int r() const { return m_r; }
	int c() const { return m_c; }
private:
	int m_r;
	int m_c;
};

bool pathExists(string maze[], int nRows, int nCols, int sr, int sc, int er, int ec)
{
	stack<Coord> cStack;
	Coord start(sr, sc);
	cStack.push(start);
	Coord end(er, ec);

	maze[sr][sc] = '0';

	while (!(cStack.empty()))
	{
		Coord temp = cStack.top();
		cStack.pop();
		if (temp.r() == end.r() && temp.c() == end.c())
		{
			return true;
		}

		if (maze[temp.r()][temp.c() + 1] == '.')
		{
			Coord east(temp.r(), temp.c() + 1);
			cStack.push(east);
			maze[temp.r()][temp.c() + 1] = '0';
		}

		if (maze[temp.r() + 1][temp.c()] == '.')
		{
			Coord south(temp.r() + 1, temp.c());
			cStack.push(south);
			maze[temp.r()][temp.c() + 1] = '0';
		}

		if (maze[temp.r()][temp.c() - 1] == '.')
		{
			Coord west(temp.r(), temp.c() - 1);
			cStack.push(west);
			maze[temp.r()][temp.c() - 1] = '0';

		}

		if (maze[temp.r() - 1][temp.c()] == '.')
		{
			Coord north(temp.r() - 1, temp.c());
			cStack.push(north);
			maze[temp.r() - 1][temp.c()] = '0';

		}

	}
	return false;
}


