// #pragma once - не е сигурно дали компилаторът го поддържа; не позволява нещо да се include-не 2пъти
#define X

#if defined(X)
//...
#endif


#ifndef _LIBRARY_H //header guard
#define _LIBRARY_H

int factorial(int n);

#endif //_LIBRARY_H