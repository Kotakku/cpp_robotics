---
title: include/cpp_robotics/algorithm/misc.hpp

---

# include/cpp_robotics/algorithm/misc.hpp



## Namespaces

| Name           |
| -------------- |
| **[cpp_robotics](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/)**  |




## Source code

```cpp
#pragma once

namespace cpp_robotics
{

    // constexpr unsigned long fact(const unsigned long n)
    // {
    //     if(n == 0)
    //         return 1;
    //     return n * fact(n-1);
    // }

    // constexpr unsigned long combination(const unsigned long n, const unsigned long r)
    // {
    //     if (n == 0)
    //         return 1;
    //     else if (r == 0)
    //         return 1;
    //     else if (n == r)
    //         return 1;
    //     else
    //         return combination(n - 1, r) + combination(n - 1, r - 1);
    // }

    // template<int N, int R, typename Callable>
    // constexpr void combi_call_impl(int num, size_t K[R], int p, int w, int n, int r, Callable && f)
    // {
    //     std::array<size_t, R> comb = {};

    //     if (p > 0)
    //     {
    //         for (int i = 0; i <= w; i++)
    //         {
    //             K[p] = i;
    //             combi_call_impl(num, K, p - 1, w - i, n, r, f);
    //         }
    //     }
    //     else
    //     {
    //         int m = 0, pick = 0;

    //         for (int i = 1; i <= r; i++)
    //         {
    //             for (int j = 0; j < K[i]; j++, m++)
    //                 pick++;
    //             comb[m] = pick;
    //             m++;
    //         }
    //         f(num, p);
    //         num++;
    //     }
    // }

    // template<int N, int R, typename Callable>
    // constexpr void combi_call(Callable && f)
    // {
        
    //     size_t K[R] = {};
    //     size_t num = 0;

    //     combi_call_impl(num, K, R, N-R, N, R, f);

    //     // auto combi_impl = [&f, &comb, &K, &num, &combi_impl](int p, int w, int n, int r) {
    //     //     if (p > 0)
    //     //     {
    //     //         for (int i = 0; i <= w; i++)
    //     //         {
    //     //             K[p] = i;
    //     //             combi_impl(p - 1, w - i, n, r);
    //     //         }
    //     //     }
    //     //     else
    //     //     {
    //     //         int m = 0, pick = 0;

    //     //         for (int i = 1; i <= r; i++)
    //     //         {
    //     //             for (int j = 0; j < K[i]; j++, m++)
    //     //                 pick++;
    //     //             comb[m] = pick;
    //     //             m++;
    //     //         });
    //     //         f(num, p);
    //     //         num++;
    //     //     }
    //     // }(R, N - R, N, R);
        
    // }

    // template<int N = 5, int R = 3>
    // constexpr auto combi_call_test()
    // {
    //     std::array<std::array<size_t, R>, combination(N, R)> re = {};
    //     combi_call<N, R>([&re](size_t num, auto p){
    //         //re[num] = p;
    //     });

    //     return re;
    // }

    // template<size_t conum>
    // using twcoeff = std::array<size_t, conum>;

    // template<>
    // using twcoeff = std::array<size_t, 3>{1, 2, 1};

    // template<>
    // using twcoeff = std::array<size_t, 4>{1, 3, 3, 1};

}
```


-------------------------------

Updated on 2022-09-28 at 01:12:56 +0900
