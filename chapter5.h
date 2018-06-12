///////////////////////////////////////////////////////////////////////////////
/// brief    %{Cpp:License:ClassName}
///
/// author  Александр Галко - ОКБ ТСП
/// date    12.6.2018
////////////////////////////////////////////////////////////////////////////////
#ifndef CHAPTER5_H
#define CHAPTER5_H

#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <random>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

namespace std
{
    ostream& operator<<(ostream& os, const pair<int, string>& p)
    {
        return os << "(" << p.first << "," << p.second << ")";
    }
} // namespace std

namespace chapter5
{
    void example1()
    {
        vector<int> v = {100, 400, 200};
        /// depreceted
        int sum = 0;
        for (int i : v)
        {
            sum += i;
        }
        cout << sum << endl;
        /// true variant
        cout << accumulate(begin(v), end(v), 0) << endl;
    }
    void example2() /// copy
    {
        vector<pair<int, string>> v = {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}};
        map<int, string> m;
        copy_n(begin(v), 3, inserter(m, begin(m)));
        auto shell_it(ostream_iterator<pair<int, string>>(cout, ","));
        copy(begin(m), end(m), shell_it);
        cout << endl;
        m.clear();
        move(begin(v), end(v), inserter(m, begin(m)));
        copy(begin(m), end(m), shell_it);
        cout << endl;
        copy(begin(v), end(v), shell_it);
        cout << endl;
    }

    static void print(const vector<int> &v)
    {
        copy(begin(v), end(v), ostream_iterator<int>(cout, ","));
        cout << endl;
    }
    void example3() /// sort
    {
        vector<int> v = {1, 2, 3, 4, 5, 6, 7, 9, 10};
        random_device rd;
        mt19937 g(rd());
        cout << is_sorted(begin(v), end(v)) << endl;
        shuffle(begin(v), end(v), g);
        cout << is_sorted(begin(v), end(v)) << endl;
        print(v);
        sort(begin(v), end(v));
        cout << is_sorted(begin(v), end(v)) << endl;
        print(v);
        shuffle(begin(v), end(v), g);
        partition(begin(v), end(v), [](int i){return i < 5; });
        print(v);
        shuffle(begin(v), end(v), g);
        auto middle (next(begin(v), int(v.size()) / 2));
        partial_sort(begin(v), middle, end(v));
        print(v);

        struct mystruct
        {
            int a;
            int b;
        };
        vector<mystruct> mv {{5, 100}, {1, 50}, {-123, 1000},{3, 70}, {-10, 20}};
        sort(begin(mv), end(mv),[] (const mystruct &lhs, const mystruct &rhs)
        {
            return lhs.b < rhs.b;
        });
        for (const auto &s : mv)
        {
        cout << "{" << s.a << ", " << s.b << "} ";
        }
        cout << '\n';
    }

} // namespace chapter5

#endif // CHAPTER5_H
