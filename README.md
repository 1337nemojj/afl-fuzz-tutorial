# afl-fuzz-tutorial for Ubuntu 22
Tutrial for afl-fuzz. How to install/setup/usage for QTapp from make file

SETUP:
```
Ubuntu 22.04, python3.11
```
dir:
```
fuzzing_test/
├── CMakeLists.txt
├── main.cpp
└── input/
    └── testcase.txt
```
---
Commands for install afl-fuzz, Qt, Ubuntu setting:
```
sudo apt install afl
sudo apt install clang
sudo apt install build-essential cmake
sudo apt install python3.11 python3.11-dev python3.11-venv
sudo apt install qtbase5-dev qtchooser qt5-qmake qtbase5-dev-tools
### optinal: gcc-plugin-dev

```
```
# check DLLs
ldd ./fuzzing_test 
```

## optional settings (one of them require for setup) afl-fuzz
1.  **Временное изменение core_pattern** - 
AFL рекомендует временно изменить значение параметра ядра core_pattern. Для этого выполните следующую команду с правами суперпользователя (root): 
```
sudo sh -c 'echo core > /proc/sys/kernel/core_pattern'
```
2. **Использование переменной окружения** -
```AFL_I_DONT_CARE_ABOUT_MISSING_CRASHES```
Если вы не хотите изменять системные параметры или просто тестируете приложение, вы можете проигнорировать это предупреждение, установив переменную окружения:
```
export AFL_I_DONT_CARE_ABOUT_MISSING_CRASHES=1
```
3. **Постоянное изменение core_pattern** - постоянно изменить поведение системы, чтобы AFL всегда мог работать корректно с крашами, добавьте следующую строку в файл ```/etc/sysctl.conf```:
```
echo "kernel.core_pattern=core" | sudo tee -a /etc/sysctl.conf
sudo sysctl -p
```
## setting Ubuntu:
1. Переключение на режим "performance" (рекомендуется)
AFL рекомендует временно переключить режим работы процессора на "performance", чтобы избежать проблем с частотным скейлингом.
```
sudo su
cd /sys/devices/system/cpu
echo performance | tee cpu*/cpufreq/scaling_governor
```
## final

create dir ```build```:
```
mkdir build
cd build
```
> if needs rebuild ```make clean``` or ```rm -rf *``` !!! IN BUILD DIR
cmake with afl-fuzz
```
cmake -DAFL_COMPILE=ON -DCMAKE_C_COMPILER=afl-clang-fast -DCMAKE_CXX_COMPILER=afl-clang-fast++ ..
```
**OR**
```
cmake -DAFL_COMPILE=ON -DCMAKE_C_COMPILER=afl-gcc -DCMAKE_CXX_COMPILER=afl-g++ ..
```
then
```
make
```
## Create input/ with testcase.txt
```
echo "100" > input/testcase.txt
```
## Start fuzzing
> addtional setting (soon)
```
afl-fuzz -i input -o output ./fuzzing_test
```
