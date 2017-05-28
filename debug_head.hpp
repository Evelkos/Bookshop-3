#ifndef DEBUG_HEAD_HPP_INCLUDED
#define DEBUG_HEAD_HPP_INCLUDED

#ifndef DEBUG
    #define DEBUG 1
#endif // DEBUG

#if DEBUG
    #define D(x) x
#else
    #define D(x)
#endif // accumulate

#endif // DEBUG_HEAD_HPP_INCLUDED
