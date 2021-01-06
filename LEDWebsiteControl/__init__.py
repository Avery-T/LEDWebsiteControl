from flask import Flask, render_template, request
import os
import serial
import struct 

#arduinoPath = ('/dev/tty%', 
ser = serial.Serial('/dev/ttyACM0', 9600, timeout=1) 

app = Flask(__name__) 



@app.route("/") 
def home():
  return render_template('home.html') 

@app.route("/TurnOn/", methods=['POST'])
   
def on(): 
  ser.write(bytes("o ","utf-8"))
  return render_template('home.html') 

#for brightness slider
@app.route('/postmethod', methods = ['POST'])
def get_post_javscript_data(): 
    jsdata = request.form['javascript_data']
    #the number of white space in b acts a margin of saftey because sometimes the arduino skips the whitespace
    #when it skips the white space the previous js data gets combined with the new jsdata and then the lights turn off
   
    ser.write(bytes("b           " + str(jsdata) + " ", 'utf-8')) # + " " is to tell the intPearser() to stop reading data 
    print(jsdata);  
    return jsdata
@app.route('/ChangeColor',methods =['POST']) 
def colorChange():
    data = request.form['data'] 
    #no white space for data so the leds wont turn off
    ser.write(bytes(data, 'utf-8') ) 
    return  data

if __name__ == '__main__': 
    app.run()
