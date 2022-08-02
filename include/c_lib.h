// defind LIB_API/LIB_HIDEN
#ifndef PYTHON_CALL_C_REF_PYTHON_CALL_C_REF_C_LIB_H
#define PYTHON_CALL_C_REF_PYTHON_CALL_C_REF_C_LIB_H

#if defined _WIN32 || defined __CYGWIN__
#  ifdef BUILDING_LIB
#    ifdef __GNUC__
#      define LIB_API __attribute__((dllexport))
#    else
#      define LIB_API __declspec(dllexport) 
#    endif
#  else
#    ifdef __GNUC__
#      define LIB_API __attribute__((dllimport))
#    else
#      define LIB_API __declspec(dllimport) 
#    endif
#  endif
#  define LIB_HIDEN
#else
#  if __GNUC__ >= 4
#    define LIB_API   __attribute__((visibility("default")))
#    define LIB_HIDEN __attribute__((visibility("hidden")))
#  else
#    define LIB_API
#    define LIB_HIDEN
#  endif
#endif

#endif // PYTHON_CALL_C_REF_PYTHON_CALL_C_REF_C_LIB_H
