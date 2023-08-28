#ifndef PLUGINLOADER_H
#define PLUGINLOADER_H
#include<vector>
#include "sortverseplugin.h"

typedef std::vector<int>(*sort_signature)(const std::vector<int>&);
typedef SortVersePlugin* (*class_signature)();

class PluginLoader 
{
private:
    std::vector<SortVersePlugin*> m_plugins; // save the address binding of plugin functionality for later reuse
    std::vector<void*> dlHandles; // saving the handles to close them later on
    PluginLoader();
    PluginLoader(PluginLoader&);
public:
    ~PluginLoader();
    static PluginLoader* instance();
    std::vector<SortVersePlugin*> getPlugins();
};

#endif // PLUGINLOADER_H