#pragma once

#include "Resource.hpp"

class ResourceManager
{
    // Twoja implementacja tutaj
public:
    ResourceManager()
    {
        rsrc = new Resource();
        
    }
    ~ResourceManager()
    {
        delete rsrc;
    }
    double get()
    { 
        return rsrc->get();
        
    }
    ResourceManager(const ResourceManager& kopia) : rsrc(new Resource(*kopia.rsrc))
    {}
    ResourceManager operator=(const ResourceManager& wartosc)
    {
        if (this != &wartosc)
        {
            Resource* nowy = new Resource(*wartosc.rsrc);
            delete rsrc;
            rsrc = nowy;
        }
        return *this;       
    }
    ResourceManager(ResourceManager&& zmiana) noexcept: rsrc{zmiana.rsrc}
    {
        
        zmiana.rsrc = nullptr;
    }
    ResourceManager& operator=(ResourceManager&& inny) noexcept
    {
        if (this != &inny) {
            delete rsrc;
            rsrc = inny.rsrc;
            inny.rsrc = nullptr;
        }
        return *this;
    }
        
private:
    Resource* rsrc;
};
