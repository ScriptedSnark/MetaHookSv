echo off

set LauncherExe=metahook.exe
set LauncherMod=valve
set PsCmdLine='call powershell -File %~dp0SteamAppsLocation/SteamAppsLocation.ps1 70 InstallDir'
for /f "delims=" %%a in (%PsCmdLine%) do set GameDir=%%a

if "%GameDir%"=="" goto fail

echo -----------------------------------------------------

echo Writing debug configuration...
copy global_template.props global.props /y
call powershell -Command "(gc global.props) -replace '<MetaHookLaunchName>.*</MetaHookLaunchName>', '<MetaHookLaunchName>%LauncherExe%</MetaHookLaunchName>' | Out-File global.props"
call powershell -Command "(gc global.props) -replace '<MetaHookLaunchCommnand>.*</MetaHookLaunchCommnand>', '<MetaHookLaunchCommnand>-game %LauncherMod%</MetaHookLaunchCommnand>' | Out-File global.props"
call powershell -Command "(gc global.props) -replace '<MetaHookGameDirectory>.*</MetaHookGameDirectory>', '<MetaHookGameDirectory>%GameDir%\</MetaHookGameDirectory>' | Out-File global.props"
call powershell -Command "(gc global.props) -replace '<MetaHookModName>.*</MetaHookModName>', '<MetaHookModName>%LauncherMod%</MetaHookModName>' | Out-File global.props"

echo -----------------------------------------------------

echo done
pause
exit

:fail

echo Failed to locate GameInstallDir of Half-Life, please make sure Steam is running and you have Half-Life installed correctly.
pause
exit