#include <iostream>

#include <algorithm>

using namespace std;

 

int N;

int cache[3] = { 0 }; //i-1번째 집을 칠하는 비용

 

int minCost(void)

{

        int RGB[3];

        int red, green, blue;

        cin >> red >> green >> blue;

        RGB[0] = red, RGB[1] = green, RGB[2] = blue;

        for (int i = 1; i < N; i++)

        {

               cin >> red >> green >> blue;

               for (int i = 0; i < 3; i++)

                       cache[i] = RGB[i]; //0번부터 i-1번째 집까지 칠하는 비용 초기화

               RGB[0] = red + min(cache[1], cache[2]); //red + i-1번째 집 중 green과 blue 중 작은 값

               RGB[1] = green + min(cache[0], cache[2]);

               RGB[2] = blue + min(cache[0], cache[1]);

        }

        return RGB[0] > RGB[1] ? (RGB[1] > RGB[2] ? RGB[2] : RGB[1]) : (RGB[0] > RGB[2]?RGB[2] : RGB[0]); //제일 작은 값 반환

}

int main(void)

{

        cin >> N;

        if (N < 1 || N>1000)

               exit(-1);

        cout << minCost() << endl;

        return 0;

}s