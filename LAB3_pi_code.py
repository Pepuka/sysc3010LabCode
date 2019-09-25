#!/usr/bin/env python
# coding: utf-8

# In[3]:


from RPi import GPIO
import time


# In[4]:


## setup LED

ledPin = 11
GPIO.setwarnings(False)
GPIO.setmode(GPIO.BOARD)
GPIO.setup(ledPin, GPIO.OUT)
#GPIO.output(ledPin, GPIO.HIGH)


# In[6]:


GPIO.output(ledPin, GPIO.LOW)


# In[ ]:


for _ in range(4):
    GPIO.output(ledPin, GPIO.HIGH)
    print("HIGH")
    time.sleep(1)
    GPIO.output(ledPin, GPIO.LOW)
    print("LOW")
    time.sleep(1)


# In[ ]:


## set up button
buttonPin = 16
GPIO.setmode(GPIO.BOARD)
GPIO.setup(buttonPin, GPIO.IN, pull_up_down=GPIO.PUD_UP)


# In[ ]:


for i in range(10):
    GPIO.wait_for_edge(buttonPin, GPIO.FALLING)
    print("BUTTON PRESSED", i)
    GPIO.output(ledPin, GPIO.HIGH)
    GPIO.wait_for_edge(buttonPin, GPIO.RISING)
    GPIO.output(ledPin, GPIO.LOW)


# In[ ]:


GPIO.cleanup()

