@echo off
setlocal
cd /d "%~dp0"
set "PATH=C:\Users\XYC\tools\openocd\bin;%PATH%"

echo =====================================================
echo   STEP 1/3   CONFIGURE   (refresh the file list)
echo =====================================================
cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Debug -DCMAKE_TOOLCHAIN_FILE=cmake/gcc-arm-none-eabi.cmake
if errorlevel 1 goto :fail

echo.
echo =====================================================
echo   STEP 2/3   BUILD
echo =====================================================
cmake --build build
if errorlevel 1 goto :fail

echo.
echo =====================================================
echo   STEP 3/3   FLASH   (OpenOCD + DAPLink)
echo =====================================================
openocd -f interface/cmsis-dap.cfg -f target/stm32f1x.cfg -c "program build/f103_hw1.elf verify reset exit"
if errorlevel 1 goto :fail

echo.
echo ============   DONE : flashed and running   ============
pause
exit /b 0

:fail
echo.
echo [X] FAILED - see the messages above.
pause
exit /b 1
