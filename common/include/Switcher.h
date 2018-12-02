//
// Created by ivb on 02.12.18.
//

#ifndef MINIJAVACOMPILER_SWITCHER_H
#define MINIJAVACOMPILER_SWITCHER_H

template<typename T>
class CSwitcher {
public:
    CSwitcher( T& _object, const T& _oldValue );

    ~CSwitcher();

private:
    T& object;
    const T& oldValue;
};


#endif //MINIJAVACOMPILER_SWITCHER_H
