#pragma once
#include <iostream>
#include <format>

namespace vsite::oop::v7
{

    class money
    {
    public:
        money(int euro = 0, int cent = 0);

        money operator+(const money& m) const;
        money operator-(const money& m) const;

        money& operator+=(const money& m);
        money& operator-=(const money& m);


        friend std::istream& operator>>(std::istream& is, money& m);
        friend std::ostream& operator<<(std::ostream& os, const money& m);

    private:
        int m_sum;
    };

}