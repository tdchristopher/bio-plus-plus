#include <iostream>
#include <queue>
#include <string>
#include <vector>

struct Message { std::string payload; };

class Robot {
public:
    void move() { std::cout << "Moving\n"; }
    void stop() { std::cout << "Stopped\n"; }
};

int main() {
    Robot motor;
    constexpr int MAX_TEMP = 70;
    int temperature = 45;
    if (temperature < MAX_TEMP) motor.move(); else motor.stop();

    std::queue<Message> outgoing;
    outgoing.push({"sensor reading"});
    std::cout << "Queued: " << outgoing.front().payload << '\n';
    outgoing.pop();

    std::vector<int> samples{10, 20, 30};
    samples.clear();

    int batteryLevel = 15;
    if (batteryLevel < 20) std::cout << "Enter low-power mode\n";
}
