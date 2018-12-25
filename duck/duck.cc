#include "duck.h"

void func(Duck& duck) {
    duck.performFly();
    duck.performQuack();
}

int
main()
{
    MallarDuck mallar_duck;

    func(mallar_duck);

    return 0;
}
