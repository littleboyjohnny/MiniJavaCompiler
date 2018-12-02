#include "../include/Switcher.h"


template<typename T>
CSwitcher<T>::CSwitcher( T& _object, const T& _oldValue ) :
    object( _object ),
    oldValue( _oldValue )
{
    //
}

template<typename T>
CSwitcher<T>::~CSwitcher()
{
    object = oldValue;
}