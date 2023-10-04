#include <iostream>
#include <stack>
#include <algorithm>

/*
*   
*   다른 이의 코드를 확인했는데  내가 했던 방식과는 크게 다름
*   일단 모든 수를 받아서 스택에 저장하는 방식이 아니라 cin으로 하나의 수를 받으면
*   기존에 저장해뒀던 스택으로 인덱스를 찾아가는 과정
*   스택을 쌓는 방식은 기존의 스택에서 현재의 수보다 작은 수들은 pop하고 현재의 수를 스택에 쌓음
*   이렇게 하면 항상 스택에 업데이트돼고 제일 오른쪽보다 작은 수들을 모두 지워진 스택이기 때문에
*   불필요한 연산이 없게됨
*
*   혼자 작성했던 방법과 시간적으로 크게 차이 날거라 생각하는 부분은 두가지가 있다.
*   1. 모든 수를 저장하고, 인덱스를 파악하면 다시 되돌리는 작업이 몇배 이상으로 오버헤드를 잡아 먹을것으로 예상
*   2. 불필요한 수들을 지우는 과정 진행 과정이 왼쪽부터 시작하기 때문에 현재의 높이가 낮은 타워는 일단 수신하지 못하기 때문에 지워도 된다.
*     그말은 즉 그만큼 연산하는 과정또한 작아질 것이다 최대 n2 -> n으로 시간복잡도가 줄어들 수 있다.
*/

using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    std::stack<std::pair<int, int> > tower;
    int N = 0;
    tower.push(make_pair(100000001, 0)); // 높이가 최대 크기보다 큰것을 맨 왼쪽에 두고, 지나온 스택들보다 작으면 무조건 0을 뽑기위함
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        int height;
        cin >> height;
        while  (height > tower.top().first)
            tower.pop();
        cout << tower.top().second << " ";
        tower.push(make_pair(height, i));
    }
}