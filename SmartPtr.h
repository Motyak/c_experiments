#ifndef SMART_PTR_H
#define SMART_PTR_H

// #include <map>

template<class T>
class SmartPtr
{
    T* ptr;
    // static std::map<SmartPtr<T>,T> smartPtrs;

    static void updateDict();

  public:
    SmartPtr();
    SmartPtr(const T &value);
    ~SmartPtr();
    T* getPtr();
    void setPtr(T* addr);
    void setPtr(SmartPtr<T>& addr);
};
template<class T>
SmartPtr<T>::SmartPtr()
{
    this->ptr = nullptr;
}

template<class T>
SmartPtr<T>::SmartPtr(const T &value)
{
    this->ptr = new T(value);
}

template<class T>
SmartPtr<T>::~SmartPtr()
{
    delete(this->ptr);
    this->ptr = nullptr;
    // faire en sorte que tous les autres smart pointers pointant vers 
    // cette espace mémoire soit mis à nullptr.
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

// template<class T>
// void SmartPtr<T>::updateDict()
// {
//     // si la clé n'existe pas
//     this->smartPtrs.insert(std::make_pair<SmartPtr,T>(this, this->ptr));
//     // sinon
//     this->smartPtrs[this] = this->ptr;
// }

// template<class T>
// void SmartPtr<T>::removeFromDict(T* ptr)
// {
//     // chaque element du dict contenant cette valeur devra être détruit
// }

#endif