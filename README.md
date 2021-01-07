# LEDWebsiteControl
## About 
This code controls LED lights with a website running on your local network and is written so that anyone can add functionality without understanding how all of the code works. Moreover, this project is structured to be deployed as an apache server and includes apache server-specific config files (more on that bellow). If you don't want to use apache, skip my install guide, and re-arrange files for whatever server you want to run it on.

## What Is Needed
- Python3
- Arduino (connected to your computer)
- FastLED (Arduino Library) compatible LED Strip
- Raspberry Pi is recomended if you want to follow the guide
## Setup
To insure that everything works correctly isntall on a Raspberry Pi, but the guide commands should work on any linux distro using apt.
#### Apache Install:
- sudo apt-get apache2 
- sudo apt-get install libapache2-mod-wsgi-py3 
- sudo a2enmod wsgi 
#### Project Setup
- cd /var/www && git clone https://github.com/Defaulti/LEDWebsiteControl.git
#### Python dependencies make sure your using python 3 
- sudo apt install libffi-dev
- sudo apt-get install libatlas-base-dev
- sudo apt-get install libportaudio2
- pip install cffi
- pip install sounddevice
- pip install Flask
- pip install numpy 
- pip install pyserial 
#### Test to see if the code works
- compile the Arduino code and connect your LEDs to it
- cd /var/www/LEDWebsiteControl/LEDWEbsiteControl
- export FLASK_APP=__init__ && flask run -h "your ip here" 
- If you can access the website in your brosswer and controll your LEDs then procceed 
#### Setup the code to run on the Apache server
- mv /var/www/LEDWebsiteControl/LEDWebsiteControl.conf /etc/apache2/sites-available/
- sudo a2ensite LEDWebsiteControl 
- use a text edditor to change the secrete key of LEDWebsiteControl.conf
- sudo vim /etc/apache2/envvars
- make APACHE_RUN_USER and APACHE_RUN_GROUP = your user name
-- mine looks like APACHE_RUN_USER=pi APACHE_RUN_GROUP=pi
- sudo service apache2 restart
#### The code should be running on the Apache server now. If its not working view the Apache log by runing:
- tail /var/log/apache2/error.log



