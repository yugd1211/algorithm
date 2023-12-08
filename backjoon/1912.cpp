#include <iostream>
#include <algorithm>
using namespace std;

int N;

// 값을 계속더해가며 ans를 업데이트하다 -값이 나왔을때 이전값을 모두더한 값에 더했는데
// 0이하로 값이 내려가면 초기화하고 다음 값부터 더해가며 ans와 비교하며 ans보다 값이
// 높아지면 업데이트한다.
// 풀이 자체는 맞았지만 -값들만 나왔을때를 생각했을때 일괄적으로 처리하는 법이 생각나지않아서
// 조건문을 줘서 마이너스일때는 계속 해당값을 ans값이랑 비교해서 업데이트해줬다.

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    int sum;
    int ans;
    int curr;
    cin >> sum;
    ans = sum;
    curr = ans;
    for (int i = 1; i < N; i++)
    {
        cin >> curr;
        if (sum + curr < 0)
        {
            if (curr > ans)
                ans = curr;
            sum = 0;
            continue;
        }
        sum += curr;
        if (sum > ans)
            ans = sum;
    }

    cout << ans;
}