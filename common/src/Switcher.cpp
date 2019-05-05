// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

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