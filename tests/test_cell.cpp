#include "../src/cell.hpp"
#include <cassert>
#include <iostream>
#include <string>

int main() {
    bpp::DNA dna("ATGC");
    assert(dna.sequence() == "ATGC");

    bpp::Cell cell("ATGC", 20);
    assert(cell.makeProtein());
    assert(cell.makeProtein());
    assert(!cell.makeProtein()); // safety check: energy exhausted
    assert(cell.energy() == 0);

    assert(cell.receive({"nutrient"}));
    assert(!cell.receive({""}));
    assert(!cell.receive({std::string(33, 'x')}));

    assert(cell.shipNext().contents == "protein:ATGC");
    assert(cell.shipNext().contents == "protein:ATGC");
    assert(cell.shipNext().contents == "nutrient");
    assert(!cell.hasPackages());
    assert(cell.shipNext().contents.empty());

    cell.discard("waste");
    assert(cell.wasteCount() == 1);
    cell.cleanUp();
    assert(cell.wasteCount() == 0);

    bpp::Mitochondria energy(5);
    assert(!energy.consume(10));
    assert(!energy.consume(-1));
    assert(energy.remaining() == 5);

    std::cout << "All Bio++ tests passed!\n";
}
