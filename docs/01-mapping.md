# Biology ↔ Machine mapping

| Bio | Machine | C++ example |
|---|---|---|
| DNA | Stored instructions | `class DNA` |
| Cell membrane | Validated I/O boundary | `CellMembrane::allows()` |
| Protein packages | Messages / packets | `struct Package` |
| Vacuoles | Cleanup | `Vacuole::clear()` |
| Mitochondria | Energy budget | `Mitochondria::consume()` |
| ER | Assembly / transport pipeline | `std::queue<Package>` |
| Ribosomes | Instructions → product | `Ribosome::synthesize()` |

**Limitations:** Ribosomes translate mRNA rather than compile software; DNA is not executable source code; cellular membranes are more complex than firewalls; vacuoles do more than trash removal. These analogies are learning tools.

## Questions to explore
- What happens when energy is insufficient?
- How do messages move in order?
- Which data should be private inside a class?
- How would feedback change cell behavior?
