#pragma once

#include <cmath>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <chrono>
#define WINDOW_WIDTH 1000

#define WINDOW_HEIGHT 1000

typedef float fpt;

#define LOG_DEBUG(x) do { std::cout << "[DEBUG] " << __FILE__ << ":" << __LINE__ << ":" << __func__ << "() " << x << std::endl; } while (0);

#define LOG_ERROR(x) do { std::cerr << "[ERROR] " << __FILE__ << ":" << __LINE__ << ":" << __func__ << "() " << x << std::endl; } while (0);

#define LOG_WARNING(x) do { std::cerr << "[WARNING] " << __FILE__ << ":" << __LINE__ << ":" << __func__ << "() " << x << std::endl; } while (0);

#define LOG_INFO(x) do { std::cout << "[INFO] " << __FILE__ << ":" << __LINE__ << ":" << __func__ << "() " << x << std::endl; } while (0);

#define MAX(x, y) (((x) > (y)) ? (x) : (y))

#define MIN(x, y) (((x) < (y)) ? (x) : (y))

/* Maths */
#define PI                  3.14159265359
#define RAD2DEG(x)          ((x)/PI*180)
#define DEG2RAD(x)          ((x)*PI/180)
#define ALIGNB(x, align)    (((x) + ((align) - 1)) & ~((align) - 1))
#define ALIGN(x, align)     ((((x) + ((align) - 1)) / (align)) * (align))
#define FLOORB(x, align)    ((x) & ~((align) - 1))
#define FLOOR(x, align)     (((x) / (align)) * (align))
#define CEILB(x, align)     ALIGNB(x, align)
#define CEIL(x, align)      ALIGN(x, align)
#define CLIP(x, min, max)   (((x) < (min)) ? (min) : \
                            (((x) > (max)) ? (max) : (x)))
#define UCLIP(x, max)       (((x) > (max)) ? (max) : (x))
#define LCLIP(x, min)       (((x) < (min)) ? (min) : (x))
#define MIN(x, y)           (((x) < (y)) ?  (x) : (y))
#define MAX(x, y)           (((x) > (y)) ?  (x) : (y))
#define ABS(x)              (((x) <  0) ? -(x) : (x))
#define DIFF(a,b)           ABS((a)-(b))
#define IS_NAN(x)            ((x) != (x))
#define IMPLIES(x, y)       (!(x) || (y))
#define SWAP(a, b)          do { a ^= b; b ^= a; a ^= b; } while ( 0 )
#define SORT(a, b)          do { if ((a) > (b)) SWAP((a), (b)); } while (0)
#define COMPARE(x, y)       (((x) > (y)) - ((x) < (y)))
#define SIGN(x)             COMPARE(x, 0)
#define IS_ODD( num )       ((num) & 1)
#define IS_EVEN( num )      (!IS_ODD( (num) ))
#define IS_BETWEEN(n,L,H)   ((unsigned char)((n) >= (L) && (n) <= (H)))

/* BITS */
#define BIT(x)          (1<<(x))
#define SETBIT(x,p)     ((x)|(1<<(p)))
#define CLEARBIT(x,p)   ((x)&(~(1<<(p))))
#define GETBIT(x,p)     (((x)>>(p))&1)
#define TOGGLEBIT(x,p)  ((x)^(1<<(p)))

/* ARRAYS */
#define ARRAY_SIZE(a) (sizeof(a) / sizeof((a)[0]))
#define SET(d, n, v)  do{ size_t i_, n_; \
                      for ( n_ = (n), i_ = 0; n_ > 0; --n_, ++i_) \
                      (d)[i_] = (v); } while(0)
#define ZERO(d, n)    SET(d, n, 0)
#define COLUMNS(S,E)  ( (E) - (S) + 1 )
#define IS_ARRAY(a)   ((void *)&a == (void *)a)

/* STRINGS */
#define STRING char*
#define STR2(s)             #s
#define STR(s)              STR2(s)
#define CAT(str1,str2)      (str1 "" str2)

std::ostream &operator<<(std::ostream &os, const sf::Vector2f &vector);

inline fpt norm(const sf::Vector2<fpt>& lhs) {
    return std::sqrt(std::pow(lhs.x, 2) + std::pow(lhs.y, 2));
}

inline sf::Vector2<fpt> unit(const sf::Vector2<fpt>& lhs) {
    return lhs / norm(lhs);
}

inline std::ostream &operator<<(std::ostream &os, const sf::Vector2<fpt> &vector) {
    os << "[x = " << vector.x << ", y = " << vector.y << "]";
    return os;
}

inline sf::Vector2<fpt> operator+(const sf::Vector2<fpt> &lhs, fpt scalar) {
    sf::Vector2<fpt> ret(lhs);
    ret.x += scalar;
    ret.y += scalar;
    return ret;
}

inline sf::Vector2<fpt> operator-(const sf::Vector2<fpt> &lhs, fpt scalar) {
    sf::Vector2<fpt> ret(lhs);
    ret.x -= scalar;
    ret.y -= scalar;
    return ret;
}

inline sf::Vector2<fpt> operator/(const sf::Vector2<fpt> &lhs, fpt scalar) {
    sf::Vector2<fpt> ret(lhs);
    ret.x /= scalar;
    ret.y /= scalar;
    return ret;
}

inline sf::Vector2<fpt> operator*(const sf::Vector2<fpt> &lhs, fpt scalar) {
    sf::Vector2<fpt> ret(lhs);
    ret.x *= scalar;
    ret.y *= scalar;
    return ret;
}

inline void mirrorVertical(sf::Vector2<fpt>& lhs) {
    lhs.y = -lhs.y;
}

inline void mirrorHorizontal(sf::Vector2<fpt>& lhs) {
    lhs.x = -lhs.x;
}