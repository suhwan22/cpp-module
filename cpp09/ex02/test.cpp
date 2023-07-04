#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <deque>


int main() {
    std::deque< std::vector<int> > couples;

    // 임의의 양의 정수로 push_back 실행
    std::vector<int> a;
    a.push_back(2);
    a.push_back(4);
    couples.push_back(a);
    {
    std::vector<int> b;
    b.push_back(1);
    b.push_back(3);
    couples.push_back(b);
    }
    {
    std::vector<int> c;
    c.push_back(5);
    c.push_back(2);
    couples.push_back(c);
    }
    {
    std::vector<int> d;
    d.push_back(3);
    d.push_back(1);
    couples.push_back(d);
    }

    // a를 기준으로 정렬
    std::sort(couples.begin(), couples.end());

    // couples 리스트 출력
    for (const auto& c : couples) {
        std::cout << "a: " << c.at(0) << ", b: " << c.at(1) << std::endl;
    }

    return 0;
}
