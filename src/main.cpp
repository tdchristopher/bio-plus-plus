#include "cell.hpp"
#include <iostream>

int main() {
    // 1 = namespace, 2 = class, 3 = variable (object)
    bpp::DNA dna("ATGC");
    std::cout << "DNA: " << dna.sequence() << '\n';

    bpp::Cell cell("ATGC", 25);
    std::cout << "Starting energy: " << cell.energy() << '\n';

    // Ribosomes need energy to make packages.
    for (int i = 0; i < 3; ++i) {
        std::cout << "Protein synthesis: "
                  << (cell.makeProtein() ? "success" : "stopped: low energy")
                  << '\n';
    }

    // Cell membrane checks incoming messages.
    std::cout << "Receive nutrient: "
              << (cell.receive({"nutrient"}) ? "allowed" : "blocked") << '\n';
    std::cout << "Receive empty package: "
              << (cell.receive({""}) ? "allowed" : "blocked") << '\n';

    // ER transports packages in first-in, first-out order.
    while (cell.hasPackages()) {
        std::cout << "ER shipped: " << cell.shipNext().contents << '\n';
    }

    // Vacuole stores waste and then cleans up.
    cell.discard("old protein");
    std::cout << "Waste before cleanup: " << cell.wasteCount() << '\n';
    cell.cleanUp();
    std::cout << "Waste after cleanup: " << cell.wasteCount() << '\n';
    std::cout << "Remaining energy: " << cell.energy() << '\n';
}
