#ifndef _DEBUG_HPP_
#define _DEBUG_HPP_

#include <unistd.h>

#define TRACE(t) std::cout << (#t) << "=" << (t) << std::endl

#define SAY(t) std::cout << (t) << std::endl

#define SLP(t) sleep(t)

#endif