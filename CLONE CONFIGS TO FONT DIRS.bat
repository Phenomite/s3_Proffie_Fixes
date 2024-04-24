REM @echo off
setlocal EnableDelayedExpansion
set "configFile=config.ini"
set "smoothswFile=smoothsw.ini"
set "destinationDirectory=000 ALL FONTS"
set "depthLevel=1"

:CopyFilesAtDepth
for /d %%F in ("%destinationDirectory%\*") do (
    echo "%%F"
    copy "%configFile%" "%%F\"
    copy "%smoothswFile%" "%%F\"
)
pause