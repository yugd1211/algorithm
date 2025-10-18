#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

int N; // 10000

class Vector3
{
public:
	double x, y, z;
	Vector3(double x, double y, double z) : x(x), y(y), z(z) {}
};

Vector3 CrossProduct(const Vector3 &a, const Vector3 &b)
{
	return Vector3(
		a.y * b.z - a.z * b.y,
		a.z * b.x - a.x * b.z,
		a.x * b.y - a.y * b.x);
}

vector<pair<long long, long long>> points;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		long long x, y;
		cin >> x >> y;
		points.push_back({x, y});
	}

	double res = 0;

	for (int i = 2; i < points.size(); i++)
	{
		double dx1 = points[i].first - points[0].first;
		double dy1 = points[i].second - points[0].second;
		double dx2 = points[i - 1].first - points[0].first;
		double dy2 = points[i - 1].second - points[0].second;

		Vector3 cp = CrossProduct(Vector3(dx1, dy1, 0), Vector3(dx2, dy2, 0));
		res += (cp.x + cp.y + cp.z) / 2;
	}
	cout << fixed << setprecision(1) << abs(res) << "\n";
}