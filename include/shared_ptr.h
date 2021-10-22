#pragma once
#include <string>
#include <cstddef>

template <class T>
class shared_ptr
{
private:
    T * data = nullptr;
    size_t * refs = nullptr;

public:
    void constructionFunction (const shared_ptr& ptr);
    void cleanFunction ();

    // default constructor
    shared_ptr () : data(nullptr), refs(new size_t(0)) { }

    // constructor from pointer
    shared_ptr (T * external_data) : data(external_data), refs(new size_t(1)) { }

    // copy constructor
    shared_ptr (const shared_ptr& ptr)
    {
        this->constructionFunction(ptr);
    }

    // assignment constructor
    shared_ptr& operator=(const shared_ptr& ptr)
    {
        this->cleanFunction();
        this->constructionFunction(ptr); 
    }

    T* operator* () const 
    {
        return this->data;
    }

    // destructor
    ~shared_ptr ()
    {
        this->cleanFunction();
    }    

    void reset(T * external_data);
};

