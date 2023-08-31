#include <iostream>
#include <dlfcn.h>
#include <filesystem>

#include "pluginloader.h"
#include "util.h"

namespace fs = std::filesystem;

PluginLoader *PluginLoader::instance() {
    static PluginLoader *instance = new PluginLoader();
    return instance; 
}

PluginLoader::PluginLoader() 
{
    void *handle;
    char *error;
    std::string path = Util::instance()->appDirPath() + (std::string)"../lib/plugins";
    for (const auto & entry : fs::directory_iterator(path)) {
        // TODO: make it load plugins with OS-specific extension only (.dll vs .so)
        handle = dlopen(entry.path().c_str(), RTLD_LAZY);
        if (!handle) {
            std::cout << "could not load dlopen" << std::endl;
            fputs (dlerror(), stderr);
            continue;    
        }
        class_signature instance = reinterpret_cast<class_signature>(dlsym(handle, "instance"));
        if ((error = dlerror()) != NULL) {
            std::cout << "could not load dlsym" << std::endl;
            fputs(error, stderr);
            continue;
        }
        SortVersePlugin* ptr = (*instance)();
        m_plugins.push_back(ptr);
    }
}

PluginLoader::~PluginLoader()
{
    for(void* handle : dlHandles) {
        dlclose(handle);
    }
}

std::vector<SortVersePlugin*> PluginLoader::getPlugins() {
    return m_plugins;
}

