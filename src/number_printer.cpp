// number_printer/src/number_printer.cpp
#include "rclcpp/rclcpp.hpp"

class NumberPrinter : public rclcpp::Node {
public:
    NumberPrinter() : Node("number_printer"), number_(0) {
        timer_ = this->create_wall_timer(
            std::chrono::seconds(1),
            std::bind(&NumberPrinter::print_number, this)
        );
    }

private:
    void print_number() {
        RCLCPP_INFO(this->get_logger(), "Current number: %d", number_);
        number_++;
    }

    int number_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<NumberPrinter>());
    rclcpp::shutdown();
    return 0;
}
