import os
import ctypes

dll_path = os.path.join(os.path.dirname(__file__), "StepSorts.dll")

try:
    sorts = ctypes.CDLL(dll_path)
    print("DLL loaded successfully.")
except OSError as e:
    print("FAILED TO LOAD DLL")
    print(e)