from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from ament_index_python.packages import get_package_share_directory
import os

def generate_launch_description():
    # Path to your world file
    world_file = os.path.join(get_package_share_directory('model_pos'), 'worlds', 'test.world')

    return LaunchDescription([
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource([os.path.join(
                get_package_share_directory('gazebo_ros'), 'launch', 'gazebo.launch.py')]),
            launch_arguments={'world': world_file, 'verbose': 'true'}.items(),
        ),
        Node(
            package='model_pos',
            executable='set_state_node',
            output='screen'
        )
    ])
