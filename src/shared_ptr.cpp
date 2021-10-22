#include "shared_ptr.h"


template<class T>
void shared_ptr<T>::constructionFunction (const shared_ptr<T>& ptr)
{
    this->data = ptr.data;
    this->refs = ptr.refs;

    if (ptr.data != nullptr)
    {   
        (*(this->refs))++;
    }
}

template<class T>
void shared_ptr<T>::cleanFunction ()
{
    if (*(this->refs) == 1)
    {
        delete this->refs;
        delete this->data;
    }
    else if (*(this->refs) == 0)
    {
        delete this->refs;
    }
    else
    {
        (*(this->refs))--;
    }
}

template<class T>
void shared_ptr<T>::reset(T * external_data)
{
    cleanFunction();
    this->data = external_data;
    this->refs = new size_t(1);
}

template class shared_ptr<int>;
template class shared_ptr<std::string>;
