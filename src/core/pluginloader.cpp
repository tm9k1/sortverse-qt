#include <iostream>
#include <dlfcn.h>
#include "pluginloader.h"

PluginLoader *PluginLoader::instance() {
    static PluginLoader *instance = new PluginLoader();
    return instance; 
}

PluginLoader::PluginLoader() 
{
    void *handle;
    char *error;
    handle = dlopen("../lib/plugins/libmergeSort.so", RTLD_LAZY);
    if (!handle) {
        std::cout << "could not load dlopen" << std::endl;
        fputs (dlerror(), stderr);
        exit(1);
    }
    // void* instance = dlsym(handle, "instance");
    class_signature instance = reinterpret_cast<class_signature>(dlsym(handle, "instance"));
    if ((error = dlerror()) != NULL) {
        std::cout << "could not load dlsym" << std::endl;
        fputs(error, stderr);
        exit(1);
    }
    
    SortVersePlugin* ptr = (*instance)();
    m_plugins.push_back(ptr);
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

