#include "epch.hpp"
#include "Entity.hpp"

Entity();
~Entity();

void preUpdate();

void initialize() = 0;
void update() = 0;

void destroy();
