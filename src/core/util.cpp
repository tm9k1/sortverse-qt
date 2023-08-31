#include "util.h"

Util* Util::instance()
{
    static Util *instance = new Util();
    return instance;
}

std::string Util::appDirPath()
{
    if (m_appDirPath == "") {

#ifdef UNIX
        char result[PATH_MAX];
        ssize_t count = readlink("/proc/self/exe", result, PATH_MAX);
        const char *path_exe;
        if (count != -1) {
            path_exe = dirname(result);
        }
        m_appDirPath = (std::string)path_exe + "/"; 

#elif WIN32

#endif
    }
    return m_appDirPath;
}