## SLA-Cheeto

### Features
- No Cooldown
- God Mode
- Damage Hack (Works for certain weapons only)
- Dumb Enemies (They don't attack you)
- Mission Time 
- Time Scale
- FPS Unlocker
- Skip Intro Movie

### Building
- ``git clone --recurse-submodules https://github.com/Taiga74164/SLA-Cheeto``
- First time building and seeing this error?\
![error](error.png)
- Replace **{PATH_TO_GAME}** with the actual path to your game in PostBuildEvent.cmd.

- _OR_ before building, you can initially just create a PostBuildEvent.cmd with:\
``xcopy /f /y "{PROJECT_PATH}\x64\Release\SoloLevelling.dll" "{PATH_TO_GAME}\winhttp.dll*" ``
- Remember to replace the place holders with your own path
