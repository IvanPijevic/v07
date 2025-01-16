#include "money.h"


namespace vsite::oop::v7
{
    money::money(int euro, int cent) :
        m_sum(euro * 100 + cent)
    {}

    money money::operator+(const money& m) const
    {
        return money(0, m_sum + m.m_sum);
    }
    money money::operator-(const money& m) const
    {
        return money(0, m_sum - m.m_sum);
    }

    money& money::operator+=(const money& m)
    {
        this->m_sum += m.m_sum;
        return *this;
    }

    money& money::operator-=(const money& m)
    {
        this->m_sum -= m.m_sum;
        return *this;
    }

    std::istream& operator>>(std::istream& is, money& m)
    {
        int euro, cent;
        is >> euro >> cent;
        m.m_sum = euro * 100 + cent;
        return is;
    }

    std::ostream& operator<<(std::ostream& os, const money& m)
    {
        int abs_sum = std::abs(m.m_sum);
        int euros = abs_sum / 100;
        int cents = abs_sum % 100;

        if (m.m_sum < 0)
        {
            os << "-";
        }

        if (euros > 0)
        {
            if (cents == 0)
            {
                os << euros << " euro";
            }
            else
            {
                os << euros << " euro, " << std::format("{:02d} cent", cents);
            }
        }
        else {
            os << std::format("{:02d} cent", cents);
        }

        return os;
    }


}