## SLA-Cheeto

## Disclaimer
This project is created and shared for educational purposes only. I do not condone or endorse the use of this project for any illegal activities or unethical behavior. The use of this project is solely at the user's discretion. I am not held responsible for any misuse of the information or code provided in this repository.

## Usage

#### DLL Proxy
The DLL will automatically be loaded by the game itself if the dll is in the game directory. You may only rename the dll to `version.dll`, `winhttp.dll` or `winmm.dll`.

#### How to Run
**Note:** If you're [building](#building), skip to #2
1. Move `winhttp.dll` into the game directory in `/sololv`
2. Start the game
3. Press insert to show the menu

## Features
- No Cooldown
- God Mode
- Damage Hack (Works for certain weapons only)
- Dumb Enemies (They don't attack you)
- Mission Time 
- Time Scale
- FPS Unlocker
- Skip Intro Movie

## Screenshot
![menu](src/res/Solo_Leveling_ARISE_4BRSUmbeJd.png)

## Building
- Clone the repository: `git clone --recurse-submodules https://github.com/Taiga74164/SLA-Cheeto`.
- If you encounter the error depicted in the [screenshot](src/res/error.png), replace **{PATH_TO_GAME}** with the actual path to your game in `PostBuildEvent.cmd`.
- **_OR_** before building, you can initially create a `PostBuildEvent.cmd` with: `xcopy /f /y "{PROJECT_PATH}\x64\Release\winhttp.dll" "{PATH_TO_GAME}\winhttp.dll*"`.
- Remember to replace the placeholders with your own paths.

## Contributing
1. Fork the repo (<https://github.com/Taiga74164/SLA-Cheeto/fork>).
2. Create your feature branch.
3. Commit your changes.
4. Push your changes to the branch.
5. Create a new pull request.