#include <math.h>
#include <iostream>
#include "Cidade.hpp"

Cidade::Cidade(int x, int y)
{
    this->x = x;
    this->y = y;
}
int Cidade::getX(){return this->x;}
int Cidade::getY(){return this->y;}

Cidade::~Cidade()
{
}