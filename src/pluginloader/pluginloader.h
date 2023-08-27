#ifndef PLUGINLOADER_H
#define PLUGINLOADER_H
#include<vector>

class PluginLoader 
{
private:
    static PluginLoader* ptr;
    std::vector<void*> sortFunctions;
    std::vector<void*> dlHandles;
    PluginLoader();
    PluginLoader(PluginLoader&);
public:
    ~PluginLoader();
    static PluginLoader* getInstance() {
        if (!ptr) {
            ptr = new PluginLoader();
        }
        return ptr;
    }
    std::vector<void*> getSortFunctions();
};

#endif // PLUGINLOADER_H