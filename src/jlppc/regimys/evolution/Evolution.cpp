#include "Evolution.hpp"

Evolution::Evolution(int evo) : evo(evo) {
}

void Evolution::checkEvo() {
    //toEvolve = Initializer::listeOp[evo];
}

Species *Evolution::getEvolution() const {
    return toEvolve;
}

