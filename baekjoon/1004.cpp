#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <tuple>

using namespace std;

int T;

int main()
{
    cin >> T;

    while (T--)
    {
        long long sx, sy, ex, ey;
        long long n;
        long long answer = 0;
        cin >> sx >> sy >> ex >> ey;
        vector<tuple<int, int, int>> t;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
			long long px, py, r;

            cin >> px >> py >> r;


            // 두 점이 같은 원 안에 있는 경우 에러 발생할수있음
            // long long tx = px - sx;
            // long long ty = py - sy;
            
            // if (sqrt(pow(px - sx, 2) + pow(py - sy, 2)) - r < 0)
            //     answer++;            
            // if (sqrt(pow(px - ex, 2) + pow(py - ey, 2)) - r < 0)
            //     answer++;



            long long distStartSq = (px - sx) * (px - sx) + (py - sy) * (py - sy);
            long long distEndSq = (px - ex) * (px - ex) + (py - ey) * (py - ey);
            long long radiusSq = r * r;

            bool startInside = distStartSq < radiusSq;
            bool endInside = distEndSq < radiusSq;

            if (startInside != endInside)
                answer++;
        }
        cout << answer << "\n";
    }
}