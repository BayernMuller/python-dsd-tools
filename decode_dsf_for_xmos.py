import ctypes

lib = ctypes.CDLL('./libdsfxmos.so')


lib.dsfxmos.argtypes = [ctypes.c_int, ctypes.POINTER(ctypes.c_uint8), ctypes.POINTER(ctypes.c_uint8), ctypes.c_int]
lib.dsfxmos.restype = None

def dsfxmos(size, indata, lsbfirst):
    indata_arr = (ctypes.c_uint8 * len(indata))(*indata)
    outdata_arr = (ctypes.c_uint8 * len(indata))()
    
    lib.dsfxmos(size, indata_arr, outdata_arr, lsbfirst)
    
    return outdata_arr