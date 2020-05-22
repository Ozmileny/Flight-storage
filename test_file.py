import ctypes
lib = ctypes.CDLL('DLL1.dll')

#create all main string
city1 = ctypes.c_char_p('Moscow'.encode('utf-8'))
city2 = ctypes.c_char_p('London'.encode('utf-8'))
city3 = ctypes.c_char_p('Oslo'.encode('utf-8'))
ID1 = ctypes.c_char_p('SU7394'.encode('utf-8'))
ID2 = ctypes.c_char_p('SU7395'.encode('utf-8'))


#define argtypes
lib.create_LF.argtypes = [ctypes.c_char_p, ctypes.c_int, ctypes.c_int, ctypes.c_char_p, ctypes.c_int, ctypes.c_int, ctypes.c_char_p]
lib.LF_fst_point.argtypes = [ctypes.c_void_p, ctypes.c_char_p, ctypes.c_size_t]
lib.LF_last_point.argtypes = [ctypes.c_void_p, ctypes.c_char_p, ctypes.c_size_t]
lib.CF_fst_point.argtypes = [ctypes.c_void_p, ctypes.c_char_p, ctypes.c_size_t]
lib.LF_print.argtypes = [ctypes.c_void_p, ctypes.c_char_p, ctypes.c_size_t]
lib.T_print.argtypes = [ctypes.c_void_p, ctypes.c_char_p, ctypes.c_size_t]


#create test string place
name = ctypes.create_string_buffer(200)
last_point = ctypes.create_string_buffer(20)
name1 = ctypes.create_string_buffer(20)
fst_point = ctypes.create_string_buffer(100)

#test LinearFlight
flight1 = lib.create_LF(city1, 2, 13, city2, 2, 19, ID1)
time = lib.LF_dep_time(flight1)
f_time = lib.LF_full_time(flight1)
print('LinearFlight test: ', end='')
print (time, f_time)

lib.LF_fst_point(flight1, name1, ctypes.sizeof(name1))
lib.LF_last_point(flight1, last_point, ctypes.sizeof(last_point))
lib.LF_print(flight1, name, ctypes.sizeof(name))

print(name.value.decode('utf-8'))

print (name1.value.decode('utf-8'), end = " ")
print (last_point.value.decode('utf-8'))

#vector<int> test
ivec = lib.create_int_vector();
lib.int_vector_push(ivec, 9)
lib.int_vector_push(ivec, 13)
lib.int_vector_push(ivec, 14)
print('vector<int> test: ' + str(lib.int_vector_get(ivec, 2)))

#vector<string> test
svec = lib.create_str_vector()
lib.str_vector_push(svec, city1)
lib.str_vector_push(svec, city2)
lib.str_vector_push(svec, city3)

lib.str_vector_get(svec, 2, name1, ctypes.sizeof(name1))
print ('vector<string> test: ' + name1.value.decode('utf-8'))

#CyclicFlight test
cflight = lib.create_CF(svec, ivec, ivec, ivec, ivec, ID2)
f_time2 = lib.CF_full_time(cflight)
lib.CF_fst_point(cflight, fst_point, ctypes.sizeof(fst_point))
print ("CyclicFlight test: " + fst_point.value.decode('utf-8'), end=" ")
lib.CF_ID(cflight, name1, ctypes.sizeof(name1))
print(name1.value.decode('utf-8'))

#Point test
point1 = lib.create_P(city2, svec, ivec, ivec)
lib.P_name(point1, name, ctypes.sizeof(name))
print("Point test: " + name.value.decode('utf-8'))

#Timetable test
ttable = lib.create_T()
lib.T_add_point(ttable, point1)
lib.T_add_lf(ttable, flight1)
lib.T_add_cf(ttable, cflight)
lib.T_print(ttable, name, ctypes.sizeof(name))
print("Timetable: \n" )
print(name.value.decode('utf-8'))



