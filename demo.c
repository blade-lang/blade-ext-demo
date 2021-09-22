#include <blade.h>
#include <stdio.h>

#ifdef _WIN32
#undef EXPORT
#define EXPORT __declspec(dllexport)
#else
#endif

/**
 * sample module variable.
 * @see blade.h for available macros.
 */
EXPORT b_value demo_version(b_vm *vm) {
  return NUMBER_VAL(1);
}

/**
 * sample module function.
 * @see blade.h for available macros.
 */
EXPORT DECLARE_MODULE_METHOD(say_hello) {
  RETURN_STRING("Hello, World");
}

/**
 * sample module method.
 * 
 * functions and class methods are essentially the same just like 
 * in Blade.
 * 
 * this example shows a function/method that returns nothing.
 * it also shows how to define number of arguments and accept some too.
 * 
 * @def shout(name: string)
 * @see blade.h for available macros.
 */
EXPORT DECLARE_MODULE_METHOD(shout_blade) {
  ENFORCE_ARG_COUNT(shout, 1);
  b_obj_string *string = AS_STRING(args[0]);

  printf("Hello %s, Welcome to my Blade C extension\n", string->chars);
  RETURN;
}

EXPORT CREATE_MODULE_LOADER(demo) {
  static b_field_reg fields[] = {
      {"version", true, demo_version},
      {NULL,       false, NULL},
  };

  static b_func_reg functions[] = {
      {"say_hello",    false, GET_MODULE_METHOD(say_hello)},
      {NULL,    false, NULL},
  };

  static b_func_reg class_functions[] = {
      {"shout",    false, GET_MODULE_METHOD(shout_blade)},
      {NULL,    false, NULL},
  };

  static b_class_reg classes[] = {
      {"MyClass", NULL, class_functions},
      {NULL,  NULL, NULL},
  };

  static b_module_reg module = {
      .name = "demo",
      .fields = fields,
      .functions = functions,
      .classes = classes,
      .preloader = NULL,
      .unloader = NULL
  };

  return &module;
}
