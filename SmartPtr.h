#ifndef SMART_PTR_H
#define SMART_PTR_H

#include <map>
#include <iostream>

template<class T>
class SmartPtr
{
    T* ptr;
    static std::map<SmartPtr<T>*,T*> smartPtrs;

    void addToDict();
    // void updateDict();
    // void removeFromDict();

  public:
    SmartPtr();
    SmartPtr(const T &value);
    ~SmartPtr();
    T* getPtr();
    void setPtr(T* addr);
    void setPtr(SmartPtr<T>& addr);
};

template<class T>
std::map<SmartPtr<T>*,T*> SmartPtr<T>::smartPtrs;

template<class T>
SmartPtr<T>::SmartPtr()
{
    this->ptr = nullptr;
    this->addToDict();
}

template<class T>
SmartPtr<T>::SmartPtr(const T &value)
{
    this->ptr = new T(value);
    this->addToDict();
}

template<class T>
SmartPtr<T>::~SmartPtr()
{
    delete(this->ptr);
    // this->ptr = nullptr;
    // faire en sorte que tous les autres smart pointers pointant vers 
    // cette espace mémoire soit mis à nullptr.
    // this->removeFromDict();
}

template<class T>
T* SmartPtr<T>::getPtr()
{
    return this->ptr;
}

template<class T>
void SmartPtr<T>::setPtr(T* addr)
{
    this->ptr = addr;
}

template<class T>
void SmartPtr<T>::setPtr(SmartPtr<T>& ptr)
{
    this->ptr = ptr.getPtr();
}

template<class T>
void SmartPtr<T>::addToDict()
{
    SmartPtr::smartPtrs.insert(std::make_pair<SmartPtr<T>*,T*>(this, this->getPtr()));
    std::cout<<"\n<added "<<this<<" to dict>\n"<<std::endl;
}

// template<class T>
// void SmartPtr<T>::updateDict()
// {
//     SmartPtr.smartPtrs[this] = this->ptr;
// }

// template<class T>
// void SmartPtr<T>::removeFromDict()
// {
//     // chaque element du dict contenant cette valeur devra être détruit
//     for(auto const& e : SmartPtr.smartPtrs)
//     {
//         if(e.second == this->ptr)
//         {
//             e.first.setPtr(nullptr);
//             SmartPtr.smartPtrs.erase(SmartPtr.smartPtrs.find(e));
//         }   
//     }
// }

#endif