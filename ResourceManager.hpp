#pragma once

#include "Resource.hpp"
//#include <iostream>

class ResourceManager
{
    // Twoja implementacja tutaj
public:
    ResourceManager();
    {
        rsrc = NULL;
        liczba = NULL;
    }
    ~ResourceManager()
    {
        //std::cout << : "Usunieto kopie zasobu";
    }
    double get()
    {
        liczba = rsrc.get();
        return liczba;
    }
    ResourceManager(const ResourceManager& kopia)
    {
        liczba = kopia.liczba;
        rsrc = kopia.rsrc;
    }
    ResourceManager operator=(const ResourceManager& wartosc)
    {
        liczba = wartosc.liczba;
        rsrc = wartosc.rsrc;
    }
    ResourceManager(ResourceManager&& zmiana) noexcept: liczba{zmiana.liczba}, rsrc{zmiana.rsrc}
    {
        zmiana.liczba = NULL;
        zmiana.rsrc = NULL;
    }
        
private:
    double liczba;
    Resource rsrc;
};
