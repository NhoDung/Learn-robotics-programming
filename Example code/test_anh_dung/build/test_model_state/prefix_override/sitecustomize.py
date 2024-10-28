import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/nhodung/Documents/ROS 2 Projects Collection/test_anh_dung/install/test_model_state'
