#ifndef UTIL_H
#define UTIL_H

#include <string>

#ifdef UNIX

#include <libgen.h>         // dirname
#include <unistd.h>         // readlink
#include <linux/limits.h>   // PATH_MAX

#elif WIN32
#endif
class Util {
private:
    Util() {};
    Util(Util&) {};
    std::string m_appDirPath{""};
public:
    std::string appDirPath();
    static Util* instance();
};

#endif //UTIL_H