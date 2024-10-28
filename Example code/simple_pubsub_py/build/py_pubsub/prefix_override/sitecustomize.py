import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/nhodung/Documents/ros2_learn/simple_pubsub_py/install/py_pubsub'
