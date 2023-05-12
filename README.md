# Mii_to_UMii
A program to programmatically convert Miis to UMiis for BoTW/ToTK, both Switch and Wii U. This program can only be controlled from the command line. This can be accessed by running `cmd` on Windows in the folder where the program is downloaded, or by opening the terminal on other operating systems.

## Command Line Options
```
Convert Mii files to UMii files for use with BoTW/ToTK
Usage:
  Mii_to_UMii [OPTION...]

  -i, --input arg            Input file
  -o, --output arg           Output file
  -t, --type arg             Input Mii type
        (wii/3ds/wiiu/miitomo/switch/switchgame/studio)
  -x, --verbose              Verbose output
  -b, --binary               Output binary file
  -v, --version              Print verson
  -p, --mod-path arg         Specify root folder of mod
  -r, --romfs arg            Path to ROMFS dump
  -d, --delete-actor-folder  Delete automatically generated actor folder
                             (default: true)
  -h, --help                 Print usage
```

* `input`: The input Mii to convert. Miis for Wii, Wii U, 3DS, Switch and Mii Studio are all supported, as well as Miis from [the online Mii editor here](https://rc24.xyz/goodies/mii/) and QR codes. URLs are also supported, as well as file wildcards like `*.jpg` to convert all QR codes in a folder
* `output`: The path to the output Mii
* `type`: The type of the input Mii. Either you can leave this blank and have the program guess the type from the extension:
```
	.mii -> wii
	.mae -> wii
	.miigx -> wii
	.rcd -> wii
	.cfsd -> 3ds
	.jpg -> 3ds (QR code)
	.jpeg -> 3ds (QR code)
	.png -> 3ds (QR code)
	.tga -> 3ds (QR code)
	.bmp -> 3ds (QR code)
	.gif -> 3ds (QR code)
	.ffsd -> wiiu
```
The types `wii/3ds/wiiu/miitomo/switch/switchgame/studio` can also be manually inputted if your type is not guessed automatically
* `verbose`: Enable verbose output for debugging and stats
* `binary`: Enable binary output. The default output is in YML format, which is useful for research but cannot be used in any mod
* `version`: Print the version of the program and exit
* `mod-path`: If generating a mod automatically, include the path to your mod folder here
* `romfs`: Needed if generating a mod automatically. The NPC whose Mii will be replaced must match the input filename or you cannot generate a mod
* `delete-actor-folder`: If you would like the uncompressed `sbactorback` file for research, set this to `false`
* `help`: Print usage and exit

## Obtaining Miis
I do not promote any of these methods and I am simply documenting them here to aid in your efforts

* Wii: https://wiibrew.org/wiki/Mii_Extractor (Homebrew)
* Wii U: QR codes
* 3DS: QR codes
* Switch: https://github.com/FlagBrew/Checkpoint: (Homebrew)
	* Requires at the very least a save dump of Super Smash Bros. Ultimate (with a Mii Fighter of your Mii saved), Super Mario Maker 2 (with the Mii as your Maker Mii or with the Mii as the creator of a downloaded course/world record on a downloaded course), or Mario Kart 8 Deluxe (with the Mii holding a record in a Time Trial course). The Mii can be found within the save of each game
* Mii Studio: https://github.com/RiiConnect24/mii2studio#exporting

[MiiCharactors.com](https://www.miicharacters.com/) also houses a database of user uploaded Miis. You can download the qr code provided with each Mii and import the Mii that way. The watermark might make the Mii impossible to transfer, but most should work