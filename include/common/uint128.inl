/*!
    \file uint128.inl
    \brief Unsigned 128-bit integer type inline implementation
    \author Ivan Shynkarenka
    \date 11.10.2017
    \copyright MIT License
*/

namespace CppCommon {

inline uint128_t::uint128_t() noexcept
    : _upper(0), _lower(0)
{
}

template <typename T>
inline uint128_t::uint128_t(const T& value) noexcept
    : _upper(0), _lower(value)
{
    static_assert(std::is_integral<T>::value, "Input argument type must be an integer!");
}

template <typename TUpper, typename TLower>
inline uint128_t::uint128_t(const TUpper& upper, const TLower& lower) noexcept
    : _upper(upper), _lower(lower)
{
    static_assert((std::is_integral<TUpper>::value && std::is_integral<TLower>::value), "Input argument types must be integers!");
}

template <typename T>
inline uint128_t& uint128_t::operator=(const T& value) noexcept
{
    static_assert(std::is_integral<T>::value, "Input argument type must be an integer!");

    _upper = 0;
    _lower = value;
    return *this;
}

inline uint128_t operator+(const uint128_t& value1, const uint128_t& value2) noexcept
{
    return uint128_t(value1._upper + value2._upper + (((value1._lower + value2._lower) < value1._lower) ? 1 : 0), value1._lower + value2._lower);
}

inline uint128_t operator-(const uint128_t& value1, const uint128_t& value2) noexcept
{
    return uint128_t(value1._upper - value2._upper - (((value1._lower - value2._lower) > value1._lower) ? 1 : 0), value1._lower - value2._lower);
}

inline uint128_t operator/(const uint128_t& value1, const uint128_t& value2)
{
    return uint128_t::divmod(value1, value2).first;
}

inline uint128_t operator%(const uint128_t& value1, const uint128_t& value2)
{
    return uint128_t::divmod(value1, value2).second;
}

inline uint128_t operator&(const uint128_t& value1, const uint128_t& value2) noexcept
{
    return uint128_t(value1._upper & value2._upper, value1._lower & value2._lower);
}

inline uint128_t operator|(const uint128_t& value1, const uint128_t& value2) noexcept
{
    return uint128_t(value1._upper | value2._upper, value1._lower | value2._lower);
}

inline uint128_t operator^(const uint128_t& value1, const uint128_t& value2) noexcept
{
    return uint128_t(value1._upper ^ value2._upper, value1._lower ^ value2._lower);
}

inline bool operator==(const uint128_t& value1, const uint128_t& value2) noexcept
{
    return ((value1._upper == value2._upper) && (value1._lower == value2._lower));
}

inline bool operator!=(const uint128_t& value1, const uint128_t& value2) noexcept
{
    return ((value1._upper != value2._upper) || (value1._lower != value2._lower));
}

inline bool operator<(const uint128_t& value1, const uint128_t& value2) noexcept
{
    return (value1._upper == value2._upper) ? (value1._lower < value2._lower) : (value1._upper < value2._upper);
}

inline bool operator>(const uint128_t& value1, const uint128_t& value2) noexcept
{
    return (value1._upper == value2._upper) ? (value1._lower > value2._lower) : (value1._upper > value2._upper);
}

inline bool operator<=(const uint128_t& value1, const uint128_t& value2) noexcept
{
    return ((value1 < value2) || (value1 == value2));
}

inline bool operator>=(const uint128_t& value1, const uint128_t& value2) noexcept
{
    return ((value1 > value2) || (value1 == value2));
}

inline bool operator&&(const uint128_t& value1, const uint128_t& value2) noexcept
{
    return ((bool)value1 && (bool)value2);
}

inline bool operator||(const uint128_t& value1, const uint128_t& value2) noexcept
{
    return ((bool)value1 || (bool)value2);
}

inline std::ostream& operator<<(std::ostream& os, const uint128_t& value)
{
    if (os.flags() & os.oct)
        os << value.string(8);
    else if (os.flags() & os.dec)
        os << value.string(10);
    else if (os.flags() & os.hex)
        os << value.string(16);
    return os;
}

inline void uint128_t::swap(uint128_t& value) noexcept
{
    using std::swap;
    swap(_upper, value._upper);
    swap(_lower, value._lower);
}

inline void swap(uint128_t& value1, uint128_t& value2) noexcept
{
    value1.swap(value2);
}

} // namespace CppCommon
