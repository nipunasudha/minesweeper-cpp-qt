#ifndef UTILS
#define UTILS
#include <cstdlib>
#include <ctime>

namespace utils{
    inline bool randbool(int weight){
    return (rand()%weight)==0;
    }
};

enum class  BoxState
{
    unclicked, clicked, exploded
};
#endif
