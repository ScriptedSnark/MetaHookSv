echo off

if not exist "%~dp0Build\svencoop.exe" goto fail_nobuild

set LauncherExe=svencoop.exe
set LauncherMod=svencoop

for /f "delims=" %%a in ('"%~dp0SteamAppsLocation/SteamAppsLocation" 225840 InstallDir') do set GameDir=%%a

if "%GameDir%"=="" goto fail

echo -----------------------------------------------------

echo Copying files...

copy "%~dp0Build\svencoop.exe" "%GameDir%\" /y
copy "%~dp0Build\SDL2.dll" "%GameDir%\" /y
copy "%~dp0Build\FreeImage.dll" "%GameDir%\" /y
xcopy "%~dp0Build\svencoop" "%GameDir%\%LauncherMod%" /y /e
xcopy "%~dp0Build\svencoop_addon" "%GameDir%\%LauncherMod%_addon\" /y /e
mkdir "%GameDir%\%LauncherMod%_schinese\"
xcopy "%~dp0Build\svencoop_schinese" "%GameDir%\%LauncherMod%_schinese\" /y /e
xcopy "%~dp0Build\platform" "%GameDir%\platform" /y /e

copy "%GameDir%\%LauncherMod%\metahook\configs\plugins_svencoop.lst" "%GameDir%\%LauncherMod%\metahook\configs\plugins.lst" /y

powershell $shell = New-Object -ComObject WScript.Shell;$shortcut = $shell.CreateShortcut(\"MetaHook for SvenCoop.lnk\");$shortcut.TargetPath = \"%GameDir%\%LauncherExe%\";$shortcut.WorkingDirectory = \"%GameDir%\";$shortcut.Arguments = \"-game %LauncherMod%\";$shortcut.Save();

echo -----------------------------------------------------

echo done
pause
exit

:fail

echo Failed to locate GameInstallDir of Sven Co-op, please make sure Steam is running and you have Sven Co-op installed correctly.
pause
exit

:fail_nobuild

echo Compiled binaries not found ! You have to download compiled zip from github release page or compile the sources by yourself before installing !!!
pause
exit