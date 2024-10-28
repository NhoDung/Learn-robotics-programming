#include "rclcpp/rclcpp.hpp"
#include "gazebo_msgs/srv/set_entity_state.hpp"
#include <chrono>
#include <memory>
#include <cmath>

using namespace std::chrono_literals;

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("set_entity_state_client");
    rclcpp::Client<gazebo_msgs::srv::SetEntityState>::SharedPtr client = node->create_client<gazebo_msgs::srv::SetEntityState>("set_entity_state");

    double radius = 1.0, angle = 0.0, angle_increment = 0.1;

    while (!client->wait_for_service(1s))
    {
        if (!rclcpp::ok())
        {
            RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Interrupted while waiting for the service. Exiting.");
            return 0;
        }
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Service not available, waiting again...");
    }

    while (rclcpp::ok())
    {
        // Tạo request mới cho mỗi lần gọi
        auto request = std::make_shared<gazebo_msgs::srv::SetEntityState::Request>();
        request->state.name = "unit_box";
        request->state.pose.position.x = radius * cos(angle);
        request->state.pose.position.y = radius * sin(angle);

        auto result = client->async_send_request(request);

        if (rclcpp::spin_until_future_complete(node, result) == rclcpp::FutureReturnCode::SUCCESS)
        {
            RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Entity state set successfully");
        }
        else
        {
            RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Failed to call service set_entity_state");
        }

        angle += angle_increment;
        angle -= (angle >= 2 * M_PI) ? 2 * M_PI : 0;

        std::this_thread::sleep_for(100ms);
    }

    rclcpp::shutdown();
    return 0;
}
