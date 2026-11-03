#pragma once
#include <cstddef>
#include <queue>
#include <string>
#include <utility>
#include <vector>

namespace bpp {

// DNA: stored instructions. This is a simplified string, not a genome model.
class DNA {
public:
    explicit DNA(std::string sequence) : sequence_(std::move(sequence)) {}
    const std::string& sequence() const { return sequence_; }
private:
    std::string sequence_;
};

// Protein package: a message passed through the cell.
struct Package {
    std::string contents;
};

// Membrane: a boundary that decides what may enter.
class CellMembrane {
public:
    bool allows(const Package& package) const {
        return !package.contents.empty() && package.contents.size() <= 32;
    }
};

// Mitochondria: a simplified energy budget.
class Mitochondria {
public:
    explicit Mitochondria(int energy) : energy_(energy < 0 ? 0 : energy) {}
    bool consume(int amount) {
        if (amount < 0 || amount > energy_) return false;
        energy_ -= amount;
        return true;
    }
    int remaining() const { return energy_; }
private:
    int energy_;
};

// Ribosome: builds a product from an instruction (teaching analogy only).
class Ribosome {
public:
    Package synthesize(const std::string& instruction) const {
        return {"protein:" + instruction};
    }
};

// ER: routes completed packages for processing.
class EndoplasmicReticulum {
public:
    void enqueue(Package package) { packages_.push(std::move(package)); }
    bool hasPackages() const { return !packages_.empty(); }
    Package dispatch() {
        if (packages_.empty()) return {""};
        Package next = packages_.front();
        packages_.pop();
        return next;
    }
private:
    std::queue<Package> packages_;
};

// Vacuole: clears stored waste (vector manages memory automatically).
class Vacuole {
public:
    void collect(std::string waste) { waste_.push_back(std::move(waste)); }
    std::size_t count() const { return waste_.size(); }
    void clear() { waste_.clear(); }
private:
    std::vector<std::string> waste_;
};

class Cell {
public:
    Cell(std::string dna, int energy)
        : dna_(std::move(dna)), mitochondria_(energy) {}

    // Safe behavior: no energy => no synthesis.
    bool makeProtein() {
        if (!mitochondria_.consume(10)) return false;
        er_.enqueue(ribosome_.synthesize(dna_.sequence()));
        return true;
    }

    bool receive(const Package& package) {
        if (!membrane_.allows(package)) return false;
        er_.enqueue(package);
        return true;
    }

    Package shipNext() { return er_.dispatch(); }
    bool hasPackages() const { return er_.hasPackages(); }
    int energy() const { return mitochondria_.remaining(); }
    void discard(std::string waste) { vacuole_.collect(std::move(waste)); }
    std::size_t wasteCount() const { return vacuole_.count(); }
    void cleanUp() { vacuole_.clear(); }

private:
    DNA dna_;
    CellMembrane membrane_;
    Mitochondria mitochondria_;
    Ribosome ribosome_;
    EndoplasmicReticulum er_;
    Vacuole vacuole_;
};

} // namespace bpp
