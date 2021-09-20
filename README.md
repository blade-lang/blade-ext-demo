# Demo C extension for Blade

## Building
---

```terminal
$ cmake -B ./build -DCMAKE_BUILD_TYPE=Release -DBLADE_ROOT="/path/to/blade/root/folder"
$ cmake --build build --config Release
```

All compilers supported for building Blade are supported. See the sample CMakeLists.txt file for how to build your C extension.

## Where is `blade.h`
---

The `blade.h` file is available when you build Blade (starting from version 0.0.6) inside the `includes` folder. This demo extension shows how to link to it directly from CMakeLists.txt file.

## Installing
---

Copy the built library file in the `build` directory to the `dist` folder in your Blade installation path.

Your library file is the file ending with `.so` if you are on a Linux server, `.dylib` if you are on OSX or `.dll` if you are on Windows.

## Test
---

```py
import demo

# module variables
echo demo.version

# module function say_hello()
echo demo.say_hello()

# module class and method
var klass = demo.MyClass()
echo klass.shout('James')
```

You get get an output similar to this:

```terminal
1
Hello, World
Hello James, Welcome to my Blade C extension
```

## License
---

[Licensed under Blade's MIT license](https://github.com/blade-lang/blade/blob/main/LICENSE)