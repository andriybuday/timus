#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

struct Point
{
	double x;
	double y;
	Point():x(0),y(0){}
	Point(const Point &p):x(p.x),y(p.y){}
	double dist(const Point &p)const{return sqrt((x-p.x)*(x-p.x)+(y-p.y)*(y-p.y));}
	friend istream& operator >>(std::istream & in, Point &p)
	{
		in >> p.x >> p.y;
		return in;
	}
};
double a[203][203];
double labels[203];
bool visited[203];
int fromcell[203];
#define DOFIGA 1e+9
Point stations[203];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	
	vector<int> way;
	Point beg, end;
	int n, i, j;
	double feet_sp, under_sp;
	cin >> feet_sp >> under_sp;
	cin >> n;
	for(i = 1; i <= n+1; ++i)labels[i] = DOFIGA;
	for(i = 1; i <= n; ++i)cin >> stations[i];

	for(i = 1; i <= n; ++i)
		for(j = 1; j <= n; ++j)
			a[i][j] = a[j][i] = stations[i].dist(stations[j])/feet_sp;

	
	int fir = 1, sec = 1;
	while(fir && sec)
	{
		cin >> fir >> sec;
		a[fir][sec] = a[sec][fir] = stations[fir].dist(stations[sec])/under_sp;
	}

	cin >> beg >> end;

	
	for(i = 1; i <= n; ++i)
	{
		a[i][0] = a[0][i] = stations[i].dist(beg)/feet_sp;
		a[i][n+1] = a[n+1][i] = stations[i].dist(end)/feet_sp;
	}
	a[0][n+1] = a[n+1][0] = beg.dist(end)/feet_sp;

	
	visited[0] = 1;
	int min_ind = -256, curr = 0;
	double min;

while(true)
{
	min = DOFIGA;
	for(i = 1; i <= n + 1; ++i)
	{
		if(!visited[i])if(labels[i] > a[i][curr] + labels[curr])
		{
			labels[i] = a[i][curr] + labels[curr];
			fromcell[i] = curr;
		}
	}	
	for(i = 1; i <= n+1; ++i)
	{
		if(!visited[i])if(min > labels[i])
		{
			min = labels[i];
			min_ind = i;
		}
	}
	visited[min_ind] = 1;
	if(min_ind == n+1)break;
	curr = min_ind;
}

	printf("%.9lf\n", labels[n+1]);

	int z = n+1;
	while(fromcell[z] != 0)
	{
		way.push_back(fromcell[z]);
		z = fromcell[z];
	}

	cout << way.size() << " ";
	for(vector<int>::reverse_iterator it = way.rbegin(); it != way.rend(); ++it)
	{
		cout << *it << " ";
	}
	cout << "\n";
}
