# Bio-Link: C++ Basics

Biology → Computer Engineering → C++

Think of a cell as a tiny autonomous system: it stores instructions, communicates, processes energy, transports materials, and manages waste.

| Biology | Computer equivalent | C++ application |
|---|---|---|
| DNA | Source code / stored instructions | Classes, functions, configuration |
| Cell membrane | Firewall + I/O interface | APIs, validation, access control |
| Golgi apparatus | Message packaging and routing | Queues, serialization, dispatch |
| Vacuoles | Storage and waste handling | Buffers, memory management, cleanup |
| Mitochondria | Power supply + energy management | Power-aware programming, sleep modes |

These are analogies, not exact biological equivalences. Lysosomes are a closer analogy for cellular breakdown and recycling.

## C++ examples

### DNA — instructions
```cpp
class Robot {
public:
    void move();
    void stop();
};
```
DNA contains biological instructions; a class defines software structure and behavior.

### Cell membrane — input/output security
```cpp
if (temperature < MAX_TEMP) {
    motor.start();
} else {
    motor.stop();
}
```
A membrane regulates transport and signaling; software can validate interactions.

### Golgi apparatus — message routing
```cpp
std::queue<Message> outgoing;
outgoing.push(sensorMessage);
```
The Golgi modifies, sorts, and packages molecules; queues prepare messages for processing or delivery.

### Vacuoles — storage and cleanup
```cpp
std::vector<int> samples;
samples.clear();
```
Vacuoles store materials and may participate in waste handling. `clear()` removes vector elements but does not necessarily release its capacity.

### Mitochondria — energy management
```cpp
if (batteryLevel < 20) {
    enterLowPowerMode();
}
```
Mitochondria produce ATP from nutrients; embedded systems monitor and conserve power.

## ESP32 robot connection

- DNA → firmware instructions
- Cell membrane → sensor input and actuator output boundaries
- Golgi → message queue
- Vacuole → data buffers and cleanup
- Mitochondria → battery and power-management logic

**Design question:** How can we design computers that regulate themselves as reliably and efficiently as living cells?
