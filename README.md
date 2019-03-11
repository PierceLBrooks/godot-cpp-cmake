# CMake Build Scripts for GDNative C++ Bindings

This repo contains CMake scripts to ease cross-platform building of GDNative C++ bindings.

Requires at least Godot Engine 3.1 RC1 with NativeScript 1.1. May work with older Godot Engine releases, but it's not tested.

To begin, clone this repo with `--recurse-submodules` option. It'll clone the repo with all required dependencies such as godot-cpp and godot_headers direct from github's repository.

## Prerequisite

You need [CMake](https://cmake.org/) generator at least 3.10 version and [Android SDK](https://developer.android.com/studio) with NDK bundle. Optionally you can use [Ninja build system](https://ninja-build.org/), my personal choice, but these CMake scripts should work with any build system.

## Compiling

The best approach to compile the library is to create a subdirectory under the /build path. For example, for _Windows x64_ build, name the subdirectory as _win64_ and open it in Command Prompt. For MSVC build, use MSVC's Native Commands Prompt. To start, generate Ninja build files (or any other build system supported by your environment) using CMake as:

```
cd build\win64
cmake -G Ninja ..\.. -DGODOT_API_JSON=C:\Path\To\godot_json.api
```

This should work with Linux the same way. But for Android, it gets a bit more complicated. You should ensure that you have latest NDK version installed on your system with CMake toolchain file bundled. Assuming you have configured Android SDK properly, you can run the CMake tool with specified definitions:

```
cd build\android
cmake -G Ninja ..\.. -DCMAKE_TOOLCHAIN_FILE=%ANDROID_NDK_ROOT%\build\cmake\android.toolchain.cmake -DGODOT_API_JSON=C:\Path\To\godot_json.api
```

Notice that we're using `%ANDROID_NDK_ROOT%` environment variable, ensure first that it's available on your system to continue. Also don't use `-DCMAKE_SYSTEM_NAME=Android` flag, it may interfere with customized Android's CMake Toolchain.

To build release (optimized) targets, use CMake's -DCMAKE_BUILD_TYPE option as `-DCMAKE_BUILD_TYPE=Release`. Built libraries should be located under the /lib root directory.

## Troubleshooting

If you don't know how to obtain godot_json.api file, just run Godot.exe within a Command Prompt with an `--gdnative-generate-json-api` option, just like:

```
Godot.exe --gdnative-generate-json-api godot_json.api
```
