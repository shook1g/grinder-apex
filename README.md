====================================================================================================================================================================================================================================================================== 
**This guide is stritctly for EDUCATIONAL purposes only and should never be used for any malicious purposes.  
Myself and all other code contributors are in no way shape or form liable IN ANY WAY for you being an idiot. 
You have been warned.**
**(Before you do anything, make sure you are on a LINUX, YES LINUX, OS..It does not matter what distro you like as long as you are gaming apex on LINUX, this is not for windows.
No we cannot port this incredible cheat to Windows, you guys are awful.)**
====================================================================================================================================================================================================================================================================== 

// DEPENDENCIES \\
-------------------
Debian/Ubuntu based dependencies
## Intall build-essential / libx11-dev / libxtst-dev / libxrender-dev (Mandatory. You only need to do this once)

sudo apt-get install build-essential libx11-dev libxtst-dev libxrender-dev

And if Arch based Linux Distros are more your style, then...

Arch based dependencies need to be installed, use whichever packagemanager you like, but pacman should be fine, type the following command which will install:

/ base-devel / libx11 / libxtst / libxrender / (Mandatory. You only need to do this once)

sudo pacman -Sy base-devel libx11 libxtst libxrender

// Now that we have all dependencies installed and out of the way, you can reboot if you like, and lets get down to squad wipes \\
### 0. Introduction:
DISCLAIMER: Once again, as mentioned above, This project is for educational purposes only.
Grinder FULL GRIND EDITION, Features available are:
- Aim Assist implemented in an advanced 'AimBot' or 'Triggerbot' configuration you can choose from
- ESP, including Mini Map and Level Map (All Configurable)
- Recoil Control System / NoRecoil 
- Auto Super Glide
- Skin Changer

CREDITS:
- arturzxc, Azreol, Gerosity, gitdev, shook1g (myself), and just about anyone and everyone over @ UknownCheats ( https://www.unknowncheats.me/forum/ )
- #1g 1st Generation #1g (if you know, then you know, and thus you know who you are!)

### 1. Download:
```
Download the zip directly from the repo or pull it down in your linux terminal with the following command:
git clone https://github.com/shook1g/grinder-apex.git
```
----------------------------------------------------------------------------------------------------------------------------

### 2. Get inside the folder
```
Now, in that same terminal type the command:
cd grinder-apex
```
-----------------------------------------------------------------------------------------------------------------------------

### 2.1.1 / Step 2 Section B -_^ :  VERY IMPORTANT, BEFORE MOVING TO STEP 3 YOU WANT TO EDIT THE GRINDER CONFIG FILE, which is called 'grinder.ini' and can be done from terminal with any linux native tool such as 'vim' or 'nano' but also just done in any text editor.
So open grinder.ini in your default notepad or nano, whatever makes you confortable...Go Through all the very easy and well explained options and set them HOW YOU WANT THEM TO BE, because there is no "In Game GUI/Ridiculous fucking overlay" you pull up with "Home" or "Insert"
Once you think you have all your settings dialed in save that grinder.ini file with your changes and lets get this puppy going....

### 3. Compile the program (compiling using 'make'     -----> command for make is, well, 'make' in terminal...this is done AFTER you change any settings in the "grinder.ini" file):
```
Type this command after setting up your prefs in grinder.ini
'make'
you should see console output that lets you know everything compiled successfully, if you get ANY errors, then I suggest you learn how to read because you have done something
wrong/left something out thus far....Go back to step 1....If you get the good news in your terminal, then you may proceed...
```

### 4. type the 'ls' command, listing all files in the current directory, and observe the presence of a new file "a.out" which is your compiled executable and
shows you are now ready to GRIND...

#### 5. sudo ./a.out 
'sudo ./a.out' in your terminal to load the cheat and you will get a successful verification after you run it, just let that terminal continue to run in background. What are you doing, get in game and GRIND.

### CONCLUSIONS / Things to remember to always do / Random THoughts / etc...  #######
1.) Before issuing the command "sudo ./a.out" in terminal which will load your cheat, YOU MUST, MUSTTTTTT START APEX LEGENDS FIRST!!!
2.) Open Apex and wait until you are at your Apex Legends "Continue" screen, where you click continue to then load up your main legend dashboard.
Once you are at that initial menu your game should be completely loaded, and this is a critical step.  You must have apex legends running FIRST, then you alt-tab back to terminal..
Now that you are on your desktop again and back to your linux terminal, you can run that 'a.out' file and this must be done with elevated privledges, so we leverage
the 'sudo' command when running it.  One way I prefer to do it is to actually just be running that terminal as the root user, which can be achieved by opening any terminal session, in which you will see 
"YourUserName@LinuxDistro $ >" or something of that nature, and then type "sudo su" in which you will be prompted for your user password..type it in, and now see you are "[ root@LinuxDistro ] $ > " and then use "cd" to change to directory of grinder.
Once there, just type 'a.out' without the 'sudo ./a.out' since you do not need to leverage the sudo command if you are obviously already running that console with root privledges. AFter  " [ root@LinuxDistro $ home/yourGrinderFolder/ > ./a.out " and press Enter, 
you should get verification you are in the lobby waiting on joining a game, and that everything went fine when loading your cheat. If this is true, just let it run in the background and bring apex back up, finally allowing you to be a top 10 pred ;)

ALSO, WHEN THE GAME UPDATES DO NOT COME RUNNING FOR THESE OFFSETS TO BE UPDATED, I WILL GET TO IT WHEN I CAN/ALWAYS AFTER I DUMP GAME AND TEST MYSELF.

===========================================================================================================================================================================================================================================================================

__________________
| Linux Terminal |
|--------------------------------
| [root@yourLinuxDistro] $ >  ./a.out   (presses enter)
| [root@yourLinuxDistro] $ > This is example output, you are not loaded successfully with Grinder, Full Grind Special Edition, player is in lobby awaiting match with high potential for multiple squad wipes likely 
| [root@yourLinuxDistro] $ > In game on Map WorldsEdge | looping and updating everything Xms | etc etc etc | this is the output you should see if everything is working fine when in a match
|--------------------------------
```
Unlimited powaaaaaaaaaa!
