#include "pluginloader.h"
#include <dlfcn.h>
#include <iostream>

// typedef std::vector<int>(*sort_signature)(const std::vector<int>&);
typedef int(*int_sig)(void);

PluginLoader::PluginLoader() 
{
    void *handle;
    // std::vector<int> (*sort)(const std::vector<int>&);
    char *error;
    handle = dlopen("../lib/plugins/mergeSort.dll", RTLD_LAZY);
    if (!handle) {
        std::cout << "could not load dlopen" << std::endl;
        fputs (dlerror(), stderr);
        exit(1);
    }
    // sort = reinterpret_cast<sort_signature>(dlsym(handle, "sort"));
    // int_signature = reinterpret_cast<int_sig>(dlsym(handle, "func"));
    // int_signature = reinterpret_cast<int_sig>(dlsym(handle, "func"));
    int_sig hello = (int_sig) dlsym(handle, "hello");
    if ((error = dlerror()) != NULL) {
        std::cout << "could not load dlsym" << std::endl;
        fputs(error, stderr);
        exit(1);
    }
    // (*int_signature)();
    // sortFunctions.push_back(sort);
}

PluginLoader::~PluginLoader()
{
    for(void* handle : dlHandles) {
        dlclose(handle);
    }
}

std::vector<void*> PluginLoader::getSortFunctions() {
    return sortFunctions;
}

