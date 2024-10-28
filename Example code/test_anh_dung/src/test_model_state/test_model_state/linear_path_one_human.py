#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from gazebo_msgs.srv import SetEntityState
from gazebo_msgs.msg import EntityState
import time
import math

class MoveModel(Node):
    def __init__(self):
        super().__init__('move_model')
        self.cli = self.create_client(SetEntityState, '/gazebo/set_entity_state')
        while not self.cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Service not available, waiting again...')
        
        self.state = EntityState()
        self.state.name = 'person_walking_1'  # Name of the model in Gazebo, check the name at World tab, Models in Gazebo
        
        # Publish new position every 0.01s
        self.timer = self.create_timer(0.01, self.timer_callback)
        
        # Initial position
        self.x = 3.0
        self.y = -4.0
        self.z = 0.0
        self.yaw = -1.57
        
        # Movement parameters
        self.linear_velocity = 0.75  # m/s
        self.angular_velocity = 1.0  # rad/s
        self.step = 0
        self.start_time = time.time()
        self.last_update_time = self.start_time

    def timer_callback(self):
        current_time = time.time()
        dt = current_time - self.last_update_time
        self.last_update_time = current_time

        if self.step == 0:
            # Move from (3, -4, 0) to (0, -4, 0)
            self.x -= self.linear_velocity * dt
            if self.x <= 0.0:
                self.x = 0.0
                self.step = 1

        elif self.step == 1:
            # Rotate 180 degrees
            self.yaw += self.angular_velocity * dt
            if self.yaw >= 1.57:
                self.yaw = 1.57
                self.step = 2

        elif self.step == 2:
            # Move back to (3, -4, 0)
            self.x += self.linear_velocity * dt
            if self.x >= 3.0:
                self.x = 3.0
                self.step = 3

        elif self.step == 3:
            # Rotate 180 degrees back
            self.yaw -= self.angular_velocity * dt
            if self.yaw <= -1.57:
                self.yaw = -1.57
                self.step = 0

        self.move_model(self.x, self.y, self.z, self.yaw)
    
    # Publish new state of model
    def move_model(self, x, y, z, yaw):
        self.state.pose.position.x = x
        self.state.pose.position.y = y
        self.state.pose.position.z = z
        self.state.pose.orientation.z = math.sin(yaw / 2)
        self.state.pose.orientation.w = math.cos(yaw / 2)
        req = SetEntityState.Request()
        req.state = self.state
        self.cli.call_async(req)

def main(args=None):
    rclpy.init(args=args)
    move_model = MoveModel()
    rclpy.spin(move_model)
    move_model.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
