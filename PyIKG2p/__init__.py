import os

from .PyIKG2p import *

current_dir = os.path.dirname(os.path.abspath(__file__))
PyIKG2p.setDictionaryPath(current_dir + '/dict')
