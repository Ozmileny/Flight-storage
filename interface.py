import ctypes

def print_menu():
    print("1. Add linear flight to timetable")
    print("2. Add cyclic flight to timetable")
    print("3. Add point to timetable")
    print("4. Print timetable")
    print("5. Find flight")
    print("6. Print variants again")
    print("0. Exit")
    
def create_ivec(ilist):
    ivec = lib.create_int_vector()
    for j in range(len(ilist)):
        lib.int_vector_push(ivec, ilist[j])
    return ivec

def create_svec(slist):
    svec = lib.create_str_vector()
    for i in range(len(slist)):
        city = ctypes.c_char_p(slist[i].encode('utf-8'))
        lib.str_vector_push(svec, city)
    return svec

#preparation block
name = ctypes.create_string_buffer(500)
lib = ctypes.CDLL('DLL1.dll')
ttable = lib.create_T()

#main part
print("Please, use only space to separete input data")
print('Menu: ')
print_menu()
while 1:
    print("Input No. of variant: ", end = "")
    x = int(input())
    if x == 1:
        #create and add Linearflight to Timetable
        print("Input A point: ", end = "")
        A = input()
        print("Input B point: ", end = "")
        B = input()
        print("Input departure and arrive time: ", end = "")
        k = list(input().split())
        while len(k) != 2:
            print("Try again")
            print("Input departure and arrive time: ", end = "")
            k = list(input().split())
        dt, at = map(int, k)
        print("Input departure and arrive days: ", end = "")
        dd, ad = map(int, input().split())
        print("Input plane ID: ", end = "")
        ID = input()

        city1 = ctypes.c_char_p(A.encode('utf-8'))
        city2 = ctypes.c_char_p(B.encode('utf-8'))
        ID = ctypes.c_char_p(ID.encode('utf-8'))
        flight0 = lib.create_LF(city1, dd,  dt, city2, ad, at, ID)
        flight = lib.create_LF(city1, dd,  dt, city2, ad, at, ID)
        if (lib.T_check_lf(ttable, flight0) != 0):
            lib.T_add_lf(ttable, flight)
            print("Flight's added")
        else:
            print("Incorrect flight")
        print()  

    elif x == 2:
        #create and add CyclicFlight to Timetable
        print("Input points list in line with a space: ", end = "")
        A = list(input().split())
        print("Input departure days: ", end = "")
        dd = list(map(int, input().split()))
        print("Input departure times: ", end = "")
        dt = list(map(int, input().split()))
        print("Input arrive days: ", end = "")
        ad = list(map(int, input().split()))
        print("Input arrive times: ", end = "")
        at = list(map(int, input().split()))
        print("Input plane ID: ", end = "")
        ID = input()
        ID = ctypes.c_char_p(ID.encode('utf-8'))
        
        A = create_svec(A)
        dd = create_ivec(dd)
        dt = create_ivec(dt)
        ad = create_ivec(ad)
        at = create_ivec(at)

        flight0 = lib.create_CF(A, dd, dt, ad, at, ID)
        flight = lib.create_CF(A, dd, dt, ad, at, ID)
        if (lib.T_check_cf(ttable, flight0) != 0):
            lib.T_add_cf(ttable, flight)
            print("Flight's added")
        else:
            print("Incorrect flight")
        print()

        lib.del_int_vector(dd)
        lib.del_int_vector(dt)
        lib.del_int_vector(ad)
        lib.del_int_vector(at)
        lib.del_str_vector(A)
        
    elif x == 3:
        #create and add Point to Timetable
        print("Input point name: ", end = "")
        A = input()
        print("Input connected points in line with a space: ", end = "")
        B = list(input().split())
        print("Input max flight time from %s to each connected point: "%A, end = "")
        maxt = list(map(int, input().split()))
        print("Input min flight time from %s to each connected point: "%A, end = "")
        mint = list(map(int, input().split()))

        svec = create_svec(B)            
        ivec1 = create_ivec(maxt)
        ivec2 = create_ivec(mint)
            
        point = lib.create_P(A, svec, ivec1, ivec2)
        lib.T_add_point(ttable, point)
        print("Point's added")
        print()

        lib.del_str_vector(svec)
        lib.del_int_vector(ivec1)
        lib.del_int_vector(ivec2)
                                   
    elif x == 4:
        #print current state of Timetable
        lib.T_print(ttable, name, ctypes.sizeof(name))
        if name.value.decode('utf-8') == "":
            print("Timetable is still empty") 
        else :
            print("Timetable:" )
            print(name.value.decode('utf-8'))
        print()
            
    elif x == 5:
        #find flight from point A to point B after time dt
        print("Input from where to where will you go: ", end = "")
        A, B = input().split()
        print("Input the earliest departure time: ", end="")
        dt = int(input())

        city1 = ctypes.c_char_p(A.encode('utf-8'))
        city2 = ctypes.c_char_p(B.encode('utf-8'))
        lib.T_find_flight(ttable, dt, city1, city2, name, ctypes.sizeof(name))
        print(name.value.decode('utf-8'))
        print()
        
    elif x == 6:
        print_menu()
    elif x == 0:
        lib.del_T(ttable)
        break
    else:
        print ("No such variant")
    


    
    
