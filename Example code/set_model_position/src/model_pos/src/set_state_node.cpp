#include "rclcpp/rclcpp.hpp"
#include "gazebo_msgs/srv/set_entity_state.hpp"
#include <gazebo_msgs/msg/entity_state.hpp>
#include <chrono>
#include <memory>
#include <cmath>

using namespace std::chrono_literals;

class SetStateClient : public rclcpp::Node
{
public:
    SetStateClient() : Node("set_entity_state_client"), radius(4.0), angle(0.0), increment_angle(0.1)
    {
        client_ = this->create_client<gazebo_msgs::srv::SetEntityState>("set_entity_state");
        while (!client_->wait_for_service(1s))
        {
            RCLCPP_INFO(this->get_logger(), "Service not available, waiting ...");
        }
        state_.name = "unit_box";
        timer_ = this->create_wall_timer(100ms, std::bind(&SetStateClient::move_callback, this));
    }
private:
    rclcpp::Client<gazebo_msgs::srv::SetEntityState>::SharedPtr client_;
    rclcpp::TimerBase::SharedPtr timer_;
    gazebo_msgs::msg::EntityState state_;
    double radius, angle, increment_angle;
    
    void move_callback() 
    {
        state_.pose.position.x = radius * cos(angle);
        state_.pose.position.y = radius * sin(angle);

        auto request = std::make_shared<gazebo_msgs::srv::SetEntityState::Request>();
        request->state = state_;

        auto future_result = client_->async_send_request(request);

        angle += increment_angle;
        angle -= (angle >= 2 * M_PI) ? 2 * M_PI : 0;
    }
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    auto node = std::make_shared<SetStateClient>();
    rclcpp::spin(node);

    rclcpp::shutdown();
    return 0;
}