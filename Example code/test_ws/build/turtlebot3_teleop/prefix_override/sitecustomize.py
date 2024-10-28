import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/nhodung/Documents/ros2_learn/test_ws/install/turtlebot3_teleop'
